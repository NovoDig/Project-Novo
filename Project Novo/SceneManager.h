#pragma once
class SceneManager
{
public:
	SceneManager();
	void addScene(Scene* scene);
	void switchScene(int id);

	Scene* getCurrentScene();

private:
	std::vector<Scene*>* scenes;
	Scene* currentScene;
};

