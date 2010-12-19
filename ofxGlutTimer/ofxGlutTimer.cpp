/*
 *  ofxGlutTimer.cpp
 *  Stop-iT
 *
 *  Created by Tobias Muthesius on 28/06/10.
 *  Copyright 2010 lab212. All rights reserved.
 *
 */

#include "ofxGlutTimer.h"

void ofxGlutTimer::init(float delay, bool loop){
	setDelay(delay);
	setLoop(loop);
	reset();
	launched = false;
}
void ofxGlutTimer::reset(){
	stop();
}
void ofxGlutTimer::start(){
	running = true;
	launch();
}
void ofxGlutTimer::stop(){
	running = false;
}
void ofxGlutTimer::setDelay(float delay){
	this->delay = delay;
}
float ofxGlutTimer::getDelay(){
	return delay;
}
void ofxGlutTimer::setLoop(bool loop){
	this->loop = loop;
}
bool ofxGlutTimer::getLoop(){
	return loop;
}

void ofxGlutTimer::launch(){
	if(!running || launched) return;
	launched = true;
	glutTimerFunc((int)delay, tickGlutCallback, (int)this);
}
void ofxGlutTimer::tick(){
	launched = false;
	ofNotifyEvent(timerTick, timerTickArgs, this);
	if(loop) launch();
}