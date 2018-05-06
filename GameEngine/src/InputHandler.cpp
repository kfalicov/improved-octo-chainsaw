#include "InputHandler.h"



InputHandler::InputHandler()
{
	_keyboardHandler = &KeyboardHandler::getKeyboard();
	_mouseHandler = &MouseHandler::getMouse();
	_gamePadHandler = &GamePadHandler::getGamePad();
}


InputHandler::~InputHandler()
{
	_keyboardHandler->destroyKeyboard();
	_mouseHandler->destroyMouse();
	_gamePadHandler->destroyGamePad();
}


InputHandler& InputHandler::getInputHandler()
{
	static InputHandler* handler = NULL;
	if (handler == NULL)
	{
		handler = new InputHandler();
	}
	return *handler;
}

void InputHandler::destroyInputHandler()
{
	InputHandler* handler = &getInputHandler();
	delete handler; // frees the memory of the handler
	handler = NULL;
}


bool InputHandler::getKeyState(int key)
{
	return _keyboardHandler->getKeyState(key);
}
bool InputHandler::getButtonState(int button)
{
	return _mouseHandler->getMouseState(button);
}

glm::vec2 InputHandler::getMousePosition()
{
	glm::vec2 pos;
	pos.x = (float)_mouseHandler->getX();
	pos.y = (float)_mouseHandler->getY();
	return pos;
}