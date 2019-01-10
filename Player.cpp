#include "Player.h"

Player::Player(int* pos) {
	this->tail = 0;
	this->score = 0;
	this->position = new struct Position;
	if (pos != nullptr) {
		this->position->setPosition(pos[0], pos[1]);
	}
}

void Player::setSize(int size) {
	this->SIZE = size;
}

int Player::getTail() {
	return this->tail;
}

void Player::setTail(int tail) {
	this->tail = tail;
}

int Player::getScore() {
	return this->score;
}

void Player::setScore(int score) {
	this->score = score;
}

int Player::getPositionX() {
	return this->position->X;
}

int Player::getPositionY() {
	return this->position->Y;
}

void Player::setPosition(int posX, int posY) {
	this->position->setPosition(posX, posY);
	this->verifyPosition();
}

void Player::incPosition(int incX, int incY) {
	this->position->incPosition(incX, incY);
	this->verifyPosition();
}

void Player::verifyPosition() {
	int _X = this->position->X;
	int _Y = this->position->Y;

	int newX = _X;
	int newY = _Y;

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