#include "Player.h"

Player::Player(int tail, int score, int* pos) {
	this->tail = tail;
	this->score = score;
	this->position = new struct Position;
	if (pos != nullptr) {
		this->position->setPosition(pos[0], pos[1]);
	}
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

unsigned int* Player::getPosition() {
	unsigned int pos[] = { this->position->X, this->position->Y };
	return pos;
}

void Player::setPosition(int posX, int posY) {
	this->position->setPosition(posX, posY);
}