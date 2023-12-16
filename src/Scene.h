#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <fstream>

class Scene{
	int lines;
	std::unordered_set<std::string> characters;
	int act;
	int sceneNum;

	public:
	Scene();
	Scene(int act, int sceneNum);

	std::vector<std::string> getCharacters();
	int getAct();
	int getScene();

	bool inScene(std::string character);

	void addLine(std::string line, std::string character);
	void addCharacter(std::string character);

	void printScene();
};
