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
	unsigned int* getPosition();
	void setPosition(unsigned int posX, unsigned int posY);
	void incPosition(int incX, int incY);
  private:
    unsigned int tail;
    int score;
	struct Position* position;
};

struct Position {
public:
	unsigned int X = 4;
	unsigned int Y = 4;
	void setPosition(unsigned int posX, unsigned int posY) {
		this->X = posX;
		this->Y = posY;
	}
	void incPosition(int incX, int incY) {
		this->X += incX;
		this->Y += incY;
	}
};

#endif