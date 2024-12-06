#include "Game.h"
#include<iostream>
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
	this->textures["SWORD"]->loadFromFile("texture\\png\\weapon\\sword.png");
	this->textures["KATANA"] = new sf::Texture();
	this->textures["KATANA"]->loadFromFile("texture\\png\\weapon\\25.png");
	this->textures["SURIKEN"] = new sf::Texture();
	this->textures["SURIKEN"]->loadFromFile("texture\\png\\weapon\\40.png");
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

	for (auto* i : this->weapons)
	{
		delete i;
	}

	//Delete enemies
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
	if (this->player->animateStatus != PLAYER_ANIMATION_STATUS::ATTACKING) {
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
		this->player->animateStatus = PLAYER_ANIMATION_STATUS::ATTACKING;
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
					10
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
				5
			)
		);

	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) {
		std::cout << "normal attack is on cooldown" << std::endl;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3) &&
		this->player->canAttack2())
	{
		this->player->animateStatus = PLAYER_ANIMATION_STATUS::ATTACKING;
		this->weapons.push_back(
			new suriken(
				this->textures["SURIKEN"],
				1.f,
				0.f,
				this->player->getPosition().x,
				this->player->getPosition().y,
				10.f,
				7
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
				7
			)
		); this->weapons.push_back(
			new suriken(
				this->textures["SURIKEN"],
				1.f,
				0.f,
				this->player->getPosition().x,
				this->player->getPosition().y + 30.f,
				9.f,
				7
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


	this->window->display();
}

void Game::renderPlayer()
{
	this->player->render(*this->window);

}
