//Debugger.h

#ifndef _DEBUGGER_h
#define _DEBUGGER_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "GameManager.h"

class Debugger {
  public:
	Debugger(GameManager* gameManager);
	void Debug();
  private:
	GameManager* gameManager;
};

#endif