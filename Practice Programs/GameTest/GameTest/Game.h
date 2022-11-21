#pragma once
#include <iostream>
class Game {
	std::string characterName;
	bool weapon;
	int hp;

public:
	Game(std::string name, bool weapon, int hp);
	void setName(std::string name);
	std::string getName();
	bool hasWeapon();
	int getHp();
};