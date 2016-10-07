#ifndef LINEAR_MOTION_H
#define LINEAR_MOTION_H

#include <boost/units/quantity.hpp>
#include <boost/function.hpp>
#include <boost/units/lambda.hpp>
#include <boost/lambda/bind.hpp>
#include <boost/units/systems/si/io.hpp>
#include <boost/units/systems/si/prefixes.hpp>

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
