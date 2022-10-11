#include "RedParticles.h"


void RedParticle::tick(double t) {
    int vx = vel*cos(direction*PI/180);
    int vy = vel*sin(direction*PI/180);
    if (x <= ofGetWidth() - 10 && y <= ofGetHeight() - 20) {
        this->x  = x + vx * t; 
    }
    if(y <= ofGetHeight() - 20) {
        this->y = y - (vy*t) - ((0.5)* (acc * pow(t,2)));
    }
    
}

void RedParticle::draw() {
    ofColor red(255,0,0);
    ofSetColor(red);
    ofDrawCircle(x,y,5);
}