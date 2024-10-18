#pragma once

class Tree {
public:
	Tree();
	bool Update(Player &player);
	sf::IntRect* collider;
	sf::Sprite gfx;
	sf::Vector2f pos;
};

class Cactus {
public:
	Cactus();
	bool Update(Player &player);
	sf::Sprite gfx;
	sf::IntRect* collider;
	sf::Vector2f pos;
};

class Deposit {
public:
	Deposit();
	bool Update(Player &player);
	sf::Sprite gfx;
	sf::IntRect* collider;
	sf::Vector2f pos;
};

class OverworldScene : public Scene
{
public:
	OverworldScene();

	void Update(sf::Clock& clock) const override;

	void Draw(sf::RenderWindow& win) const override;

private:

	std::vector<Tree>* trees;
	std::vector<Cactus>* cacti;
	std::vector<Deposit>* deposits;

	Player* player;
	Map* map;

};

