#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>


class Engine
{
private:

	//window
	sf::RenderWindow* window = nullptr;
	sf::VideoMode videoMode;
	sf::Event ev;


	//set special value
	


	//function 
	void initWindow();
	
public:
	//Init 
	Engine();

	//running the program
	void running();

	//render
	void render();

	//Destructor
	~Engine();
};

