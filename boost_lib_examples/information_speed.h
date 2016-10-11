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
 *    Andr'e Lucas Chinazzo
 */

#ifndef INFORMATION_SPEED_H
#define INFORMATION_SPEED_H

#include <boost/units/systems/si.hpp>
#include <boost/units/systems/information.hpp>

//This is an example on how to create a new dimension and unit.
//Most probably you will never add a new base dimension.
//New dimensions can be added to the units namespace,
//while new units should be within its own namespace.

namespace boost {
namespace units {

/// derived dimension for speed of information: INFO (dimensionless) T^-1
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
