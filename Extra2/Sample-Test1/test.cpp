#include "pch.h"
#include "../Extra2/Polynomial.cpp"

// Testing the default constructor
TEST(PolynomialTest, DefaultConstructor) {
    Polynomial p;
    EXPECT_EQ(p[0], 0.0);
    EXPECT_EQ(p[1], 7.0);
    EXPECT_EQ(p[2], 0.0);
    EXPECT_EQ(p[3], -1.3);
    EXPECT_EQ(p[4], 2.0);
}

// Test constructor with vector
TEST(PolynomialTest, VectorConstructor) {
    std::vector<float> terms = { 1.0, 2.0, 3.0 };
    Polynomial p(terms);
    EXPECT_EQ(p[0], 1.0);
    EXPECT_EQ(p[1], 2.0);
    EXPECT_EQ(p[2], 3.0);
}

// Test constructor with list
TEST(PolynomialTest, ListConstructor) {
    std::list<float> terms = { 1.0, 2.0, 3.0 };
    Polynomial p(terms);
    EXPECT_EQ(p[0], 1.0);
    EXPECT_EQ(p[1], 2.0);
    EXPECT_EQ(p[2], 3.0);
}

// Test out-of-range access
TEST(PolynomialTest, OutOfRangeAccess) {
    std::list<float> terms = { 1.0, 2.0, 3.0 };
    Polynomial p(terms);
    EXPECT_THROW(p[3], std::out_of_range);
}

// Test operator+
TEST(PolynomialTest, AdditionOperator) {
    std::list<float> terms1 = { 1.0, 2.0, 3.0 };
    std::list<float> terms2 = { 4.0, 5.0 };
    Polynomial p1(terms1);
    Polynomial p2(terms2);
    Polynomial result = p1 + p2;
    EXPECT_EQ(result[0], 5.0);
    EXPECT_EQ(result[1], 7.0);
    EXPECT_EQ(result[2], 3.0);
}

// Test operator-
TEST(PolynomialTest, SubtractionOperator) {
    std::list<float> terms1 = { 1.0, 2.0, 3.0 };
    std::list<float> terms2 = { 4.0, 5.0 };
    Polynomial p1(terms1);
    Polynomial p2(terms2);
    Polynomial result = p1 - p2;
    EXPECT_EQ(result[0], -3.0);
    EXPECT_EQ(result[1], -3.0);
    EXPECT_EQ(result[2], 3.0);
}

// Test operator* (scalar)
TEST(PolynomialTest, ScalarMultiplicationOperator) {
    std::list<float> terms = { 1.0, 2.0, 3.0 };
    Polynomial p = (terms);
    Polynomial result = p * 2.0;
    EXPECT_EQ(result[0], 2.0);
    EXPECT_EQ(result[1], 4.0);
    EXPECT_EQ(result[2], 6.0);
}

// Test operator* (polynomial)
TEST(PolynomialTest, PolynomialMultiplicationOperator) {
    std::list<float> terms1 = { 1.0, 2.0 };
    std::list<float> terms2 = { 3.0, 4.0 };
    Polynomial p1(terms1);
    Polynomial p2(terms2);
    Polynomial result = p1 * p2;
    EXPECT_EQ(result[0], 3.0);
    EXPECT_EQ(result[1], 10.0);
    EXPECT_EQ(result[2], 8.0);
}

// Test evaluate with a float
TEST(PolynomialTest, EvaluateFloat) {
    std::list<float> terms = { 1.0, -3.0, 2.0 };
    Polynomial p(terms);
    auto result = p.evaluate(3.0);
    EXPECT_FLOAT_EQ(result[0], 2.0);
}

// Test evaluate with a string that can be converted to float
TEST(PolynomialTest, EvaluateStringValid) {
    std::list<float> terms = { 1.0, -3.0, 2.0 };
    Polynomial p(terms);
    auto result = p.evaluate(std::string("3.0"));
    EXPECT_FLOAT_EQ(result[0], 2.0);
}

// Test evaluate with a string that cannot be converted to float
TEST(PolynomialTest, EvaluateStringInvalid) {
    std::list<float> terms = { 1.0, -3.0, 2.0 };
    Polynomial p(terms);
    EXPECT_THROW(p.evaluate(std::string("invalid")), std::invalid_argument);
}

// Test solve method
TEST(PolynomialTest, SolveMethod) {
    std::list<float> terms = { 1.0, -3.0, 2.0 };
    Polynomial p(terms);
    auto result = p.solve();
    EXPECT_NEAR(result[0], 1.0, 0.01);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
