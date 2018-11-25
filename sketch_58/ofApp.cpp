#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
float pNs=0.0;
void ofApp::update(){
//    for(auto &vert :  line.getVertices()){
//        float nsx= ofMap(ofNoise(pNs*vert.x),0.0,1.0,-1,1);
//        float nsy= ofMap(ofNoise(pNs*vert.y),0.0,1.0,-1,1);

//        vert.x += nsx;
//        vert.y += nsy;
//    }
//    pNs+=0.01;
//    std::cout << ns;
    for(auto &line : lines){
        float nsx= ofMap(ofNoise(pNs*line.a),0.0,1.0,-1,1);
        float nsy= ofMap(ofNoise(pNs*line.b),0.0,1.0,-1,1);
        line.a += nsx;
        line.b += nsy;

    }
        pNs+=0.0001;

}

//--------------------------------------------------------------
void ofApp::draw(){
   ofEnableAlphaBlending();
    ofBackground(230);
    ofSetColor(30,30,30,30);

    for (auto line : lines){
        ofDrawLine(line.a, line.b);
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
    for(auto point : drawnPoints){
        ofPoint mouse;
        mouse.set(x,y);
        float dist = (mouse - point).length();
        if(dist < 50){
            Line lineTemp;
            lineTemp.a = mouse;
            lineTemp.b = point;
            lines.push_back(lineTemp);
        }
    }
    drawnPoints.push_back(ofPoint(x,y));
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

