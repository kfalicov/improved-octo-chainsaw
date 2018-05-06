
#include <glm/glm.hpp>
#include <stdlib.h>
#include <stdio.h>
#include <glew.h>
#include <glfw3.h>
#include <iostream>
#include "Game.h"

//Update Rate
#define Updates_Per_Second 60.0f

int main()
{
	printf("Initializing FFW-Axle\n");
	int width = 1366;
	int height = 768;

	if (!glfwInit())
	{
		printf("ERROR: %s\n", "GLFW Failed to initialize");
		exit(EXIT_FAILURE);
	}

	// Gets the primary monitor for fullscreen mode
	GLFWmonitor* primary = glfwGetPrimaryMonitor();
	int monitorCount;
	GLFWmonitor** monitors = glfwGetMonitors(&monitorCount); // Used for multimonitor setup
	std::cout << "There are : " << monitorCount << " monitors.\n";

	//fullscreen settings
	const GLFWvidmode* mode = glfwGetVideoMode(primary);
	glfwWindowHint(GLFW_RED_BITS, mode->redBits);
	glfwWindowHint(GLFW_GREEN_BITS, mode->greenBits);
	glfwWindowHint(GLFW_BLUE_BITS, mode->blueBits);
	glfwWindowHint(GLFW_REFRESH_RATE, mode->refreshRate);
	glfwWindowHint(GLFW_ALPHA_BITS, 8);
	glfwWindowHint(GLFW_SAMPLES, (8 + mode->redBits + mode->greenBits + mode->blueBits));


	//GLFWwindow* window = glfwCreateWindow(width, height, "GLFW TEST", primary, NULL); //Good for full screen release build
	GLFWwindow* window = glfwCreateWindow(width, height, "FFW-Axle", NULL, NULL); //Good for windowed mode

	if (!window)
	{
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
	glfwMakeContextCurrent(window);


	GLint GlewInitResult = glewInit();
	if (GLEW_OK != GlewInitResult)
	{
		printf("ERROR: %s\n", glewGetErrorString(GlewInitResult));
		exit(EXIT_FAILURE);
	}
	//Calculate timing for update rate
	double lastTime = glfwGetTime();
	double deltaTime = 0.0f;
	bool msaa = false;

	Game* game = new Game(width, height);

	//Main game loop
	while (!glfwWindowShouldClose(window))
	{
		//Viewport
		float ratio;
		int w, h;
		glfwGetFramebufferSize(window, &w, &h);
		ratio = w / (float)h;
		glViewport(0, 0, w, h);

		// Updates the update timer
		double currentTime = glfwGetTime();
		deltaTime += (currentTime - lastTime) * Updates_Per_Second;
		lastTime = currentTime;

		//Clears buffers
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glLoadIdentity();
		while (deltaTime >= 1.0f / Updates_Per_Second)
		{
			//update the game
			game->update();
			--deltaTime;
		}
		//render
		game->render();
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	game->destroyGame();
	glfwDestroyWindow(window); // Frees the memory the window is using
	glfwTerminate(); // Frees the memory glfw is using
					 //system("PAUSE"); //Just if you want to pause console at end



	return 0;
}