#include "Init.h"

void Init(SimulationStatus& pong, Ball& ball, PONG& game, MENU& mainmenu, player::Player& player1, player::Player& player2)
{
	InitSimulation(pong, game, mainmenu);
	InitGamePlay(ball, player1, player2);
	InitButtons();
}

void InitSimulation(SimulationStatus& pong, PONG& game, MENU& mainmenu)
{
	pong.inMenu = true;
	pong.fisrtPauseOk = true;
	game = PONG::MAINMENU;
	mainmenu = MENU::NONE;
	InitWindow(screenWidth, screenHeigth, " PONG by Francisco Jonas ");
}

void InitGamePlay(Ball& ball, player::Player& player1, player::Player& player2)
{
	player::CreatePlayer(player1, player2);
	InitBall(ball);
}

void ResetGame(Ball& ball, player::Player& player1, player::Player& player2, SimulationStatus& pong, PONG& game, MENU& mainmenu)
{
	pong.inMenu = false;
	pong.fisrtPauseOk = true;
	pong.gamePause = false;
	pong.resetButtonPress = false;
	game = PONG::MAINGAME;
	mainmenu = MENU::NONE;
	player::CreatePlayer(player1, player2);
	InitBall(ball);
	InitButtons();
}

void BackMenu(Ball& ball, player::Player& player1, player::Player& player2, SimulationStatus& pong, PONG& game, MENU& mainmenu)
{
	pong.inMenu = true;
	pong.fisrtPauseOk = true;
	pong.backToMenuButton = false;
	pong.gamePause = false;
	pong.resetButtonPress = false;
	game = PONG::MAINMENU;
	mainmenu = MENU::NONE;
	player::CreatePlayer(player1, player2);
	InitBall(ball);
	InitButtons();
}

void ResetWhenPoint(Ball& ball, SimulationStatus& pong, player::Player& player1, player::Player& player2)
{
	pong.fisrtPauseOk = true;
	player1.isPoint = false;
	player2.isPoint = false;
	InitBall(ball);
}