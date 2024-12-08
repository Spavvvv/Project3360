#ifndef DAGGER_H
#define DAGGER_H
#include "Weapon.h"

class Dagger : public Weapon {
public:

    Dagger(sf::Texture* text, float dirx, float diry, float posx, float posy, float velocity, int dmg);
};

#endif // DAGGER_H