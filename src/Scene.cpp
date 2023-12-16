#include "Scene.h"

Scene::Scene(){
	act = 0;
	sceneNum = 0;
}

Scene::Scene(int act, int sceneNum){
	this->act = act;
	this->sceneNum = sceneNum;
}

std::vector<std::string> Scene::getCharacters(){
	std::vector<std::string> chars;

	auto iter = characters.begin();
	for(; iter != characters.end(); iter++){
		chars.push_back(*iter);
	}

	return chars;
}

int Scene::getAct(){
	return act;
}

int Scene::getScene(){
	return sceneNum;
}


bool Scene::inScene(std::string character){
	return characters.find(character) != characters.end();
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

	auto iter = characters.begin();
	for(; iter != characters.end(); iter++){
		std::cout << *iter << " ";
	}
	std::cout << std::endl;
}
