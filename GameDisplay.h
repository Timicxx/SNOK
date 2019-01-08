//GameDisplay.h

#ifndef _GAMEDISPLAY_h
#define _GAMEDISPLAY_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "LedControlMS.h"

class GameDisplay {
  public:
	  GameDisplay(int intensity);
	  void setIntensity(int intensity);
	  int getSize();
	  int getAddress();
	  LedControl* getLedControl();
  private:
	  const int DISPLAY_ADDR = 0;
	  const int SIZE = 8;
	  int intensity;
	  LedControl ledControl;
	  void init(int intensity);
};

#endif