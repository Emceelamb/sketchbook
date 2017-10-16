#pragma once

#include "ofMain.h"
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
	
		ofVideoGrabber vid;

		unsigned char ** vidData;
		int numFrames;
		int maxFrames;
		int nRec;
		int imgW, imgH, imgCol; 
		ofTexture tex;

		struct Portion ** strPortions;
		int maxPortions;

		int pW, pH, pMod;
		int nPo;
		int zoom;
		int testx;

		ofxPanel gui;
		ofxIntSlider portions;
};
