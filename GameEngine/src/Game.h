#ifndef _GAME_H
#define _GAME_H
#include "Renderer.h"
#include "Loader.h"
#include "EventManager.h"
#include "StaticShader.h"
#include "TexturedEntity.h"
#include "Util.h"

/*
	Puts everything together
*/
class Game
{
public:

	/*
		Creates a new game
		@param width The width of the window
		@param height The height of the window
	*/
	Game(int width, int height);

	/*
		Destroys the game
	*/
	~Game();
	
	/*
		Controls all of the logic in the game and is called a certain number of times per second
	*/
	void update(); 

	/*
		Renders the game to the screen
	*/
	void render();

	/*
		Cleans up memory used by the game
	*/
	void destroyGame();

private:
	int _width;
	int _height;
	EventManager* _EventManager;
	Camera* _camera;

	Renderer* _renderer;
	Loader* _loader;
	StaticShader* _staticShader;

	Mesh* tmpMesh; // tmp
	TexturedMesh* tmpTexturedMesh; // tmp

	std::vector<Entity*>* _entities; // stores all of the entities currently in the game
protected:

};

#endif