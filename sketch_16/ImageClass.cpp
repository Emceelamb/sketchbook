#include "ImageClass.h"

void ImageClass::setup() {
	img.load("heart.png");
}

void ImageClass::draw() {
	img.draw(20, 20);
}