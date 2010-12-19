/*
 *  ofxGlutTimer.h
 *  Stop-iT
 *
 *  Created by Tobias Muthesius on 28/06/10.
 *  Copyright 2010 lab212. All rights reserved.
 *
 */

#pragma once
#include "ofMain.h"

class ofxGlutTimer{
public:
	void init(float delay, bool loop);
	void reset();
	void start();
	void stop();
	
	void setDelay(float delay);
	float getDelay();
	void setLoop(bool loop);
	bool getLoop();
	
	ofEvent<ofEventArgs> timerTick;
	
	
	static void tickGlutCallback(int pt){
		((ofxGlutTimer*)pt)->tick();
	}
	
protected:
	float delay;
	bool loop;
	bool running;
	bool launched;
	
	ofEventArgs timerTickArgs;
	
	void launch();
	void tick();
};