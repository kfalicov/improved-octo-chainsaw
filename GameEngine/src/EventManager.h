#ifndef _EVENT_MANAGER_H
#define _EVENT_MANAGER_H
#include <stdio.h>
#include <map>
#include <glm\glm.hpp>
#include <glfw3.h>
#include <iostream>
#include <stdio.h>

/*
	Wrapper class. This is a singleton
	This wraps around the keyboard, mouse, and gamepad input handlers
*/
class EventManager
{
public:

	//	Destructor
	~EventManager();

	//	Returns the only instance of EventManager
	static EventManager& getEventManager();

	//	Destroys the only instance of EventManager
	static void destroyEventManager();

	//	handles key callbacks only when a key press event is detected
	static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

	static void cursorPosCallback(GLFWwindow * window, double x, double y);

	static void mouseButtonCallback(GLFWwindow * window, int button, int action, int mods);

	static void scrollCallback(GLFWwindow * window, double x, double y);

	//	 returns the current press state of the requested key
	bool getKeyState(int key);

	//	returns the mouse cursor coordinates
	double getX();
	double getY();

	//	returns the change in mouse cursor coordinates from the last
	double getDX();
	double getDY();

	void disposeDeltas();

protected:

private:

	//	an array of keys is fast, and will support keybindings in the future
	static bool KEYS[348];

	static double _x; // stores the x position of the mouse
	static double _y; // stores the y position of the mouse

	static double _dx; // stores the change in x position of the mouse
	static double _dy; // stores the ghange in y position of the mouse

	//	stores the states of the mouse buttons
	static bool MOUSE[12];

	//	Creates a new EventManager
	EventManager(); 

};

#endif