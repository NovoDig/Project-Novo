#include "globals.h"

Animation::Animation() {
	this->_frames = new std::vector<sf::IntRect*>();
	this->_frame = 0;
}
void Animation::setPosition(sf::Vector2f pos) {

	this->_gfx->setPosition(pos);

}
float Animation::getX() {
	return this->_gfx->getPosition().x;
}
float Animation::getY() {
	return this->_gfx->getPosition().y;
}

void Animation::setSpeed(float speed) {
	this->animationSpeed = speed;
}

void Animation::setSprite(sf::Sprite* gfx) {

	this->_gfx = gfx;

}

void Animation::addFrame(sf::IntRect *frame) {
	this->_frames->push_back(frame);
}

void Animation::Update(sf::Clock clock, bool flipped, sf::Vector2f velocity, bool willCollide) {
	
	if (willCollide) {
		//MessageBoxA(NULL, "Collide", "collide", 0);
	}
	else {
		if (this->_frames->capacity() == 0)
			return;

		if (flipped)
			this->_gfx->setScale(-1, 1);
		else
			this->_gfx->setScale(1, 1);

		this->_gfx->setTextureRect(*this->_frames->at(this->_frame));
		currentTime += clock.getElapsedTime().asSeconds();

		if (currentTime >= animationSpeed) {
			this->_frame++;
			if (this->_frame > this->_frames->capacity() - 1)
				this->_frame = 0;
			currentTime = 0;
		}

		this->_gfx->setPosition(this->_gfx->getPosition() + (velocity));
	}
}

void Animation::Draw(sf::RenderWindow &win) {
	win.draw(*this->_gfx);
}