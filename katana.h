#ifndef KATANA_H
#define KATANA_H

#include "Weapon.h"

class katana : public Weapon {
private:

public:
    katana(sf::Texture* text, float dirx, float diry, float posx, float posy, float velocity, int dmg);
    
};

#endif // KATANA_H
