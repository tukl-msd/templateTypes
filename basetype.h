#ifndef GENERIC_TYPE_H
#define GENERIC_TYPE_H

#include<iostream>

class baseType
{
public:

    typedef uint64_t value_type;

    // Constructors
    baseType();
    baseType( const baseType& );
    baseType( const uint64_t& );

    static baseType from_value( value_type );

    // Assignment operator
    baseType& operator = ( const baseType& );

    // Conversion functions
    value_type value() const;

    // relational operators
    bool operator == ( const baseType& ) const;
    bool operator != ( const baseType& ) const;
    bool operator <  ( const baseType& ) const;
    bool operator <= ( const baseType& ) const;
    bool operator >  ( const baseType& ) const;
    bool operator >= ( const baseType& ) const;

    // arithmetic operators
    baseType& operator += ( const baseType& );
    baseType& operator -= ( const baseType& );

    baseType& operator *= ( const baseType& );
    baseType& operator /= ( const baseType& );
    baseType& operator %= ( const baseType& );

    friend const baseType operator + ( const baseType&, const baseType& );
    friend const baseType operator - ( const baseType&, const baseType& );
    friend const baseType operator * ( const baseType&, const baseType& );
    friend const baseType operator / ( const baseType&, const baseType& );
    friend const baseType operator % ( const baseType&, const baseType& );

    // print function
    void print( ::std::ostream& os = std::cout ) const;

private:

    value_type _value;
};

// print operator
inline ::std::ostream& operator << ( ::std::ostream&, const baseType& );


// constructors
inline
baseType::baseType()
: _value( 0 )
{}

inline
baseType::baseType( const baseType& t )
: _value( t._value )
{}

inline
baseType::baseType( const uint64_t& t )
: _value( t )
{}


// assignment operator
inline
baseType&
baseType::operator = ( const baseType& t )
{
    _value = t._value;
    return *this;
}

// conversion functions
inline
baseType::value_type
baseType::value() const
{
    return _value;
}

// relational operators
inline
bool
baseType::operator == ( const baseType& t ) const
{
    return ( _value == t._value );
}

inline
bool
baseType::operator != ( const baseType& t ) const
{
    return ( _value != t._value );
}

inline
bool
baseType::operator < ( const baseType& t ) const
{
    return ( _value < t._value );
}

inline
bool
baseType::operator <= ( const baseType& t ) const
{
    return ( _value <= t._value );
}

inline
bool
baseType::operator > ( const baseType& t ) const
{
    return ( _value > t._value );
}

inline
bool
baseType::operator >= ( const baseType& t ) const
{
    return ( _value >= t._value );
}


// arithmetic operators
inline
baseType&
baseType::operator += ( const baseType& t )
{
    _value += t._value;
    return *this;
}

inline
baseType&
baseType::operator -= ( const baseType& t )
{
    _value -= t._value;
    return *this;
}

inline
const baseType
operator + ( const baseType& t1, const baseType& t2 )
{
    return baseType( t1 ) += t2;
}

inline
const baseType
operator / ( const baseType& t1, const baseType& t2 )
{
    return baseType( t1 ) /= t2;
}

inline
const baseType
operator * ( const baseType& t1, const baseType& t2 )
{
    return baseType( t1 ) *= t2;
}

inline
const baseType
operator - ( const baseType& t1, const baseType& t2 )
{
    return baseType( t1 ) -= t2;
}

inline
baseType&
baseType::operator *= ( const baseType& t )
{
    _value *= t._value;
    return *this;
}

inline
baseType&
baseType::operator /= ( const baseType& t )
{
    _value /= t._value;
    return *this;
}

inline
baseType&
baseType::operator %= ( const baseType& t )
{
    _value %= t._value;
    return *this;
}

void baseType::print(::std::ostream &os) const
{
   os << _value;
}

inline
const baseType
operator % ( const baseType& t1, const baseType& t2 )
{
    baseType tmp(t1);
    return tmp %= t2;
}

// print operator

inline
::std::ostream&
operator << ( ::std::ostream& os, const baseType& t )
{
    t.print( os );
    return os;
}

// friend operator declarations:
const baseType operator + ( const baseType&, const baseType& );
const baseType operator - ( const baseType&, const baseType& );
const baseType operator / ( const baseType&, const baseType& );
const baseType operator * ( const baseType&, const baseType& );

/*
template <class T>
class baseType {
  private:
    T _value;

  public:
    baseType();
    baseType(baseType &o);
    baseType(T t);
    T value() const;
    void untouched();
    void setValue(const T &value);

    // Operators:
    baseType operator +  (baseType<T> const& other);
    void     operator += (baseType<T> const& other);

    baseType operator -  (baseType<T> const& other);
    void     operator -= (baseType<T> const& other);

    baseType operator /  (baseType<T> const& other);
    void     operator /= (baseType<T> const& other);
};

template <class T>
baseType<T>::baseType()
{
}

template <class T>
baseType<T>::baseType(baseType &o)
{
    this->setValue(o.value());
}

template <class T>
baseType<T>::baseType(T t)
{
   this->setValue(t);
}

template <class T>
T baseType<T>::value() const
{
    return _value;
}

template <class T>
void baseType<T>::setValue(const T &value)
{
    _value = value;
}

template <typename T>
baseType<T> baseType<T>::operator+(baseType<T> const &other)
{
    baseType<T> tmp;
    tmp.setValue(this->_value + other.value());
    return tmp;
}

template <typename T>
void baseType<T>::operator+=(baseType<T> const &other)
{
    this->_value += other.value();
}

template <typename T>
baseType<T> baseType<T>::operator-(baseType<T> const &other)
{
    baseType<T> tmp;
    tmp.setValue(this->_value - other.value());
    return tmp;
}

template <typename T>
void baseType<T>::operator-=(baseType<T> const &other)
{
    this->_value -= other.value();
}

template <typename T>
inline
baseType<T> baseType<T>::operator/(baseType<T> const &other)
{
    baseType<T> tmp;
    tmp.setValue(this->_value / other.value());
    return tmp;
}

template <typename T>
void baseType<T>::operator/=(baseType<T> const &other)
{
    this->_value /= other.value();
}
*/
#endif
