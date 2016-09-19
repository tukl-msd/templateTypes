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
       else
       {
           return "ERROR";
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
        else
        {
            os << "ERROR";
        }
    }
};

#endif // BITTYPE_H
