/*
 *  ofxUVCVideoGrabber.h
 *
 *  Created by Tobias Muthesius on 31/12/10.
 *  Copyright 2010. All rights reserved.
 *  http://tobiasmuthesius.net
 *
 *  This addon simply puts together the ofxQTKitVideoGrabber addon (James George, http://www.jamesgeorge.org ) and the
 *  UVCCameraControl obj-c class (Phoboslab, http://www.phoboslab.org ).
 *  What is that for ? Be able to adjust the settings of some UVC Webcams like the Logitech QuickCam Pro 9000 on OSX.
 *
 *  To use it, you need to get the ofxQTKitVideoGrabber addon and add the CoreVideo and QTKit frameworks to your project.
 *  Because this addon extends ofxQTKitVideoGrabber, you can use it exactly like ofVideoGrabber. 
 *  The camera settings are exposed through set and get methods. Values between 0 and 1 should be used.
 *  UVCCameraControl internaly maps that values to the min and max values that the camera settings allow.
 *  The exposure, gain, ... properties are intended to be used with Memo's ofxSimpleGuiToo addon. The cam settings are
 *  updated only when this properties are changing.
 *
 */

#ifndef _OFX_UVC_VIDEOGRABBER
#define _OFX_UVC_VIDEOGRABBER

#include "ofMain.h"

#include "ofxQTKitVideoGrabber.h"

class ofxUVCVideoGrabber : public ofxQTKitVideoGrabber {
public:
	ofxUVCVideoGrabber();
	
	void initGrabber(int w, int h);
	void update(){
		this->grabFrame();
	}
	void grabFrame();
	
	bool autoExposure;
	void setAutoExposure(bool enabled);
	bool getAutoExposure();
	
	float exposure;
	void setExposure(float value);
	float getExposure();
	float getMinExposure();
	float getMaxExposure();
	
	float gain;
	void setGain(float value);
	float getGain();
	float getMinGain();
	float getMaxGain();
	
	float brightness;
	void setBrightness(float value);
	float getBrightness();
	float getMinBrightness();
	float getMaxBrightness();
	
	float contrast;
	void setContrast(float value);
	float getContrast();
	float getMinContrast();
	float getMaxContrast();
	
	float saturation;
	void setSaturation(float value);
	float getSaturation();
	float getMinSaturation();
	float getMaxSaturation();
	
	float sharpness;
	void setSharpness(float value);
	float getSharpness();
	float getMinSharpness();
	float getMaxSharpness();
	
	bool autoWhiteBalance;
	void setAutoWhiteBalance(bool enabled);
	bool getAutoWhiteBalance();
	
	float whiteBalance;
	void setWhiteBalance(float value);
	float getWhiteBalance();
	float getMinWhiteBalance();
	float getMaxWhiteBalance();
	
	
protected:
	void *cameraControl;
	
	bool _oldAutoExposure;
	float _oldExposure;
	float _oldGain;
	float _oldBrightness;
	float _oldContrast;
	float _oldSaturation;
	float _oldSharpness;
	bool _oldAutoWhiteBalance;
	float _oldWhiteBalance;
};


#endif