#ifndef WEAPON_H
#define WEAPON_H


#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include<map>
class Weapon
{
private:
	sf::Texture* texture = nullptr;
	sf::Vector2f direction = sf::Vector2f(0.f, 0.f);
	float speed = 0.f;
	

protected:
	sf::Sprite sprite;
	uint16_t damage;                                   // Damage value for the weapon
public:
	
	Weapon();
	Weapon(sf::Texture*, float dirx, float diry, float posx, float posy, float spe, int dmg);
	virtual ~Weapon();

	const sf::FloatRect getBound() const;
	void update();
	void render(sf::RenderTarget* tar);
	void setDamage(uint16_t dmg);               // Set the damage of the weapon
	uint16_t getDamage();

};

#endif // WEAPON_H