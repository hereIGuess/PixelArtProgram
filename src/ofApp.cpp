#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup() {
	//set up colourSlider
	colourSlider.setup("Colour", ofColor(0, 0, 0), 0, 255, 200, 20);
}

//--------------------------------------------------------------
void ofApp::update() {
	//resize window
	ofSetWindowShape(columns * pixelSize, rows * pixelSize);

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
	if (key == 57356 || key == 57357 || key == 57358 || key == 57359 || key == 99 || key == 67)
		pixels = std::vector<std::vector<ofColor>>(rows, std::vector<ofColor>(columns));

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {
	//if 's' or 'S' is pressed, save the file
	if (key == 115 || key == 83) saveFiles(pixels);

	//std::cout << key;
	if (key == 108) loadBWFile();
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
	//figure out which column and row user has clicked
	int col{ x / pixelSize };
	int row{ y / pixelSize };

	//set the pixel colour to the pixelColour
	pixels[row][col] = ofColor(pixelColour);
}

void ofApp::saveBWFile(std::vector<std::vector<ofColor>> image) {
	//create the output file
	std::ofstream BWFile("BWOutput.ppm");

	if (!BWFile.fail()) {
		//ppm header information
		BWFile << "P1" << "\n";
		BWFile << columns << " " << rows << "\n";

		//stream each pixel into file
		for (int y = 0; y < rows; y++) {
			for (int x = 0; x < columns; x++) {
				bool pixel = true;

				//if current pixel is white, pixel is false
				//so each coloured pixel will get printed as true
				if (image[y][x] == ofColor(255, 255, 255)) pixel = false;

				BWFile << pixel << " ";
			}
			//after each row is done, new line
			BWFile << "\n";
		}

		BWFile.close();
	}
}

void ofApp::saveColourFile(std::vector<std::vector<ofColor>> image) {
	//create the output file
	std::ofstream colourFile("ColourOutput.ppm");

	if (!colourFile.fail()) {
		//ppm header information
		colourFile << "P3" << "\n";
		colourFile << columns << " " << rows << "\n";
		colourFile << "255" << "\n";

		//stream each pixel into file
		for (int y = 0; y < rows; y++) {
			for (int x = 0; x < columns; x++) {
				colourFile << (int)image[y][x].r << " " << (int)image[y][x].g << " " << (int)image[y][x].b << " ";
			}
			//after each row is done, new line
			colourFile << "\n";
		}

		colourFile.close();
	}
}

void ofApp::saveFiles(std::vector<std::vector<ofColor>> image) {
	saveBWFile(image);
	saveColourFile(image);
}

void ofApp::loadBWFile() {
	//input file
	std::ifstream BWFile("BWOutput.ppm");

	if (!BWFile.fail()) {
		std::string type;

		//ppm header information
		BWFile >> type >> columns >> rows;

		pixels = std::vector<std::vector<ofColor>>(rows, std::vector<ofColor>(columns));

		//stream each pixel into file
		for (int y = 0; y < rows; y++) {
			for (int x = 0; x < columns; x++) {
				bool pixel;
				BWFile >> pixel;

				//set pixel colour
				if (pixel) pixels[y][x] = ofColor(0, 0, 0);
				else pixels[y][x] = ofColor(255, 255, 255);
			}
		}

		BWFile.close();
	}
}