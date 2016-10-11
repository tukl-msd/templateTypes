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

#ifndef ELECTRICAL_POWER_H
#define ELECTRICAL_POWER_H

#include <boost/units/quantity.hpp>

//This is one way of overloading a function, in this case the power consumed by a resistor,
//depending on which values you know, in this case two from voltage, current and resistance.

template<class System,class Y>
boost::units::quantity<boost::units::unit<boost::units::power_dimension,System>,Y>
power(boost::units::quantity<boost::units::unit<boost::units::current_dimension,System>,Y> I,
     boost::units::quantity<boost::units::unit<boost::units::resistance_dimension,System>,Y> R)
{
    return I*I*R;
}

template<class System,class Y>
boost::units::quantity<boost::units::unit<boost::units::power_dimension,System>,Y>
power(boost::units::quantity<boost::units::unit<boost::units::electric_potential_dimension,System>,Y> V,
     boost::units::quantity<boost::units::unit<boost::units::resistance_dimension,System>,Y> R)
{
    return V*V/R;
}

template<class System,class Y>
boost::units::quantity<boost::units::unit<boost::units::power_dimension,System>,Y>
power(boost::units::quantity<boost::units::unit<boost::units::electric_potential_dimension,System>,Y> V,
     boost::units::quantity<boost::units::unit<boost::units::current_dimension,System>,Y> I)
{
    return V*I;
}

#endif // ELECTRICAL_POWER_H
