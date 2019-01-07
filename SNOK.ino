#include "InputManager.h"
#include "GameManager.h"
#include "GameDisplay.h"
#include "Player.h"

GameManager gameManager = GameManager();

void setup() {
	gameManager.Setup();
}

void loop() {
	gameManager.isPlaying(true);
	while (!gameManager.isPlaying()) {
		gameManager.GetInputManager()->checkForInput();
		gameManager.Draw();
	}
}
