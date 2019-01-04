#pragma once

class Player {
  public:
    Player(int tail=0, int score=0);
    int getTail();
    void setTail(int tail);
    int getScore();
    void setScore(int score);
	int* getPixelArray();
	void pushPixel(int x, int y);
  private:
    int tail;
    int score;
	int* pixels;
};
