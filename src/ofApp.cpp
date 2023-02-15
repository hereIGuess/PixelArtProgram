#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup() {
	//set window size
	ofSetWindowShape(columns * pixelSize, rows * pixelSize);

	//set up colourSlider
	colourSlider.setup("Colour", ofColor(0, 0, 0), 0, 255, 200, 20);
}

//--------------------------------------------------------------
void ofApp::update() {
	//set pixelColour to colourSlider's value
	pixelColour = colourSlider;
}

//--------------------------------------------------------------
void ofApp::draw() {
	//loop through entire 2D vector and draw each square
	for (int y = 0; y < rows; y++) {
		for (int x = 0; x < columns; x++) {
			//set the colour the pixel should be drawn with
			ofSetColor(ofColor(pixels[y][x]));

			ofDrawRectangle(pixelSize * x, pixelSize * y, pixelSize, pixelSize);
		}
	}

	//draw colourSlider
	colourSlider.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	//if left arrow is pressed, subtract from the columns
	//if up arrow is pressed, subtract from the rows
	//if right arrow is pressed, add to the columns
	//if down arrow is pressed, add to the rows
	switch (key) {
		case 57356: {
			if (columns > 6) columns--;
			break;
		}
		case 57357: {
			if (rows > 6) rows--;
			break;
		}
		case 57358: {
			if (columns < 50) columns++;
			break;
		}
	case 57359: {
			if (rows < 50) rows++;
			break;
		}
	}

	//if any of the arrow keys OR 'c' OR 'C' is pressed, resize pixels and update window size
	if (key == 57356 || key == 57357 || key == 57358 || key == 57359 || key == 99 || key == 67) {
		pixels = std::vector<std::vector<ofColor>>(rows, std::vector<ofColor>(columns));
		ofSetWindowShape(columns * pixelSize, rows * pixelSize);
	}

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {
	//if 's' or 'S' is pressed, save the file
	if (key == 115 || key == 83) saveFile(pixels);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
	//figure out which column and row user has clicked
	int col{ x / pixelSize };
	int row{ y / pixelSize };

	//set the pixel colour to the pixelColour
	pixels[row][col] = ofColor(pixelColour);
}

void ofApp::saveFile(std::vector<std::vector<ofColor>> image) {
	//create the output file
	std::ofstream file("Output.ppm");

	if (!file.fail()) {
		//ppm header information
		file << "P1" << "\n";
		file << columns << " " << rows << "\n";

		//stream each pixel into file
		for (int y = 0; y < rows; y++) {
			for (int x = 0; x < columns; x++) {
				bool pixel = true;

				//if current pixel is white, pixel is false
				//so each coloured pixel will get printed as true
				if (image[y][x] == ofColor(255, 255, 255)) pixel = false;

				file << pixel << " ";
			}
			//after each row is done, new line
			file << "\n";
		}

		file.close();
	}
}