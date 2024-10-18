#pragma once

enum TileType {
	WATER,
	SAND,
	GRASS,
	DARKGRASS
};

struct Tile {
	sf::Sprite* gfx;
	TileType type;
};

struct Chunk {
	std::vector<Tile>* tiles;
	sf::Vector2f startPos;
	bool isEnabled;
};

class Map
{
public:
	
	Map();
	void Draw(sf::RenderWindow& win);
	std::vector<Tile>* getTiles();
	
private:
	std::vector<Tile>* tiles;
};

