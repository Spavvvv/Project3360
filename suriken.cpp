#include "suriken.h"

suriken::suriken()
{
}

suriken::suriken(sf::Texture* text, float dirx, float diry, float posx, float posy, float velocity, int dmg)
	: Weapon(text, dirx, diry, posx, posy, velocity, dmg)
{
	this->sprite.setScale(0.1f, 0.1f);
}
