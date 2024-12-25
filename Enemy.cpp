#include "Enemy.h"

#include <iostream>

Enemy::Enemy(sf::Texture* text, float scaleX, float scaleY, float dirx, float diry, float startX, float startY
    , uint16_t mHp, float spd, uint16_t dmg, uint16_t point, bool isbo) {

    // check valid sprite
    if (text != nullptr) {
        this->sprite.setTexture(*text);
    }

    // Initialize direction vector
    // Initialize direction vector
    this->direction.x = dirx;
    this->direction.y = diry;

    setPosition(startX, startY);

    // Initialize speed
    this->speed = spd;
    // Initialize damage
    this->damage = dmg;

    this->point = point;

    this->maxHP = mHp;
    this->currentHP = mHp;
    this->isBonus = isbo;
    this->sprite.setScale(scaleX, scaleY);
}

const sf::FloatRect Enemy::getBounds() const {
    return this->sprite.getGlobalBounds();
}

const sf::Vector2f& Enemy::getPosition() const {
    return this->sprite.getPosition();
}

uint16_t Enemy::getCurrentHp()
{
    return this->currentHP;
}

uint16_t Enemy::getMaxHp()
{
    return this->maxHP;
}

uint16_t Enemy::getPoint()
{
    return this->point;
}

uint16_t Enemy::getDamage()
{
    return this->damage;
}

void Enemy::setPosition(float x, float y) {
    this->sprite.setPosition(x, y);
}

void Enemy::setSpeed(float spd) {
    this->speed = spd;
}

void Enemy::setCurrentHp(uint16_t cHp) {
    this->currentHP = cHp;
}

void Enemy::setMaxHp(uint16_t mHP) {
    this->maxHP = mHP;
}

void Enemy::setScale(float xScale, float yScale) {
    this->sprite.setScale(sf::Vector2f(xScale, yScale));
}

bool Enemy::getBonusStatus()
{
    return isBonus;
}

// Update the enemy's position
void Enemy::update() {
    this->sprite.move(this->direction * this->speed);
}

// Render the enemy on the target
void Enemy::render(sf::RenderTarget* target) {
    target->draw(this->sprite);
}

Enemy::~Enemy()
{
    delete texture;

}

