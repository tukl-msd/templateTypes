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

#ifndef LINEAR_MOTION_H
#define LINEAR_MOTION_H

#include <boost/units/quantity.hpp>
#include <boost/function.hpp>
#include <boost/units/lambda.hpp>
#include <boost/lambda/bind.hpp>
#include <boost/units/systems/si/io.hpp>
#include <boost/units/systems/si/prefixes.hpp>

//This is another way of implementing a function of one or more variables.
//Still to be understood what are the pros and cons of this method.

namespace bl = boost::lambda;
namespace si = boost::units::si;

boost::units::quantity<si::length> position (boost::units::quantity<si::time> Tf,
                                   boost::units::quantity<si::acceleration> A,
                                   boost::units::quantity<si::velocity> Vi,
                                   boost::units::quantity<si::length> Si
                                   )
{
    boost::function<boost::units::quantity<si::length> (boost::units::quantity<si::time>) >
            pos = 0.5 * bl::var(A) * bl::_1 * bl::_1 + bl::var(Vi) * bl::_1 + bl::var(Si);

    return pos(Tf);
}

#endif // LINEAR_MOTION_H
