#include <iostream>
#include <assert.h>

#include "basetype.h"
#include "bittype.h"

using namespace std;

void testBaseType()
{
    //Test initializations
    baseType<uint64_t> a(5);
    baseType<uint64_t> z;
    z = a;
    z = 5;
    baseType<uint64_t> b(a);

    // Test Addition and Substraction:
    baseType<uint64_t> c;
    c = a + b + 5;
    assert(c.value() == 15);
    baseType<uint64_t> d;
    d = c - a - 5;
    assert(d.value() == 5);
    d = 5 - a;
    assert(d.value() == 0);
    d = 5;
    d += 1;
    assert(d.value() == 6);
    d -= 1;
    assert(d.value() == 5);
    d--;
    --d;
    assert(d.value() == 3);
    d++;
    ++d;
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
}

void testBitType()
{
    std::cout << "foo: " << std::to_string(static_cast<uint64_t>(2)<<10) << std::endl;
    bitType a(128);
    std::cout << a << " (" << a.toByte() << ")" << endl;
    a *= 8;
    std::cout << a << " (" << a.toByte() << ")" << endl;
    a *= 1024;
    std::cout << a << " (" << a.toByte() << ")" << endl;
    a *= 1024;
    std::cout << a << " (" << a.toByte() << ")" << endl;
    a *= 1024;
    std::cout << a << " (" << a.toByte() << ")" << endl;
    a *= 8;
    std::cout << a << " (" << a.toByte() << ")" << endl;
    a *= 1024;
    std::cout << a << " (" << a.toByte() << ")" << endl;
}

int main()
{
    testBaseType();
    testBitType();
    std::cout<< "All tests passed" << std::endl;
}




