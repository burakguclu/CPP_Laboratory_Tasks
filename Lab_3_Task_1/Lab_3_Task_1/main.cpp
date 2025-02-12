#include <iostream>
#include "player.h"

int main() {
	player myPlayer;
	myPlayer.setName("Burak");
	myPlayer.setLevel(50);

	std::cout << "Name: " << myPlayer.debugReference("name") << std::endl;
	std::cout << "ID: " << myPlayer.debugReference("id") << std::endl;
	std::cout << "Level: " << myPlayer.debugReference("level") << std::endl;

	std::cout << "Name: " << myPlayer.getName() << std::endl;
	std::cout << "ID: " << myPlayer.getID() << std::endl;
	std::cout << "Level: " << myPlayer.getLevel() << std::endl;

	std::cout << "Memory address of name: " << myPlayer.debugPointer("name") << std::endl;
	std::cout << "Memory address of ID: " << myPlayer.debugPointer("id") << std::endl;
	std::cout << "Memory address of level: " << myPlayer.debugPointer("level") << std::endl;

	return 0;
}
