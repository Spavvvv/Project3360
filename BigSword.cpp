#include "BigSword.h"

BigSword::BigSword(sf::Texture* text, float dirx, float diry, float posx, float posy, float velocity, int dmg)
	: Weapon(text, dirx, diry, posx, posy, velocity, dmg) {
	this->setScale(0.3f, 0.3f);
	this->setRotation(45.f);
}

