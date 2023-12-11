#include "Play.h"

Play::Play(std::string title, std::string author){
	this->title = title;
	this->author = author;
}

Play::Play(std::string file){
	readFromFile(file);
}

bool isAct(std::string line){
	return std::regex_match(line, std::regex("^ACT [0-9]+$"));
}

bool isScene(std::string line){
	return std::regex_match(line, std::regex("^Scene [0-9]+$"));
}

bool characterSpeaks(std::string line){
	return std::regex_match(line, std::regex("^[A-Z][A-Z ]+*"));
}

int returnAct(std::string line){

	std::string act = "";
	for(int i = 4; i < line.size(); i++)
		act += line[i];
	std::cout << "Act:" << act <<std::endl;
	return stoi(act);
}

int returnScene(std::string line){
	std::string scene = "";
	for(int i = 6; i < line.size(); i++)
		scene += line[i];

	std::cout << "Scene:" << scene <<std::endl;
	return stoi(scene);
}

std::string returnCharacterName(std::string line){
	bool justName = std::regex_match(line, std::regex("[A-Z ]+"));
	if(justName)
		return line;

	std::string consecCaps = "";
	for(int i = 0; i < line.size(); i++){
		if(isupper(line[i]))
			consecCaps += line[i];
		else
			break;
	}

	std::string name = "";
	for(int i = 0; i < consecCaps.size() - 3; i++)
		name += consecCaps[i];

	return name;
}


void Play::readFromFile(std::string path){
	std::ifstream file(path);

	if(!file.is_open()){
		std::cout << "File not open!" << std::endl;
	}

	// reading title
	std::string line;
	getline(file, line);
	this->title = line;
	
	// reading author
	getline(file, line);
	for(int i = 3; i < line.size(); i++){
		author += line[i];
	}

	
	// Skipping through the section until we actually get to the play
	while(getline(file, line)){
		if(isAct(line))
			break;
	}

	// We are now at the first act (ACT is contained in line)
	std::cout << line <<std::endl;
	int actNum = returnAct(line);
	
	// skipping until we receive the scene number
	while(getline(file, line)){
		if(isScene(line))
			break;
	}

	int sceneNum = returnScene(line);
	// Creates Scene with everything
	Scene currScene = Scene(actNum, sceneNum);

	std::cout << "here" << std::endl;
	while(getline(file, line)){
		if(characterSpeaks(line))
			break;
	}

	std::string characterName = returnCharacterName(line);
	characters[characterName] = Character(characterName);

	if(characterName.size() < line.size())
		line = line.substr(characterName.size());
	else
		line = "";
	// Loops through the current scene
	// Then there's inner loop looking for characters speaking
	// Then there's inner loop looking for lines

	std::string currLine = line;

	while(getline(file, line)){
		if(isAct(line)){
			actNum = returnAct(line);
			while(getline(file, line))
				if(isScene(line)) break;
			sceneNum = returnScene(line);

			scenes.push_back(currScene);
			currScene = Scene(actNum, sceneNum);
		}

		if(characterSpeaks(line)){
			characters[characterName].addLine(currLine);
			currScene.addLine(currLine, characterName);
			
			characterName = returnCharacterName(line);
			// if the rest of the line still contains text because a
			// character spoke, it just takes the rest of the
			// character's line
			line = line.substr(characterName.size());

			// adds character to Characters if their name wasn't found
			// in the map of characters
			if(characters.find(characterName) == characters.end()){
				characters[characterName] = Character(characterName);
			}
		}
		
		// skips any random lines
		if(line.size() < 2)
			continue;
		// skips stage directions
		if(line[0] == '[')
			continue;

		currLine += line;
		currLine += "\n";
	}

	currScene.addLine(currLine, characterName);
	scenes.push_back(currScene);
	characters[characterName].addLine(currLine);
}

std::vector<Character> Play::getCharacters(){
	std::vector<Character> chars;
	auto iter = characters.begin();
	for(; iter != characters.end(); iter++){
		chars.push_back(iter->second);
	}

	return chars;
}

