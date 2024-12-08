#ifndef SURIKEN_H
#define SURIKEN_H
#include "Weapon.h"

class suriken : public Weapon
{
public:
    suriken();
    suriken(sf::Texture* text, float dirx, float diry, float posx, float posy, float velocity, int dmg);
};

#endif // !SURIKEN_H