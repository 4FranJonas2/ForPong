#pragma once
#include "..\Init.h" 

void Pong();
void GamePlay(PONG& game);
void mainMenu(PONG& game, MENU& mainmenu, SimulationStatus& pong);
void Update(SimulationStatus& pong, player::Player& player1, player::Player& player2);
void Draw(Ball& ball, PONG game, SimulationStatus& pong);
void Close();