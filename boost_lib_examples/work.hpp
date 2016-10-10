#ifndef WORK_H
#define WORK_H

#include <boost/units/quantity.hpp>

//This is one way of overloading a function, in this case the work done by a force or torque,
//depending on the type of data you have.

template<class System,class Y>
boost::units::quantity<boost::units::unit<boost::units::energy_dimension,System>,Y>
work(boost::units::quantity<boost::units::unit<boost::units::force_dimension,System>,Y> F,
     boost::units::quantity<boost::units::unit<boost::units::length_dimension,System>,Y> dx)
{
    return F*dx;
}
template<class System,class Y>
boost::units::quantity<boost::units::unit<boost::units::energy_dimension,System>,Y>
work(boost::units::quantity<boost::units::unit<boost::units::torque_dimension,System>,Y> T,
     boost::units::quantity<boost::units::unit<boost::units::plane_angle_dimension,System>,Y> dphi)
{
    return T*dphi;
}

#endif // WORK_H
