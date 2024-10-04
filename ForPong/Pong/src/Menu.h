#pragma once
#include "Entities\Ball.h" 

struct Mouse
{
	Vector2 mousePos;
};

void InitButtons();
void InputMenu( PONG& game, MENU& mainmenu, SimulationStatus& pong);
void UpdateMenu(PONG& game, MENU& mainmenu, SimulationStatus& pong);
void DrawMainPauseMenu(player::Player& player1, player::Player& player2);
void DrawInitPauseMenu();
void DrawExitText();
void DrawCredits();
void DrawMenu();
void DrawButton(Vector2 buttonPos, Vector2 buttonSize, Color color);
bool isOverButon(Mouse mouse, Vector2 buttonPos, Vector2 buttonDimension);