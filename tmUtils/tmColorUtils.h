/*
 *  ColorUtils.h
 *  Stop-iT
 *
 *  Created by Tobias Muthesius on 18/05/10.
 *  Copyright 2010 lab212. All rights reserved.
 *
 */

static int colorDistance(ofColor c1, ofColor c2){
	return sqrt(pow(c1.r - c2.r, 2) + pow(c1.g - c2.g, 2) + pow(c1.b - c2.b, 2));
}
/*
static ofColor RGBtoHSV(ofColor c){
	ofColor rc;
	float min, max, delta;
	
	min = MIN( c.r, c.g, c.b );
	max = MAX( c.r, c.g, c.b );
	rc.b = max;				// v
	
	delta = max - min;
	
	if( max != 0 )
		rc.g = delta / max;		// s
	else {
		// r = g = b = 0		// s = 0, v is undefined
		rc.g = 0;
		rc.r = -1;
		return rc;
	}
	
	if( c.r == max )
		rc.r = ( c.g - c.b ) / delta;		// between yellow & magenta
	else if( g == max )
		rc.r = 2 + ( c.b - c.r ) / delta;	// between cyan & yellow
	else
		rc.r = 4 + ( c.r - c.g ) / delta;	// between magenta & cyan
	
	rc.r *= 60;				// degrees
	if( rc.r < 0 )
		rc.r += 360;
	
	return rc;
}*/