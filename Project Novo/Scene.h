#pragma once
class Scene
{
public:
	Scene();

	virtual void Draw(sf::RenderWindow& win) const;
	virtual void Update(sf::Clock& clock) const;

private:

	// Nothing to put at this moment.

};

