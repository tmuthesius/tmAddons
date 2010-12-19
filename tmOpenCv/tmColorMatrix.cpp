/*
 *  tmColorMatrix.cpp
 *  Fire
 *
 *  Created by Tobias Muthesius on 10/11/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "tmColorMatrix.h"

float tmColorMatrix::baseMatrix[] = {
	1, 0, 0, 0,  
	0, 1, 0, 0,  
	0, 0, 1, 0
};


void tmColorMatrix::adjustSaturation(float s){
	float sInv = (1 - s);
	float irlum = (sInv * TM_LUMA_R);
	float iglum = (sInv * TM_LUMA_G);
	float iblum = (sInv * TM_LUMA_B);
	
	float temp[3*4];
	memcpy(temp, baseMatrix, sizeof(float)*3*4);
	temp[0] = irlum + s;
	temp[1] = iglum;
	temp[2] = iblum;
	
	temp[4] = irlum;
	temp[5] = iglum + s;
	temp[6] = iblum;
	
	temp[8] = irlum;
	temp[9] = iglum;
	temp[10] = iblum + s;
	
	concat(temp);
}

void tmColorMatrix::adjustContrast(float value){
	value ++;
	
	float temp[3*4];
	memcpy(temp, baseMatrix, sizeof(float)*3*4);
	temp[0] = value;
	temp[3] = 128 * (1 - value);
	
	temp[5] = value;
	temp[7] = 128 * (1 - value);
	
	temp[10] = value;
	temp[11] = 128 * (1 - value);
	
	concat(temp);
}

void tmColorMatrix::adjustBrightness(float value){
	
	float temp[3*4];
	memcpy(temp, baseMatrix, sizeof(float)*3*4);
	
	temp[3] = value;
	temp[7] = value;
	temp[11] = value;
	
	concat(temp);
}