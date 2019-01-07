//GameManager.h

#ifndef _GAMEMANAGER_h
#define _GAMEMANAGER_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "LedControlMS.h"
#include "GameDisplay.h"
#include "Player.h"
#include "InputManager.h"

class GameManager {
  public:
	  GameManager(int din=12, int clk=11, int cs=10, int intensity=8, int tail=0, int score=0, int* pos=nullptr);
	  void Setup();
	  void Draw();
	  bool isPlaying();
	  void isPlaying(bool state);
	  Player* getPlayer();
	  GameDisplay* getGameDisplay();
	  InputManager* GetInputManager();
  private:
	  Player player;
	  GameDisplay gameDisplay;
	  InputManager inputManager;
	  bool m_isPlaying;
};

#endif