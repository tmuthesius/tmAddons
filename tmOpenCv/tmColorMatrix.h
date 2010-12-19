/*
 *  tmColorMatrix.h
 *  Fire
 *
 *  Created by Tobias Muthesius on 10/11/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *	Orifinal in AS3 from Mario Klingemann
 */

#pragma once

#define TM_LUMA_R 0.212671
#define TM_LUMA_G 0.71516
#define TM_LUMA_B 0.072169

#define TM_LUMA_R2 0.3086
#define TM_LUMA_G2 0.6094
#define TM_LUMA_B2 0.0820

//const float tmOneThird = 1 / 3;
//const float tmRad = PI / 180; 

class tmColorMatrix{
public:
	tmColorMatrix(){
		reset();
	}
	void reset(){
		memcpy(matrix, baseMatrix, sizeof(float)*3*4);
	}
	float *getMatrix(){
		return matrix;
	}
	
	void adjustSaturation(float s);
	void adjustContrast(float value);
	void adjustBrightness(float value);
	/*
	public function adjustHue( degrees:Number ):void
	{
		degrees *= RAD;
		var cos:Number = Math.cos(degrees);
		var sin:Number = Math.sin(degrees);
		concat([((LUMA_R + (cos * (1 - LUMA_R))) + (sin * -(LUMA_R))), ((LUMA_G + (cos * -(LUMA_G))) + (sin * -(LUMA_G))), ((LUMA_B + (cos * -(LUMA_B))) + (sin * (1 - LUMA_B))), 0, 0, 
				((LUMA_R + (cos * -(LUMA_R))) + (sin * 0.143)), ((LUMA_G + (cos * (1 - LUMA_G))) + (sin * 0.14)), ((LUMA_B + (cos * -(LUMA_B))) + (sin * -0.283)), 0, 0, 
				((LUMA_R + (cos * -(LUMA_R))) + (sin * -((1 - LUMA_R)))), ((LUMA_G + (cos * -(LUMA_G))) + (sin * LUMA_G)), ((LUMA_B + (cos * (1 - LUMA_B))) + (sin * LUMA_B)), 0, 0, 
				0, 0, 0, 1, 0]);
	}
	
	public function colorize(rgb:int, amount:Number=1):void
	{
		var r:Number;
		var g:Number;
		var b:Number;
		var inv_amount:Number;
		
		r = (((rgb >> 16) & 0xFF) / 0xFF);
		g = (((rgb >> 8) & 0xFF) / 0xFF);
		b = ((rgb & 0xFF) / 0xFF);
		inv_amount = (1 - amount);
		
		concat([(inv_amount + ((amount * r) * LUMA_R)), ((amount * r) * LUMA_G), ((amount * r) * LUMA_B), 0, 0, 
				((amount * g) * LUMA_R), (inv_amount + ((amount * g) * LUMA_G)), ((amount * g) * LUMA_B), 0, 0, 
				((amount * b) * LUMA_R), ((amount * b) * LUMA_G), (inv_amount + ((amount * b) * LUMA_B)), 0, 0, 
				0, 0, 0, 1, 0]);
	}
	*/
protected:
	static float baseMatrix[3*4];
	
	
	float matrix[3*4];
	
	
	void concat(float *mat){
		float temp[3*4];
		int i = 0;
		for (int y = 0; y < 3; y++ ){
			for (int x = 0; x < 4; x++ ){
				temp[i + x] = mat[i] * matrix[x] + mat[i+1] * matrix[x + 4] + mat[i+2] * matrix[x + 8] + (x == 3 ? mat[i+3] : 0);
			}
			i+=4;
		}
		memcpy(matrix, temp, sizeof(float)*3*4);
	}
};

