#pragma once
#include "Scene.h"
class TitleScene :
    public Scene
{
public:
    TitleScene();

    void Update(sf::Clock& clock) const override;
    void Draw(sf::RenderWindow& win) const override;
private:

    sf::Sprite* bg;
    sf::Sprite* logo;
};

