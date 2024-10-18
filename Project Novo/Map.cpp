#include "globals.h"
#include <noise/noise.h>

void Map::Draw(sf::RenderWindow& win) {
	sf::FloatRect rect(win.getView().getCenter() - win.getView().getSize() / 2.0f, win.getView().getSize());

	int startX = std::max(-2500, static_cast<int>(rect.left));
	int endX = std::min(2500, static_cast<int>(rect.left + rect.width+1));
	int startY = std::max(-2500, static_cast<int>(rect.top));
	int endY = std::min(2500, static_cast<int>(rect.top + rect.height+1));

	for (auto tile : *tiles) {
		if ((tile.gfx->getPosition().x >= startX && tile.gfx->getPosition().x <= endX)
			&& (tile.gfx->getPosition().y >= startY && tile.gfx->getPosition().y <= endY)) {
			win.draw(*tile.gfx);
		}
	}
}

std::vector<Tile>* Map::getTiles() {
	return tiles;
}

Map::Map() {
	tiles = new std::vector<Tile>();
	//chunks = new std::vector<Chunk>();

	int numPerRow = (2500 / 32);
	int numPerCol = (2500 / 32);

	float perlinValue;

	noise::module::Perlin perlin;
	perlin.SetFrequency(0.39);
	double scale = 0.1;

	//Chunk chunk;

	sf::Texture* waterTex = new sf::Texture();
	sf::Texture* grassTex = new sf::Texture();
	sf::Texture* darkGrassTex = new sf::Texture();
	sf::Texture* sandTex = new sf::Texture();
	waterTex->loadFromFile("water.png");
	grassTex->loadFromFile("grass.png");
	darkGrassTex->loadFromFile("darkGrass.png");
	sandTex->loadFromFile("sand.png");

	for (int i = (-2500/32); i <= numPerRow; i++) {
		for (int j = (-2500/32); j <= numPerCol; j++) {

			Tile tile;

			sf::Sprite* _gfx = new sf::Sprite();

			double nx = i * scale;
			double ny = j * scale;

			perlinValue = perlin.GetValue(nx, ny, 0.0);

			if (perlinValue <= 0.001) {
				_gfx->setTexture(*waterTex);
				tile.type = TileType::WATER;
			}
			else if (perlinValue < 0.2 && perlinValue > 0.001) {
				_gfx->setTexture(*sandTex);
				tile.type = TileType::SAND;
			}
			else if (perlinValue >= 0.2 && perlinValue <= 0.9) {
				_gfx->setTexture(*grassTex);
				tile.type = TileType::GRASS;
			}
			else {
				_gfx->setTexture(*darkGrassTex);
				tile.type = TileType::DARKGRASS;
			}
			_gfx->setPosition(sf::Vector2f(i*32, j*32));

			tile.gfx = _gfx;
			tiles->push_back(tile);
		}
		//chunk.tiles = tiles;
		//chunk.isEnabled = true;
		//chunks->push_back(chunk);
	}
}