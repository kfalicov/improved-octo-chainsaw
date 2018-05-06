#include "Game.h"



Game::Game(int width, int height) : 
	_width(width), 
	_height(height),
	_inputHandler(&InputHandler::getInputHandler())
{
	_entities = new std::vector<Entity*>();
	_loader = new Loader();
	_camera = new Camera(glm::vec3(0,0,0));
	_staticShader = new StaticShader("./res/shaders/vertexShader.vs", "./res/shaders/fragmentShader.fs");
	glm::mat4* projectionMatrix = new glm::mat4();
	createProjectionMatrix(projectionMatrix);
	_staticShader->bind();
	_staticShader->loadProjectionMatrix(*projectionMatrix);
	_staticShader->unbind();
	_renderer = new Renderer();

	// vertices, texturecoords, and indices for a cube
	float vertices[] = {
		-0.5f,0.5f,-0.5f,
		-0.5f,-0.5f,-0.5f,
		0.5f,-0.5f,-0.5f,
		0.5f,0.5f,-0.5f,

		-0.5f,0.5f,0.5f,
		-0.5f,-0.5f,0.5f,
		0.5f,-0.5f,0.5f,
		0.5f,0.5f,0.5f,

		0.5f,0.5f,-0.5f,
		0.5f,-0.5f,-0.5f,
		0.5f,-0.5f,0.5f,
		0.5f,0.5f,0.5f,

		-0.5f,0.5f,-0.5f,
		-0.5f,-0.5f,-0.5f,
		-0.5f,-0.5f,0.5f,
		-0.5f,0.5f,0.5f,

		-0.5f,0.5f,0.5f,
		-0.5f,0.5f,-0.5f,
		0.5f,0.5f,-0.5f,
		0.5f,0.5f,0.5f,

		-0.5f,-0.5f,0.5f,
		-0.5f,-0.5f,-0.5f,
		0.5f,-0.5f,-0.5f,
		0.5f,-0.5f,0.5f

	};

	float textureCoords[] = {
		0,0,
		0,1,
		1,1,
		1,0,
		0,0,
		0,1,
		1,1,
		1,0,
		0,0,
		0,1,
		1,1,
		1,0,
		0,0,
		0,1,
		1,1,
		1,0,
		0,0,
		0,1,
		1,1,
		1,0,
		0,0,
		0,1,
		1,1,
		1,0
	};

	int indices[] = {
		0,1,3,
		3,1,2,
		4,5,7,
		7,5,6,
		8,9,11,
		11,9,10,
		12,13,15,
		15,13,14,
		16,17,19,
		19,17,18,
		20,21,23,
		23,21,22

	};

	tmpMesh = _loader->loadObj("./res/models/stall.obj");//_loader->loadMesh(vertices, indices, textureCoords, size_of(vertices) ,size_of(indices));
	Texture* texture = new Texture(_loader->loadTexture("./res/textures/stallTexture_preview.png"));
	tmpTexturedMesh = new TexturedMesh(tmpMesh, texture);

	Entity* testEntity = new TexturedEntity(glm::vec3(0,0,-25),0,0,0,1,tmpTexturedMesh);
	_entities->push_back(testEntity);
}


Game::~Game()
{
}

void Game::update()
{

	// loops through all of the entities and updates them
	for (int i = 0; i < _entities->size(); i++)
	{
		Entity* entity = _entities->at(i);
		entity->update();
	}
}

void Game::render()
{
	// clears the screen
	_renderer->clearScreen();


	_staticShader->bind();
	_staticShader->loadViewMatrix(_camera);
	_renderer->draw(_entities, _staticShader);
	_staticShader->unbind();
}


void Game::destroyGame()
{
	delete _loader;
	delete _staticShader;
	delete _entities;
	delete _renderer;
	delete _camera;

	_loader = NULL;
	_staticShader = NULL;
	_entities = NULL;
	_renderer = NULL;
	_camera = NULL;
	_inputHandler->destroyInputHandler();
	_inputHandler = NULL;
}