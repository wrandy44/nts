//
// Component4001.cpp for  in /home/brunel_d/rendu/sem3/cpp/cpp_nanotekspice
// 
// Made by Axel Brunel
// Login   <brunel_d@epitech.net>
// 
// Started on  Wed Feb  8 15:06:09 2017 Axel Brunel
// Last update Fri Mar  3 02:09:14 2017 debrau_c
//

// #include "Component4001.hpp"
#include "ComponentCreator.hpp"

Component4001::Component4001(std::string const &name)
  : Component(name)
{
  _pinLink_t	tmppin;
  _nbPin = 14;
  _type = "Chipset 4001";
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

Component4001::~Component4001()
{
}

void		Component4001::output1()
{
  if (_pin[0]._pin == nts::FALSE && _pin[1]._pin == nts::FALSE)
    _pin[2]._pin = nts::TRUE;
  else if (_pin[0]._pin == nts::UNDEFINED && _pin[1]._pin == nts::UNDEFINED)
    _pin[2]._pin = nts::UNDEFINED;
  else
    _pin[2]._pin = nts::FALSE;
}

void		Component4001::output2()
{
  if (_pin[4]._pin == nts::FALSE && _pin[5]._pin == nts::FALSE)
    _pin[3]._pin = nts::TRUE;
  else if (_pin[4]._pin == nts::UNDEFINED && _pin[5]._pin == nts::UNDEFINED)
    _pin[3]._pin = nts::UNDEFINED;
  else
    _pin[3]._pin = nts::FALSE;
}

void		Component4001::output3()
{
  if (_pin[7]._pin == nts::FALSE && _pin[8]._pin == nts::FALSE)
    _pin[9]._pin = nts::TRUE;
  else if (_pin[7]._pin == nts::UNDEFINED && _pin[8]._pin == nts::UNDEFINED)
    _pin[9]._pin = nts::UNDEFINED;
  else
    _pin[9]._pin = nts::FALSE;
}

void		Component4001::output4()
{
  if (_pin[11]._pin == nts::FALSE && _pin[12]._pin == nts::FALSE)
    _pin[10]._pin = nts::TRUE;
  else if (_pin[11]._pin == nts::UNDEFINED && _pin[12]._pin == nts::UNDEFINED)
    _pin[10]._pin = nts::UNDEFINED;
  else
    _pin[10]._pin = nts::FALSE;
}

nts::Tristate	Component4001::Compute(size_t pin_num_this)
{
  output1();
  output2();
  output3();
  output4();
  return(_pin[pin_num_this - 1]._pin);
}
