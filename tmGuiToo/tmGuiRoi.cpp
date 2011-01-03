/*
 *  SimpleGuiRoi.cpp
 *  Stop-iT
 *
 *  Created by Tobias Muthesius on 15/05/10.
 *  Copyright 2010 lab212. All rights reserved.
 *
 */

#include "tmGuiRoi.h"

#define MOUSE_DISTANCE		10.0f
#define MIN_ROI_SIZE		10



tmGuiRoi::tmGuiRoi(string name, ofBaseDraws& content, float fixwidth, ofRectangle &rect) : ofxSimpleGuiContent(name, content, fixwidth){
	this->rect = &rect;
	curPoint = NULL;
	controlType = "ROI";
	
	ofAddListener(ofEvents.mousePressed, this, &tmGuiRoi::mousePressed);
	ofAddListener(ofEvents.mouseDragged, this, &tmGuiRoi::mouseDragged);
}

void tmGuiRoi::mousePressed(ofMouseEventArgs &e) {
	curPoint = NULL;
	for(int i=0; i<2; i++) {
		if(ofDistSquared(e.x - this->x, e.y - this->y, points[i].x, points[i].y) < MOUSE_DISTANCE * MOUSE_DISTANCE) {
			curPoint = points + i;
		}
	}
}

void tmGuiRoi::mouseDragged(ofMouseEventArgs &e) {
	if(curPoint) {
		curPoint->set(min(max((int)(e.x - this->x), 0), (int)fixwidth), min(max((int)(e.y - this->y), 0), (int)fixheight));
	}
}


void tmGuiRoi::onRelease(int x, int y, int button) {
	curPoint = NULL;
	
	if(points[1].x > points[0].x) rect->x = points[0].x;
	else rect->x = points[1].x;
	if(points[1].y > points[0].y) rect->y = points[0].y;
	else rect->y = points[1].y;
	
	rect->width = max(abs((int)(points[1].x - points[0].x)), MIN_ROI_SIZE);
	rect->height = max(abs((int)(points[1].y - points[0].y)), MIN_ROI_SIZE);
	
	rectRatio(rect);
	int d = 0;
	ofNotifyEvent(roiUpdateEvent, d, this);
}
void tmGuiRoi::onReleaseOutside(int x, int y, int button) {
	onRelease(x, y, button);
}



void tmGuiRoi::loadFromXML(ofxXmlSettings &XML) {
	for(int i=0; i<2; i++) {
		points[i].x = XML.getValue(controlType + "_" + key + ":values_" + ofToString(i) + "_x", 0.0f);
		points[i].y = XML.getValue(controlType + "_" + key + ":values_" + ofToString(i) + "_y", 0.0f);
	}
	rect->x = points[0].x;
	rect->y = points[0].y;
	rect->width  = points[1].x - rect->x;
	rect->height  = points[1].y - rect->y;
	rectRatio(rect);
}

void tmGuiRoi::saveToXML(ofxXmlSettings &XML) {
	XML.addTag(controlType + "_" + key);
	XML.pushTag(controlType + "_" + key);
	XML.addValue("name", name);
	for(int i=0; i<2; i++) {
		XML.addValue("values_" + ofToString(i) + "_x", points[i].x);
		XML.addValue("values_" + ofToString(i) + "_y", points[i].y);
	}
	XML.popTag();
}



void tmGuiRoi::draw(float x, float y){
	ofxSimpleGuiContent::draw(x, y);
	
	glPushMatrix();
	glTranslatef(x, y, 0);
	ofPushStyle();

	ofNoFill();
	ofSetHexColor(0x00FFFF);
	ofSetLineWidth(1);
	ofRect(points[0].x, points[0].y, points[1].x-points[0].x, points[1].y-points[0].y);
	
	ofFill();
	for(int i=0; i<2; i++) {
		if(curPoint == &points[i]) {
			ofSetHexColor(0xFF0000);
			ofCircle(points[i].x, points[i].y, 5);
		}
		else{
			ofSetHexColor(0x00FFFF);
			ofCircle(points[i].x, points[i].y, 3);
		}
	}
	
	ofPopStyle();
	glPopMatrix();
}


void tmGuiRoi::rectRatio(ofRectangle *r){
	float ra = content->getWidth() / fixwidth;
	rect->x *= ra;
	rect->y *= ra;
	rect->width *= ra;
	rect->height *= ra;
}