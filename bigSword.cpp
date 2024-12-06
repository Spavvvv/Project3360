#include "bigSword.h"

bigSword::bigSword()
{
}

bigSword::bigSword(sf::Texture* text, float dirx, float diry, float posx, float posy, float velocity, int dmg)
	: Weapon(text, dirx, diry, posx, posy, velocity, dmg)
{
	this->setScale();
   
}

/*void bigSword::setScale()
{
	this->sprite.setScale(sf::Vector2f(0.5f, 0.5f));
}*/

void bigSword::setScale()
{
	this->sprite.setScale(sf::Vector2f(0.7f, 0.7f));
}



