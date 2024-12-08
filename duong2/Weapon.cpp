#include "Weapon.h"
#include<iostream>


Weapon::Weapon()
{

}

Weapon::Weapon(sf::Texture* text, float dirx, float diry, float posX, float posY, float velocity, uint16_t dmg)
{
    // check valid sprite
    if (text != nullptr) {
        this->sprite.setTexture(*text);
    }

    // Initialize direction vector
    this->direction.x = dirx;
    this->direction.y = diry;

    // Initialize speed
    this->speed = velocity;

    // Set the initial position of the weapon sprite
    this->sprite.setPosition(posX, posY);

    // set the damage of weapon:
    this->damage = dmg;
}

Weapon::~Weapon()
{

}

// Get the bounding rectangle of the sprite
const sf::FloatRect Weapon::getBound() const
{
    return this->sprite.getGlobalBounds();  //collision detection
}

// Update the weapon's position based on its speed and direction
void Weapon::update()
{
    this->sprite.move(this->speed * this->direction);  // Moves the sprite in the desired direction
}

// Render the weapon to the target (e.g., game window)
void Weapon::render(sf::RenderTarget* tar)
{
    if (tar) {
        tar->draw(this->sprite);  // Draw the sprite on the provided render target
    }
    else {
        // Log an error if the render target is null
        std::cerr << "Render target is null in Weapon::render." << std::endl;
    }
}


// Set the texture of the weapon and update the sprite
void Weapon::setTexture(sf::Texture* newTexture) {
    this->texture = newTexture;
    if (newTexture) {
        this->sprite.setTexture(*newTexture);
    }
}

// Set the direction of the weapon
void Weapon::setDirection(float xDir, float yDir) {
    this->direction = sf::Vector2f(xDir, yDir);
}

// Set the speed of the weapon
void Weapon::setSpeed(float spd) {
    this->speed = spd;
}

// Set the scale of the weapon sprite
void Weapon::setScale(float xScale, float yScale) {
    this->sprite.setScale(sf::Vector2f(xScale, yScale));
}

//// Set the position of the weapon sprite
//void Weapon::setPosition(float x, float y) {
//    this->sprite.setPosition(sf::Vector2f(x, y));
//}

// Set the damage value of the weapon
void Weapon::setDamage(uint16_t dmg) {
    this->damage = dmg;
}

// Set the damage value of the weapon
uint16_t Weapon::getDamage() {
    return this->damage;
}

void Weapon::setRotation(float angle) {
    this->sprite.setRotation(angle); // Rotate the weapon
}

//// Set the sprite directly (useful for advanced customization)
//void Weapon::setSprite(const sf::Sprite& newSprite) {
//    this->sprite = newSprite;
//}

/*
* 1. set scale of weapon: x2 or x3, maybe reduce damage
* 2. set damage of weapon
* 3. increase critical chance
* 4. set speed of weapon
* 5. set direction of weapon
* ...
*/

