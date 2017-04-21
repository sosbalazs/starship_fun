#ifndef TYPES_H
#define TYPES_H

#include <ostream>

namespace ShipClass
{
  enum Value
  {
    UNDEFINED = 0,
    HUMAN
  };
  inline std::ostream& operator<<(std::ostream &os, ShipClass::Value value)
  {
    switch (value)
    {
    case UNDEFINED: os << "UNDEFINED"; break;
    case HUMAN: os << "HUMAN"; break;
    default: os << "UNKNOWN(" << (int)value << ")"; break;
    }
    return os;
  }
}

namespace TurretSize
{
  enum Value
  {
    UNDEFINED = 0,
    BIG,
    SMALL
  };
  inline std::ostream& operator<<(std::ostream &os, ShipClass::Value value)
  {
    switch (value)
    {
    case UNDEFINED: os << "UNDEFINED"; break;
    case BIG: os << "BIG"; break;
    case SMALL: os << "SMALL"; break;
    default: os << "UNKNOWN(" << (int)value << ")"; break;
    }
    return os;
  }
}

namespace TurretClass
{
  enum Value
  {
    UNDEFINED = 0,
    ENERGY,
    BULLET,
    BIO,
    PLASMA
  };
  inline std::ostream& operator<<(std::ostream &os, ShipClass::Value value)
  {
    switch (value)
    {
    case UNDEFINED: os << "UNDEFINED"; break;
    case ENERGY: os << "ENERGY"; break;
    case BULLET: os << "BULLET"; break;
    case BIO: os << "BIO"; break;
    case PLASMA: os << "PLASMA"; break;
    default: os << "UNKNOWN(" << (int)value << ")"; break;
    }
    return os;
  }
}

#endif // TYPES_H
