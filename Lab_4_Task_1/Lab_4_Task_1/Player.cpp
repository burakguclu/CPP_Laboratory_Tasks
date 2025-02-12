#include "player.h"
#include <random>
#include <iostream>

player::player() {
    auto generate_random_id = []() {
        std::mt19937_64 rng(std::random_device{}());
        std::uniform_int_distribution<int> dist(0, 9999);
        return dist(rng);
    };
    name = "";
    id = generate_random_id();
    level = 0;
}

player::player(const player& other) {
    name = other.name;
    id = other.id;
    level = other.level;
}

const void player::levelUp() {
    level++;
}

const std::string player::getName() {
    return name;
}

void player::setName(std::string name) {
    this->name = name;
}

const uint8_t player::getLevel() {
    return level;
}

void player::setLevel(uint8_t level) {
    this->level = level;
}

const uint32_t player::getID() {
    return id;
}

std::string& player::debugReference(const std::string& variable) {
    if (variable == "name")
        return name;
    else if (variable == "id") {
        static std::string idStr;
        idStr = std::to_string(id);
        return idStr;
    }
    else if (variable == "level") {
        static std::string levelStr;
        levelStr = std::to_string(level);
        return levelStr;
    }
}

void* player::debugPointer(const std::string& variable) {
    if (variable == "name")
        return &name;
    else if (variable == "id")
        return &id;
    else if (variable == "level")
        return &level;
}
