#pragma once

#include<vector>
#include<map>
#include <sstream>
#include <iostream>
#include <string>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>


#include"Player.h"
#include"Weapon.h"
#include"katana.h"
#include"suriken.h"
#include"bigSword.h"
#include"Enemy.h"

//Include for mainMenu and playingMenu, this is a mess so i dont want to touch it
#include "User.h"
#include "Mainmenu.h"
#include "playMenu.h"
#include "Event.h"



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
	void initTexture(const playMenu& skillManager);

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
	bool canUsekeyBoard;

	playMenu* menu;
	std::vector<sf::String> selectedSkills;
	User* user;

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
	void initMenu();

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
	void updateCollision();
	void saveGame();
	bool getEndGame() const;

	void spawnEnemy();           // Method to spawn a new enemy
	void updateEnemies();        // Update all enemies
	void updateCombat();
	void renderEnemies();        // Render all enemies

};

