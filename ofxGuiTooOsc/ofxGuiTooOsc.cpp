/*
 *  tmGuiTooOsc.cpp
 *
 *  Created by Tobias Muthesius on 12/12/10.
 *  Copyright 2010. All rights reserved.
 *  http://tobiasmuthesius.net
 *
 */

#include "ofxGuiTooOsc.h"

void ofxGuiTooOsc::setup(int inPort, string outHost, int outPort){
	oscIn.setup(inPort);
	oscOut.setup(outHost, outPort);
	shoudUpdate = false;
}

void ofxGuiTooOsc::add(ofxSimpleGuiControl &control, const string address){
	ofxGuiTooOscElm e;
	e.control = &control;
	e.address = address;
	list.push_back(e);
}

void ofxGuiTooOsc::update(){
	
	unusedMessages.clear();
	ofxOscMessage mess;
	
	while(oscIn.hasWaitingMessages()){
		oscIn.getNextMessage(&mess);
		if(!processMessage(mess)){
			unusedMessages.push_back(mess);
		}
	}
	
	
	for (int i=0; i < list.size(); i++) {
		ofxGuiTooOscElm &e = list[i];
		if(e.control->controlType == "SliderInt"){
			ofxSimpleGuiSliderInt *c = (ofxSimpleGuiSliderInt*) e.control;
			if(c->oldValue != c->targetValue || shoudUpdate) {
				mess.clear();
				mess.setAddress(e.address);
				mess.addFloatArg(ofMap(c->targetValue, c->min, c->max, 0.0, 1.0, true));
				oscOut.sendMessage(mess);
			}
		}
		else if(e.control->controlType == "SliderFloat"){
			ofxSimpleGuiSliderFloat *c = (ofxSimpleGuiSliderFloat*) e.control;
			if(c->oldValue != c->targetValue || shoudUpdate) {
				mess.clear();
				mess.setAddress(e.address);
				mess.addFloatArg(ofMap(c->targetValue, c->min, c->max, 0.0, 1.0, true));
				oscOut.sendMessage(mess);
			}
		}
	}
	
	shoudUpdate = false;
}


bool ofxGuiTooOsc::processMessage(ofxOscMessage &mess){
	string addr = mess.getAddress();
	for (int i=0; i < list.size(); i++) {
		if(list[i].address == addr){
			ofxGuiTooOscElm &e = list[i];
			
			if(e.control->controlType == "SliderInt"){
				ofxSimpleGuiSliderInt *c = (ofxSimpleGuiSliderInt*) e.control;
				c->setValue(ofMap(mess.getArgAsFloat(0), 0.0, 1.0, c->min, c->max, true));
			}
			else if(e.control->controlType == "SliderFloat"){
				ofxSimpleGuiSliderFloat *c = (ofxSimpleGuiSliderFloat*) e.control;
				c->setValue(ofMap(mess.getArgAsFloat(0), 0.0, 1.0, c->min, c->max, true));
			}
			
			return true;
		}
	}
	return false;
}