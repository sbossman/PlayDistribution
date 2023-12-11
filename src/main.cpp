#include <iostream>
#include <string>
#include <vector>

#include "Play.h"


int main(){
	std::cout << "Hello world" << std::endl;
	std::string path = "./plays/";
	std::string filename = "hamlet.txt"; 

	Play hamlet(path + filename);

	std::vector<Character> characters = hamlet.getCharacters();
	for(int i = 0; i < characters.size(); i++){
		std::cout << characters[i].getName() << std::endl;
	}
}
