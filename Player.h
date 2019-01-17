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
	Player();
    int getScore();
    void setScore(int score);
	// int getPositionX();
	// int getPositionY();
	void getPosition(byte* positionArray);
	void setPosition(byte posX, byte posY);
	void incPosition(byte incX, byte incY);
	char getDirection();
	void setDirection(char dir);
  private:
	char direction;
	static const byte SIZE = 8;
	void verifyPosition();
    int score;
	// struct Position* position;
	byte* positions;
};

// struct Position {
// public:
// 	int X = 4;
// 	int Y = 4;
// 	void setPosition(int posX, int posY) {
// 		this->X = posX;
// 		this->Y = posY;
// 	}
//  void incPosition(int incX, int incY) {
// 		this->X += incX;
// 		this->Y += incY;
// 	}
// };

#endif