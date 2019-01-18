#include "Player.h"

Player::Player() {
	this->score = 0;
	// this->position = new struct Position;
	initializePositionsArray();
}

void Player::initializePositionsArray() {
	this->positions = new byte[64];
	this->positions[0] = 4;
	this->positions[1] = 4;	
	for (int i = 2; i < 64; i++) {
		this->positions[i] = 255;
	}
}

int Player::getScore() {
	return this->score;
}

void Player::setScore(int score) {
	this->score = score;
}

// int Player::getPositionX() {
// 	return this->position->X;
// }

// int Player::getPositionY() {
// 	return this->position->Y;
// }

void Player::getPosition(byte* positionArray) {
	positionArray = this->positions;
}

void Player::setPosition(byte posX, byte posY) {
	// this->position->setPosition(posX, posY);
	byte newPosition[64];
	
	newPosition[0] = posX;
	newPosition[1] = posY;
	
	for(int i = 2; i < 64; i += 2) {
		byte x = this->positions[i - 2];
		byte y = this->positions[i - 1];

		if(this->positions[i - 2] == 255) {
			x = 255;
			y = 255;
		}

		newPosition[i] = x;
		newPosition[i + 1] = y;
	}
	this->positions = newPosition;
	this->verifyPosition();
}

void Player::incPosition(byte incX, byte incY) {
	byte newX = this->positions[0] + incX;
	byte newY = this->positions[1] + incY;
	
	// this->position->incPosition(posX, posY);
	this->setPosition(newX, newY);
	this->verifyPosition();
}

void Player::verifyPosition() {
	// int _X = this->position->X;
	// int _Y = this->position->Y;
	byte _X = this->positions[0];
	byte _Y = this->positions[1];
	
	byte newX = _X;
	byte newY = _Y;
	
	if (_X > this->SIZE) {
		newX = 0;
	}
	else if (_X < 0) {
		newX = this->SIZE;
	}

	if (_Y > this->SIZE) {
		newY = 0;
	}
	else if (_Y < 0) {
		newY = this->SIZE;
	}

	this->setPosition(newX, newY);
}

char Player::getDirection() {
	return this->direction;
}

void Player::setDirection(char dir) {
	this->direction = dir;
}