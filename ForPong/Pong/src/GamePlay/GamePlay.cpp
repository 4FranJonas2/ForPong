#include "GamePlay.h"

player::Player player1;
player::Player player2;
Ball ball;
SimulationStatus pong;
Rectangle arenaLimitsOnMenu;
Rectangle arenaLimitsOnGame;
PONG game;
MENU mainmenu;

void Pong()
{
	srand(time(NULL));

	Init(pong, ball, game, mainmenu, player1, player2);

	while (!WindowShouldClose())
	{
		Input(game, mainmenu, pong, player1, player2);

		switch ((PONG)game)
		{
		case PONG::MAINMENU:
			mainMenu(game, mainmenu, pong);
			break;

		case PONG::MAINGAME:
			GamePlay(game);
			break;

		default:
			break;
		}
	}

	Close();
}

void GamePlay(PONG& game)
{
	Update(pong, player1, player2);
	Draw(ball, game, pong);
}

void mainMenu(PONG& game, MENU& mainmenu, SimulationStatus& pong)
{
	UpdateMenu(game, mainmenu, pong);
	Draw(ball, game, pong);
}

void Update(SimulationStatus& pong, player::Player& player1, player::Player& player2)
{
	//normal update run
	if (!(player1.points == pointsToWin || player2.points == pointsToWin) && pong.gamePause == false)
	{
		player::UpdatePlayer(player1, player2);
		UpdateBall(ball, player1, player2);
	}

	//all updates status during gameplay  

	if (IsKeyPressed(KEY_SPACE) && pong.fisrtPauseOk == true) 
	{
		pong.fisrtPauseOk = false;
	}  
	else if (IsKeyDown(KEY_ENTER) && pong.fisrtPauseOk == false)
	{
		pong.gamePause = true;
	} 
	else if ((player1.points == pointsToWin || player2.points == pointsToWin) && (pong.resetButtonPress == false && pong.backToMenuButton == false))
	{
		pong.gamePause = true; 
	}
	else if (pong.resetButtonPress == true) 
	{
		ResetGame(ball, player1, player2, pong, game, mainmenu);
	}
	else if (pong.backToMenuButton == true) 
	{
		BackMenu(ball, player1, player2, pong, game, mainmenu);
	}
	else if ((player2.isPoint == true || player1.isPoint == true) || (player1.points == pointsToWin || player2.points == pointsToWin))
	{
		ResetWhenPoint(ball, pong, player1, player2);
	}
}

void Draw(Ball& ball, PONG game, SimulationStatus& pong)
{
	BeginDrawing();

	switch ((PONG)game)
	{
	case PONG::MAINMENU:

		if (pong.inMenu)
		{
			arenaLimitsOnMenu = setArenaOnMenu();
			DrawRectangleLinesEx(arenaLimitsOnMenu, lineThick, PURPLE);
			DrawMenu();
		}
		else if (pong.inCredits)
		{
			DrawCredits();
		}
		else if (pong.inExit)
		{
			DrawExitText();
		}
		break;

	case PONG::MAINGAME:

		arenaLimitsOnGame = setArenaOnGame();

		if (pong.fisrtPauseOk == true)
		{
			DrawInitPauseMenu();
		}
		else if (pong.gamePause == true)
		{
			player::DrawWinLosePauseSceen(player1, player2);
			DrawMainPauseMenu(player1, player2);
		}

		player::DrawGameUI(player1, player2);
		DrawRectangleLinesEx(arenaLimitsOnGame, lineThick, LIME);
		player::DrawPlayer(player1, player2);
		DrawBall(ball);
		break;

	default:
		break;
	}

	ClearBackground(BLACK);
	EndDrawing();
}

void Close()
{
	CloseWindow();
}