#include "ofApp.h"

int rad;
int timer;
//--------------------------------------------------------------
void ofApp::setup(){
	cout << "this is running";
	cout << " now this is running" << endl;
	rad = 0;

	ofSetVerticalSync(true);
	ofSetLogLevel(OF_LOG_NOTICE);

	box2d.init();
	box2d.setGravity(0, 10);
	box2d.createBounds();
	box2d.setFPS(60.0);
	
	timer = 0;
}

//--------------------------------------------------------------
void ofApp::update(){
	//rad= rad+ 10;
	box2d.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
	
	timer++;
	if (timer % 4 == 0) {

	if (circles.size() < 100) {
		float r = ofRandom(25, 50);
		circles.push_back(shared_ptr<ofxBox2dCircle>(new ofxBox2dCircle));
		circles.back().get()->setPhysics(3.0, 0.53, 0.1);
		circles.back().get()->setup(box2d.getWorld(), ofRandomWidth(), 0, r);
	}
	}

	for (int i = 0; i < circles.size(); i++) {
		ofFill();
		circles[i].get()->draw();
	}
	box2d.drawGround();

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
