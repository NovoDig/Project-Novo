#include "globals.h"

Tree::Tree() {}

bool Tree::Update(Player& player) {
	sf::IntRect& playerCollider = *player.getCollisionRect();
	sf::IntRect futureCollide = playerCollider;
	
	futureCollide.left += player.velocity.x;
	futureCollide.top += player.velocity.y;

	return futureCollide.intersects(*collider);
}
Cactus::Cactus() { }

bool Cactus::Update(Player& player) {
	sf::IntRect& playerCollider = *player.getCollisionRect();
	sf::IntRect futureCollide = playerCollider;

	futureCollide.left += player.velocity.x;
	futureCollide.top += player.velocity.y;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LControl)) {
		if (futureCollide.intersects(*collider)) {
			// Collect resources;
		}
	}

	return futureCollide.intersects(*collider);
}

Deposit::Deposit() {}

bool Deposit::Update(Player& player) {
	sf::IntRect& playerCollider = *player.getCollisionRect();
	sf::IntRect futureCollide = playerCollider;

	futureCollide.left += player.velocity.x;
	futureCollide.top += player.velocity.y;

	return futureCollide.intersects(*collider);
}

OverworldScene::OverworldScene() {

	srand(rand());

	map = new Map();
	player = new Player();

	trees = new std::vector<Tree>();
	cacti = new std::vector<Cactus>();
	deposits = new std::vector<Deposit>();


	sf::Texture* _treeTex = new sf::Texture();
	_treeTex->loadFromFile("tree.png");
	sf::Texture* _cactusTex = new sf::Texture();
	_cactusTex->loadFromFile("cactus.png");
	sf::Texture* _depositTex = new sf::Texture();
	_depositTex->loadFromFile("ore.png");

	sf::Sprite* tree = new sf::Sprite(*_treeTex);
	sf::Sprite* cactus = new sf::Sprite(*_cactusTex);
	sf::Sprite* deposit = new sf::Sprite(*_depositTex);

	for (auto tileObj : *map->getTiles()) {
		if (tileObj.type == TileType::GRASS && tileObj.gfx->getPosition().x >= 0 && tileObj.gfx->getPosition().y >= 0) {
			sf::Vector2f pos = tileObj.gfx->getPosition();
			player->SetInitialPos(pos + sf::Vector2f(32, 32));
			break;
		}
	}

	for (auto tileObj : *map->getTiles()) {

		if (tileObj.type == TileType::SAND) {
			sf::Vector2f pos = tileObj.gfx->getPosition();

			//for (int i = 0; i < 50; i++) {
				int shouldPlaceTree = rand() % 500;

				// Half of the time, create a cactus on a sand tile;
				if (shouldPlaceTree < 50) {

					Cactus* cactusObj = new Cactus();
					cactusObj->gfx = *cactus;
					cactusObj->pos = pos;

					cactusObj->collider = new sf::IntRect(pos.x+20, pos.y+20, 16, 16);

					cactusObj->gfx.setPosition(cactusObj->pos);

					cacti->push_back(*cactusObj);
				}
				if (shouldPlaceTree > 50 && shouldPlaceTree < 75) {
					
					Deposit* depositObj = new Deposit();
					depositObj->gfx = *deposit;
					depositObj->pos = pos;
					depositObj->collider = new sf::IntRect(pos.x+20, pos.y+20, 16, 16);
					depositObj->gfx.setPosition(depositObj->pos);
					deposits->push_back(*depositObj);

				}
			//}
		}

		if (tileObj.type == TileType::GRASS) {

			sf::Vector2f pos = tileObj.gfx->getPosition();

			//for (int i = 0; i < 50; i++) {
				int shouldPlaceTree = rand() % 500;

				// Half of the time, create a tree on grass tiles;
				if (shouldPlaceTree < 50) {

					Tree* treeObj = new Tree();
					treeObj->gfx = *tree;
					treeObj->pos = pos;

					treeObj->gfx.setPosition(treeObj->pos);
					treeObj->collider = new sf::IntRect(pos.x+20, pos.y+20, 16, 16);
					trees->push_back(*treeObj);
				}
				if (shouldPlaceTree > 50 && shouldPlaceTree < 75) {

					Deposit* depositObj = new Deposit();
					depositObj->gfx = *deposit;
					depositObj->pos = pos;
					depositObj->collider = new sf::IntRect(pos.x+20, pos.y+20, 16, 16);
					depositObj->gfx.setPosition(depositObj->pos);
					deposits->push_back(*depositObj);

				}
			//}
			
		}
	}

}

void OverworldScene::Update(sf::Clock& clock) const {
	
	bool collide = false;
	for (auto tree : *trees) {
		if (tree.Update(*player)) {
			collide = true;
		}
	}

	for (auto cactus : *cacti) {
		if (cactus.Update(*player)) {
			collide = true;
		}
	}

	for (auto deposit : *deposits) {
		if (deposit.Update(*player))
		{
			collide = true;
		}
	}
	player->Update(clock, collide);
}

void OverworldScene::Draw(sf::RenderWindow& win) const {
	map->Draw(win);

	for (auto tree : *trees) {
		win.draw(tree.gfx);
	}

	for (auto cactus : *cacti) {
		win.draw(cactus.gfx);
	}

	for (auto deposit : *deposits) {
		win.draw(deposit.gfx);
	}
	player->Draw(win);
}