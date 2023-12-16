#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

#include "Play.h"


int main(){
	std::cout << "Hello world" << std::endl;
	std::string path = "./plays/";
	std::string filename = "hamlet.txt"; 

	Play hamlet(path + filename);

	std::vector<Character> characters = hamlet.getCharacters();
	for(int i = 0; i < characters.size(); i++){
		std::cout << std::setw(20) << characters[i].getName() << "\t\t" << characters[i].getNumLines() << std::endl;
	}

	std::vector<std::string> lines = characters[6].getLines();
	std::vector<std::string> talksTo = characters[6].getTalksTo();
	for(int i = 0; i < lines.size(); i++){
		std::cout << lines[i] << std::endl;
	}
	for(int i = 0; i < lines.size(); i++){
		std::cout << talksTo[i] << std::endl;
	}

	std::vector<Scene> scenes = hamlet.getScenes();
	for(int i = 0; i < scenes.size(); i++){
		scenes[i].printScene();
	}

	std::cout << "In scene: " << hamlet.talksTo("HAMLET", "OPHELIA") << std::endl; 

}
