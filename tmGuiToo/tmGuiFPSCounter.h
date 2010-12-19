/*
 *  tmGuiFPSCounter.h
 *  Fire
 *
 *  Created by Tobias Muthesius on 10/11/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#pragma once

#include "ofxSimpleGuiControl.h"

class tmGuiFPSCounter : public ofxSimpleGuiControl{
public:
	tmGuiFPSCounter(string label, float &value);
	void setup(string label, float &value);
	void draw(float x, float y);
	
private:
	float *_value;
	string _label;
};