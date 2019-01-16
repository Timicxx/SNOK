//Player.h

#ifndef _PLAYER_h
#define _PLAYER_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class Player {
  public:
	Player(int* pos);
    int getScore();
    void setScore(int score);
	void setSize(int size);
	// int getPositionX();
	// int getPositionY();
	int getPositionArraySize();
	void getPosition(int* positionArray);
	void setPosition(int posX, int posY);
	void incPosition(int incX, int incY);
	char getDirection();
	void setDirection(char dir);
  private:
	char direction;
	int posistionArraySize;
	int SIZE = 8;
	void verifyPosition();
    int score;
	int* pos;
	// struct Position* position;
};

struct Position {
public:
	int X = 4;
	int Y = 4;
	void setPosition(int posX, int posY) {
		this->X = posX;
		this->Y = posY;
	}
	// void incPosition(int incX, int incY) {
	// 	this->X += incX;
	// 	this->Y += incY;
	// }
};

#endif