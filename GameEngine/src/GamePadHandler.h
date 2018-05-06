#ifndef _GAMEPAD_HANDLER_H
#define _GAMEPAD_HANDLER_H
#include <stdio.h>

/*
	Handles gamepad input.
	This class is a singleton
*/
class GamePadHandler
{
private:

	/*
		Creates a new GamePadHandler
	*/
	GamePadHandler();

public:

	/*
		Destroys the GamePadHandler
	*/
	~GamePadHandler();

	/*
		Returns the only instance of a GamePadHandler
		@return Returns the only instance of a GamePadHandler
	*/
	static GamePadHandler& getGamePad(); 

	/*
		Destroys the only instance of a GamePadHandler
	*/
	static void destroyGamePad();

	// TODO: Add gamepad functions
protected:

};

#endif