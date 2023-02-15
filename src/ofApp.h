#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include <vector>

class ofApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mousePressed(int x, int y, int button);

		void saveBWFile(std::vector<std::vector<ofColor>> image);
		void saveColourFile(std::vector<std::vector<ofColor>> image);
		void saveFiles(std::vector<std::vector<ofColor>> image);

		void loadBWFile();

		ofxColorSlider colourSlider;

		int rows{ 15 };
		int columns{ 15 };
		const int& pixelSize{ 25 };
		ofColor pixelColour = ofColor{ 0, 0, 0};
		std::vector<std::vector<ofColor>> pixels = std::vector<std::vector<ofColor>>(rows, std::vector<ofColor>(columns));
};
