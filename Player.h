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
	Player(int tail, int score, int* pos);
    int getTail();
    void setTail(int tail);
    int getScore();
    void setScore(int score);
	unsigned int* getPosition();
	void setPosition(int posX, int posY);
  private:
    int tail;
    int score;
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
};

#endif