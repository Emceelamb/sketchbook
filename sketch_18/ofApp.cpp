#include "ofApp.h"

//--- portions
struct Portion{
	int id;
	int x;
	int y;
	int w;
	int h;
	int sz;

	unsigned char * pixels;
	ofTexture tx;
};

//--------------------------------------------------------------
void ofApp::setup(){
	gui.setup();
	testx = 0;
	imgW = 640;
	imgH = 480;
	imgCol = 3;

	nRec = 0;
	numFrames = 80;
	maxFrames = 1000;
	maxPortions = imgH;
	
	nPo = 2;
	gui.add(portions.setup("int slider", 20, 0, 30));


	vidData = new unsigned char *[maxFrames];

	for (int i = 0; i < maxFrames; i++) {
		vidData[i] = new unsigned char[imgW*imgH*imgCol];
	}

	strPortions = new Portion *[maxPortions];

	for (int i = 0; i < maxPortions; i++) {
		strPortions[i] = new Portion;
		strPortions[i]->id = i;
		strPortions[i]->w = imgW;
		strPortions[i]->pixels = new unsigned char[imgW* (imgH/2)* imgCol];
		strPortions[i]->tx.allocate(imgW, imgH, GL_RGB);
	}


	vid.setup(imgW, imgH);
	tex.allocate(imgW, imgH, GL_RGB);
}

//--------------------------------------------------------------
void ofApp::update(){
	testx++;
	vid.update();
	if (vid.isFrameNew()) {
		tex.loadData(vid.getPixels());
	}
	memcpy(vidData[nRec], vid.getPixels().getData(), imgW*imgH*imgCol);
	pW = imgW;
	/*pH = imgH / nPo;
	pMod = imgH % nPo;*/

	pH = imgH / portions;
	pMod = imgH % portions;

	// buff
	int tempY = imgH;
	int posIm = imgW * imgH * imgCol;
	int tempSz, tempH;
/*
	int frameDiff = numFrames - (numFrames / nPo);
	for (int i = 0; i < nPo; i++) {*/

	int frameDiff = numFrames - (numFrames / portions);
	for (int i = 0; i < portions; i++) {
		tempH = pH;
		if (pMod > 0) {
			tempH++;
			pMod--;
		}
		tempSz = pW * tempH * imgCol;
		tempY -= tempH;
		posIm -= tempSz;

		strPortions[i]->h = tempH;
		strPortions[i]->sz = tempSz;
		strPortions[i]->y = tempY;

		int portionFrame = (nRec + (frameDiff* i)) % numFrames;

		memcpy(strPortions[i]->pixels, vidData[portionFrame] + (posIm), tempSz);
		strPortions[i]->tx.loadData(strPortions[i]->pixels, strPortions[i] -> w, strPortions[i]->h, GL_RGB);
	}
	nRec++;
	nRec %= numFrames;


}

//--------------------------------------------------------------
void ofApp::draw(){
	//vid.draw(0, 0);
	//tex.draw(ofGetMouseX(), ofGetMouseY());
	ofBackground(33);
	for (int i = portions; i >= 0; i--) {
		//strPortions[i]->tx.draw(340,30*nPo+ nPo*-30+(strPortions[0]->h / 2) + strPortions[i]->y, pW, strPortions[i]->h*nPo);
		strPortions[i]->tx.draw(340, 30 * portions + portions*-30 + (strPortions[0]->h / 2) + strPortions[i]->y, pW, strPortions[i]->h*portions);
	}
	gui.draw();
	//strPortions[1]->tx.draw(340, 10 + strPortions[1]->y, pW, strPortions[1]->h*nPo);
	//strPortions[0]->tx.draw(340, -110 + strPortions[0]->y+(strPortions[0]->h/2), pW, strPortions[0]->h*nPo);


}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
