#include "MouseHandler.h"

MouseHandler::MouseHandler()
	: _x(0), _y(0)
{
	for (int i = 0; i < 12; i++) // sets all of the mouse buttons to the up state
	{
		MOUSE[i] = false;
	}
}


MouseHandler::~MouseHandler()
{

}

double MouseHandler::getX()
{
	return _x;
}
double MouseHandler::getY()
{
	return _y;
}
MouseHandler& MouseHandler::getMouse()
{
	static MouseHandler* mouse = NULL;
	if (mouse == NULL) // if mouse is NULL then a mouse has not been created yet
	{
		glfwSetCursorPosCallback(glfwGetCurrentContext(), *cursor_position_callbackFun);
		glfwSetMouseButtonCallback(glfwGetCurrentContext(), *mouse_button_callbackFun);
		glfwSetScrollCallback(glfwGetCurrentContext(), *scroll_callbackFun);
		glfwSetInputMode(glfwGetCurrentContext(), GLFW_CURSOR, GLFW_CURSOR_NORMAL);
		mouse = new MouseHandler();
	}
	return *mouse;
}
void MouseHandler::destroyMouse()
{
	MouseHandler* mouse = &getMouse();
	delete mouse;
	mouse = NULL;
}
void MouseHandler::cursor_position_callbackFun(GLFWwindow* window, double x, double y)
{
	MouseHandler* mouse = &getMouse();
	mouse->cursor_position_callback(window, x, y); // calls the callback handler
}


void MouseHandler::cursor_position_callback(GLFWwindow* window, double x, double y)
{
	_x = x;
	_y = y;
}

void MouseHandler::scroll_callback(GLFWwindow* window, double x, double y)
{
	// TODO
}

void MouseHandler::mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
	if (action == GLFW_PRESS) // If the button has been pressed set it to true
	{
		MOUSE[button] = true;
	}
	else // else set the button to false
	{
		MOUSE[button] = false;
	}
}


void MouseHandler::mouse_button_callbackFun(GLFWwindow* window, int button, int action, int mods)
{
	MouseHandler* mouse = &getMouse();
	mouse->mouse_button_callback(window, button, action, mods);
}

bool MouseHandler::getMouseState(int button)
{
	return MOUSE[button];
}

void MouseHandler::scroll_callbackFun(GLFWwindow* window, double x, double y)
{
	MouseHandler* mouse = &getMouse();
	mouse->scroll_callback(window, x, y);
}
