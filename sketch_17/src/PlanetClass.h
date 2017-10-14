#include "ofMain.h"

class PlanetClass {
public:
	void setup();
	void update();
	void draw();

	ofParameterGroup planets;
	ofParameter<float> rotateSpeed;
	ofParameter<float> posX;
	ofParameter<float> posY;
	ofParameter<int> red;
	ofParameter<int> grn;
	ofParameter<int> blu;
	float rotation = 0.0;
};