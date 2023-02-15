#pragma once

#include "ofMain.h"
#include <vector>

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mousePressed(int x, int y, int button);

		void saveFile(std::vector<std::vector<bool>> image);

		int rows{ 15 };
		int columns{ 15 };
		const int& pixelSize{ 20 };
		std::vector<std::vector<bool>> pixels = std::vector<std::vector<bool>>(rows, std::vector <bool>(columns));
};
