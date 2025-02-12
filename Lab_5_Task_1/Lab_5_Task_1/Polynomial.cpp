#include "Polynomial.h"
#include <cmath>

// (G5) N-th degree polynomial
Polynomial::Polynomial() {
    terms = { 0.0, 7.0, 0.0, -1.3, 2.0 };
}

Polynomial::Polynomial(const std::vector<float>& termsParam) {
    terms = termsParam;
}

Polynomial::Polynomial(const std::list<float>& termsParam) {
    terms.assign(termsParam.begin(), termsParam.end());
}
// (G5) N-th degree polynomial


// (G5) Operators overload
std::ostream& operator<<(std::ostream& os, const Polynomial& polynomial) {
    for (size_t i = polynomial.terms.size(); i-- > 0;) {
        if (polynomial.terms[i] != 0) {
            if (i != polynomial.terms.size() - 1 && polynomial.terms[i] > 0)
                os << " + ";
            else if (polynomial.terms[i] < 0)
                os << " - ";

            if (fabs(polynomial.terms[i]) != 1 || i == 0)
                os << fabs(polynomial.terms[i]);

            if (i > 0) {
                os << "x";
                if (i > 1)
                    os << "^" << i;
            }
        }
    }
    return os;
}

Polynomial Polynomial::operator+(const Polynomial& polynomial) {
    size_t max_size = std::max(this->terms.size(), polynomial.terms.size());
    std::vector<float> new_terms(max_size, 0);

    for (size_t i = 0; i < max_size; ++i) {
        if (i < this->terms.size()) {
            new_terms[i] += this->terms[i];
        }
        if (i < polynomial.terms.size()) {
            new_terms[i] += polynomial.terms[i];
        }
    }
    return Polynomial(new_terms);
}

Polynomial Polynomial::operator-(const Polynomial& polynomial) {
    size_t max_size = std::max(this->terms.size(), polynomial.terms.size());
    std::vector<float> new_terms(max_size, 0);

    for (size_t i = 0; i < new_terms.size(); ++i) {
        if (i < this->terms.size())
            new_terms[i] += this->terms[i];
        if (i < polynomial.terms.size())
            new_terms[i] -= polynomial.terms[i];
    }
    return Polynomial(new_terms);
}

Polynomial Polynomial::operator*(float scalar) {
    std::vector<float> new_terms(this->terms.size());

    for (size_t i = 0; i < this->terms.size(); i++) {
        new_terms[i] = this->terms[i] * scalar;
    }
    return Polynomial(new_terms);
}

Polynomial Polynomial::operator*(const Polynomial& polynomial) {
    std::vector<float> new_terms(this->terms.size() + polynomial.terms.size() - 1);

    for (int i = 0; i < this->terms.size(); i++) {
        for (int j = 0; j < polynomial.terms.size(); j++) {
            new_terms[i + j] += this->terms[i] * polynomial.terms[j];
        }
    }
    return Polynomial(new_terms);
}

const float Polynomial::operator[](size_t index)  {
    return terms.at(index);
}
// (G5) Operators overload


// (G5) Function overload
std::vector<float> Polynomial::evaluate() {
    float a = terms[2], b = terms[1], c = terms[0];
    float delta = b * b - 4 * a * c;
    
    std::vector<float> roots(2);
    
    roots[0] = (-b + sqrt(delta)) / (2 * a);
    roots[1] = (-b - sqrt(delta)) / (2 * a);
    return roots;
}

std::vector<float> Polynomial::evaluate(float number) {
    float totalsum = 0, sum;
    for (size_t i = 0; i < terms.size(); i++) {
        sum = 1;
        for (size_t a = i; a > 0; a--) {
            sum *= number;
        }
        totalsum += sum * terms[i];
    }

    return {totalsum};
}
// (G5) Function overload

// (G5) Solving*
std::vector<float> Polynomial::solve() {
    double a = -500, b = 500;

    if (evaluate(a)[0] * evaluate(b)[0] >= 0) {
        std::cout << "This function is talented enough to solve the equation, unfortunately :(" << std::endl;
        return {0};
    }

    float c = a;
    while ((b - a) >= 0.01) {
        c = (a + b) / 2;

        if (evaluate(c)[0] == 0.0)
            break;

        else if (evaluate(c)[0] * evaluate(a)[0] < 0)
            b = c;
        else
            a = c;
    }
    return {c};
}
// (G5)Solving*

int main() {
    std::vector<float> terms1 = { 1, 2, 3 };
    std::vector<float> terms2 = { 3, 4 };
    Polynomial p1(terms1);
    Polynomial p2(terms2);
    Polynomial p7;

    Polynomial p3 = p1 + p2;
    Polynomial p4 = p1 - p2;
    Polynomial p5 = p1 * p2;
    Polynomial p6 = p1 * 5;

    std::cout << p1 << std::endl;
    std::cout << p2 << std::endl;
    std::cout << p3 << std::endl;
    std::cout << p4 << std::endl;
    std::cout << p5 << std::endl;
    std::cout << p6 << std::endl;
    std::cout << p7 << std::endl;

    std::vector<float> terms3 = { 2, 0, 1, 1 };
    Polynomial p8(terms3);

    std::vector<float> solution1 = p8.evaluate();
    std::cout << solution1[0] << std::endl;
    std::cout << solution1[1] << std::endl;
    std::vector <float> solution2 = p8.evaluate(2);
    std::cout << solution2[0] << std::endl;
    
    std::vector<float> solution3 = p8.solve();
    std::cout << solution3[0] << std::endl;

    return 0;
}