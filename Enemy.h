#ifndef ENEMY_H
#define ENEMY_H
#include <iostream>
#include <SFML/Graphics.hpp>

class Enemy
{
private:
	//stat of enemy
	uint16_t currentHP;			//data type with range 0~65k
	uint16_t maxHP;
	uint16_t damage;
	uint16_t point;				//score of the enemy
	float speed;

	//sprite, texture and direction to move enemy
	sf::Sprite sprite;
	sf::Texture* texture = nullptr;
	sf::Vector2f direction = sf::Vector2f(0.f, 0.f);

public:

	Enemy(sf::Texture* texture, float scaleX, float scaleY, float dirx, float diry, float startX, float startY
		, uint16_t mHp, float speed, uint16_t dmg, uint16_t point);

	// getter
	const sf::FloatRect getBounds() const;   // Get the bounding box for collision detection
	const sf::Vector2f& getPosition() const; // Get the current position

	uint16_t getCurrentHp();
	uint16_t getMaxHp();
	uint16_t getPoint();
	uint16_t getDamage();

	// setter
	void setPosition(float x, float y);     // Set the position of the enemy
	void setSpeed(float spd);				// Set the movement speed

	void setCurrentHp(uint16_t cHp);
	void setMaxHp(uint16_t mHp);

	void setScale(float xScale, float yScale);

	// Methods
	void update();                            // Update the enemy's position
	void render(sf::RenderTarget* target);    // Render the enemy
};

#endif // ENEMY_H
