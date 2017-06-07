#ifndef TYPES_HPP
#define TYPES_HPP

#include <ostream>

enum class ShipClass
{
  UNDEFINED = 0,
  HUMAN
};

inline std::ostream& operator<<(std::ostream &os, ShipClass value)
{
  switch (value)
  {
  case ShipClass::UNDEFINED: os << "UNDEFINED"; break;
  case ShipClass::HUMAN: os << "HUMAN"; break;
  }
  return os;
}

enum class TurretSize
{
  UNDEFINED = 0,
  BIG,
  SMALL
};

inline std::ostream& operator<<(std::ostream &os, TurretSize value)
{
  switch (value)
  {
  case TurretSize::UNDEFINED: os << "UNDEFINED"; break;
  case TurretSize::BIG: os << "BIG"; break;
  case TurretSize::SMALL: os << "SMALL"; break;
  }
  return os;
}

enum class TurretClass
{
  UNDEFINED = 0,
  ENERGY,
  BALLISTIC,
  BIO,
  PLASMA
};

inline std::ostream& operator<<(std::ostream &os, TurretClass value)
{
  switch (value)
  {
  case TurretClass::UNDEFINED: os << "UNDEFINED"; break;
  case TurretClass::ENERGY: os << "ENERGY"; break;
  case TurretClass::BALLISTIC: os << "BALLISTIC"; break;
  case TurretClass::BIO: os << "BIO"; break;
  case TurretClass::PLASMA: os << "PLASMA"; break;
  }
  return os;
}

#endif // TYPES_HPP
