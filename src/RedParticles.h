#pragma once

#include "ofMain.h"

class RedParticle {
    private:
        double x;
        double y;
        double vel;
        double acc;
        double direction;

    public:
        RedParticle(double x,double y, double speed,double acc,double angle) {
            this->x = x;
            this->y = y;
            this->acc = acc;
            this->vel = speed;
            this->direction = angle;  
        }
        RedParticle() {
            this->x = 0.0;
            this->y = ofGetHeight();
            this->acc = -10.0;
            this->vel = 0.0;
            this->direction = 45.0;
        }
        //setters
        void setX(double x) {this->x = x;}
        void setY(double y) {this->y = y;}
        void setVel(double v) {this->vel = v;}
        void setAcc(double a) {this->acc = a;}
        void setAngle(double a) {this->direction = a;}
        //getters
        double getX() {return this->x;}
        double getY() {return this->y;}
        double getVel() {return this->vel;}
        double getAcc() {return this->acc;}
        double getAngle() {return direction;}

        void tick(double t);
        void draw();
        

};
