#include "fraction.h"

bool fraction::operator<(fraction const &other) const {
    fraction result = *this - other;
    return !((result.num < 0) ^ (result.denom < 0));
}

fraction fraction::operator-() const {
    fraction f(-num, denom);
    return f;
}

fraction &fraction::operator-=(fraction const &other) {
    return *this += -other;
}

fraction fraction::operator-(fraction const &other) const {
    return *this + -other;
}

fraction fraction::operator+(fraction const &other) const {
    fraction f(num, denom);
    f += other;
    return f;
}

void fraction::reduce() {
    for (int i = 2; i <= num; i++) {
        if (num % i == 0 && denom % i == 0) {
            num /= i;
            denom /= i;
            i--;
        }
    }
}

fraction &fraction::operator+=(fraction const &other) {
    int new_denom = denom * other.denom;
    int new_num = num * other.denom + denom * other.num;
    num = new_num;
    denom = new_denom;
    return *this;
}

#include <iostream>

void fraction::print() const {
    using namespace std;
    cout << num << "/" << denom << endl;
}