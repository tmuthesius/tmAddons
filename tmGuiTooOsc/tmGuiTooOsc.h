/*
 *  tmGuiTooOsc.h
 *  Fire
 *
 *  Created by Tobias Muthesius on 12/12/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */


#pragma once

#include "ofxOsc.h"
#include "ofxSimpleGuiToo.h"


struct tmGuiTooOscElm {
	ofxSimpleGuiControl *control;
	string address;
};


class tmGuiTooOsc{
public:
	tmGuiTooOsc(){}
	tmGuiTooOsc(int inPort, string outHost, int outPort){
		setup(inPort, outHost, outPort);
	}
	
	void setup(int inPort, string outHost, int outPort);
	void add(ofxSimpleGuiControl &control, const string address);
	void update();
	void forceOscUpdate(){
		shoudUpdate = true;
	}
	
	vector<ofxOscMessage> unusedMessages;
	
protected:
	bool processMessage(ofxOscMessage &mess);
	
	vector<tmGuiTooOscElm> list;
	ofxOscReceiver oscIn;
	ofxOscSender oscOut;
	bool shoudUpdate;
};