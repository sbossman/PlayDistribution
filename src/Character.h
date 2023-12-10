#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <fstream>

#include "Scene.h"

class Character{
	private:
		int numLines;
		std::unordered_set<Character> talksTo;
		std::vector<Scene> scenes;
		std::string name;

	public:
		Character();
		Character(std::string name);
		void addLine(std::string line);
		void addTalksTo(Character character);
}
