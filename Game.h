#pragma once

#include<vector>
#include<map>
#include <sstream>
#include <iostream>
#include <string>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>


#include"Player.h"
#include"Weapon.h"
#include"katana.h"
#include"suriken.h"
#include"bigSword.h"
#include"Enemy.h"



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

	//stuffs for ending game
	sf::Font font;
	sf::Text text;
	sf::Text endGameText;
	sf::Text nextStageText;
	sf::Text completeGameText;
	bool endGame;

	//stuff for GUI ingame
	sf::RectangleShape playerHpBar;
	sf::RectangleShape playerHpBarMax;
	
	//stuff for next stage
	int countMonster;
	int countMonsterMax;
	bool nextStage;

	int LEVEL;
	int LEVELMAX;

public:
	int sk1 = 0;
	Game();
	virtual ~Game();

	void initFont();
	void initText();
	void initGUI();
	void updateGUI();
	void renderGUI();
	void initSystem();


	void pollEvent();
	void render();
	void renderPlayer();
	void updateMovement();
	void choosingSkill();
	void updateWeapon();
	void update();
	int run();
	void playerDecision();
	void cleanUpState();
	void CompleteGame();
	void deadAnimiation();


	void spawnEnemy();           // Method to spawn a new enemy
	void updateEnemies();        // Update all enemies
	void updateCombat();
	void renderEnemies();        // Render all enemies

};

