﻿#include "Game.h"
#include<iostream>

void Game::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(1400, 1000), "Battle game", sf::Style::Close | sf::Style::Titlebar);
	this->window->setFramerateLimit(60);
	this->window->setVerticalSyncEnabled(false);
}

void Game::initTexture()
{
	this->textures["SWORD"] = new sf::Texture();
	this->textures["SWORD"]->loadFromFile("texture\\png\\weapon\\sword.png");
	this->textures["KATANA"] = new sf::Texture();
	this->textures["KATANA"]->loadFromFile("texture\\png\\weapon\\25.png");
	this->textures["SURIKEN"] = new sf::Texture();
	this->textures["SURIKEN"]->loadFromFile("texture\\png\\weapon\\40.png");


	this->textures["ENEMY_1"] = new sf::Texture();
	this->textures["ENEMY_1"]->loadFromFile("texture\\enemy\\enemy_1.png");

	this->textures["ENEMY_2"] = new sf::Texture();
	this->textures["ENEMY_2"]->loadFromFile("texture\\enemy\\enemy_2.png");

	this->textures["ENEMY_3"] = new sf::Texture();
	this->textures["ENEMY_3"]->loadFromFile("texture\\enemy\\enemy_3.png");
}

void Game::initPlayer()
{
	
	this->player = new Player();
}


//Con/Des
Game::Game()
{
	this->initWindow();
	this->initTexture();
	this->initPlayer();
	initFont();
	initText();
	initGUI();

}

Game::~Game()
{
	delete this->window;
	delete this->player;
	//Delete textures
	for (auto& i : this->textures)
	{
		delete i.second;
	}

	for (auto* i : this->weapons)
	{
		delete i;
	}

	//Delete enemies
	for (auto& k : this->enemyTextures)
	{
		delete k.second;
	}
	for (auto* enemy : this->enemies) {
		delete enemy;
	}
}

void Game::initFont()
{
	if (!font.loadFromFile("C:/Windows/Fonts/Arial.ttf")) {
		std::cout << "Could not load font !" << '\n';
	}
}

void Game::initText()
{
	text.setFont(font);
	text.setCharacterSize(20);
	text.setFillColor(sf::Color::White);
	text.setPosition(sf::Vector2f(30.f, 30.f));

	endGameText.setFont(font);
	endGameText.setCharacterSize(90);
	endGameText.setFillColor(sf::Color::Red);
	endGameText.setString("You are lose, NIGGA !");
	endGameText.setPosition(
	window->getSize().x / 2.f - endGameText.getGlobalBounds().width / 2.f,
	window->getSize().y / 2.f - endGameText.getGlobalBounds().height / 2.f
	);
}

void Game::initGUI()
{

	playerHpBar.setSize(sf::Vector2f(500.f, 25.f));
	playerHpBar.setFillColor(sf::Color::Red);
	playerHpBar.setPosition(sf::Vector2f(30.f, 60.f));

	playerHpBarMax = playerHpBar;
	playerHpBarMax.setFillColor(sf::Color(25,25,25,200));

}

void Game::updateGUI()
{
	std::stringstream ss;

	ss << "Points: " << point;

	text.setString(ss.str());

	//Hp bar
	float hpPercent = static_cast<float>(player->getCurrentHp()) / player->getHpMax();
	playerHpBar.setSize(sf::Vector2f(500.f * hpPercent, playerHpBar.getSize().y));
}

void Game::renderGUI()
{
	window->draw(text);
	window->draw(playerHpBarMax);
	window->draw(playerHpBar);
}

//Functions
void Game::run()
{
	while (this->window->isOpen())
	{
		this->pollEvent();

		if(player->getCurrentHp() > 0)
		this->update();

		this->render();
	}
}

void Game::pollEvent()
{
	sf::Event e;
	while (this->window->pollEvent(e))
	{
		if (e.Event::type == sf::Event::Closed)
			this->window->close();
		if (e.Event::KeyPressed && e.Event::key.code == sf::Keyboard::Escape)
			this->window->close();
	}
}

void Game::updateMovement()
{

	//Move player
	if (this->player->animateStatus != PLAYER_ANIMATION_STATUS::ATTACKING && 
		this->player->animateStatus != PLAYER_ANIMATION_STATUS::ATTACKING2 && 
		this->player->animateStatus != PLAYER_ANIMATION_STATUS::ATTACKING3) {
		this->player->animateStatus = PLAYER_ANIMATION_STATUS::IDLE;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		this->player->movement(-1.f, 0.f);
		this->player->animateStatus = PLAYER_ANIMATION_STATUS::MOVING_LEFT;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		this->player->movement(1.f, 0.f);
		this->player->animateStatus = PLAYER_ANIMATION_STATUS::MOVING_RIGHT;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		this->player->movement(0.f, -1.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		this->player->movement(0.f, 1.f);
	}


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2) && 
		this->player->canAttack1())
	{
		this->player->animateStatus = PLAYER_ANIMATION_STATUS::ATTACKING2;
		if (true)
		{
			this->weapons.push_back(
				new bigSword(
					this->textures["SWORD"],
					1.f,
					0.f,
					this->player->getPosition().x,
					this->player->getPosition().y,
					5.f,
					40
				)
			);
		}
		else
		{
			std::cout << "Pls choose your skill!" << std::endl;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)){
		std::cout << "normal attack is on cooldown" << std::endl;
	}


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1) &&
		this->player->canAttackna())
	{
		this->player->animateStatus = PLAYER_ANIMATION_STATUS::ATTACKING;
		this->weapons.push_back(
			new katana(
				this->textures["KATANA"],
				1.f,
				0.f,
				this->player->getPosition().x,
				this->player->getPosition().y,
				10.f,
				20
			)
		);

	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) {
		std::cout << "normal attack is on cooldown" << std::endl;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3) &&
		this->player->canAttack2())
	{
		this->player->animateStatus = PLAYER_ANIMATION_STATUS::ATTACKING3;
		this->weapons.push_back(
			new suriken(
				this->textures["SURIKEN"],
				1.f,
				0.f,
				this->player->getPosition().x,
				this->player->getPosition().y,
				10.f,
				20
			)
		);
		this->weapons.push_back(
			new suriken(
				this->textures["SURIKEN"],
				1.f,
				0.f,
				this->player->getPosition().x,
				this->player->getPosition().y - 30.f,
				9.f,
				20
			)
		); this->weapons.push_back(
			new suriken(
				this->textures["SURIKEN"],
				1.f,
				0.f,
				this->player->getPosition().x,
				this->player->getPosition().y + 30.f,
				9.f,
				20
			)
		);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)) {
		std::cout << "normal attack is on cooldown" << std::endl;
	}
}


void Game::choosingSkill()
{
	int index1;
	std::cout << "Choosing your first skill" << std::endl;
	std::cout << "1. Big sword" << std::endl;
	std::cin >> index1;
	sk1 = index1;

}
void Game::updateWeapon()
{
	// Duyệt ngược để xóa an toàn
	for (int i = this->weapons.size() - 1; i >= 0; --i)
	{
		Weapon* weapon = this->weapons[i];
		weapon->update();

		// Kiểm tra xem vũ khí có vượt ra ngoài giới hạn màn hình hay không
		if (weapon->getBound().top + weapon->getBound().height < 0.f ||
			weapon->getBound().top > this->window->getSize().y ||
			weapon->getBound().left + weapon->getBound().width < 0.f ||
			weapon->getBound().left > this->window->getSize().x)
		{
			delete weapon; // Giải phóng bộ nhớ
			this->weapons.erase(this->weapons.begin() + i); // Xóa phần tử khỏi vector
		}
	}
}


void Game::update()
{
	this->updateMovement();
	this->player->update();
	this->updateWeapon();
	this->updateEnemies();
	//update combat
	this->updateCombat();


	updateGUI();
}


void Game::render()
{
	this->window->clear();

	//Draw world
	renderPlayer();
	//Draw all the stuffs
	for (auto* bullet : this->weapons)
	{
		bullet->render(this->window);
	}

	//enemy
	renderEnemies();
	renderGUI();

	if (endGame == true) {
		window->draw(endGameText);
	}
	this->window->display();
}

void Game::renderPlayer()
{
	this->player->render(*this->window);

}
void Game::spawnEnemy() {
	//direction is set as default from right to left:
	float dirX = -1.f;
	float dirY = 0.f;

	float startX = this->window->getSize().x;								// Start at the far right
	float startY = static_cast<float>(rand() % this->window->getSize().y);  // Random Y position

	// Randomly select a texture for the enemy
	int randomType = rand() % 3;											//choose random between 3 types
	if (randomType == 0) {
		enemies.push_back(new Enemy(this->textures["ENEMY_1"], 0.1f, 0.1f, dirX, dirY, startX, startY, 15, 1.5f, 30, 10));
	}
	else if (randomType == 1) {
		enemies.push_back(new Enemy(this->textures["ENEMY_2"], 0.2f, 0.2f, dirX, dirY, startX, startY, 20, 2.0f, 40, 20));
	}
	else if (randomType == 2) {
		enemies.push_back(new Enemy(this->textures["ENEMY_3"], 0.3f, 0.3f, dirX, dirY, startX, startY, 25, 2.5f, 50, 30));
	}
}

void Game::updateCombat() {
	for (int i = this->weapons.size() - 1; i >= 0; --i)
	{
		bool weaponRemoved = false;            //variable to check if the weapon is erased

		for (int j = this->enemies.size() - 1; j >= 0; --j)
		{
			if (this->weapons[i]->getBound().intersects(this->enemies[j]->getBounds())) {
				//subtract enemy health
				if (enemies[j]->getCurrentHp() - this->weapons[i]->getDamage() <=0) {
					this->enemies[j]->setCurrentHp(0);
				}
				else
				this->enemies[j]->setCurrentHp(enemies[j]->getCurrentHp() - this->weapons[i]->getDamage());

				//delete enemy when collison happen and hp of enemy reach 0
				if (this->enemies[j]->getCurrentHp() <= 0) {
					this->point += enemies[j]->getPoint();
					delete this->enemies[j];
					this->enemies.erase(enemies.begin() + j);
				}
				//delete weapon when collison happen 
				delete this->weapons[i];
				this->weapons.erase(this->weapons.begin() + i);
				weaponRemoved = true;
				break; // Exit enemy loop as weapon is deleted
			}
		}

		// Skip further processing of this weapon if it was removed
		if (weaponRemoved) {
			continue;
		}
	}

	// Player-Enemy Collisions
	for (int j = this->enemies.size() - 1; j >= 0; --j) {
		if (this->player->globalBound().intersects(this->enemies[j]->getBounds())) {
			this->player->setCurrentHp(this->player->getCurrentHp() - (this->enemies[j]->getDamage()));
			std::cout << "Player gets hit: -" << this->enemies[j]->getDamage() << "damage \n";
			//remove enemy when collison happen
			delete this->enemies[j];
			this->enemies.erase(enemies.begin() + j);

			if (this->player->getCurrentHp() <= 0) {
				this->player->setCurrentHp(0);
				std::cout << "Player is dead\n";
				endGame = true;
			}
		}
		if (endGame == true) {
			break;
		}
	}
}

void Game::updateEnemies() {
	//mechanism to spawn enemies
	static sf::Clock spawnTimer;
	if (spawnTimer.getElapsedTime().asSeconds() > 2.f) { // Spawn every 5 seconds
		this->spawnEnemy();
		spawnTimer.restart();
	}

	for (int i = this->enemies.size() - 1; i >= 0; --i)
	{
		this->enemies[i]->update();

		// Remove enemies that go off-screen
		if (this->enemies[i]->getBounds().top + this->enemies[i]->getBounds().height < 0.f ||
			this->enemies[i]->getBounds().top > this->window->getSize().y ||
			this->enemies[i]->getBounds().left + this->enemies[i]->getBounds().width < 0.f ||
			this->enemies[i]->getBounds().left > this->window->getSize().x)
		{
			delete this->enemies[i];
			this->enemies.erase(this->enemies.begin() + i);
		}
	}
}

void Game::renderEnemies() {
	for (auto* enemy : this->enemies) {
		enemy->render(this->window);
	}
}