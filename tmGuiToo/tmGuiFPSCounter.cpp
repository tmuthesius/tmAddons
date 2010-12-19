/*
 *  tmGuiFPSCounter.cpp
 *  Fire
 *
 *  Created by Tobias Muthesius on 10/11/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "tmGuiFPSCounter.h"

tmGuiFPSCounter::tmGuiFPSCounter(string label, float &value) : ofxSimpleGuiControl("FPS Counter") {
	controlType = "FPSCounter";
	setup(label, value);
}

void tmGuiFPSCounter::setup(string label, float &value) {
	_value = &value;
	_label = label;
	setSize(config->gridSize.x - config->padding.x, config->titleHeight);
}


void tmGuiFPSCounter::draw(float x, float y) {
	setPos(x, y);
	
	glPushMatrix();
	glTranslatef(x, y, 0);
	
	ofEnableAlphaBlending();
	ofFill();
	setTextBGColor(false);
	ofRect(0, 0, width, height);
	
	setTextColor(false);
	ofDrawBitmapString(_label+": " + ofToString(*(_value)), 3, 15);
	
	glPopMatrix();
}