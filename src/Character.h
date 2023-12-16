#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <fstream>

#include "Scene.h"

class Character{
	private:
		int numLines;
		std::unordered_set<std::string> talksTo;
		std::vector<Scene> scenes;
		std::string name;
		std::vector<std::string> lines;

	public:

		Character();
		Character(std::string name);

		int getNumLines();
		std::vector<std::string> getLines();
		std::string getName();
		std::vector<std::string> getTalksTo();
		std::vector<Scene> getScenes();
		
		void addLine(std::string line);
		void addTalksTo(std::string character);
		void addScene(Scene scene);

};
