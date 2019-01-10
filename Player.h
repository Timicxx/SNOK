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
    int getTail();
    void setTail(int tail);
    int getScore();
    void setScore(int score);
	void setSize(int size);
	int getPositionX();
	int getPositionY();
	void setPosition(int posX, int posY);
	void incPosition(int incX, int incY);
	int* getCoordinates();
  private:
	int SIZE = 8;
	void verifyPosition();
	int* coordinates;
    int score;
	int* pos;
	struct Position* position;
};

struct Position {
public:
	int X = 4;
	int Y = 4;
	void setPosition(int posX, int posY) {
		this->X = posX;
		this->Y = posY;
	}
	void incPosition(int incX, int incY) {
		this->X += incX;
		this->Y += incY;
	}
};

#endif