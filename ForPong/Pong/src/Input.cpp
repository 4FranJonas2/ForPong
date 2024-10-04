#include "Input.h"

void Input( PONG& game, MENU& mainmenu, SimulationStatus& pong, player::Player& player1, player::Player& player2)
{
	player::InputMovement(pong, player1, player2);
	InputMenu( game, mainmenu, pong);
}