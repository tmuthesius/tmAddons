/*
 *  tmCvColorImage.cpp
 *  Fire
 *
 *  Created by Tobias Muthesius on 10/11/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "tmCvColorImage.h"

void tmCvColorImage::colorTransform(float *matrix){
	CvMat mat = cvMat(3, 4, CV_32F, matrix);
	cvTransform(cvImage, cvImageTemp, &mat);
	swapTemp();
    flagImageChanged();
}

void tmCvColorImage::setFromBayer(ofxCvGrayscaleImage &input, int code){
	cvCvtColor(input.getCvImage(), cvImage, code);
    flagImageChanged();
}