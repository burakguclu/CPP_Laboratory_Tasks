#include "child.h"
#include <vector>
#include <memory>
#include <iostream>

class Principal;

class School {
private:
    std::vector<std::shared_ptr<Child>> children;

public:
    School(const std::vector<std::shared_ptr<Child>>& children);

    friend class Principal;
};
