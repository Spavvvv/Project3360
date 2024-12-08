#include "Weapon.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include<iostream>




Weapon::Weapon() 
{

}

Weapon::Weapon(sf::Texture* text, float dirx, float diry, float posX, float posY, float velocity, int dmg)
{
	if (text != nullptr) {
		this->sprite.setTexture(*text);
	}
	this->direction.x = dirx;
	this->direction.y = diry;
	this->speed = velocity;
	this->sprite.setPosition(posX, posY);
	
}



Weapon::~Weapon()
{

}







const sf::FloatRect Weapon::getBound() const
{
	return this->sprite.getGlobalBounds();
}



void Weapon::update()
{
	this->sprite.move(this->speed * this->direction);
	
}

void Weapon::render(sf::RenderTarget* tar)
{
	if (tar) {
		tar->draw(this->sprite);
	}
	else {
		std::cerr << "Render target is null in Sword::render." << std::endl;
	}
}
void Weapon::setDamage(uint16_t dmg) {
	this->damage = dmg;
}
uint16_t Weapon::getDamage() {
	return this->damage;
}
