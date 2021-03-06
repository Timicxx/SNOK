#include "GameDisplay.h"

GameDisplay::GameDisplay(int intensity)
	: ledControl(12, 11, 10, intensity) {
	this->init(intensity);
}

void GameDisplay::setIntensity(int intensity) {
	this->ledControl.setIntensity(this->DISPLAY_ADDR, intensity);
}

void GameDisplay::init(int intensity) {
	this->ledControl.shutdown(this->DISPLAY_ADDR, false);
	this->setIntensity(intensity);
	this->ledControl.clearDisplay(this->DISPLAY_ADDR);
}

int GameDisplay::getSize() {
	return this->SIZE;
}

LedControl* GameDisplay::getLedControl() {
	LedControl* lc = &this->ledControl;
	return lc;
}

int GameDisplay::getAddress() {
	return this->DISPLAY_ADDR;
}
