#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include<vector>
#include<map>
#include"Player.h"
#include"Weapon.h"
#include"katana.h"
#include"suriken.h"
#include"bigSword.h"
class Game
{
private:
	sf::RenderWindow* window;
	sf::VideoMode vid;
	sf::Event event;
	std::map<sf::String, sf::Texture*> textures;
	std::vector<Weapon*> weapons;
	Player* player;
	// game logic
	
	void initWindow();
	void initPlayer();
	void initTexture();
public:
	int sk1 = 0;
	Game();
	virtual ~Game();
	void pollEvent();
	void render();
	void renderPlayer();
	void updateMovement();
	void choosingSkill();
	void updateWeapon();
	void update();
	void run();
};

