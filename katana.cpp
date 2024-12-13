#include "katana.h"
#include <iostream>


katana::katana()
{

}

katana::katana(sf::Texture* text, float dirx, float diry, float posx, float posy, float velocity, int dmg)
    : Weapon(text, dirx, diry, posx, posy, velocity, dmg)
{
    this->setScale();
    
}


void katana::setScale()
{
    this->sprite.setScale(sf::Vector2f(0.1f, 0.1f));
}


