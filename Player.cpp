#include "Player.h"
#include<iostream>

void Player::initTexture()
{
	if (!texture.loadFromFile("texture\\Samurai\\idle.png"))
	{
		std::cout << "Could not load the character file" << std::endl;
	}
	if (!texture2.loadFromFile("texture\\Samurai\\run.png"))
	{
		std::cout << "Could not load the character file" << std::endl;
	}
	if (!texture3.loadFromFile("texture\\Samurai\\Attack_1.png"))
	{
		std::cout << "Could not load the character file" << std::endl;
	}
	if (!texture4.loadFromFile("texture\\Samurai\\Attack_2.png"))
	{
		std::cout << "Could not load the character file" << std::endl;
	}
	if (!texture5.loadFromFile("texture\\Samurai\\Attack_3.png"))
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

void Player::initAnimation()
{
	this->animationTime.restart();
}
void Player::initVar()
{
	this->animateStatus = PLAYER_ANIMATION_STATUS::IDLE;
	this->attacking = false;
	this->jumping = false;
	this->moving = false;
	this->speed = 3.f;
	this->hpmax = 100;
	this->hp = this->hpmax;
	this->cooldownnormalAttackmax = 20.f;
	this->cooldownSkill1max = 50.f;
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
	this->initAnimation();
}

Player::~Player()
{
}

const sf::Vector2f Player::getPosition()
{
	return this->sprite.getPosition();
}
void Player::updateAnimation()
{
	if (this->animateStatus == PLAYER_ANIMATION_STATUS::IDLE)
	{
		if (animationTime.getElapsedTime().asSeconds() >= 0.2f)
		{
			this->currentFrame.left += 128.f;
			if (this->currentFrame.left >= 640.f)
			{
					this->currentFrame.left = 0.f;
			}
			this->animationTime.restart();
			this->sprite.setTexture(texture);
			this->sprite.setTextureRect(currentFrame);
		}
	} else if (this->animateStatus == PLAYER_ANIMATION_STATUS::MOVING_RIGHT)
	{
		if (animationTime.getElapsedTime().asSeconds() >= 0.1f)
		{
			this->currentFrame.left += 128.f;
			if (this->currentFrame.left >= 896.f)
			{
				this->currentFrame.left = 0.f;
			}
			this->animationTime.restart();
			this->sprite.setTexture(texture2);
			this->sprite.setTextureRect(currentFrame);
		}
		this->sprite.setScale(2.f, 2.f);
		this->sprite.setOrigin(0.f, 0.f);
	} else if (this->animateStatus == PLAYER_ANIMATION_STATUS::MOVING_LEFT)
	{
		if (animationTime.getElapsedTime().asSeconds() >= 0.1f)
		{
			this->currentFrame.left += 128.f;
			if (this->currentFrame.left >= 896.f)
			{
				this->currentFrame.left = 0.f;
			}
			this->animationTime.restart();
			this->sprite.setTexture(texture2);
			this->sprite.setTextureRect(currentFrame);
		}
		this->sprite.setScale(-2.f, 2.f);
		this->sprite.setOrigin(this->sprite.getGlobalBounds().width / 3.f, 0.f);
	} else if (this->animateStatus == PLAYER_ANIMATION_STATUS::ATTACKING)
	{
		if (animationTime.getElapsedTime().asSeconds() >= 0.2f)
		{
			this->currentFrame.left += 128.f;
			if (this->currentFrame.left >= 384.f)
			{
				this->currentFrame.left = 0.f;
				waitTimeanimation();
				this->animateStatus = PLAYER_ANIMATION_STATUS::IDLE;
			}
			this->animationTime.restart();
			this->sprite.setTexture(texture3);
			this->sprite.setTextureRect(currentFrame);
		}
	}
	else if (this->animateStatus == PLAYER_ANIMATION_STATUS::ATTACKING2)
	{
		if (animationTime.getElapsedTime().asSeconds() >= 0.2f)
		{
			this->currentFrame.left += 128.f;
			if (this->currentFrame.left >= 512.f)
			{
				this->currentFrame.left = 0.f;
				waitTimeanimation();
				this->animateStatus = PLAYER_ANIMATION_STATUS::IDLE;
			}
			this->animationTime.restart();
			this->sprite.setTexture(texture4);
			this->sprite.setTextureRect(currentFrame);
		}
	}
	else if (this->animateStatus == PLAYER_ANIMATION_STATUS::ATTACKING3)
	{
		if (animationTime.getElapsedTime().asSeconds() >= 0.2f)
		{
			this->currentFrame.left += 128.f;
			if (this->currentFrame.left >= 384.f)
			{
				this->currentFrame.left = 0.f;
				waitTimeanimation();
				this->animateStatus = PLAYER_ANIMATION_STATUS::IDLE;
			}
			this->animationTime.restart();
			this->sprite.setTexture(texture5);
			this->sprite.setTextureRect(currentFrame);
		}
	}

}
void Player::waitTimeanimation()
{
	if (this->animationTime.getElapsedTime().asSeconds() >= 5.f) {
		this->animateStatus = PLAYER_ANIMATION_STATUS::IDLE;
		this->animationTime.restart(); // Reset time after switching to idle
	}
}
void Player::update()
{ 
	this->updateAnimation();
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

const sf::FloatRect Player::globalBound() const
{
	return this->sprite.getGlobalBounds();
}


// combat

int Player::getCurrentHp()
{
	return this->hp;
}

void Player::setCurrentHp(int hp)
{
	this->hp = hp;
}
