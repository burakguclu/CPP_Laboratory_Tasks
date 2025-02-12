#include "child.h"

const std::string FriendFromSchool::play(const Child& child) {
    return child.getName() + " playing";
}

Child::Child(const std::string& name) : name(name) {}

std::string Child::getName() const {
    return name;
}

void Child::setName(const std::string& name) {
    this->name = name;
}
