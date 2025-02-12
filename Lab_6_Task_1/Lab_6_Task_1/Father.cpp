#include "Father.h"

template <typename T>
void Father::combatAssignment(const T& object) {
    std::cout << child.getName() + " holding " + std::to_string(object) << std::endl;
}
