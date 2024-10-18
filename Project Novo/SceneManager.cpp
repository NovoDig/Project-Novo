#include "globals.h"

SceneManager::SceneManager(){

	scenes = new std::vector<Scene*>();

}

void SceneManager::addScene(Scene* scene) {
	scenes->push_back(scene);
}

void SceneManager::switchScene(int id) {

	currentScene = scenes->at(id);

}

Scene* SceneManager::getCurrentScene() {
	return currentScene;
}