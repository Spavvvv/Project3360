#ifndef SPEAR_H
#define SPEAR_H
#include "Weapon.h"

class Spear : public Weapon {

public:

    Spear(sf::Texture* text, float dirx, float diry, float posx, float posy, float velocity, int dmg);

};

#endif // SPEAR_H
