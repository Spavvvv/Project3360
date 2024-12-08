#include "Dagger.h"

Dagger::Dagger(sf::Texture* text, float dirx, float diry, float posx, float posy, float velocity, int dmg)
	: Weapon(text, dirx, diry, posx, posy, velocity, dmg) {
	this->setScale(0.15f, 0.15f);
	this->setRotation(45.f);
}
