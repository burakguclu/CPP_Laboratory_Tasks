#include "Polynomial.h"

int main() {
    std::vector<float> terms;

    // Testing the reaching index of array/vector out of range
    try {
        terms = { 1.0, -2.0, 3.0 };
        Polynomial p1(terms);
        std::cout << p1[7] << " is the term at index 7: " << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    // Testing with a string input
    try {
        terms = { 1.0, 2.0, 3.0 };
        Polynomial p5(terms);
        auto result = p5.evaluate("string input");
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    // Testing with non-real roots
    try {
        terms = { 1.0, 2.0, 5.0 };
        Polynomial p3(terms);
        auto roots = p3.evaluate();
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    // Testing with no solution with bisection method.
    try {
        terms = { 2.0, -3.0, 1.0 };
        Polynomial p4(terms);
        auto root = p4.solve();
        std::cout << "Root found: " << root[0] << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    // Testing with non-quadratic polynomial
    try {
        terms = { 1.0, -2.0 };
        Polynomial p2(terms);
        auto roots = p2.evaluate();
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}