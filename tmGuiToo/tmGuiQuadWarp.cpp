/*
 *  tmGuiQuadWarp.cpp
 *  Stop-iT
 *
 *  Created by Tobias Muthesius on 16/05/10.
 *  Copyright 2010 lab212. All rights reserved.
 *
 */

#include "tmGuiQuadWarp.h"

#define MOUSE_DISTANCE		10.0f

tmGuiQuadWarp::tmGuiQuadWarp(string name, ofBaseDraws& content, float fixwidth, ofPoint *points) : ofxSimpleGuiContent(name, content, fixwidth){
	this->points = points;
	curPoint = NULL;
	controlType = "QuadWarp";
	
	ofAddListener(ofEvents.mousePressed, this, &tmGuiQuadWarp::mousePressed);
	ofAddListener(ofEvents.mouseDragged, this, &tmGuiQuadWarp::mouseDragged);
}


void tmGuiQuadWarp::mousePressed(ofMouseEventArgs &e) {
	curPoint = NULL;
	for(int i=0; i<4; i++) {
		if(ofDistSquared(e.x - this->x, e.y - this->y, points[i].x, points[i].y) < MOUSE_DISTANCE * MOUSE_DISTANCE) {
			curPoint = points + i;
		}
	}
}

void tmGuiQuadWarp::mouseDragged(ofMouseEventArgs &e) {
	if(curPoint) {
		curPoint->set(min(max((int)(e.x - this->x), 0), (int)fixwidth), min(max((int)(e.y - this->y), 0), (int)fixheight));
	}
}


void tmGuiQuadWarp::onRelease(int x, int y, int button) {
	if(curPoint) {
		curPoint->set(min(max((int)curPoint->x, 0), (int)fixwidth), min(max((int)curPoint->y, 0), (int)fixheight));
	}
	curPoint = NULL;
	
	int d = 0;
	ofNotifyEvent(warpUpdateEvent, d, this);
}
void tmGuiQuadWarp::onReleaseOutside(int x, int y, int button) {
	onRelease(x, y, button);
}
void tmGuiQuadWarp::keyPressed(int key){
	if(curPoint) switch (key) {
		case 356:
			curPoint->x --;
			break;
		case 357:
			curPoint->y --;
			break;
		case 358:
			curPoint->x ++;
			break;
		case 359:
			curPoint->y ++;
			break;
	}
}

void tmGuiQuadWarp::loadFromXML(ofxXmlSettings &XML) {
	points[0].x = (float)XML.getValue(controlType + "_" + key + ":p0x", 0.0f);
	points[0].y = (float)XML.getValue(controlType + "_" + key + ":p0y", 0.0f);
	points[1].x = (float)XML.getValue(controlType + "_" + key + ":p1x", 0.0f);
	points[1].y = (float)XML.getValue(controlType + "_" + key + ":p1y", 0.0f);
	points[2].x = (float)XML.getValue(controlType + "_" + key + ":p2x", 0.0f);
	points[2].y = (float)XML.getValue(controlType + "_" + key + ":p2y", 0.0f);
	points[3].x = (float)XML.getValue(controlType + "_" + key + ":p3x", 0.0f);
	points[3].y = (float)XML.getValue(controlType + "_" + key + ":p3y", 0.0f);
}

void tmGuiQuadWarp::saveToXML(ofxXmlSettings &XML) {
	XML.addTag(controlType + "_" + key);
	XML.pushTag(controlType + "_" + key);
	XML.addValue("name", name);
	XML.addValue("p0x", points[0].x);
	XML.addValue("p0y", points[0].y);
	XML.addValue("p1x", points[1].x);
	XML.addValue("p1y", points[1].y);
	XML.addValue("p2x", points[2].x);
	XML.addValue("p2y", points[2].y);
	XML.addValue("p3x", points[3].x);
	XML.addValue("p3y", points[3].y);
	XML.popTag();
}


void tmGuiQuadWarp::draw(float x, float y){
	ofxSimpleGuiContent::draw(x, y);
	
	glPushMatrix();
	glTranslatef(x, y, 0);
	ofPushStyle();
	
	ofNoFill();
	ofSetHexColor(0x00FFFF);
	ofBeginShape();
	for(int i=0; i<4; i++) {
		ofVertex(points[i].x, points[i].y);
	}
	ofEndShape(TRUE);
	
	ofFill();
	for(int i=0; i<4; i++) {
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