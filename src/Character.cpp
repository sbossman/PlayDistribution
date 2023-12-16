#include "Character.h"

Character::Character(){
	name = "UNNAMED";
}

Character::Character(std::string name){
	this->name = name;
}


int Character::getNumLines(){
	return lines.size();
}

std::vector<std::string> Character::getLines(){
	return lines;
}


std::string Character::getName(){
	return name;
}

std::vector<std::string> Character::getTalksTo(){
	std::vector<std::string> talkToVec;

	auto iter = talksTo.begin();

	for(; iter != talksTo.end(); iter++){
		talkToVec.push_back(*iter);
	}

	return talkToVec;
}

std::vector<Scene> Character::getScenes(){
	return scenes;
}


void Character::addLine(std::string line){
	numLines++;
	lines.push_back(line);
	//TODO: make this a better function (like actually create a 
	//way of storing lines)
}

void Character::addTalksTo(std::string character){
	talksTo.insert(character);
}

void Character::addScene(Scene scene){
	scenes.push_back(scene);
}


