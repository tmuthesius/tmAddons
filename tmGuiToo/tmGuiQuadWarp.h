/*
 *  tmGuiQuadWarp.h
 *  Stop-iT
 *
 *  Created by Tobias Muthesius on 16/05/10.
 *  Copyright 2010 lab212. All rights reserved.
 *
 */

#pragma once
#include "ofxSimpleGuiContent.h"

class tmGuiQuadWarp : public ofxSimpleGuiContent{
	
public:
	
	tmGuiQuadWarp(string name, ofBaseDraws& content, float fixwidth, ofPoint *points);
	void draw(float x, float y);
	
	ofEvent<int> warpUpdateEvent;
	
protected:
	void onRelease(int x, int y, int button);
	void onReleaseOutside(int x, int y, int button);
	
	void mousePressed(ofMouseEventArgs &e);
	void mouseDragged(ofMouseEventArgs &e);
	
	void keyPressed(int key);
	
	void loadFromXML(ofxXmlSettings &XML);
	void saveToXML(ofxXmlSettings &XML);
	
	ofPoint *points;
	ofPoint	*curPoint;
	
};