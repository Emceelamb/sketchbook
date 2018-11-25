#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
float pNs=0.0;
void ofApp::update(){
    for(auto &vert :  line.getVertices()){
        float nsx= ofMap(ofNoise(pNs*vert.x),0.0,1.0,-1,1);
        float nsy= ofMap(ofNoise(pNs*vert.y),0.0,1.0,-1,1);

        vert.x += nsx;
        vert.y += nsy;
    }
    pNs+=0.01;
//    std::cout << ns;
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(230);
    ofSetColor(30);

    line.draw();

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
    ofPoint pt;
    pt.set(x,y);
    line.addVertex(pt);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    line.clear();
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

