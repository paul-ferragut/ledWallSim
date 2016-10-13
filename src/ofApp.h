#pragma once

#include "ofMain.h"
#include "ofxGui.h"

#define WALL_WIDTH 5000
#define WALL_HEIGHT 2000

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		ofxPanel gui;

		ofxToggle useCamB;
		ofEasyCam cam;

		ofxToggle showSourceB;

		ofxFloatSlider pitchLed;

		ofxButton pitch7mm;
		ofxButton pitch16mm;
		ofxButton pitch33mm;

		ofxFloatSlider ledSize;

		ofxFloatSlider ledBrightness;
		
		int  ledNumW;
		int	 ledNumH;
		int	 ledNum;

		ofVideoPlayer video;

		ofImage dot;

		ofImage silhouette;

};
