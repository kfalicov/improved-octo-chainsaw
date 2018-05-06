#include "KeyboardHandler.h"


KeyboardHandler::KeyboardHandler()
{
	// initalizes all of the keys to up
	for (int i = 0; i < 348; i++)
	{
		KEYS[i] = false;
	}
}


KeyboardHandler::~KeyboardHandler()
{

}

void KeyboardHandler::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (action == GLFW_PRESS) // if the key has been pressed it sets the key to true which is down
	{
		KEYS[key] = true;
	}
	else if (action == GLFW_RELEASE) // if the key has been released it sets the key to false which is up
	{
		KEYS[key] = false;
	}
	else // otherwise it sets the key to down.
	{
		KEYS[key] = true;
	}
}

void KeyboardHandler::keyCallbackFun(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	KeyboardHandler* keyboard = &getKeyboard(); // gets a pointer to the keyboard
	keyboard->keyCallback(window, key, scancode, action, mods); // calls a callback handler. 
}

KeyboardHandler& KeyboardHandler::getKeyboard()
{
	static KeyboardHandler* keyboard = NULL;
	if (keyboard == NULL) // If keyboard is NULL then a keyboard has not been created yet
	{
		glfwSetKeyCallback(glfwGetCurrentContext(), *keyCallbackFun);
		glfwSetInputMode(glfwGetCurrentContext(), GLFW_CURSOR, GLFW_CURSOR_NORMAL);
		keyboard = new KeyboardHandler();
	}
	return *keyboard;
}

void KeyboardHandler::destroyKeyboard()
{
	KeyboardHandler* keyboard = &getKeyboard();
	delete keyboard;
	keyboard = NULL;
}

bool KeyboardHandler::getKeyState(int key)
{
	return KEYS[key];
}
