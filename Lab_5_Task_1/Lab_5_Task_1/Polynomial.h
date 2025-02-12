#include <iostream>
#include <vector>
#include <list>

class Polynomial {

private:
    std::vector<float> terms;

public:
    Polynomial(const std::vector<float>& terms);
    Polynomial(const std::list<float>& termsList);
    Polynomial();

    friend std::ostream& operator<<(std::ostream& os, const Polynomial& polynomial);
    Polynomial operator+(const Polynomial& polynomial);
    Polynomial operator-(const Polynomial& polynomial);
    Polynomial operator*(float scalar);
    Polynomial operator*(const Polynomial& polynomial);
    const float operator[](size_t index);

    std::vector<float> evaluate();
    std::vector<float> evaluate(float number);

    std::vector<float> solve();
};

