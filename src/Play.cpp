#include "Play.h"

Play::Play(std::string title, std::string author){
	this->title = title;
	this->author = author;
}

int returnAct(std::string line){

	std::string act = "";
	for(int i = 4; i < line.size(); i++)
		act += line[i];
	return stoi(act);
}

int returnScene(std::string line){
	std::string scene = "";
	for(int i = 6; i < line.size(); i++)
		scene += line[i];

	return stoi(scene);
}

std::string returnCharacterName(std::string line){
	bool justName = regex_match(line, regex("[A-Z ]+"));
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

	bool isAct = regex_match(line, regex("^ACT [0-9]+$"));
	bool isScene = regex_match(line, regex("^Scene [0-9]+$"));
	bool characterSpeaks = regex_search(line, regex("^[A-Z ]+"));
	
	// Skipping through the section until we actually get to the play
	while(getline(file, line)){
		if(isAct)
			break;
	}

	// We are now at the first act (ACT is contained in line)
	int actNum = returnAct(line);
	
	// skipping until we receive the scene number
	while(getline(file, line)){
		if(isScene)
			break;
	}

	int sceneNum = returnScene(line);
	// Creates Scene with everything
	Scene currScene = Scene(actNum, sceneNum);

	while(getline(file, line)){
		if(characterSpeaks)
			break;
	}

	std::string characterName = returnCharacterName(line);
	characters[characterName] = Character(characterName);
	// Loops through the current scene
	// Then there's inner loop looking for characters speaking
	// Then there's inner loop looking for lines

	std::string currLine = "";

	while(getline(file, line)){
		if(isAct){
			actNum = returnAct(line);
			while(getline(file, line))
				if(isScene) break;
			sceneNum = returnScene(line);

			scenes.push_back(currScene);
			currScene = Scene(actNum, sceneNum);
		}

		if(characterSpeaks){
			characters[characterName].addLine(currLine);
			currScene.addLine(currLine, characters[characterName]);
			
			characterName = returnCharacterName(line);
			// if the rest of the line still contains text because a
			// character spoke, it just takes the rest of the
			// character's line
			line = substring(characterName.size());

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

	currScene.addLine(currLine, Characters[characterName]);
	scenes.push_back(currScene);
	characters[characterName].addLine(currLine);
}
