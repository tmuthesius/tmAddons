/*
 *  ofxUVCVideoGrabber.cpp
 *
 *  Created by Tobias Muthesius on 31/12/10.
 *  Copyright 2010. All rights reserved.
 *  http://tobiasmuthesius.net
 *
 */

#include "ofxUVCVideoGrabber.h"
#include "UVCCameraControl.h"
#import <QTKit/QTKit.h>

ofxUVCVideoGrabber::ofxUVCVideoGrabber(){
	autoExposure = _oldAutoExposure =
	exposure = _oldExposure =
	gain = _oldGain =
	brightness = _oldBrightness =
	contrast = _oldContrast =
	saturation = _oldSaturation =
	sharpness = _oldSharpness =
	autoWhiteBalance = _oldAutoWhiteBalance =
	whiteBalance = _oldWhiteBalance = 0;
}


void ofxUVCVideoGrabber::initGrabber(int w, int h){
	ofxQTKitVideoGrabber::initGrabber(w, h);
	
	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
	
	NSArray* videoDevices = [[QTCaptureDevice inputDevicesWithMediaType:QTMediaTypeVideo] 
							 arrayByAddingObjectsFromArray:[QTCaptureDevice inputDevicesWithMediaType:QTMediaTypeMuxed]];
	
	int i = deviceID;
	if(i >= videoDevices.count) i = videoDevices.count -1;
	QTCaptureDevice *videoDevice = [videoDevices objectAtIndex:i];
	
	unsigned int locationID = 0;
	sscanf( [[videoDevice uniqueID] UTF8String], "0x%8x", &locationID );
	cameraControl = [[UVCCameraControl alloc] initWithLocationID:(UInt32)locationID];
	
	
	[(UVCCameraControl*)cameraControl setAutoExposure:NO];
	[(UVCCameraControl*)cameraControl setExposure:100];
	[(UVCCameraControl*)cameraControl setAutoWhiteBalance:YES];
	
	[pool release];
}


void ofxUVCVideoGrabber::grabFrame(){
	ofxQTKitVideoGrabber::update();
	
	if(autoExposure != _oldAutoExposure){
		setAutoExposure(autoExposure);
	}
	if(exposure != _oldExposure){
		setExposure(exposure);
	}
	if(gain != _oldGain){
		setGain(gain);
	}
	if(brightness != _oldBrightness){
		setBrightness(brightness);
	}
	if(contrast != _oldContrast){
		setContrast(contrast);
	}
	if(saturation != _oldSaturation){
		setSaturation(saturation);
	}
	if(sharpness != _oldSharpness){
		setSharpness(sharpness);
	}
	if(autoWhiteBalance != _oldAutoWhiteBalance){
		setAutoWhiteBalance(autoWhiteBalance);
	}
	if(whiteBalance != _oldWhiteBalance){
		setWhiteBalance(whiteBalance);
	}
}




void ofxUVCVideoGrabber::setAutoExposure(bool enabled){
	_oldAutoExposure = autoExposure = enabled;
	[(UVCCameraControl*)cameraControl setAutoExposure:enabled];
}
bool ofxUVCVideoGrabber::getAutoExposure(){
	return [(UVCCameraControl*)cameraControl getAutoExposure];
}





void ofxUVCVideoGrabber::setExposure(float value){
	_oldExposure = exposure = value;
	[(UVCCameraControl*)cameraControl setExposure:value];
}
float ofxUVCVideoGrabber::getExposure(){
	return [(UVCCameraControl*)cameraControl getExposure];
}
float ofxUVCVideoGrabber::getMinExposure(){
	return [(UVCCameraControl*)cameraControl getRangeForControl:&uvc_controls.exposure].min;
}
float ofxUVCVideoGrabber::getMaxExposure(){
	return [(UVCCameraControl*)cameraControl getRangeForControl:&uvc_controls.exposure].max;
}





void ofxUVCVideoGrabber::setGain(float value){
	_oldGain = gain = value;
	[(UVCCameraControl*)cameraControl setGain:value];
}
float ofxUVCVideoGrabber::getGain(){
	return [(UVCCameraControl*)cameraControl getGain];
}
float ofxUVCVideoGrabber::getMinGain(){
	return [(UVCCameraControl*)cameraControl getRangeForControl:&uvc_controls.gain].min;
}
float ofxUVCVideoGrabber::getMaxGain(){
	return [(UVCCameraControl*)cameraControl getRangeForControl:&uvc_controls.gain].max;
}





void ofxUVCVideoGrabber::setBrightness(float value){
	_oldBrightness = brightness = value;
	[(UVCCameraControl*)cameraControl setBrightness:value];
}
float ofxUVCVideoGrabber::getBrightness(){
	return [(UVCCameraControl*)cameraControl getBrightness];
}
float ofxUVCVideoGrabber::getMinBrightness(){
	return [(UVCCameraControl*)cameraControl getRangeForControl:&uvc_controls.brightness].min;
}
float ofxUVCVideoGrabber::getMaxBrightness(){
	return [(UVCCameraControl*)cameraControl getRangeForControl:&uvc_controls.brightness].max;
}






void ofxUVCVideoGrabber::setContrast(float value){
	_oldContrast = contrast = value;
	[(UVCCameraControl*)cameraControl setContrast:value];
}
float ofxUVCVideoGrabber::getContrast(){
	return [(UVCCameraControl*)cameraControl getContrast];
}
float ofxUVCVideoGrabber::getMinContrast(){
	return [(UVCCameraControl*)cameraControl getRangeForControl:&uvc_controls.contrast].min;
}
float ofxUVCVideoGrabber::getMaxContrast(){
	return [(UVCCameraControl*)cameraControl getRangeForControl:&uvc_controls.contrast].max;
}






void ofxUVCVideoGrabber::setSaturation(float value){
	_oldSaturation = saturation = value;
	[(UVCCameraControl*)cameraControl setSaturation:value];
}
float ofxUVCVideoGrabber::getSaturation(){
	return [(UVCCameraControl*)cameraControl getSaturation];
}
float ofxUVCVideoGrabber::getMinSaturation(){
	return [(UVCCameraControl*)cameraControl getRangeForControl:&uvc_controls.saturation].min;
}
float ofxUVCVideoGrabber::getMaxSaturation(){
	return [(UVCCameraControl*)cameraControl getRangeForControl:&uvc_controls.saturation].max;
}






void ofxUVCVideoGrabber::setSharpness(float value){
	_oldSharpness = sharpness = value;
	[(UVCCameraControl*)cameraControl setSharpness:value];
}
float ofxUVCVideoGrabber::getSharpness(){
	return [(UVCCameraControl*)cameraControl getSharpness];
}
float ofxUVCVideoGrabber::getMinSharpness(){
	return [(UVCCameraControl*)cameraControl getRangeForControl:&uvc_controls.sharpness].min;
}
float ofxUVCVideoGrabber::getMaxSharpness(){
	return [(UVCCameraControl*)cameraControl getRangeForControl:&uvc_controls.sharpness].max;
}





void ofxUVCVideoGrabber::setAutoWhiteBalance(bool enabled){
	_oldAutoWhiteBalance = autoWhiteBalance = enabled;
	[(UVCCameraControl*)cameraControl setAutoWhiteBalance:enabled];
}
bool ofxUVCVideoGrabber::getAutoWhiteBalance(){
	return [(UVCCameraControl*)cameraControl getAutoWhiteBalance];
}





void ofxUVCVideoGrabber::setWhiteBalance(float value){
	_oldWhiteBalance = whiteBalance = value;
	[(UVCCameraControl*)cameraControl setWhiteBalance:value];
}
float ofxUVCVideoGrabber::getWhiteBalance(){
	return [(UVCCameraControl*)cameraControl getWhiteBalance];
}
float ofxUVCVideoGrabber::getMinWhiteBalance(){
	return [(UVCCameraControl*)cameraControl getRangeForControl:&uvc_controls.whiteBalance].min;
}
float ofxUVCVideoGrabber::getMaxWhiteBalance(){
	return [(UVCCameraControl*)cameraControl getRangeForControl:&uvc_controls.whiteBalance].max;
}


