#include "PlanetClass.h"

void PlanetClass::setup() {
	planets.add(rotateSpeed.set("speed", 1.0,0.0, 9.0));
	planets.add(posX.set("X", 0 ,0 ,600));
	planets.add(posY.set("Y", 0, 0, 600));

	planets.add(red.set("red", 255, 0, 255));
	planets.add(grn.set("gren", 255, 0, 255));
	planets.add(blu.set("blue", 255, 0, 255));
}

void PlanetClass::update() {
	rotation++;
}

void PlanetClass::draw() {
	ofSetColor(red, grn, blu);
	ofRotateDeg(rotation * rotateSpeed);
	ofDrawCircle(posX, posY, 30);
}