#include "child.h"
#include "mother.h"
#include "school.h"
#include <iostream>
#include <vector>
#include <memory>

class Father {
public:
    template <typename T>
    void combatAssignment(const Child& child, const T& object) {
        std::cout << child.getName() + " holding " + std::to_string(object) << std::endl;
    }
};

class Principal {
public:
    Child* getAddress(const std::shared_ptr<School>& school, size_t index) {
        if (index < school->children.size()) {
            return school->children[index].get();
        }
        return nullptr;
    }
};

int main() {
    auto child1 = std::make_shared<Child>("Burak");
    auto child2 = std::make_shared<Child>("Guclu");

    std::vector<std::shared_ptr<Child>> children;
    children.push_back(child1);
    children.push_back(child2);
    School school(children);
}
