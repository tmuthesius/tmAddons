/*
 *  tmCvGrayscaleImage.h
 *  Laban
 *
 *  Created by Tobias Muthesius on 20/12/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#pragma once

#include "ofxCvColorImage.h"
#include "ofxCvGrayscaleImage.h"

class tmCvGrayscaleImage : public ofxCvGrayscaleImage{
public:
	
	using ofxCvGrayscaleImage::operator =;
	
	int findLines();
};