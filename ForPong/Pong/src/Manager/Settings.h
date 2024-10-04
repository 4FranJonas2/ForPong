#include <iostream>
#pragma once
#include "raylib.h"
#include "..\Manager\SceneManager.h"

using namespace std;

struct MenuSet
{
	Vector2 buttonsDimension;

	Vector2 button1Pos;
	Vector2 button2Pos;
	Vector2 button3Pos;
	Vector2 button4Pos;

	Vector2 button5Pos;
	Vector2 button6Pos;
	Vector2 button7Pos;

	bool isOnPlayButton;
	bool isOnCreditsButton;
	bool isOnExitButton;
	bool isOnBackButton;
	bool overButton = false;
};

struct SimulationStatus
{
	bool gamePause = false;
	bool inMenu = false;
	bool inCredits = false;
	bool inGameplay = false;
	bool inPause = false;
	bool inExit = false;
	bool fisrtPauseOk = false;
	bool resetButtonPress = false;
	bool backToMenuButton = false;
};

struct SimulationExtras
{
	int posX = 0;
	int posY = 0;
};

// simulation settings
const float screenWidth = 800.0f;
const float screenHeigth = 650.0f;
const int pointsToWin = 5;

//player settings
const float minDistanceFromBorder = 10.0f;
const float playerPaletteWidth = 15;
const float playerPaletteHeigth = 80;

//ball settings
const int ballWidth = 15;
const int ballRad = 10;
const int ballMinRange = -100.0f;
const int ballMaxRange = 100.0f;
const float ballSpeed = 400.0f;
const float auxFloat = 100.0f;
const int distanceForCenter = 80;

//arena settings
const float lineThick = 5.0f;
const float originPointX = 0;
const float originPointY = 0;

//mainMenu buttons settings
const int buttonsWidth = 100;
const int buttonHeigth = 40;
const int centerCreditsButton = ((buttonsWidth / 4) * 2);
const int centerPlayButton = (buttonsWidth / 4);
const int centerExitButton = (buttonsWidth / 4);
const int midScreenOnX = (screenWidth / 2) - (buttonsWidth / 2);

// Exit text settings
const int exitText1OnX = 240;
const int exitText2OnX = (screenWidth / 8) * 3;
const int exitText3OnX = (screenWidth / 8) * 3 + 15;
const int exitText4OnX = 160;
const int exittext1PosOnY = (screenHeigth / 7) * 1;
const int exittext2PosOnY = (screenHeigth / 7) * 3;
const int exittext3PosOnY = (screenHeigth / 7) * 4;
const int exittext4PosOnY = (screenHeigth / 7) * 6;

// credits text settings
const int centerText1OnX = (screenWidth / 7) * 3;
const int centerText2OnX = (screenWidth / 8) ;
const int centerText3OnX = 10 ;
const int centerText4OnX = 30;
const int text1PosOnY = (screenHeigth / 7) * 1;
const int text2PosOnY = (screenHeigth / 7) * 3;
const int text3PosOnY = (screenHeigth / 7) * 4;
const int text4PosOnY = 400;

// first pause
const int firstPauseTextOnX = 100;
const int firstPauseText1OnX = 370;
const int firstPauseText2OnX = 250;
const int firstPauseText3OnX = 250;

const int firstPausetextOnY = 500;
const int firstPausetext1OnY = 150;
const int firstPausetext2OnY = 200;
const int firstPausetext3OnY = 250;

// Text Game UI
const int gameUIText1OnX = 200;
const int gameUIText2OnX = 350;
const int gameUIText3OnX = 400;
const int gameUIText4OnX = 500;
const int gameUIText5OnX = 630;
const int gameUIText8OnX = 220;

const int gameUIText1OnY = 40;
const int gameUIText2OnY = 25;
const int gameUIText3OnY = 25;
const int gameUIText4OnY = 40;
const int gameUIText5OnY = 5;
const int gameUIText8OnY = 75;

// mainPause menu
const int mainPauseTextOnX = 265;
const int mainPauseText1OnX = 360;
const int mainPauseText2OnX = 360;
const int mainPauseText3OnX = 370;
		  
const int mainPausetextOnY = 150;
const int mainPausetext1OnY = 270;
const int mainPausetext2OnY = 450;
const int mainPausetext3OnY = 550;