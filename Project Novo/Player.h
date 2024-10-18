#pragma once
class Player
{
public:
	Player();
	void SetInitialPos(sf::Vector2f pos);
	void Update(sf::Clock clock, bool collide);
	sf::Vector2f getPosition();
	void setWillCollide(bool state);
	sf::IntRect* getCollisionRect();
	void Draw(sf::RenderWindow &win);
	bool willCollide;
	sf::Vector2f velocity = sf::Vector2f(0, 0);
private:
	bool flipped = false;
	sf::View view;

	int animationIndex = 0;
	sf::IntRect* collisionRect;
	
	
	std::vector<Animation>* animations;
};

