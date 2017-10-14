#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	plan1.setup();
	plan2.setup();

	planets.add(plan1.planets);
	planets.add(plan2.planets);
	gui.setup(planets);
}

//--------------------------------------------------------------
void ofApp::update(){

	plan1.update();
	plan2.update();

}

//--------------------------------------------------------------
void ofApp::draw(){

	gui.draw();
	ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
	plan1.draw();
	ofTranslate(plan1.posX, plan1.posY);
	plan2.draw();
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
