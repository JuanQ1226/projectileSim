#include "ofApp.h"
#include <vector>
//--------------------------------------------------------------
void ofApp::setup(){
    gui.setup();
    gui.add(ySlider.setup("Initial Height",yo,0,ofGetHeight() - 20));
    gui.add(xSlider.setup("Initial Width",xo,0,ofGetWidth()));
    gui.add(aSlider.setup("Angle",angle,0,360));
    gui.add(vSlider.setup("Initial Velocity",vo,0,200));
    gui.add(Start.setup("Start"));
    gui.add(Reset.setup("Reset"));
    ofSetFrameRate(165);
    RedParticle p(xo,yo,vo,a,angle);
    particles.push_back(p);
    
}

//--------------------------------------------------------------
void ofApp::update(){
    if(!started) {
        particles[0].setX(xSlider);
        particles[0].setY(ySlider);
        particles[0].setAngle(aSlider);
        particles[0].setVel(vSlider);
    }

    if(Start) {
        started = true;
    }

    if (started) {
        ticks += 1;
        seconds = ticks / 165;
        particles[0].tick(seconds);
        ofPoint p(particles[0].getX(),particles[0].getY());
        trail.addVertex(p);
        
    }

    if(Reset) {
        keyPressed('r');
    }
}




//--------------------------------------------------------------
void ofApp::draw(){
    ofColor sky(138,213,255);
    ofColor atm(211,239,255);
    ofBackgroundGradient(atm,sky,OF_GRADIENT_LINEAR);
    particles[0].draw();
    ofSetColor(255,0,0);
    ofDrawBitmapString("x: "+to_string((int)particles[0].getX()),20,40);
    ofDrawBitmapString("y: "+to_string((int)particles[0].getY()),20,50);
    ofDrawBitmapString("vel: "+to_string((int)particles[0].getVel()),20,60);
    ofSetColor(51,25,0);
    ofFill();
    ofDrawRectangle(0,ofGetHeight()-20,ofGetWidth(),20);
    ofSetColor(0);
    ofFill();
    if(!started) {
        ofVec3f p1(particles[0].getX(),particles[0].getY(),0);
        ofVec3f p2(particles[0].getX() + particles[0].getVel()*cos(particles[0].getAngle()*PI/180),particles[0].getY() - particles[0].getVel()*sin(particles[0].getAngle()*PI/180),0);
        ofDrawArrow(p1,p2,4);
    }
    ofSetColor(ofColor::navy);
    if(started) {
        trail.draw();
    }
    gui.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
   switch (key)
   {
   case 'r':
    seconds = 0;
    ticks = 0;
    started = false;
    trail.clear();
    break;
   
   default:
    break;
   }

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
   if(button == 0) {
    ySlider = y;
    xSlider = x;
   } 
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