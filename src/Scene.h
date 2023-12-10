#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <fstream>

class Scene{
	int lines;
	std::unordered_set<Characters> characters;
	int act;
	int sceneNum;

	public:
	Scene();
	Scene(int act, int sceneNum);

	void addLine(std::string line, Character character);
	void addCharacter(Character character);

	void printScene();
}
