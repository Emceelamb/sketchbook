#pragma once

#include "ofMain.h"
#include "ImageClass.h"
#include "SoundClass.h"
#include "VideoClass.h"

#include "ofxGui.h"
class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

	ImageClass img;
	SoundClass sound;
	VideoClass video;

	ofxPanel gui;

	ofxIntSlider intSlider;
	ofxFloatSlider floatSlider;
	ofxToggle toggle;
	ofxButton button;

	ofxIntSlider posX;
	ofxIntSlider posY;
};
