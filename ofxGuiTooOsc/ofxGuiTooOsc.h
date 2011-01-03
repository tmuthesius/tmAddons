/*
 *  tmGuiTooOsc.h
 *
 *  Created by Tobias Muthesius on 12/12/10.
 *  Copyright 2010. All rights reserved.
 *  http://tobiasmuthesius.net
 *
 *  This is a small bridge between Memo's ofxSimpleGuiToo and ofxOsc so a gui control can easily be controlled through osc
 *  (with touchOsc for example). Communication is made in both directions : if a gui control is updated, it's value is sent thought osc
 *  and if a value is received on the address registered with the gui control, it's updated according to this value.
 *  
 *  To use is, simply create an instance of ofxGuiTooOsc and call setup with osc in port, osc out host and osc out port.
 *  After that, call add with a ofxSimpleGuiToo control and an osc address.
 *  Update needs to be called manually (perhaps using events in a next version ?...)
 *  
 *  osc.setup(1212, "iPhoneTmuthesius.local", 2212);
 *  osc.add(gui.addSlider("Gain", cam->gain, 0, 1), "/Capture/camGain");
 *
 *  The unusedMessages vector is intended to be used for remaining messages that are not used for the gui controls and that we need to
 *  process manually
 *
 *  TODO:
 *  This is a first version, actually only the Slider control is implemented, hope I'll have time to extend 
 *  that to almost all controls of ofxSimpleGuiToo
 *  
 */


#pragma once

#include "ofxOsc.h"
#include "ofxSimpleGuiToo.h"


struct ofxGuiTooOscElm {
	ofxSimpleGuiControl *control;
	string address;
};


class ofxGuiTooOsc{
public:
	ofxGuiTooOsc(){}
	ofxGuiTooOsc(int inPort, string outHost, int outPort){
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
	
	vector<ofxGuiTooOscElm> list;
	ofxOscReceiver oscIn;
	ofxOscSender oscOut;
	bool shoudUpdate;
};