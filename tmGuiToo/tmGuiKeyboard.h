/*
 *  tmGuiKeyboard.h
 *  Stop-iT
 *
 *  Created by Tobias Muthesius on 03/06/10.
 *  Copyright 2010 lab212. All rights reserved.
 *
 */

#pragma once

#include "ofxSimpleGuiControl.h"


class tmGuiKeyboard : public ofxSimpleGuiControl{
public:
	
	tmGuiKeyboard(string name, char *notes = NULL, int maxNotes = 0);
	
	void draw(float x, float y);
	
	
	ofEvent <ofKeyEventArgs> testNoteClick;
	
protected:
	
	void mousePressed(ofMouseEventArgs &e);
	void mouseReleased(ofMouseEventArgs &e);
	void mouseMoved(ofMouseEventArgs &e);
	
	void loadFromXML(ofxXmlSettings &XML);
	void saveToXML(ofxXmlSettings &XML);
	
	char isInTempNotes(char n);
	
	int mouseX;
	int mouseY;
	bool bReleased;
	
	char *notes;
	vector<char> tmpNotes;
	int maxNotes;
};