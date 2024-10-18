#include "globals.h"

sf::Vector2f Player::getPosition() {
	return sf::Vector2f(animations->at(animationIndex).getX(), animations->at(animationIndex).getY());
}

Player::Player() {
	animationIndex = 1;
	//willCollide = false;
	animations = new std::vector<Animation>();
	
	sf::Texture* player = new sf::Texture();
	player->loadFromFile("player.png");
	
	// Setup the sprite;
	sf::Sprite* playerSpr = new sf::Sprite(*player);
	playerSpr->setOrigin(16, 16);
	//playerSpr->setPosition(x, y);

	// Setup the Animations;
	Animation walk = Animation();
	walk.setSprite(playerSpr);
	walk.setSpeed(0.003);
	for (int i = 0; i < 9; i++) {
		walk.addFrame(new sf::IntRect(i*32, 0, 32, 32));
	}
	animations->push_back(walk);

	Animation stand = Animation();
	stand.setSpeed(0);
	stand.setSprite(playerSpr);
	stand.addFrame(new sf::IntRect(0, 0, 32, 32));
	animations->push_back(stand);
}

void Player::SetInitialPos(sf::Vector2f pos) {
	for (auto index : *animations) {
		
		index.setPosition(pos);

	}

	collisionRect = new sf::IntRect(animations->at(animationIndex).getX() - 16, animations->at(animationIndex).getY() + 10, 32, 16);
}

void Player::Update(sf::Clock clock, bool collide) {


	
	velocity = sf::Vector2f(0, 0);
	animationIndex = 1;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		velocity.x = 0.095;
		flipped = false;
		animationIndex = 0;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		velocity.x = -0.095;
		flipped = true;
		animationIndex = 0;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		animationIndex = 0;
		velocity.y = -0.095;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		animationIndex = 0;
		velocity.y = 0.095;
	}
	view = sf::View(sf::Vector2f(animations->at(animationIndex).getX(), animations->at(animationIndex).getY()), sf::Vector2f(1280, 720));
	
	collisionRect = new sf::IntRect(animations->at(animationIndex).getX(), animations->at(animationIndex).getY() + 10, 32, 16);

	animations->at(animationIndex).Update(clock, flipped, velocity, collide);
}
void Player::setWillCollide(bool state) {
	willCollide = state;
}

sf::IntRect* Player::getCollisionRect() {
	return this->collisionRect;
}

void Player::Draw(sf::RenderWindow& win) {
	win.setView(view);
	animations->at(animationIndex).Draw(win);
}