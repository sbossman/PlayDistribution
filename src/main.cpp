#include <iostream>
#include <string>
#include <vector>

#include "Play.h"


int main(){
	std::cout << "Hello world" << std::endl;
	std::string path = "./plays/";
	std::string filename = "romeo-and-juliet_TXT_FolgerShakespeare"; 

	Play romeoAndJuliet(path + filename);
}
