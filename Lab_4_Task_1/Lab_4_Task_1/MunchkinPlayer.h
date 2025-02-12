#include <iostream>
#include "player.h"

enum munchkinClass { WIZARD = 0, WARRIOR, THIEF, CLERIC, BARD, RANGER };
enum munchkinRace { ELF, DWARF, HALFLING, ORC, GNOME };

class MunchkinPlayer : public player {

private:
	uint8_t armour;
	uint8_t weapon;
	munchkinClass playerClass;
	munchkinRace playerRace;
	static int monsterCounter;

public:
	MunchkinPlayer();
	void setArmour(uint8_t armour);
	uint8_t getArmour();
	void setWeapon(uint8_t weapon);
	uint8_t getWeapon();
	void setClass(munchkinClass playerClass);
	munchkinClass getClass();
	void setRace(munchkinRace playerRace);
	munchkinRace getRace();
	const void levelUp();
	static void increaseMonsterCounter();
	void fightMonster();
};

