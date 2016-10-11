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

#ifndef BITTYPE_H
#define BITTYPE_H
#include <basetype.h>
#include <string>

class bitType : public baseType<uint64_t>
{
public:
    bitType() : baseType(0) {}
    bitType(uint64_t t) : baseType(t) {}

    std::string toByte()
    {
       if(this->value() < (static_cast<uint64_t>(1)<<10)*8)
       {
           return std::to_string(this->value()/8) + " Byte";
       }
       else if(this->value() < (static_cast<uint64_t>(1)<<20)*8)
       {
           return std::to_string(this->value()/(static_cast<uint64_t>(1)<<10)/8) + " kByte";
       }
       else if(this->value() < (static_cast<uint64_t>(1)<<30)*8)
       {
           return std::to_string(this->value()/(static_cast<uint64_t>(1)<<20)/8) + " MByte";
       }
       else if(this->value() < (static_cast<uint64_t>(1)<<40)*8)
       {
           return std::to_string(this->value()/(static_cast<uint64_t>(1)<<30)/8) + " GByte";
       }
       else if(this->value() < (static_cast<uint64_t>(1)<<50)*8)
       {
           return std::to_string(this->value()/(static_cast<uint64_t>(1)<<40)/8) + " TByte";
       }
       else if(this->value() < (static_cast<uint64_t>(1)<<60)*8)
       {
           return std::to_string(this->value()/(static_cast<uint64_t>(1)<<50)/8) + " PByte";
       }
        else
       {
           return std::to_string(this->value()/(static_cast<uint64_t>(1)<<50)/8) + " PByte";
       }
    }

private:

    void print( ::std::ostream& os = std::cout ) const
    {
        if(this->value() < static_cast<uint64_t>(1)<<10)
        {
            os << this->value() << " bit";
        }
        else if(this->value() < static_cast<uint64_t>(1)<<20)
        {
            os << this->value()/(static_cast<uint64_t>(1)<<10) << " kbit";
        }
        else if(this->value() < static_cast<uint64_t>(1)<<30)
        {
            os << this->value()/(static_cast<uint64_t>(1)<<20) << " Mbit";
        }
        else if(this->value() < static_cast<uint64_t>(1)<<40)
        {
            os << this->value()/(static_cast<uint64_t>(1)<<30) << " Gbit";
        }
        else if(this->value() < static_cast<uint64_t>(1)<<50)
        {
            os << this->value()/(static_cast<uint64_t>(1)<<40) << " Tbit";
        }
        else if(this->value() < static_cast<uint64_t>(1)<<60)
        {
            os << this->value()/(static_cast<uint64_t>(1)<<50) << " Pbit";
        }
        else
        {
            os << this->value()/(static_cast<uint64_t>(1)<<50) << " Pbit";
        }
    }
};

#endif // BITTYPE_H
