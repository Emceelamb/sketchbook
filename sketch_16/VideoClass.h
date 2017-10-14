#pragma once
#include "ofMain.h"

class VideoClass {
public:
	void setup();
	void update();
	void draw();
	void keyPressed(int key);

	ofVideoPlayer video;
	
};

