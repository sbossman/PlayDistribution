#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <map>
#include <regex>

#include "Character.h"
#include "Scene.h"

class Play{
	private:
		std::map<std::string, Character> characters;
		std::vector<Scene> scenes;
		std::string title;
		std::string author;
	public:
		Play(std::string title, std::string author);
		Play(std::string file);

		void readFromFile(std::string file);
		std::vector<Character> getCharacters();
		std::vector<Scene> getScenes();

		bool inSceneTogether(std::string char1, std::string char2);
		bool talksTo(std::string char1, std::string char2);
};
