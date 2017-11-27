#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofEnableDepthTest();
	ofSetVerticalSync(true);
	cam.setDistance(160);
	cam.setTarget(ofVec3f(30 * 10, 30 * 10, 30 * 10));
}

//--------------------------------------------------------------
void ofApp::update(){

}

float inc = 0.1;
float sz = 12;

//--------------------------------------------------------------
void ofApp::draw(){
	cam.begin();
	ofSetColor(33, 0, 90);
	ofFill();
	for (int x = 0; x < 20; x++) {
		for (int y = 0; y < 20; y++) {
			for (int z = 0; z < 20; z++) {
				ofDrawBox(x * 30, y * 30, z*30, sz);

			}

		}
	}
	cam.end();
	cout << sz << endl;
	sz+=inc;
	if (sz < 7 || sz>15) {
		inc*=-1;
		
	}
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
