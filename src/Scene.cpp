#include "Scene.h"

Scene::Scene(){
	act = 0;
	sceneNum = 0;
}

Scene::Scene(int act, int sceneNum){
	this->act = act;
	this->sceneNum = sceneNum;
}


void Scene::addLine(std::string line, std::string character){
	lines++;
	characters.insert(character);
}

void Scene::addCharacter(std::string character){
	characters.insert(character);
}

void Scene::printScene(){
	std::cout << act << "." << sceneNum << std::endl;
}
