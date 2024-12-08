#include "Shuriken.h"

Shuriken::Shuriken(sf::Texture* text, float dirx, float diry, float posx, float posy, float velocity, int dmg)
	: Weapon(text, dirx, diry, posx, posy, velocity, dmg) {
	this->setScale(0.1f, 0.1f);
	this->setRotation(45.f);
}
