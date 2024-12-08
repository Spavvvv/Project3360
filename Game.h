#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <vector>
#include <map>
#include"Player.h"
#include"Enemy.h"
//weapon
#include"Weapon.h"
#include"katana.h"
#include"BigSword.h"
#include"Shuriken.h"
#include"Dagger.h"
#include"Spear.h"
class Game
{
private:
	sf::RenderWindow* window;
	sf::VideoMode vid;
	sf::Event event;
	std::map<sf::String, sf::Texture*> textures;
	std::vector<Weapon*> weapons;
	Player* player;

	std::vector<Enemy*> enemies;  // Vector to hold enemy instances
	std::map<sf::String, sf::Texture*> enemyTextures;    // Texture for the enemies
	uint16_t point;

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
	void updateMovement();
	/*void updateMovementPlayer2();*/
	/*void choosingSkill();*/
	void updateWeapon();
	void update();
	void run();

	/*
	* enemy logic in Game:
	*/
	void spawnEnemy();           // Method to spawn a new enemy
	void updateEnemies();        // Update all enemies
	void updateCombat();
	void renderEnemies();        // Render all enemies
};

