#include "ImageClass.h"

void ImageClass::setup() {
	img.load("heart.png");
}

void ImageClass::draw(int posX, int posY) {
	img.draw(posX, posY);
}