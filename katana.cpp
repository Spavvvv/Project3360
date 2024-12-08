#include "katana.h"

katana::katana(sf::Texture* text, float dirx, float diry, float posx, float posy, float velocity, int dmg)
    : Weapon(text, dirx, diry, posx, posy, velocity, dmg){
    this->setScale(0.2f, 0.2f);
    this->setRotation(45.f);
}



