#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofBackground(39);
	ofSetWindowTitle("Insta");

	ofSetLineWidth(1.5);
	ofEnableBlendMode(ofBlendMode::OF_BLENDMODE_ADD);
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);

	int radius = 150;
	int deg_span = 10;
	ofColor line_color;
	for (int deg = 0; deg < 360; deg += deg_span) {

		ofPoint start = ofPoint(radius * cos(deg * DEG_TO_RAD), radius * sin(deg * DEG_TO_RAD));
		ofPoint end = ofPoint(radius * cos((deg + deg_span) * DEG_TO_RAD), radius * sin((deg + deg_span) * DEG_TO_RAD));
		ofPoint gap = end - start;

		ofPoint line_start = end + gap * 100;
		ofPoint line_end = start - gap * 100;

		line_color.setHsb(((int)ofMap(deg, 0, 360, 0, 255) + ofGetFrameNum()) % 255, 255, 255);
		ofSetColor(line_color);

		ofDrawLine(line_start, line_end);
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}