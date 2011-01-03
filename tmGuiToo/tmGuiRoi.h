/*
 *  SimpleGuiRoi.h
 *  Stop-iT
 *
 *  Created by Tobias Muthesius on 15/05/10.
 *  Copyright 2010 lab212. All rights reserved.
 *
 */

#pragma once
#include "ofxSimpleGuiContent.h"

class tmGuiRoi : public ofxSimpleGuiContent{

public:
	
	tmGuiRoi(string name, ofBaseDraws& content, float fixwidth, ofRectangle &rect);
	void draw(float x, float y);
	
	void loadFromXML(ofxXmlSettings &XML);
	void saveToXML(ofxXmlSettings &XML);
	
	ofEvent<int> roiUpdateEvent;

protected:
	void onRelease(int x, int y, int button);
	void onReleaseOutside(int x, int y, int button);
	
	void mousePressed(ofMouseEventArgs &e);
	void mouseDragged(ofMouseEventArgs &e);
	
	void rectRatio(ofRectangle *r);
	
	ofRectangle *rect;
	ofPoint points[2];
	ofPoint	*curPoint;
	
};