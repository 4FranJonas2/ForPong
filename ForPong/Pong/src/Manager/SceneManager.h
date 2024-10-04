#pragma once

enum class PONG
{
	MAINMENU =1,
	MAINGAME,
};

enum class MENU
{
	NONE,
	PLAY,
	CREDITS,
	BACK,
	EXIT
};

enum class GAMESTATE
{
	GAMERUN,
	INITGAME,
	ONPAUSE,
	RESUME,
	RESETGAME,
	BACKMENU,
};