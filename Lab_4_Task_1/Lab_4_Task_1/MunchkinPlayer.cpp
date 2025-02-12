#include "MunchkinPlayer.h"
#include <random>

int MunchkinPlayer::monsterCounter = 0;
void MunchkinPlayer::increaseMonsterCounter() {
	monsterCounter++;
}

auto generator = [](int start, int X) {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(start, X);
	return dis(gen);
};

void MunchkinPlayer::fightMonster() {
	increaseMonsterCounter();

	int monsterLevel = generator(1, 20);
	int playerPoints = getLevel() + getArmour() + getWeapon();

	if (playerPoints >= monsterLevel) {
		levelUp();

		if (generator(1, 2) == 1)
			setArmour(getArmour() + generator(1, 3));
		else
			setWeapon(getWeapon() + generator(1, 3));

	}
	else {
		if (getLevel() > 1)
			setLevel(getLevel() - 1);
	}
}

MunchkinPlayer::MunchkinPlayer() {
	setLevel(1);
	armour = 0;
	weapon = 0;
	
	setClass(static_cast<munchkinClass>(generator(0, static_cast<int>(munchkinClass::RANGER))));
	setRace(static_cast<munchkinRace>(generator(0, static_cast<int>(munchkinRace::GNOME))));
}

void MunchkinPlayer::setArmour(uint8_t armour) {
	this->armour = armour;
}

uint8_t MunchkinPlayer::getArmour() {
	return armour;
}

void MunchkinPlayer::setWeapon(uint8_t weapon) {
	this->weapon = weapon;
}

uint8_t MunchkinPlayer::getWeapon() {
	return weapon;
}

void MunchkinPlayer::setClass(munchkinClass playerClass) {
	this->playerClass = playerClass;
}

munchkinClass MunchkinPlayer::getClass() {
	return playerClass;
}

void MunchkinPlayer::setRace(munchkinRace playerRace) {
	this->playerRace = playerRace;
}

munchkinRace MunchkinPlayer::getRace() {
	return playerRace;
}

const void MunchkinPlayer::levelUp() {
	setLevel(getLevel() + 2);
}


