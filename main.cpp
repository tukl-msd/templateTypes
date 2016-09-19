#include <iostream>
#include <assert.h>
#include "basetype.h"

using namespace std;

int main()
{
    //Test initializations
    baseType a(5);
    baseType z;
    z = a;
    z = 5;
    baseType b(a);

    // Test Addition and Substraction:
    baseType c;
    c = a + b + 5;
    assert(c.value() == 15);
    baseType d;
    d = c - a - 5;
    assert(d.value() == 5);
    d = 5 - a;
    assert(d.value() == 0);
    d = 5;
    d += 1;
    assert(d.value() == 6);
    d -= 1;
    assert(d.value() == 5);

    // Test Division and Multiplication:
    a = 15;
    b = 3;
    c = a / b;
    assert(c.value() == 5);
    c = a / 5;
    assert(c.value() == 3);
    a = 15 / c;
    assert(a.value() == 5);
    a = 15 / 5;
    assert(c.value() == 3);
    a = 5;
    b = 5;
    c = a * b;
    assert(c.value() == 25);
    c = a * 4;
    assert(c.value() == 20);
    a = 4;
    c = 5 * a;
    assert(c.value() == 20);

    // Test Modulo:
    a = 25;
    b = 5;
    c = a % b;
    assert(c.value() == 0);

    // Test Streams:
    std::cout << a << std::endl;

    // Test Comperators
    a = 25;
    b = 25;
    c = 5;
    assert(a == b);
    assert(c <  b);
    assert(b >  c);
    assert(c <= b);
    assert(b >= c);
    assert(b <= b);
    assert(b >= b);
    assert(b != c);


    std::cout<< "All tests passed" << std::endl;
}


