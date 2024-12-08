#ifndef SWORD_H
#define SWORD_H
#include"Weapon.h"
class bigSword : public Weapon
{
private:

public:
	bigSword();
	bigSword(sf::Texture* text, float dirx, float diry, float posx, float posy, float velocity, int dmg);
	void setScale();




};
#endif // SWORD_H

