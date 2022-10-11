#include "Explosion.h"

void Explosion::draw() {
    int timer = 0;
    ofSetColor(245,0,23);
    int trans = 255;
    ofFill();
    while (timer < interval * 2) {
        if (timer < interval) {
            ofDrawCircle(x,y,30);
        }
        if (timer > interval) {
            ofSetColor(245,0,23,trans);
            trans--;
        }
    }
    this->~Explosion();
}