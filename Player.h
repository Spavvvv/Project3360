#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

enum PLAYER_ANIMATION_STATUS{ IDLE = 0, MOVING_RIGHT, MOVING_LEFT, ATTACKING, ATTACKING2, ATTACKING3};



class Player
{
protected:
	sf::Texture texture, texture2, texture3, texture4, texture5;
	sf::Sprite sprite;
	int hp, hpmax;
	float speed;
	sf::Clock animationTime;

	sf::IntRect currentFrame;
	void initVar();
	void initTexture();
	void initSprite();
	void initAnimation();
	float cooldownSkill1, cooldownSkill2, cooldownSkill3, cooldownnormalAttack;
	float cooldownSkill1max, cooldownSkill2max, cooldownSkill3max, cooldownnormalAttackmax;

	void waitTimeanimation();
public:
	Player();
	short animateStatus;
	bool moving, jumping, attacking;
	virtual ~Player();
	const sf::FloatRect globalBound() const;
	const sf::Vector2f getPosition();
	void update();
	void updateAnimation();
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
};

