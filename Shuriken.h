#ifndef SHURIKEN_H
#define SHURIKEN_H
#include "Weapon.h"

class Shuriken : public Weapon {

public:

    Shuriken(sf::Texture* text, float dirx, float diry, float posx, float posy, float velocity, int dmg);

};

#endif // SHURIKEN_H