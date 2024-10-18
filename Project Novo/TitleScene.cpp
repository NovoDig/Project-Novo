#include "globals.h"

TitleScene::TitleScene() {
	bg = new sf::Sprite();
	logo = new sf::Sprite();

	sf::Texture* bgTex = new sf::Texture();
	bgTex->loadFromFile("titleBg.png");

	sf::Texture* logoTex = new sf::Texture();
	logoTex->loadFromFile("title.png");

	bg->setTexture(*bgTex);
	logo->setTexture(*logoTex);
	logo->setPosition(1280 / 2, 100);
	logo->setOrigin(400, 0);
}

void TitleScene::Update(sf::Clock& clock) const {
}

void TitleScene::Draw(sf::RenderWindow& win) const {
	win.draw(*bg);
	win.draw(*logo);
}