#include "test.h"
#include "GameManager.h"
#include "GameDisplay.h"
#include "Player.h"


GameDisplay gameDisplay(12, 11, 10, 8);
Player player = Player(5, 0);
GameManager gameManager = GameManager(&player, &gameDisplay);

void setup() {
	// Yes
}

void loop() {
	gameManager.Play();
}
