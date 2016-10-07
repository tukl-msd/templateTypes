/*
 * Copyright (c) 2016, University of Kaiserslautern
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from
 *    this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
 * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER
 * OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * Authors:
 *    Matthias Jung
 */

#include <iostream>
#include <assert.h>

#include "basetype.h"
#include "bittype.h"

using namespace std;

void testBaseType()
{
    //Test initializations
    std::cout << "baseType<uint64_t> a(5);\t";
    baseType<uint64_t> a(5);
    std::cout << "baseType<uint64_t> z;\t";
    baseType<uint64_t> z;
    std::cout << "z = a;\t";
    z = a;
    std::cout << "z = 5;\t";
    z = 5;
    std::cout << "baseType<uint64_t> b(a);\t";
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




