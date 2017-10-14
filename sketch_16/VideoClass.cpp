#include "VideoClass.h"

void VideoClass::setup() {
	video.load("video.mp4");
}

void VideoClass::update() {
	video.update();
}

void VideoClass::draw() {
	video.draw(100, 100, 400, 400);
}

void VideoClass::keyPressed(int key) {
	switch (key) {
	case OF_KEY_TAB:
		video.play();
	break;
	case OF_KEY_DOWN:
		video.previousFrame();
	break;
	case OF_KEY_UP:
		video.nextFrame();
	break;

	case 'a':
		video.stop();
	break;
		
	}
}