#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	gui.setup();
	gui.add(intSlider.setup("int slider", 0, 400, 400));
	gui.add(floatSlider.setup("float slider", 33.33, 0.0, 66.66));
	gui.add(toggle.setup("toggle" ));
	gui.add(button.setup("button"));
	
	gui.add(posX.setup("Pos X", ofGetWidth() / 2, 0, ofGetWidth()));
	gui.add(posY.setup("Pos Y", ofGetHeight() / 2, 0, ofGetHeight()));



	img.setup();
	sound.setup();
	video.setup();

	
}

//--------------------------------------------------------------
void ofApp::update(){
	video.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
	img.draw(posX,posY);
	video.draw();
	gui.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	sound.keyPressed(key);
	video.keyPressed(key);
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
