//
// Component4030.cpp for 4030 in /home/brunel/Rendu/Semestre_3/CPP/nts/src
// 
// Made by Brunel Axel
// Login   <axel.brunel@epitech.eu>
// 
// Started on  Fri Mar  3 22:11:30 2017 Brunel Axel
// Last update Fri Mar  3 22:19:50 2017 Brunel Axel
//

#include "ComponentCreator.hpp"

Component4030::Component4030(std::string const &name)
  : Component(name)
{
  _pinLink_t	tmppin;
  _nbPin = 14;
  _type = "Chipset 4030";
  for (unsigned int i = 0; i < _nbPin; i++)
    {
      tmppin._pin = nts::UNDEFINED;
      _pin.push_back(tmppin);
    }
  _pin[0]._type = PIN_IN;
  _pin[1]._type = PIN_IN;
  _pin[2]._type = PIN_OUT;

  _pin[3]._type = PIN_OUT;
  _pin[4]._type = PIN_IN;
  _pin[5]._type = PIN_IN;

  _pin[6]._type = PIN_UNDEF;
  _pin[7]._type = PIN_IN;
  _pin[8]._type = PIN_IN;

  _pin[9]._type = PIN_OUT;
  _pin[10]._type = PIN_OUT;
  _pin[11]._type = PIN_IN;

  _pin[12]._type = PIN_IN;
  _pin[13]._type = PIN_UNDEF;
  
}

Component4030::~Component4030()
{
}

nts::Tristate	Component4030::Compute(size_t pin_num_this)
{
  _pin[2]._pin = tristate_xor(_pin[0]._pin, _pin[1]._pin);
  _pin[3]._pin = tristate_xor(_pin[4]._pin, _pin[5]._pin);
  _pin[9]._pin = tristate_xor(_pin[7]._pin, _pin[8]._pin);
  _pin[10]._pin = tristate_xor(_pin[11]._pin, _pin[12]._pin);
  return (_pin[pin_num_this - 1]._pin);
}
