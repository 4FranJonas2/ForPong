#include "Menu.h"

Mouse mouse;
MenuSet menu;

void InitButtons()
{
	menu.button1Pos.x = midScreenOnX;
	menu.button1Pos.y = ((screenHeigth / 7) * 2) - (buttonHeigth / 2);

	menu.button2Pos.x = midScreenOnX;
	menu.button2Pos.y = ((screenHeigth / 7) * 4) - (buttonHeigth / 2);

	menu.button3Pos.x = midScreenOnX;
	menu.button3Pos.y = ((screenHeigth / 7) * 5) - (buttonHeigth / 2);

	menu.button4Pos.x = midScreenOnX;
	menu.button4Pos.y = ((screenHeigth / 7) * 6) - (buttonHeigth / 2);


	menu.button5Pos.x = midScreenOnX;
	menu.button5Pos.y = ((screenHeigth / 7) * 3) - (buttonHeigth / 2);

	menu.button6Pos.x = midScreenOnX;
	menu.button6Pos.y = ((screenHeigth / 7) * 5) - (buttonHeigth / 2);

	menu.button7Pos.x = midScreenOnX;
	menu.button7Pos.y = ((screenHeigth / 7) * 6) - (buttonHeigth / 2);


	menu.buttonsDimension.x = buttonsWidth;
	menu.buttonsDimension.y = buttonHeigth;
}

void InputMenu(PONG& game, MENU& mainmenu, SimulationStatus& pong)
{
	mouse.mousePos.x = GetMouseX();
	mouse.mousePos.y = GetMouseY();

	switch ((PONG)game)
	{
	case PONG::MAINMENU:
		if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) && isOverButon(mouse, menu.button1Pos, menu.buttonsDimension))
		{
			mainmenu = MENU::CREDITS;
		}
		else if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) && isOverButon(mouse, menu.button2Pos, menu.buttonsDimension))
		{
			game = PONG::MAINGAME;

		}
		else if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) && isOverButon(mouse, menu.button3Pos, menu.buttonsDimension))
		{
			mainmenu = MENU::EXIT;
		}

		if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) && isOverButon(mouse, menu.button4Pos, menu.buttonsDimension))
		{
			pong.inMenu = true;
			pong.inCredits = false;
			mainmenu = MENU::NONE;
		}
		break;

	case PONG::MAINGAME:
		if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) && isOverButon(mouse, menu.button5Pos, menu.buttonsDimension))
		{
			pong.gamePause = false;
		}
		else if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) && isOverButon(mouse, menu.button6Pos, menu.buttonsDimension))
		{
			pong.resetButtonPress = true;
		}
		else if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) && isOverButon(mouse, menu.button7Pos, menu.buttonsDimension))
		{
			pong.backToMenuButton = true;
		}
		break;

	default:
		break;
	}
}

void UpdateMenu(PONG& game, MENU& mainmenu, SimulationStatus& pong)
{
	switch ((MENU)mainmenu)
	{
	case MENU::NONE:
		game = PONG::MAINMENU;
		break;

	case MENU::PLAY:
		game = PONG::MAINGAME;
		break;

	case MENU::CREDITS:
		pong.inMenu = false;
		pong.inCredits = true;
		break;

	case MENU::BACK:
		game = PONG::MAINMENU;
		pong.inMenu = true;
		pong.inExit = false;
		break;

	case MENU::EXIT:
		pong.inMenu = false;
		pong.inExit = true;
		break;

	default:
		break;
	}
}

void DrawMainPauseMenu(player::Player& player1, player::Player& player2)
{
	if (isOverButon(mouse, menu.button5Pos, menu.buttonsDimension))
	{
		DrawButton(menu.button5Pos, menu.buttonsDimension, DARKGRAY);
	}
	else
	{
		DrawButton(menu.button5Pos, menu.buttonsDimension, WHITE);
	}

	if (isOverButon(mouse, menu.button6Pos, menu.buttonsDimension))
	{
		DrawButton(menu.button6Pos, menu.buttonsDimension, DARKGRAY);
	}
	else
	{
		DrawButton(menu.button6Pos, menu.buttonsDimension, WHITE);
	}

	if (isOverButon(mouse, menu.button7Pos, menu.buttonsDimension))
	{
		DrawButton(menu.button7Pos, menu.buttonsDimension, DARKGRAY);
	}
	else
	{
		DrawButton(menu.button7Pos, menu.buttonsDimension, WHITE);
	}

	DrawText("Resume", mainPauseText1OnX, mainPausetext1OnY, 20, BLACK);
	DrawText("Restart", mainPauseText2OnX, mainPausetext2OnY, 20, BLACK);
	DrawText("Menu", mainPauseText3OnX, mainPausetext3OnY, 20, BLACK);
}

void DrawInitPauseMenu()
{
	DrawText("RULES:", firstPauseText1OnX, firstPausetext1OnY, 20, LIGHTGRAY);
	DrawText("PLAYER 1: move with W and S", firstPauseText2OnX, firstPausetext2OnY, 20, LIGHTGRAY);
	DrawText("PLAYER 2: move with UP and DOWN", firstPauseText3OnX, firstPausetext3OnY, 20, LIGHTGRAY);
	DrawText("---- PRESS SPACEBAR TO START ----", firstPauseTextOnX, firstPausetextOnY, 30, LIGHTGRAY);
}

void DrawExitText()
{
	DrawText("Thanks for playing FORPONG :)", exitText1OnX, exittext1PosOnY, 20, YELLOW);
	DrawText("Hope you enjoy it.", exitText2OnX, exittext2PosOnY, 20, BLUE);
	DrawText("See you later !! ", exitText3OnX, exittext3PosOnY, 20, GOLD);
	DrawText("---- PRESS ESC TO CLOSE THE WINDOW ----", exitText4OnX, exittext4PosOnY, 20, LIGHTGRAY);
}

void DrawCredits()
{
	DrawText("CREDITS", centerText1OnX, text1PosOnY, 20, WHITE);
	DrawText("Reworked version of PONG, made by Francisco Jonas.", centerText2OnX, text2PosOnY, 20, RED);
	DrawText("	Special thanks to Professor Sergio Baretto and Stefano Juan Cvitanich", centerText3OnX, text3PosOnY, 20, GOLD);
	DrawText("and the extra support provided by Federico Olive and Emanuel Parajon.", centerText4OnX, text4PosOnY, 20, PURPLE);

	if (isOverButon(mouse, menu.button4Pos, menu.buttonsDimension))
	{
		DrawButton(menu.button4Pos, menu.buttonsDimension, DARKGRAY);
	}
	else
	{
		DrawButton(menu.button4Pos, menu.buttonsDimension, WHITE);
	}

	DrawText("BACK", menu.button4Pos.x + centerExitButton, menu.button4Pos.y + (buttonHeigth / 4), 20, BLACK);
}

void DrawMenu()
{
	if (isOverButon(mouse, menu.button1Pos, menu.buttonsDimension))
	{
		DrawText("FORPONG", menu.button1Pos.x - centerCreditsButton, menu.button1Pos.y - (buttonHeigth / 4), 40, DARKGRAY);
	}
	else
	{
		DrawText("FORPONG", menu.button1Pos.x - centerCreditsButton, menu.button1Pos.y - (buttonHeigth / 4), 40, RED);
	}

	if (isOverButon(mouse, menu.button2Pos, menu.buttonsDimension))
	{
		DrawButton(menu.button2Pos, menu.buttonsDimension, DARKGRAY);
	}
	else
	{
		DrawButton(menu.button2Pos, menu.buttonsDimension, WHITE);
	}

	if (isOverButon(mouse, menu.button3Pos, menu.buttonsDimension))
	{
		DrawButton(menu.button3Pos, menu.buttonsDimension, DARKGRAY);
	}
	else
	{
		DrawButton(menu.button3Pos, menu.buttonsDimension, WHITE);
	}

	DrawText("PLAY", menu.button2Pos.x + centerPlayButton, menu.button2Pos.y + (buttonHeigth / 4), 20, BLACK);
	DrawText("EXIT", menu.button3Pos.x + centerExitButton, menu.button3Pos.y + (buttonHeigth / 4), 20, BLACK);
}

void DrawButton(Vector2 buttonPos, Vector2 buttonSize, Color color)
{
	DrawRectangle(buttonPos.x, buttonPos.y, buttonSize.x, buttonSize.y, color);
}

bool isOverButon(Mouse mouse, Vector2 buttonPos, Vector2 buttonDimension)
{
	if (mouse.mousePos.x >= buttonPos.x &&
		mouse.mousePos.x <= buttonPos.x + buttonDimension.x &&
		mouse.mousePos.y >= buttonPos.y &&
		mouse.mousePos.y <= buttonPos.y + buttonDimension.y)
	{
		return true;
	}
	return false;
}