/*
 *  tmGuiKeyboard.cpp
 *  Stop-iT
 *
 *  Created by Tobias Muthesius on 03/06/10.
 *  Copyright 2010 lab212. All rights reserved.
 *
 */

#include "tmGuiKeyboard.h"

tmGuiKeyboard::tmGuiKeyboard(string name, char *notes, int maxNotes) : ofxSimpleGuiControl(name){
	controlType = "Keyboard";
	
	this->notes = notes;
	this->maxNotes = maxNotes;
	
	height = 16;
	
	bReleased = false;
	
	ofAddListener(ofEvents.mouseMoved, this, &tmGuiKeyboard::mouseMoved);
	ofAddListener(ofEvents.mousePressed, this, &tmGuiKeyboard::mousePressed);
	ofAddListener(ofEvents.mouseReleased, this, &tmGuiKeyboard::mouseReleased);
}

void tmGuiKeyboard::mouseMoved(ofMouseEventArgs &e) {
	mouseX = e.x;
	mouseY = e.y;
}
void tmGuiKeyboard::mousePressed(ofMouseEventArgs &e) {
	mouseX = e.x;
	mouseY = e.y;
	bReleased = true;
}
void tmGuiKeyboard::mouseReleased(ofMouseEventArgs &e) {
	mouseX = e.x;
	mouseY = e.y;
	
	ofKeyEventArgs noteEventArgs;
	noteEventArgs.key = -1;
	ofNotifyEvent(testNoteClick, noteEventArgs, this);
}

void tmGuiKeyboard::loadFromXML(ofxXmlSettings &XML) {
	if(maxNotes == 0) return;
	
	XML.pushTag("controls");
	XML.pushTag(controlType + "_" + key);
	XML.pushTag("notes");
	for(int i=0; i<maxNotes; i++){
		notes[i] = (char)XML.getValue("note", -1, i);
		if(notes[i] >= 0) tmpNotes.push_back(notes[i]);
	}
	XML.popTag();
	XML.popTag();
	XML.popTag();
}

void tmGuiKeyboard::saveToXML(ofxXmlSettings &XML) {
	if(maxNotes == 0) return;
	
	XML.addTag(controlType + "_" + key);
	XML.pushTag(controlType + "_" + key);
	XML.addValue("name", name);
	XML.addTag("notes");
	XML.pushTag("notes");
	for(int i=0; i<maxNotes; i++){
		XML.addValue("note", notes[i]); 
	}
	XML.popTag();
	XML.popTag();
}

void tmGuiKeyboard::draw(float x, float y){
	int xPos = (mouseX - x);
	int yPos = (mouseY - y);
	
	glPushMatrix();
	glTranslatef(x, y, 0);
	ofPushStyle();
	
	ofFill();
	int n = 0;
	for(int i=0; i<128; i++) {
		int r = i%12;
		if (r==0||r==2||r==4||r==5||r==7||r==9||r==11) {
			
			if(xPos/7 == n && yPos > 8 && yPos <= 16){
				if(bReleased){
					if(maxNotes > 0){
						char on = isInTempNotes(i);
						if(on >= 0) tmpNotes.erase(tmpNotes.begin() + on);
						else if(tmpNotes.size() < maxNotes) tmpNotes.push_back(i);
					}
					ofKeyEventArgs noteEventArgs;
					noteEventArgs.key = i;
					ofNotifyEvent(testNoteClick, noteEventArgs, this);
				}
				ofSetHexColor(config->fullOverColor);
			}
			else if(isInTempNotes(i) >= 0) ofSetHexColor(config->fullActiveColor);
			else ofSetHexColor(config->fullColor);
			
			ofRect(n*7, 0, 6, 16);
			n++;
		}
	}
	
	n = 0;
	for(int i=0; i<128; i++) {
		int r = i%12;
		if (r==1||r==3||r==6||r==8||r==10) {
			
			if((xPos-3)/7 == n-1 && yPos > 0 && yPos <= 8){
				if(bReleased){
					if(maxNotes > 0){
						char on = isInTempNotes(i);
						if(on >= 0) tmpNotes.erase(tmpNotes.begin() + on);
						else if(tmpNotes.size() < maxNotes) tmpNotes.push_back(i);
					}
					ofKeyEventArgs noteEventArgs;
					noteEventArgs.key = i;
					ofNotifyEvent(testNoteClick, noteEventArgs, this);
				}
				ofSetHexColor(config->fullOverColor);
			}
			else if(isInTempNotes(i) >= 0) ofSetHexColor(config->fullActiveColor);
			else ofSetHexColor(config->emptyColor);
			
			ofRect(n*7-3, 0, 6, 8);
		}
		else n++;
	}
	
	ofPopStyle();
	glPopMatrix();
	
	if(bReleased){
		if(maxNotes > 0){
			sort(tmpNotes.begin(), tmpNotes.end());
			for(int i=0; i<maxNotes; i++){
				if(i<tmpNotes.size()) notes[i] = tmpNotes[i];
				else notes[i] = -1;
			}
		}
		bReleased = false;
	}
}


char tmGuiKeyboard::isInTempNotes(char n){
	if(maxNotes == 0) return -1;
	
	for(int i=0; i<tmpNotes.size(); i++){
		if(tmpNotes[i] == n) return i;
	}
	return -1;
}