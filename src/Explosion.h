#pragma once

#include "ofMain.h"

class Explosion {
    private:
        ofColor color;
        double interval;
        double x;
        double y;


    public:
        Explosion(ofColor c, double i,double x,double y) {
            this->interval = i;
            this->color = c;
            this->x = x;
            this->y = y;
        }
        Explosion() {
            this->color = ofColor(255,0,0);
            this->interval = 10;
        }
        ~Explosion() {delete this;}
        //getters
        ofColor getColor() {return color;}
        double getIntensity() {return interval;}
        //setters
        void setColor(ofColor c) {this->color = c;}
        void setIntensity(double d) {this->interval = d;}

        void draw();
};
