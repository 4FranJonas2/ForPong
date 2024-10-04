#pragma once
#include "Input.h"

void Init(SimulationStatus& pong, Ball& ball, PONG& game, MENU& mainmenu, player::Player& player1, player::Player& player2);
void InitSimulation(SimulationStatus& pong, PONG& game, MENU& mainmenu);
void InitGamePlay(Ball& ball, player::Player& player1, player::Player& player2);
void ResetGame(Ball& ball, player::Player& player1, player::Player& player2, SimulationStatus& pong, PONG& game, MENU& mainmenu);
void BackMenu(Ball& ball, player::Player& player1, player::Player& player2, SimulationStatus& pong, PONG& game, MENU& mainmenu);
void ResetWhenPoint(Ball& ball, SimulationStatus& pong, player::Player& player1, player::Player& player2);