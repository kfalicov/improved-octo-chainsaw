#include "EventManager.h"

bool EventManager::KEYS[348];
bool EventManager::MOUSE[12];
double EventManager::_x;
double EventManager::_y;
double EventManager::_dx;
double EventManager::_dy;


EventManager::EventManager()
{
	for (int i = 0; i < 348; i++)
	{
		KEYS[i] = false;
	}
	for (int i = 0; i < 12; i++) // sets all of the mouse buttons to the up state
	{
		MOUSE[i] = false;
	}
}


EventManager::~EventManager()
{
}


EventManager& EventManager::getEventManager()
{
	static EventManager* handler = NULL;
	if (handler == NULL)
	{
		//	init keyboard callbacks
		glfwSetKeyCallback(glfwGetCurrentContext(), *keyCallback);

		//	init mouse callbacks
		glfwSetCursorPosCallback(glfwGetCurrentContext(), *cursorPosCallback);
		glfwSetMouseButtonCallback(glfwGetCurrentContext(), *mouseButtonCallback);
		glfwSetScrollCallback(glfwGetCurrentContext(), *scrollCallback);
		glfwSetInputMode(glfwGetCurrentContext(), GLFW_CURSOR, GLFW_CURSOR_NORMAL);
		handler = new EventManager();		
	}
	return *handler;
}

void EventManager::destroyEventManager()
{
	EventManager* manager = &getEventManager();
	delete manager; // frees the memory of the handler
	manager = NULL;

	//delete &KEYS;
}

void EventManager::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (action == GLFW_PRESS) // if the key has been pressed it sets the key to true which is down
	{
		KEYS[key] = true;
		std::cout << "pressed " << key << std::endl;
	}
	else if (action == GLFW_RELEASE) // if the key has been released it sets the key to false which is up
	{
		KEYS[key] = false;
		std::cout << "released " << key << std::endl;
	}
	else // if the key has been 'repeated' it's still technically pressed (repeating is only for typing, which we don't need)
	{
		//KEYS[key] = true;
		//std::cout << "repeated " << key << std::endl;
	}
}

void EventManager::cursorPosCallback(GLFWwindow* window, double x, double y) {
	_dx = x - _x;
	_dy = y - _y;
	_x = x;
	_y = y;
	std::cout << _dx << ", " << _dy << std::endl;
}

void EventManager::mouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
{
	// 0 is left mouse
	// 1 is right mouse
	// 2 is middle mouse
	if (action == GLFW_PRESS) // If the button has been pressed set it to true
	{
		MOUSE[button] = true;
		std::cout << "pressed " << button << std::endl;
	}
	else // else set the button to false
	{
		MOUSE[button] = false;
		std::cout << "released " << button << std::endl;
	}
}

void EventManager::scrollCallback(GLFWwindow* window, double x, double y) {
	//	TODO add something here if necessary
}

// returns the press state of the key
bool EventManager::getKeyState(int key)
{
	return KEYS[key];
}

double EventManager::getX()
{
	return _x;
}
double EventManager::getY()
{
	return _y;
}