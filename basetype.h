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

#ifndef GENERIC_TYPE_H
#define GENERIC_TYPE_H

#include<iostream>

template <class T>
class baseType
{

public:

    // Constructors:
    baseType() : _value( 0 ) {}
    baseType( const baseType& t) : _value( t._value ) {}
    baseType( const T& t) : _value( t ) {}

    // Getter function:
    T value() const
    {
        return _value;
    }

    // Assignment operator:
    baseType& operator = ( const baseType& t )
    {
        _value = t._value;
        return *this;
    }

    // Relational operators:
    bool operator == ( const baseType& t) const
    {
        return ( _value == t._value );
    }
    bool operator != ( const baseType& t) const
    {
        return ( _value != t._value );
    }
    bool operator <  ( const baseType& t) const
    {
        return ( _value < t._value );
    }
    bool operator <= ( const baseType& t) const
    {
        return ( _value <= t._value );
    }
    bool operator >  ( const baseType& t) const
    {
        return ( _value > t._value );
    }
    bool operator >= ( const baseType& t) const
    {
        return ( _value >= t._value );
    }

    // Arithmetic operators:
    baseType& operator += ( const baseType& t )
    {
        _value += t._value;
        return *this;
    }
    baseType& operator -= ( const baseType& t )
    {
        _value -= t._value;
        return *this;
    }
    baseType& operator *= ( const baseType& t )
    {
        _value *= t._value;
        return *this;
    }
    baseType& operator /= ( const baseType& t )
    {
        _value /= t._value;
        return *this;
    }
    baseType& operator %= ( const baseType& t )
    {
        _value %= t._value;
        return *this;
    }
    baseType& operator ++ () // for ++d
    {
        _value += 1;
        return *this;
    }
    baseType& operator -- ()
    {
        _value -= 1;
        return *this;
    }
    baseType& operator ++ (int) // for d++
    {
        _value += 1;
        return *this;
    }
    baseType& operator -- (int)
    {
        _value -= 1;
        return *this;
    }

    friend const baseType
    operator + ( const baseType& t1, const baseType& t2 )
    {
        return baseType( t1 ) += t2;
    }
    friend const baseType
    operator / ( const baseType& t1, const baseType& t2 )
    {
        return baseType( t1 ) /= t2;
    }
    friend const baseType
    operator * ( const baseType& t1, const baseType& t2 )
    {
        return baseType( t1 ) *= t2;
    }
    friend const baseType
    operator - ( const baseType& t1, const baseType& t2 )
    {
        return baseType( t1 ) -= t2;
    }
    friend const baseType
    operator % ( const baseType& t1, const baseType& t2 )
    {
        baseType tmp(t1);
        return tmp %= t2;
    }

    // print function
    virtual void print( ::std::ostream& os = std::cout ) const
    {
        os << _value;
    }

    friend ::std::ostream&
    operator << (::std::ostream& os, const baseType &t )
    {
        t.print( os );
        return os;
    }

private:

    T _value;
};

#endif
