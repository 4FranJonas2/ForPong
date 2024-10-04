#include "Player.h"

namespace player
{
	void CreatePlayer(player::Player& player1, player::Player& player2)
	{
		player1 = InitPlayer(true, player1.isPlayer1 = true, ORANGE);
		player2 = InitPlayer(false, player2.isPlayer2 = true, BLUE);
	}

	Player InitPlayer(bool isLeft, bool isPlayer, Color color)
	{
		Player player;
		Rectangle gameArena;
		gameArena = setArenaOnGame();

		player.auxInitPosX = minDistanceFromBorder;
		player.playerWidth = playerPaletteWidth;
		player.playerHeigth = playerPaletteHeigth;
		player.speed = 450.0f;
		player.isPlayer1;
		player.isPlayer2;
		player.centerPointX = player.PosX + player.playerWidth / 2;
		player.centerPointY = player.PosY + playerPaletteHeigth / 2;
		player.playerColor = color;
		player.points = 0;

		if (isLeft)
			player.initPosX = player.auxInitPosX;
		else
			player.initPosX = screenWidth - player.auxInitPosX - player.playerWidth;

		player.initPosY = gameArena.height / 2 + (player.playerHeigth / 2);
		player.PosX = player.initPosX;
		player.PosY = player.initPosY;

		DIRECTION playerDir = DIRECTION::STOP;

		return player;
	}

	void InputMovement(SimulationStatus& pong, player::Player& player1, player::Player& player2)
	{
		if (IsKeyDown(KEY_W))
		{
			player1.playerDir = DIRECTION::UP;
		}
		else if (IsKeyDown(KEY_S))
		{
			player1.playerDir = DIRECTION::DOWN;
		}

		if (IsKeyDown(KEY_UP))
		{
			player2.playerDir = DIRECTION::UP;
		}
		else if (IsKeyDown(KEY_DOWN))
		{
			player2.playerDir = DIRECTION::DOWN;
		}

		StopMovement(player1, player2);
	}

	void StopMovement(player::Player& player1, player::Player& player2)
	{
		if (IsKeyUp(KEY_W) && IsKeyUp(KEY_S))
		{
			player1.playerDir = DIRECTION::STOP;
		}

		if (IsKeyUp(KEY_UP) && IsKeyUp(KEY_DOWN))
		{
			player2.playerDir = DIRECTION::STOP;
		}
	}

	void UpdatePlayer(player::Player& player1, player::Player& player2)
	{
		UpdatePlayerMovement(player1);
		UpdatePlayerMovement(player2);
	}

	void UpdatePlayerMovement(Player& player)
	{
		Rectangle gameArena;
		gameArena = setArenaOnGame();

		bool IsTopScreen = player.PosY <= gameArena.y + minDistanceFromBorder;
		bool IsBottomScreen = (player.PosY + player.playerHeigth) >= (screenHeigth - minDistanceFromBorder);

		player.centerPointX = player.PosX + player.playerWidth / 2;
		player.centerPointY = player.PosY + playerPaletteHeigth / 2;

		if (player.playerDir == DIRECTION::UP)
		{
			if (!IsTopScreen)
			{
				player.PosY -= player.speed * GetFrameTime();
			}
		}
		else if (player.playerDir == DIRECTION::DOWN)
		{
			if (!IsBottomScreen)
			{
				player.PosY += player.speed * GetFrameTime();
			}
		}
	}

	void DrawWinLosePauseSceen(player::Player& player1, player::Player& player2)
	{
		if (player1.points >= pointsToWin)
		{
			DrawText("PLAYER 1 WINS !!", mainPauseTextOnX, mainPausetextOnY, 40, GREEN);
		}
		else if (player2.points >= pointsToWin)
		{
			DrawText("PLAYER 2 WINS !!", mainPauseTextOnX, mainPausetextOnY, 40, GREEN);
		}
		else
		{
			DrawText("GAME PAUSE", mainPauseTextOnX, mainPausetextOnY, 40, MAROON);
		}
	}

	void DrawGameUI(player::Player& player1, player::Player& player2)
	{
		int pointsPlayer1 = player1.points;
		int pointsPlayer2 = player2.points;

		DrawText("PLAYER 1", gameUIText1OnX, gameUIText1OnY, 20, GOLD);
		DrawText(TextFormat("%i |", pointsPlayer1), gameUIText2OnX, gameUIText2OnY, 50, MAROON);
		DrawText(TextFormat("| %i", pointsPlayer2), gameUIText3OnX, gameUIText3OnY, 50, MAROON);
		DrawText("PLAYER 2", gameUIText4OnX, gameUIText4OnY, 20, BLUE);
		DrawText("| PRESS ENTER TO PAUSE |", gameUIText5OnX, gameUIText5OnY, 10, WHITE);
		DrawText("Hit the oposite wall you make 1 POINT, got 5 to WIN", gameUIText8OnX, gameUIText8OnY, 15, LIGHTGRAY);
	}

	void DrawPlayer(player::Player& player1, player::Player& player2)
	{
		DrawUpdatePlayer(player1, player1.playerColor);
		DrawUpdatePlayer(player2, player2.playerColor);
	}

	void DrawUpdatePlayer(Player player, Color color)
	{
		DrawRectangle(player.PosX, player.PosY, player.playerWidth, player.playerHeigth, color);
	}

	void AddPointPlayer1(player::Player& player1)
	{
		player1.points++;
		player1.isPoint = true;
	}

	void AddPointPlayer2(player::Player& player2)
	{
		player2.points++;
		player2.isPoint = true;
	}
}