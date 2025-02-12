#ifndef CHILD_H
#define CHILD_H

#include <string>

class Mother;
class Father;

class Child;

class FriendFromSchool {
public:
    const std::string play(const Child& child);
};

class Child {
private:
    std::string name;
    void setName(const std::string& name);

public:
    Child(const std::string& name);
    std::string getName() const;

    friend class Mother;
    friend const std::string FriendFromSchool::play(const Child& child);
    friend class Father;
};

#endif
