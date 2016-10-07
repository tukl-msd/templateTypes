#ifndef ELECTRICAL_POWER_H
#define ELECTRICAL_POWER_H

#include <boost/units/quantity.hpp>

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
