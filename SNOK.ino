#include "InputManager.h"
#include "GameManager.h"
#include "GameDisplay.h"
#include "Player.h"
#include "Debugger.h"

GameManager gameManager = GameManager();
Debugger debugger = Debugger(&gameManager);

void setup() {
	gameManager.Setup();
}

void loop() {
	gameManager.isPlaying(true);
	while (!gameManager.isPlaying()) {
		gameManager.GetInputManager()->checkForInput();
		gameManager.Draw();
		debugger.debug();
	}
}
