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

#ifndef BOOST_EXERCISE_H
#define BOOST_EXERCISE_H

#include <iostream>
#include <string>

#include <boost/units/systems/si/io.hpp>
#include <boost/units/systems/si/prefixes.hpp>

#include "work.h"
#include "electrical_power.h"
#include "information_speed.h"
#include "linear_motion.h"

using namespace std;
namespace bu = boost::units;
namespace si = boost::units::si;
namespace inf = boost::units::information;

namespace is = boost::units::information_speed;
namespace bis = boost::units::information_speed::bit_sec;
namespace bys = boost::units::information_speed::byte_sec;

#define UNIT_CONVERSION(From, To) static_cast<bu::quantity<To>> (From)

int boostExercise(void)
{
    int menu_int=1;
    while (menu_int) {
        cout << endl << "Hello!" << endl
             << "Please tell me what do you want to calculate:" << endl
             << "1: Work done by a force through a given distance;" << endl
             << "2: Work done by a torque through a given angular distance;" << endl
             << "3: Power consumption of a resistor;" << endl
             << "4: Position of an accelerated particle;" << endl
             << "5: Download rate from connection speed;" << endl
             << "0: Nothing!" << endl
             << endl;

        cin >> menu_int;

        switch (menu_int) {
        case 1:{
            double F_m_i, D_m_i;
            cout << "Please tell me the magnitude of the force in Newtons:" << endl;
            cin >> F_m_i;
            bu::quantity<si::force> F = F_m_i * si::newtons;
            cout << "Please tell me the distance traveled in meters:" << endl;
            cin >> D_m_i;
            bu::quantity<si::length> D = D_m_i * si::meter;
            bu::quantity<si::energy> W = work(F,D);
            cout << bu::engineering_prefix << "The work done was " << W << "!" << endl;
        }break;

        case 2:{
            double T_m_i, PHI_m_i;
            cout << "Please tell me the magnitude of the torque in Newtons*Meters:" << endl;
            cin >> T_m_i;
            bu::quantity<si::torque> T = T_m_i * si::newton_meter;
            cout << "Please tell me the angular distance traveled in radians:" << endl;
            cin >> PHI_m_i;
            bu::quantity<si::plane_angle> PHI = PHI_m_i * si::radians;
            bu::quantity<si::energy> W = work(T,PHI);
            cout << bu::engineering_prefix << "The work done was " << W << "!" << endl;
        }break;

        case 3:{
            string V_m_i, I_m_i, R_m_i;

            cout << "Please tell me the magnitude of the voltage between the terminals of the resistor in volts (type ? if you don't know!):" << endl;
            cin >> V_m_i;

            cout << "Please tell me the magnitude of the current passing through the resistor in amperes (type ? if you don't know!):" << endl;
            cin >> I_m_i;

            cout << "Please tell me its resistance in ohms (type ? if you don't know!):" << endl;
            cin >> R_m_i;
            bu::quantity<si::power> P;

            if (V_m_i[0] == '?') {
                bu::quantity<si::current> I = stod(I_m_i) * si::ampere;
                bu::quantity<si::resistance> R = stod(R_m_i) * si::ohms;
                P = power(I,R);
            }
            else if (I_m_i[0] == '?') {
                bu::quantity<si::electric_potential> V = stod(V_m_i) * si::volt;
                bu::quantity<si::resistance> R = stod(R_m_i) * si::ohms;
                P = power(V,R);
            }
            else if (R_m_i[0] == '?') {
                bu::quantity<si::electric_potential> V = stod(V_m_i) * si::volt;
                bu::quantity<si::current> I = stod(I_m_i) * si::ampere;
                P = power(V,I);
            }
            else {
                bu::quantity<si::electric_potential> V = stod(V_m_i) * si::volt;
                bu::quantity<si::current> I = stod(I_m_i) * si::ampere;
                bu::quantity<si::resistance> R = stod(R_m_i) * si::ohms;
                if (power(V,R) == power(I,R)) {
                    P = power(V,I);
                }
                else {
                    cout << "There is something wrong with your calculation! Try mine =)" << endl;
                    break;
                }
            }
            cout << bu::engineering_prefix << "The power consumption is " << P << "!" << endl;
        }break;

        case 4:{
            double S0_m_i, V0_m_i, A_m_i, Tf_m_i;
            cout << "Please tell me the initial position of the particle in meters:" << endl;
            cin >> S0_m_i;
            bu::quantity<si::length> S0 = S0_m_i * si::meter;
            cout << "Please tell me the initial velocity of the particle in meters per second:" << endl;
            cin >> V0_m_i;
            bu::quantity<si::velocity> V0 = V0_m_i * si::meter_per_second;
            cout << "Please tell me the acceleration of the particle in meters per second squared:" << endl;
            cin >> A_m_i;
            bu::quantity<si::acceleration> A(A_m_i * si::meter_per_second_squared);
            cout << "Please tell me the moment in time you have interest in in seconds:" << endl;
            cin >> Tf_m_i;
            bu::quantity<si::time> Tf(Tf_m_i * si::second);
            bu::quantity<si::length> Pf = position(Tf,A,V0,S0);
            cout << bu::engineering_prefix << "The final position of the particle is " << Pf << "!" << endl;
        }break;

        case 5:{
            double CS_m_i;
            cout << "Please tell me you connection speed in Mbps:" << endl;
            cin >> CS_m_i;

            //NOTE 1: si::MEBI = 2^20 differ from si::MEGA = 10^6. Commonly mistaken conversion factors!
            //NOTE 2: Implicit conversion (from b/s to B/s) made by declaring
            //         DR as B/s, but assigning the b/s unit to the user input.
            //         Could have been done by a static_cast, as shown the the UNIT_CONVERSION macro.
            bu::quantity<bys::is> DR(CS_m_i * inf::mebi * is::bit_per_second);

            cout << bu::binary_prefix << "Your download rate is " << DR << "!" << endl;
        }break;

        case 0:{
            cout << "Ok, have a nice day!" << endl;
        }break;

        default:
                cout << "I couldn't understand you, please try again!" << endl;
                break;
        }
    }

    return 0;
}

#endif // BOOST_EXERCISE_H
