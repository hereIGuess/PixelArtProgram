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
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		void saveFile(std::vector<std::vector<bool>> image);

		int rows{ 15 };
		int columns{ 15 };
		const int& pixelSize{ 20 };
		std::vector<std::vector<bool>> pixels = std::vector<std::vector<bool>>(rows, std::vector <bool>(columns));
};
