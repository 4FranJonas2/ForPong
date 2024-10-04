#include "Arena.h"

Rectangle setArenaOnMenu()
{
	Rectangle rectangleOnMenu;

	rectangleOnMenu.x = originPointX;
	rectangleOnMenu.y = originPointY;
	rectangleOnMenu.width = screenWidth;
	rectangleOnMenu.height = screenHeigth;

	return rectangleOnMenu;
}

Rectangle setArenaOnGame()
{
	Rectangle rectangleOnGame;

	rectangleOnGame.x = originPointX;
	rectangleOnGame.y = originPointY + (screenHeigth / 7);
	rectangleOnGame.width = screenWidth;
	rectangleOnGame.height = screenHeigth - (screenHeigth / 7);

	return rectangleOnGame;
}