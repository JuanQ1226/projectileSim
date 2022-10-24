#include "ofApp.h"
#include <vector>
//--------------------------------------------------------------
void ofApp::setup(){
    //Sets up the GUI with all of its components
    gui.setup("","Parameters",ofGetWidth() - 300,40);
    gui.setFillColor(ofColor::aliceBlue);
    gui.add(ySlider.setup("Initial Height",yo,0,ofGetHeight() - 20));
    gui.add(xSlider.setup("Initial Width",xo,0,ofGetWidth()));
    gui.add(aSlider.setup("Angle",angle,0,360));
    gui.add(vSlider.setup("Initial Velocity",vo,0,200));
    gui.add(Start.setup("Start"));
    gui.add(Reset.setup("Reset"));
    gui.add(MaxH.setup("Get Max Height"));
    ///Sets Framerate to 165 FPS Note: This affects how fast the calculations are made
    FPS = 165;
    ofSetFrameRate(FPS);
    RedParticle p(xo,yo,vo,a,angle);
    particles.push_back(p);
    
}

//--------------------------------------------------------------
void ofApp::update(){
    // updates the particles values when using the sliders
    if(!started) {
        particles[0].setX(xSlider);
        particles[0].setY(ySlider);
        particles[0].setAngle(aSlider);
        particles[0].setVel(vSlider);
    }
    if(MaxH) {
        showMH = !showMH;
    }
    //When the start button is pressed the simulation starts
    if(Start) {
        started = true;
    }
    
    if (started) {
        //Calculates the seconds for the particles movement
        ticks += 1;
        seconds = ticks / 165;
        particles[0].tick(seconds);
        //Adds the points that the particle has been to the trail
        ofPoint p(particles[0].getX(),particles[0].getY());
        trail.addVertex(p);
        
    }
    //Reset button is pressed
    if(Reset) {
        keyPressed('r');
    }
}




//--------------------------------------------------------------
void ofApp::draw(){
    //Sets Background 
    ofColor sky(138,213,255);
    ofColor atm(211,239,255);
    ofBackgroundGradient(atm,sky,OF_GRADIENT_LINEAR);
    //Axis Arrows
    ofSetColor(0);
    ofFill();
    ofVec3f y2(10,10,0);
    ofVec3f y1(10,ofGetHeight() - 40,0);
    ofDrawBitmapString("y",20,ofGetHeight() - 50);
    ofDrawBitmapString("x",ofGetWidth() - 50, ofGetHeight() - 50);
    ofDrawArrow(y1,y2,6);
    ofVec3f x1(10,ofGetHeight() - 40,0);
    ofVec3f x2(ofGetWidth() - 10,ofGetHeight() - 40,0);
    ofDrawArrow(x1,x2,6);
    //Draws the particle
    particles[0].draw();
    //Draws the indicator text on the window
    ofSetColor(255,0,0);
    ofDrawBitmapString("x: "+to_string((int)particles[0].getX()),20,40);
    ofDrawBitmapString("y: "+to_string(ofGetHeight() - (int)particles[0].getY()),20,50);
    ofDrawBitmapString("vel: "+to_string((int)particles[0].getVel()),20,60);
    //Draws the ground
    ofSetColor(51,25,0);
    ofFill();
    ofDrawRectangle(0,ofGetHeight()-20,ofGetWidth(),20);
    //Calculates the points of the arrow and draws it
    ofSetColor(0);
    ofFill();
    if(!started) {
        ofVec3f p1(particles[0].getX(),particles[0].getY(),0);
        ofVec3f p2(particles[0].getX() + particles[0].getVel()*cos(particles[0].getAngle()*PI/180),particles[0].getY() - particles[0].getVel()*sin(particles[0].getAngle()*PI/180),0);
        ofDrawArrow(p1,p2,4);
    }
    //Draws the trail left by the particle
    ofSetColor(ofColor::navy);
    if(started) {
        trail.draw();
    }
    if(showMH) {
        ofSetColor(ofColor::red);
        ofDrawBitmapString("Max Height: " + to_string(particles[0].maxHeight()),20,70);
    }
    //Draws the GUI
    gui.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
   switch (key)
   {
   case 'r':
   //What happens when you Reset
    seconds = 0;
    ticks = 0;
    started = false;
    showMH = 0;
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
    //Changes the sliders and hence the particle, when left clicking and Draging
   if(button == 0) { //0 == LeftClick, 1 == middleClick, 2 == rightClick
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