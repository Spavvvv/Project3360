#include "Engine.h"
#include <random>
//defined some specific things
const unsigned int cWidth = 800;
const unsigned int cHeight = 600;

void Engine::initWindow() {
	videoMode.height = cHeight;
	videoMode.width = cWidth;


	window = new sf::RenderWindow(videoMode, "Testing", sf::Style::Titlebar | sf::Style::Close);
}


void Engine::running() {
	while (window->isOpen()) {

		render();

		while (window->pollEvent(ev)) {

			switch (ev.type)
			{
			case sf::Event::Closed:
				window->close();
				break;
			case sf::Event::KeyPressed:
				if (ev.key.code == sf::Keyboard::Escape)
					window->close();
				break;


			default:
				break;
			}
		}
	}
}

Engine::Engine() {
	initWindow();
	running();
}


void Engine::render() {
	std::random_device rd;
	std::mt19937 generator(rd());
	
	std::uniform_int_distribution<int> distribution(0, 255);

	int r = distribution(generator);
	int g = distribution(generator);
	int b = distribution(generator);

	window->clear(sf::Color(r,g,b,0.5));

	window->display();
}

Engine::~Engine() {
	delete window;
}