/*
 *  ProcCounter.h
 *  Fire
 *
 *  Created by Tobias Muthesius on 05/11/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */


#pragma once
#include "ofMain.h"

class tmProcCounter{
public:
	tmProcCounter(){
		time = 0;
	}
	void start(){
		time = ofGetElapsedTimeMillis();
	}
	void stop(){
		time = ofGetElapsedTimeMillis() - time;
	}
	float time;
};