#include <iostream>
#include "fraction.h"

using namespace std;

int main() {
    fraction f1(3, 4);
    fraction f2(1, 4);
    fraction f3 = f1 + f2;
    f3.reduce();
    f3.print();
    return 0;
}