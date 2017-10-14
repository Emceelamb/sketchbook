#include "SoundClass.h"



void SoundClass::setup() {
	song.load("heart.mp3");
	song.setVolume(0.3);
	song.setLoop(true);
}

void SoundClass::keyPressed(int key) {

	switch (key) {
		case ' ':
			song.play();
		break;
		case OF_KEY_LEFT:
			song.setSpeed(-1);
		break;
		case OF_KEY_RIGHT:
			song.setSpeed(1.0);
		break;

	}
}

