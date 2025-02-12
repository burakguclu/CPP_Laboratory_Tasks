#include <string>

class player {

private:
    std::string name;
    uint32_t id;
    uint8_t level;

public:
    player();
    player(const player& other);
    const void levelUp();
    const std::string getName();
    void setName(std::string name);
    const uint8_t getLevel();
    void setLevel(uint8_t level);
    const uint32_t getID();
    std::string& debugReference(const std::string& variable);
    void* debugPointer(const std::string& variable);
};

