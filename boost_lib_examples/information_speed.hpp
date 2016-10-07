#ifndef INFORMATION_SPEED_H
#define INFORMATION_SPEED_H

#include <boost/units/systems/si.hpp>
#include <boost/units/systems/information.hpp>


namespace boost {
namespace units {

/// derived dimension for speed of information: INFO (dibitsmensionless) T^-1
typedef derived_dimension<information_base_dimension,1,
                          time_base_dimension,-1>::type information_speed_dimension;

namespace information_speed {
namespace bit_sec {

typedef make_system<boost::units::information::bit_base_unit,
                    boost::units::si::second_base_unit>::type system;

typedef unit<information_speed_dimension, bit_sec::system> information_speed;

typedef information_speed is;

} //namespace bit_sec

BOOST_UNITS_STATIC_CONSTANT(bit_per_second,bit_sec::information_speed);
BOOST_UNITS_STATIC_CONSTANT(bits_per_second,bit_sec::information_speed);

namespace byte_sec {

typedef make_system<boost::units::information::byte_base_unit,
                    boost::units::si::second_base_unit>::type system;

typedef unit<information_speed_dimension, byte_sec::system> information_speed;

typedef information_speed is;

} //namespace byte_sec

BOOST_UNITS_STATIC_CONSTANT(byte_per_second,byte_sec::information_speed);
BOOST_UNITS_STATIC_CONSTANT(bytes_per_second,byte_sec::information_speed);

} //information_speed
} //namescape units
} //namespace boost

#endif // INFORMATION_SPEED_H
