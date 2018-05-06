#include "GamePadHandler.h"



GamePadHandler::GamePadHandler()
{
}


GamePadHandler::~GamePadHandler()
{
}

GamePadHandler& GamePadHandler::getGamePad()
{
	static GamePadHandler* gamePad = NULL;
	if (gamePad == NULL)
	{
		gamePad = new GamePadHandler();
	}
	return *gamePad;
}
void GamePadHandler::destroyGamePad()
{
	GamePadHandler* gamePad = &GamePadHandler::getGamePad();
	delete gamePad;
	gamePad = NULL;
}
