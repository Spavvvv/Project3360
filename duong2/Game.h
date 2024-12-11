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
#include"Enemy.h"

#include <sstream>

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

	//enemy
	std::vector<Enemy*> enemies;  // Vector to hold enemy instances
	std::map<sf::String, sf::Texture*> enemyTextures;    // Texture for the enemies
	uint16_t point;

	sf::Font font;
	sf::Text text;
	sf::Text endGameText;

	sf::RectangleShape playerHpBar;
	sf::RectangleShape playerHpBarMax;

	bool endGame = false;

public:
	int sk1 = 0;
	Game();
	virtual ~Game();

	void initFont();
	void initText();
	void initGUI();
	void updateGUI();
	void renderGUI();

	void pollEvent();
	void render();
	void renderPlayer();
	void updateMovement();
	void choosingSkill();
	void updateWeapon();
	void update();
	void run();


	void spawnEnemy();           // Method to spawn a new enemy
	void updateEnemies();        // Update all enemies
	void updateCombat();
	void renderEnemies();        // Render all enemies
};

