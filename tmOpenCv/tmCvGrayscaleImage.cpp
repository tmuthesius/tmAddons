/*
 *  tmCvGrayscaleImage.cpp
 *  Laban
 *
 *  Created by Tobias Muthesius on 20/12/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "tmCvGrayscaleImage.h"

int tmCvGrayscaleImage::findLines(){
	
	CvMemStorage* storage = cvCreateMemStorage(0);
	CvSeq* lines = 0;
	
	lines = cvHoughLines2(cvImage,
						  storage,
						  CV_HOUGH_STANDARD,
						  1,
						  CV_PI/180,
						  100,
						  0,
						  0);
	
	int n = lines->total;
	
	cout << n << endl;
	
	delete storage;
	delete lines;
	
	return n;
}