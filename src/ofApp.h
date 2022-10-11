#pragma once

#include "ofMain.h"
#include "RedParticles.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		ofxButton Start;
		ofxPanel gui;
		ofxIntSlider ySlider;
		ofxIntSlider xSlider;
		ofxIntSlider aSlider;
		ofxIntSlider vSlider;
		ofxButton Reset;
		double seconds = 0;
		double ticks = 0;
		vector<RedParticle> particles;
		double vo = 10;
		double a = -9.81;
		double xo = 145;
		double yo = 370;
		double angle = 30.0;
		bool started = false;
		ofPolyline trail;  
};

