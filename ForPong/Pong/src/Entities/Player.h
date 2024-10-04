#pragma once
#include "Arena.h"

namespace player
{
	enum class DIRECTION
	{
		STOP = 1,
		UP,
		DOWN
	};

	struct Player
	{
		float PosX;
		float PosY;
		float centerPointX;
		float centerPointY;
		int playerWidth;
		int playerHeigth;
		float speed;
		int points = 0;
		bool isPoint = false;

		float auxInitPosX;
		float initPosX;
		float initPosY;

		bool isPlayer1;
		bool isPlayer2;

		DIRECTION playerDir;
		Color playerColor;
	};

	void CreatePlayer(player::Player& player1, player::Player& player2);
	Player InitPlayer(bool isLeft, bool isPlayer, Color color);
	void InputMovement(SimulationStatus& pong, player::Player& player1, player::Player& player2);
	void StopMovement(player::Player& player1, player::Player& player2);
	void UpdatePlayer(player::Player& player1, player::Player& player2);
	void UpdatePlayerMovement(Player& player);
	void DrawWinLosePauseSceen(player::Player& player1, player::Player& player2);
	void DrawGameUI(player::Player& player1, player::Player& player2);
	void DrawPlayer(player::Player& player1, player::Player& player2);
	void DrawUpdatePlayer(Player player, Color color);
	void AddPointPlayer1(player::Player& player1);
	void AddPointPlayer2(player::Player& player2);
}