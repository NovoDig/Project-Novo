#pragma once
class Animation
{
public:
	Animation();
	void setSprite(sf::Sprite *gfx);
	void setSpeed(float speed);
	void addFrame(sf::IntRect *frame);
	void Draw(sf::RenderWindow &win);
	void Update(sf::Clock clock, bool flipped, sf::Vector2f velocity, bool willCollide);
	float getX();
	float getY();
	void setPosition(sf::Vector2f pos);

private:
	float animationSpeed;
	float currentTime = 0;
	std::vector<sf::IntRect*>* _frames;
	int _frame;
	sf::Sprite *_gfx;
};

