#include "Game.h"
#include<iostream>
#include <cstdlib>
#include <ctime>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

//Private functions
void Game::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(1400, 1000), "Battle game", sf::Style::Close | sf::Style::Titlebar);
	this->window->setFramerateLimit(144);
	this->window->setVerticalSyncEnabled(false);
}

void Game::initTexture()
{
	this->textures["SWORD"] = new sf::Texture();
	this->textures["SWORD"]->loadFromFile("27.png");

	this->textures["KATANA"] = new sf::Texture();
	this->textures["KATANA"]->loadFromFile("34.png");

	this->textures["SHURIKEN"] = new sf::Texture();
	this->textures["SHURIKEN"]->loadFromFile("2.png");

	this->textures["SPEAR"] = new sf::Texture();
	this->textures["SPEAR"]->loadFromFile("43.png");

	this->textures["DAGGER"] = new sf::Texture();
	this->textures["DAGGER"]->loadFromFile("37.png");

	//initialize texture of enemy:
	// Load textures for enemies
	this->textures["ENEMY_1"] = new sf::Texture();
	this->textures["ENEMY_1"]->loadFromFile("enemy_1.png");

	this->textures["ENEMY_2"] = new sf::Texture();
	this->textures["ENEMY_2"]->loadFromFile("enemy_2.png");

	this->textures["ENEMY_3"] = new sf::Texture();
	this->textures["ENEMY_3"]->loadFromFile("enemy_3.png");
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

	for (auto& k : this->enemyTextures)
	{
		delete k.second;
	}

	for (auto* i : this->weapons)
	{
		delete i;
	}

	//Delete enemies
	for (auto* enemy : this->enemies){
		delete enemy;
	}
}

//Functions
void Game::run()
{
	while (this->window->isOpen())
	{
		this->pollEvent();
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
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		this->player->movement(-1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		this->player->movement(1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		this->player->movement(0.f, -1.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		this->player->movement(0.f, 1.f);

	//big sword
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1) && 
		this->player->canAttack1())
	{
		this->weapons.push_back(
			new BigSword(
				this->textures["SWORD"],
				1.f,
				0.f,
				this->player->getPosition().x,
				this->player->getPosition().y,
				2.f,
				50
			)
		);

	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)){
		std::cout << "normal attack is on cooldown" << std::endl;
	}

	//katana
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2) &&
		this->player->canAttackna())
	{
		this->weapons.push_back(
			new katana(
				this->textures["KATANA"],
				1.f,
				0.f,
				this->player->getPosition().x,
				this->player->getPosition().y,
				4.f,
				30
			)
		);

	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) {
		std::cout << "normal attack is on cooldown" << std::endl;
	}

	//Shuriken
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3) &&
		this->player->canAttack2())
	{
		this->weapons.push_back(
			new Dagger(
				this->textures["SHURIKEN"],
				1.f,
				0.f,
				this->player->getPosition().x,
				this->player->getPosition().y,
				8.f,
				15
			)
		);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)) {
		std::cout << "normal attack is on cooldown" << std::endl;
	}

	//Spear
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4) &&
		this->player->canAttack2())
	{
		this->weapons.push_back(
			new Spear(
				this->textures["SPEAR"],
				1.f,
				0.f,
				this->player->getPosition().x,
				this->player->getPosition().y,
				5.f,
				25
			)
		);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4)) {
		std::cout << "normal attack is on cooldown" << std::endl;
	}

	//Spear
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5) &&
		this->player->canAttack2())
	{
		this->weapons.push_back(
			new Dagger(
				this->textures["SPEAR"],
				1.f,
				0.f,
				this->player->getPosition().x,
				this->player->getPosition().y,
				5.f,
				25
			)
		);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5)) {
		std::cout << "normal attack is on cooldown" << std::endl;
	}
}

//void Game::choosingSkill()
//{
//	int index1;
//	std::cout << "Choosing your first skill" << std::endl;
//	std::cout << "1. Big sword" << std::endl;
//	std::cin >> index1;
//	sk1 = index1;
//
//}

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

	//update enemy:
	this->updateEnemies();
	//update combat
	this->updateCombat();
}



void Game::render()
{
	this->window->clear();

	//Draw world

	//Draw all the stuffs
	this->player->render(*this->window);
	for (auto* bullet : this->weapons)
	{
		bullet->render(this->window);
	}
	renderEnemies();

	this->window->display();
}

void Game::spawnEnemy(){
	//direction is set as default from right to left:
	float dirX = -1.f;
	float dirY = 0.f;

	float startX = this->window->getSize().x;								// Start at the far right
	float startY = static_cast<float>(rand() % this->window->getSize().y);  // Random Y position

	// Randomly select a texture for the enemy
	int randomType = rand() % 3;											//choose random between 3 types
	if (randomType == 0) { 
		enemies.push_back(new Enemy(this->textures["ENEMY_1"], 0.1f, 0.1f, dirX, dirY, startX, startY, 100 , 1.5f, 30, 10));
	}
	else if (randomType == 1) { 
		enemies.push_back(new Enemy(this->textures["ENEMY_2"], 0.2f, 0.2f, dirX, dirY, startX, startY, 200, 2.0f, 40, 20));
	}
	else if (randomType == 2) { 
		enemies.push_back(new Enemy(this->textures["ENEMY_3"], 0.3f, 0.3f, dirX, dirY, startX, startY, 300, 2.5f, 50, 30));
	}
}

void Game::updateEnemies(){
	//mechanism to spawn enemies
	static sf::Clock spawnTimer;
	if (spawnTimer.getElapsedTime().asSeconds() > 5.f) { // Spawn every 5 seconds
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

void Game::updateCombat(){
	for (int i = this->weapons.size() - 1; i >= 0; --i)
	{
		bool weaponRemoved = false;			//variable to check if the weapon is erased

		for (int j = this->enemies.size() - 1; j >= 0; --j)
		{
			if (this->weapons[i]->getBound().intersects(this->enemies[j]->getBounds())){
				//subtract enemy health
				this->enemies[j]->setCurrentHp(enemies[j]->getCurrentHp() - this->weapons[i]->getDamage());

				//delete enemy when collison happen and hp of enemy reach 0
				if (this->enemies[j]->getCurrentHp() <= 0) {
					this->point += enemies[j]->getPoint();
					delete this->enemies[j];
					this->enemies.erase(enemies.begin() + j);

					//delete weapon when collison happen 
					delete this->weapons[i];
					this->weapons.erase(this->weapons.begin() + i);
					weaponRemoved = true;
					break; // Exit enemy loop as weapon is deleted
				}
			}
		}

		// Skip further processing of this weapon if it was removed
		if (weaponRemoved) {
			continue;
		}
	}

	// Player-Enemy Collisions
	for (int j = this->enemies.size() - 1; j >= 0; --j) {
		if (this->player->getBounds().intersects(this->enemies[j]->getBounds())) {
			this->player->setCurrentHp(this->player->getCurrentHp() - (this->enemies[j]->getDamage()));
			std::cout << "Player gets hit: -" << this->enemies[j]->getDamage() << "damage \n";

			if (this->player->getCurrentHp() <= 0) {
				this->player->setCurrentHp(0);
				std::cout << "Player is dead\n";
			}
			//remove enemy when collison happen
			delete this->enemies[j];
			this->enemies.erase(enemies.begin() + j);
		}
	}
}

void Game::renderEnemies(){
	for (auto* enemy : this->enemies) {
		enemy->render(this->window);
	}
}

