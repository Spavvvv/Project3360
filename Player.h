#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
class Player
{
protected:
	sf::Texture texture;
	sf::Sprite sprite;
	int hp, hpmax;
	float speed;

	sf::IntRect currentFrame;
	void initVar();
	void initTexture();
	void initSprite();
	float cooldownSkill1, cooldownSkill2, cooldownSkill3, cooldownnormalAttack;
	float cooldownSkill1max, cooldownSkill2max, cooldownSkill3max, cooldownnormalAttackmax;
public:
	Player();
	virtual ~Player();
	const sf::Vector2f getPosition();
	void update();
	void updateTimena();
	void updateTime1();
	void updateTime2();
	void updateTime3();
	bool canAttackna();
	bool canAttack1();
	bool canAttack2();
	bool canAttack3();
	void movement(const float, const float);
	void render(sf::RenderTarget &);

	//function to get the bound of player:
	const sf::FloatRect getBounds() const;
	//setter, getter:
	int getCurrentHp();
	void setCurrentHp(int hp);
};

