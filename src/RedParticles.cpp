#include "RedParticles.h"


void RedParticle::tick(double t) {
    vx = vel*cos(direction*PI/180);
    vy = vel*sin(direction*PI/180);
    if (x <= ofGetWidth() - 10) {
        this->x  = x + vx * t; 
    }
    if(y <= ofGetHeight() - 20 && y > 0) {
        this->y = y - (vy*t) - ((0.5)* (acc * pow(t,2)));
    }
    
}

void RedParticle::draw() {
    ofColor red(255,0,0);
    ofSetColor(red);
    ofDrawCircle(x,y,5);
}

int RedParticle::maxHeight() {
    int max =  pow(vel*sin(direction*PI/180),2) / (2*acc);
    return yo + max;
}