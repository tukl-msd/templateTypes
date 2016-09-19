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
