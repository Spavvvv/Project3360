#include "Player.h"
#include<iostream>

void Player::initTexture()
{
	if (!texture.loadFromFile("enemy_3.png"))
	{
		std::cout << "Could not load the character file" << std::endl;
	}
}

void Player::initSprite()
{
	this->sprite.setTexture(this->texture);
	this->currentFrame = sf::IntRect(0, 64, 128, 64);
	this->sprite.setTextureRect(currentFrame);
	this->sprite.scale(2.f, 2.f);
	this->sprite.setPosition(30.f, 500.f);
}

void Player::initVar()
{
	this->speed = 3.f;
	this->hpmax = 100;
	this->hp = this->hpmax;
	this->cooldownnormalAttackmax = 20.f;
	this->cooldownSkill1max = 10.f;
	this->cooldownSkill2max = 50.f;
	this->cooldownSkill3max = 100.f;
	this->cooldownnormalAttack = cooldownnormalAttackmax;
	this->cooldownSkill1 = cooldownSkill1max;
	this->cooldownSkill2 = cooldownSkill2max;
	this->cooldownSkill3 = cooldownSkill3max;
}

Player::Player()
{
	this->initTexture();
	this->initSprite();
	this->initVar();
}

Player::~Player()
{
}

const sf::Vector2f Player::getPosition()
{
	return this->sprite.getPosition();
}


void Player::update()
{ 
	this->updateTimena();
	this->updateTime1();
	this->updateTime2();
	this->updateTime3();
}

void Player::movement(const float dirX, const float dirY)
{
	this->sprite.move(dirX * speed, dirY * speed);
}

void Player::render(sf::RenderTarget & tar)
{
	tar.draw(this->sprite);
}

const sf::FloatRect Player::getBounds() const {
	return this->sprite.getGlobalBounds();
}

int Player::getCurrentHp()
{
	return this->hp;
}

void Player::setCurrentHp(int hp)
{
	this->hp = hp;
}


void Player::updateTimena()
{
	if (this->cooldownnormalAttack < this->cooldownnormalAttackmax)
	{
		cooldownnormalAttack += 0.2f;
	}
}

void Player::updateTime1()
{
	if (this->cooldownSkill1 < this->cooldownSkill1max)
	{
		cooldownSkill1 += 0.2f;
	}
}

void Player::updateTime2()
{
	if (this->cooldownSkill2 < this->cooldownSkill2max)
	{
		cooldownSkill2 += 0.2f;
	}
}

void Player::updateTime3()
{
	if (this->cooldownSkill3 < this->cooldownSkill3max)
	{
		cooldownSkill3 += 0.2f;
	}
}

bool Player::canAttackna()
{
	if (this->cooldownnormalAttack >= this->cooldownnormalAttackmax)
	{
		cooldownnormalAttack = 0.f;
		return true;
	}
	else
	{
		return false;
	}
}

bool Player::canAttack1()
{
	if (this->cooldownSkill1 >= this->cooldownSkill1max)
	{
		cooldownSkill1 = 0.f;
		return true;
	}
	else
	{
		return false;
	}
}

bool Player::canAttack2()
{
	if (this->cooldownSkill2 >= this->cooldownSkill2max)
	{
		cooldownSkill2 = 0.f;
		return true;
	}
	else
	{
		return false;
	}
}

bool Player::canAttack3()
{
	if (this->cooldownSkill3 >= this->cooldownSkill3max)
	{
		cooldownSkill3 = 0.f;
		return true;
	}
	else
	{
		return false;
	}
}