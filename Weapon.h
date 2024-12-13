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
    Weapon();                                           // Default constructor
    Weapon(sf::Texture*, float dirx, float diry, float posx, float posy, float spe, uint16_t dmg);

    virtual ~Weapon();                                  // Virtual destructor for cleanup

    //methods
    const sf::FloatRect getBound() const;  // Get the bounding rectangle of the sprite (used for collision detection)
    void update();                         // Update the weapon's state (e.g., movement)
    void render(sf::RenderTarget* tar);    // Render the weapon on the target

    // Set the damage value of the weapon
    uint16_t getDamage();

    // Setters
    void setTexture(sf::Texture* newTexture);    // Set the texture of the weapon
    void setDirection(float xDir, float yDir);  // Set the direction of the weapon
    void setSpeed(float spd);                   // Set the speed of the weapon
    void setScale(float xScale, float yScale);  // Set the scale of the weapon sprite
    //void setPosition(float x, float y);         // Set the position of the weapon sprite
    void setDamage(uint16_t dmg);               // Set the damage of the weapon
    void setSprite(const sf::Sprite& newSprite); // Set the sprite of the weapon
    //set rotation of weapon's texture
    void setRotation(float angle);

};

#endif // WEAPON_H