#include "globals.h"
#include <Windows.h>


//int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
//	_In_opt_ HINSTANCE hPrevInstance,
//	_In_ LPWSTR    lpCmdLine,
//	_In_ int       nCmdShow)
int main()
{

	sf::RenderWindow win(sf::VideoMode(1280, 720, 32), "Project Novo");

	/*
	sf::Texture tex = sf::Texture();
	tex.loadFromFile("title.png");
	*/

	SceneManager* sceneManager = new SceneManager();
	sceneManager->addScene(new TitleScene());
	sceneManager->addScene(new OverworldScene());
	sceneManager->switchScene(0);

	sf::Clock* clock = new sf::Clock();

	while (win.isOpen()) {
		clock->restart();

		sf::Event event;
		while (win.pollEvent(event)) {
			switch (event.type) {
				default:
					break;
				case sf::Event::Closed:
					win.close();
					break;
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter)) {
			sceneManager->switchScene(1);
		}

		sceneManager->getCurrentScene()->Update(*clock);

		win.clear(sf::Color(91,110,225));
		
		sceneManager->getCurrentScene()->Draw(win);

		win.display();

	}
}