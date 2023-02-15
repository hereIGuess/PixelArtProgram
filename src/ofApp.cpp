#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){
	ofSetWindowShape(columns * pixelSize, rows * pixelSize);
}

//--------------------------------------------------------------
void ofApp::draw(){
	for (int y = 0; y < rows; y++) {
		for (int x = 0; x < columns; x++) {
			bool pixel = pixels[y][x];

			if (pixel) {
				ofSetColor(0);
			} else {
				ofSetColor(200);
			}

			ofDrawRectangle(pixelSize * x, pixelSize * y, pixelSize, pixelSize);
		}
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	switch (key) {
		case 57356: {
			if (columns > 6) columns--;
			break;
		}
		case 57357: {
			if (rows > 1) rows--;
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

	if (key == 57356 || key == 57357 || key == 57358 || key == 57359 || key == 99 || key == 67) 
		pixels = std::vector<std::vector<bool>>(rows, std::vector <bool> (columns));
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	if (key == 115 || key ==83) saveFile(pixels);
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	int col{ x / pixelSize };
	int row{ y / pixelSize };

	pixels[row][col] = !pixels[row][col];
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

void ofApp::saveFile(std::vector<std::vector<bool>> image) {
	std::ofstream file("Output.ppm");

	if (!file.fail()) {
		file << "P1" << "\n";
		file << columns << " " << rows << "\n";

		for (int y = 0; y < rows; y++) {
			for (int x = 0; x < columns; x++) {
				std::cout << image[y][x] << "  ";
				file << image[y][x] << " ";
			}
			std::cout << "\n";
			file << "\n";
		}

		file.close();
	}
}