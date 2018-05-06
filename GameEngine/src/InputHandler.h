#ifndef _INPUT_HANDLER_H
#define _INPUT_HANDLER_H
#include "GamePadHandler.h"
#include "MouseHandler.h"
#include "KeyboardHandler.h"
#include <stdio.h>
#include <glm\glm.hpp>

/*
	Wrapper class. This is a singleton
	This wraps around the keyboard, mouse, and gamepad input handlers
*/
class InputHandler
{
public:

	/*
		Destroys the InputHandler
	*/
	~InputHandler();

	/*
		Returns the only instance of a InputHandler
		@return Returns the only instance of a InputHandler
	*/
	static InputHandler& getInputHandler();

	/*
		Destroys the only instance of a inputhandler
	*/
	static void destroyInputHandler();

	/*
		Returns the state of a key on the keyboard
		@param key The keycode to get the state of
		@return Returns the state of the key
	*/
	bool getKeyState(int key);

	/*
		Returns the state of a mouse button
		@param button The button code to get the state of
		@return Returns the state of the button
	*/
	bool getButtonState(int button); 

	/*
		Returns the position of the mouse on the screen
		@return Returns the position of the mouse on the screen
	*/
	glm::vec2 getMousePosition(); 
	
private:

	/*
		Creates a new InputHandler
	*/
	InputHandler(); 

	GamePadHandler* _gamePadHandler; // A pointer to the only instance of the GamePadHandler
	MouseHandler* _mouseHandler; // A pointer to the only instance of the MouseHandler
	KeyboardHandler* _keyboardHandler; // A pointer to the only instance of the KeyboardHandler

protected:
};

#endif