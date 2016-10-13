#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	gui.setup();

	gui.add(useCamB.setup("3d view", false));
	gui.add(showSourceB.setup("show source movie", false));

	gui.add(pitchLed.setup("pitch led mm", 33.0 ,3.5,60.0));
	gui.add(ledSize.setup("led size mm", 4.5, 2, 26.0));
	//gui.add(ledBrightness.setup("led brightness", 2.0, 0.1, 10.0));



	gui.add(pitch7mm.setup("pitch 7 mm", false));
	gui.add(pitch16mm.setup("pitch 16 mm", false));
	gui.add(pitch33mm.setup("pitch 33 mm", false));

	gui.setPosition(20, 80);



	video.load("video.mp4");
	video.setLoopState(OF_LOOP_NORMAL);
	video.play();

	dot.load("dot.png");
	silhouette.load("silhouette.png");
}

//--------------------------------------------------------------
void ofApp::update(){
	video.update();


	if (pitch7mm) {
		pitchLed = 7;
	}
	if (pitch16mm) {
		pitchLed = 16;
	}
	if (pitch33mm) {
		pitchLed = 33;
	}


}

//--------------------------------------------------------------
void ofApp::draw(){

	ofBackgroundGradient(ofColor(60, 60, 60), ofColor(10, 10, 20), OF_GRADIENT_LINEAR);

	ofSetColor(255, 255, 255, 255);

	if(showSourceB)
	video.draw(0, 0);


	ofSetHexColor(0x000000);
	ofPixels & pixels = video.getPixels();

	int vidWidth = pixels.getWidth();
	int vidHeight = pixels.getHeight();
	int nChannels = pixels.getNumChannels();

	// let's move through the "RGB(A)" char array
	ofEnableAlphaBlending();

	if (useCamB) { cam.begin(); 
	ofEnableDepthTest();

	}
	else {
		ofPushMatrix();
		ofTranslate(40, 40);
		ofScale(0.35, 0.35);
	}

	ofSetColor(0, 0, 0);
	int extraEdge = WALL_HEIGHT*0.04;
	int bottomEdge = extraEdge * 4;
	ofDrawBox((WALL_WIDTH/2), ((WALL_HEIGHT+ bottomEdge) / 2), -20, WALL_WIDTH + (extraEdge * 2), WALL_HEIGHT + (extraEdge * 2) + bottomEdge, 10);


	for (int i = 0; i < WALL_WIDTH; i += pitchLed ) {
		for (int j = 0; j < WALL_HEIGHT; j += pitchLed ) {


			int nI = ofMap(i, 0, WALL_WIDTH, 0, vidWidth);
			int nJ = ofMap(j, 0, WALL_HEIGHT, 0, vidHeight);

			unsigned char r = pixels[(nJ * vidWidth + nI)*nChannels];
			unsigned char g = pixels[((nJ * vidWidth + nI)*nChannels)+1];
			unsigned char b = pixels[((nJ * vidWidth + nI)*nChannels)+2];
			//float val = 1 - ((float)r / 255.0f);

			//float posX=ofMap(i, 0, vidWidth, 0, WALL_WIDTH);
			//float posY = ofMap(j, 0, vidHeight, 0, WALL_HEIGHT);

			ofSetColor((float)r, (float)g, (float)b);
			float dotSize = ledSize * 10;
			dot.setAnchorPoint(dotSize/2, dotSize/2);
			dot.draw(i, j, dotSize, dotSize);
			ofDrawSphere(i, j, ledSize/2, ledSize);
		
		
		}
	}

	ledNumW = WALL_WIDTH/ pitchLed;
	ledNumH = WALL_HEIGHT / pitchLed;

	ofSetColor(255, 255, 255, 255);

	silhouette.setAnchorPoint(0, silhouette.getHeight());

	if (useCamB) {
		ofPushMatrix();
		ofTranslate(0,  silhouette.getHeight()*2);
		ofScale(1, -1,1);
	}

	silhouette.draw(400, WALL_HEIGHT+ bottomEdge,100);
	if (useCamB) {
		ofPopMatrix();
	}

	if (useCamB) { ofDisableDepthTest(); cam.end(); }
	else {
		ofPopMatrix();
	}



	gui.draw();
	ofDrawBitmapStringHighlight("LED number width:" + ofToString(ledNumW), gui.getPosition().x, gui.getPosition().y-60);
	ofDrawBitmapStringHighlight("LED number height:" + ofToString(ledNumH), gui.getPosition().x, gui.getPosition().y - 40);
	ofDrawBitmapStringHighlight("LED number total:" + ofToString(ledNumW*ledNumH), gui.getPosition().x, gui.getPosition().y - 20);
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
