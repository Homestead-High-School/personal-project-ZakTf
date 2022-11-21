#include "Game.h"
#include <iostream>

Game::Game(std::string name, bool Weapon, int Hp) {
	characterName = name;
	weapon = Weapon;
	hp = Hp;
}
void Game::setName(std::string name) {
	characterName = name;
}
std::string Game::getName() {
	return characterName;
}
bool Game::hasWeapon() {
	return weapon;
}
int Game::getHp() {
	return hp;
}