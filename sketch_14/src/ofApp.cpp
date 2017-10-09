#include "ofApp.h"

int rad;
//--------------------------------------------------------------
void ofApp::setup(){
	cout << "this is running";
	cout << " now this is running" << endl;
	rad = 0;

}

//--------------------------------------------------------------
void ofApp::update(){
	rad= rad+ 10;
}

//--------------------------------------------------------------
void ofApp::draw(){
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {

			ofDrawEllipse(ofGetViewportWidth()/4*i+rad/2, ofGetViewportHeight()/4*j+rad/2, rad, rad);
		}
	}
	if (rad > ofGetViewportWidth()/4) {
		rad = 0;
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
