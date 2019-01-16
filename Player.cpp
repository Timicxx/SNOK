#include "Player.h"

Player::Player(int* pos) {
	this->score = 0;
	// this->position = new struct Position;
	this->positions = { new struct Position };
	this->posistionArraySize = 1;
	if (pos != nullptr) {
		this->position->setPosition(pos[0], pos[1]);
	}
}

void Player::setSize(int size) {
	this->SIZE = size;
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

int Player::getPositionArraySize() {
	return this->posistionArraySize;
}

void Player::getPosition(int* positionArray) {
	for(int i = 0; i < this->posistionArraySize); i++) {
		positionArray[i] = this->positions.X;
		positionArray[i + 1] = this->positions.Y;
	}
}

void Player::setPosition(int posX, int posY) {
	// this->position->setPosition(posX, posY);
	int newPosition[this->posistionArraySize];
	for(int i = 0; i < this->posistionArraySize - 1; i++) {
		if(i == 0) {
			newPosition[0] = new struct Position;
			newPosition[0].setPosition(posX, posY);
		}
		newPosition[i - 1] = this->positions[i];
	}
	this->positions = newPosition;
	this->verifyPosition();
}

void Player::incPosition(int incX, int incY) {
	int newX = this->positions[0]->X;
	int newY = this->positions[0]->Y;
	
	// this->position->incPosition(posX, posY);
	this->setPosition(newX, newY);
	this->verifyPosition();
}

void Player::verifyPosition() {
	// int _X = this->position->X;
	// int _Y = this->position->Y;
	int _X = this->positions[0]->X;
	int _Y = this->positions[0]->Y;
	
	int newX = _X;
	int newY = _Y;
	
	this->posistionArraySize = (sizeof(this->positions) / sizeof(int);
	
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

	this->position->setPosition(newX, newY);
}

char Player::getDirection() {
	return this->direction;
}

void Player::setDirection(char dir) {
	this->direction = dir;
}