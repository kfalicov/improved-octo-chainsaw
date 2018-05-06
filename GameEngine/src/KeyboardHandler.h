#ifndef _KEYBOARD_HANDLER
#define _KEYBOARD_HANDLER
#include <stdio.h>
#include <iostream>
#include <glfw3.h>

/*
	Handles keyboard input from the user.
	This class is a singleton class
*/
class KeyboardHandler
{
private:
	
	/*
		Creates a new KeyboardHandler
	*/
	KeyboardHandler(); 

	/*
		Destroys the KeyboardHandler
	*/
	~KeyboardHandler();

	/*
		Handles keyboard callbacks (Helper function)
		@param window A pointer to the window 
		@param key The key code
		@param scancode The scan code
		@param action The action taken by the key
		@param mods Additional info
	*/
	void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods); // handles keyboard callbacks
	bool KEYS[348]; // stores the state of the keys on the keyboard
public:
	/*
		Returns a pointer to the single instance of the KeyboardHandler
		@return Returns the only instance of a KeyboardHandler
	*/
	static KeyboardHandler& getKeyboard();

	/*
		Destroys the only instance of a KeyboardHandler
	*/
	static void destroyKeyboard();

	/*
		The call back function used as a pointer
		@param window A pointer to the window 
		@param key The key code
		@param scancode The scan code
		@param action The action taken by the key
		@param mods Additional info
	*/
	static void keyCallbackFun(GLFWwindow* window, int key, int scancode, int action, int mods); 

	/*
		Returns the state of a key
		@param key the keycode to check
		@return Returns the state of the key in question
	*/
	bool getKeyState(int key);
};

#endif