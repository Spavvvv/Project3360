#include "Spear.h"

Spear::Spear(sf::Texture* text, float dirx, float diry, float posx, float posy, float velocity, int dmg)
	: Weapon(text, dirx, diry, posx, posy, velocity, dmg) {
	this->setScale(0.25f, 0.25f);
	this->setRotation(45.f);
}
