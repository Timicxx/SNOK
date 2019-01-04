#pragma once

#include "LedControlMS.h"

class LedControl;
class GameDisplay {
  public:
	  GameDisplay(int din, int clk, int cs, int intensity);
	  void setIntensity(int intensity);
	  int getSize();
	  int getAddress();
	  LedControl getLedControl();
  private:
	  static const int DISPLAY_ADDR = 0;
	  static const int SIZE = 8;
	  int intensity;
	  LedControl ledControl;
	  void init(int intensity);
};