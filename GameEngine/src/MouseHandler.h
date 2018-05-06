#ifndef _MOUSEHANDLER_H
#define _MOUSEHANDLER_H
#include <stdio.h>
#include <iostream>
#include <glfw3.h>

/*
	Handles mouse input.
	This class is a singleton
*/
class MouseHandler
{
private:

	/*
		Creates a new MouseHandler
	*/
	MouseHandler();

	/*
		Destroys the MouseHandler
	*/
	~MouseHandler();

	/*
		Callback function for the cursors position
		@param window A pointer to the window
		@param x The x position of the mouse
		@param y The y position of the mouse
	*/
	void cursor_position_callback(GLFWwindow* window, double x, double y);

	/*
		Callback function for the mouse button
		@param window A pointer to the window
		@param button The button code of the button in question
		@param action The action the button is taking
		@param mods Additional information
	*/
	void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);

	/*
		Callback function for the mouse scrollwheel
		@param window A pointer to the window
		@param x The x position of the mouse
		@param y The y position of the mouse
	*/
	void scroll_callback(GLFWwindow* window, double x, double y);


	double _x; // stores the x position of the mouse
	double _y; // stores the y position of the mouse
	GLFWimage* image; // store an image icon of the mouse to render where the mouse is
	bool MOUSE[12]; // stores the states of the mouse buttons
public:

	/*
		Returns the x position of the mouse
		@return Returns the x position of the mouse
	*/
	double getX();

	/*
		Returns the y position of the mouse
		@return Returns the y position of the mouse
	*/
	double getY();

	/*
		Returns the state of a button
		@param button The button to get the state of
		@return Returns the state of the button
	*/
	bool getMouseState(int button);

	/*
		Returns the single instance of the MouseHandler
		@return Returns the only instance of a MouseHandler
	*/
	static MouseHandler& getMouse(); 

	/*
		Destroys the mouse
	*/
	static void destroyMouse(); 

	/*
		Callback function used as a pointer for the mouse's position
		@param window A pointer to the window
		@param x The x position of the mouse
		@param y The y position of the mouse
	*/
	static void cursor_position_callbackFun(GLFWwindow* window, double x, double y); // the callback function used as a pointer

	/*
		Callback function used as a pointer for the mouse's buttons
		@param window A pointer to the window
		@param button The button in question
		@param action The action the button took
		@param mods Additional information
	*/
	static void mouse_button_callbackFun(GLFWwindow* window, int button, int action, int mods); // the callback function used as a pointer

	/*
		Callback function used as a pointer for the scrollwheel
		@param window A pointer to the window
		@param x The x position of the mouse
		@param y The y position of the mouse
	*/
	static void scroll_callbackFun(GLFWwindow* window, double x, double y); // the callback function used as a pointer
};

#endif