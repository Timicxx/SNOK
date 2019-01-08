#include "InputManager.h"
#include "GameManager.h"
#include "GameDisplay.h"
#include "Player.h"
#include "Debugger.h"

/// LED MATRIX CONNECTION:	|	JOYSTICK CONNECTION:
/// DIN =	DIGITAL	12		|	SW	=	DIGITAL	2
/// CLK =	DIGITAL	11		|	X	=	ANALOG	0
/// CS	=	DIGITAL	10		|	Y	=	ANALOG	1

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
		debugger.Debug();
	}
}
