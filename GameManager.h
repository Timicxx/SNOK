#pragma once

#include "LedControlMS.h"
#include "GameDisplay.h"
#include "Player.h"

class GameManager {
  public:
	  GameManager(Player* player, GameDisplay* gameDisplay);
	  void Play();
  private:
	  void Draw(Player* player); 
	  Player* player;
	  GameDisplay* gameDisplay;
};
