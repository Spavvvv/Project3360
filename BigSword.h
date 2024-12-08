#pragma once
#ifndef BIGSWORD_H
#define BIGSWORD_H
#include "Weapon.h"

class BigSword : public Weapon {

public:

    BigSword(sf::Texture* text, float dirx, float diry, float posx, float posy, float velocity, int dmg);



};

#endif // BIGSWORD_H
