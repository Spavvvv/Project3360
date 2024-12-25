#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

enum PLAYER_ANIMATION_STATUS{ IDLE = 0, MOVING_RIGHT, MOVING_LEFT, DEATH, ATTACKING, ATTACKING2, ATTACKING3};



class Player
{
protected:
	sf::Texture texture, texture2, texture3, texture4, texture5, texture6;
	sf::Sprite sprite;
	int hp, hpmax;
	float speed;
	sf::Clock animationTime;
	sf::Vector2f velocity;

	sf::IntRect currentFrame;
	void initVar();
	void initTexture();
	void initSprite();
	void initAnimation();
	float cooldownSkill1, cooldownSkill2, cooldownSkill3, cooldownnormalAttack;
	float cooldownSkill1max, cooldownSkill2max, cooldownSkill3max, cooldownnormalAttackmax;
	short animateStatus;


	void waitTimeanimation();
public:
	Player();
	void setAnimateStatus(short an);
	short getAnimateStatus() const;
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


	void setHpMax(const int& Hp);
	//void setDamage(int& Damage);

	int getCurrentHp();
	const int& getHpMax() const;
	void setCurrentHp(int hp);
	void setPosition(const float xpo, const float ypo);
	void resetVelocity();

};

