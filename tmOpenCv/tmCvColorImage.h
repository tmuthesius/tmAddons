/*
 *  tmCvColorImage.h
 *  Fire
 *
 *  Created by Tobias Muthesius on 10/11/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#pragma once

#include "ofxCvColorImage.h"
#include "ofxCvGrayscaleImage.h"


class tmCvColorImage : public ofxCvColorImage{
public:
	void colorTransform(float *matrix);
	void setFromBayer(ofxCvGrayscaleImage &input, int code = CV_BayerBG2RGB);
};