#pragma once
#include "Player.h"

struct Ball
{
	Vector2 ballPosition;
	Vector2 ballDir;

	int ballWidth;
	int ballRad;
	float ballSpeed;

	int initLaunch;
};

void InitBall(Ball& ball);
void MoveBall(Ball& ball);
void CheckWallCollision(Ball& ball, float width, float heigth, float lineThick, player::Player& player1, player::Player& player2);
void ChekPlayerCollision(Ball& ball, player::Player& player);
void UpdateBall(Ball& ball, player::Player& player1, player::Player& player2);
void DrawBall(Ball ball);