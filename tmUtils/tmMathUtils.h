/*
 *  MathUtils.h
 *  Stop-iT
 *
 *  Created by Tobias Muthesius on 12/05/10.
 *  Copyright 2010 lab212. All rights reserved.
 *
 */

#pragma once

typedef struct{
	float r;
	float t;
} polarPoint;

static polarPoint cartesianToPolar(int x, int y){
	polarPoint p;
	p.r = sqrt(x * x + y * y);
	p.t = atan2(y, x);
	return p;
}

static ofPoint polarToCartesian(float r, float t){
	ofPoint p;
	p.x = r * cos(t);
	p.y = r * sin(t);
	return p;
}

static ofPoint linesIntersection(ofPoint a1, ofPoint a2, ofPoint b1, ofPoint b2){
	ofPoint p;
	float d = (a1.x-a2.x)*(b1.y-b2.y)-(a1.y-a2.y)*(b1.x-b2.x);
	if(d != 0){
		float d1 = a1.x*a2.y - a1.y*a2.x;
		float d2 = b1.x*b2.y - b1.y*b2.x;
		p.x = (d1*(b1.x-b2.x)-(a1.x-a2.x)*d2) / d;
		p.y = (d1*(b1.y-b2.y)-(a1.y-a2.y)*d2) / d;
		return p;
	}
	return NULL;
}