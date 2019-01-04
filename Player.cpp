#include "Player.h"

Player::Player(int tail, int score) {
	this->tail = tail;
	this->score = score;
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

int* Player::getPixelArray() {
	return this->pixels;
}

void Player::pushPixel(int x, int y) {
	this->pixels[8 * x + y] = x;
	this->pixels[8 * x + y + 1] = y;
}