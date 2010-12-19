/*
 *  FpsCounter.h
 *  Fire
 *
 *  Created by Tobias Muthesius on 05/11/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */


#pragma once
#include "ofMain.h"

#define AVERAGE_ITERATIONS 10

class tmFpsCounter{
public:
	tmFpsCounter(){
		prev = tot = pos = 0;
		memset(val, 0, AVERAGE_ITERATIONS * sizeof(int));
	}
	void update(){
		int t = ofGetElapsedTimeMillis();
		tot -= val[pos];
		instantFps = val[pos] = 1000/(t-prev);
		tot += val[pos];
		pos ++;
		if(pos >= AVERAGE_ITERATIONS) pos = 0;
		prev = t;
		
		averageFps = (float)tot / AVERAGE_ITERATIONS;
	}
	
	float averageFps;
	float instantFps;
	
private:
	int prev;
	int tot;
	int val[AVERAGE_ITERATIONS];
	int pos;
};