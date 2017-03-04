//
// Component4008.cpp for component4008 in /home/brunel/Rendu/Semestre_3/CPP/cpp_nanotekspice/src
// 
// Made by Brunel Axel
// Login   <axel.brunel@epitech.eu>
// 
// Started on  Thu Mar  2 17:12:30 2017 Brunel Axel
// Last update Sat Mar  4 16:40:11 2017 debrau_c
//

#include "ComponentCreator.hpp"

Component4008::Component4008(std::string const &name)
  : Component(name)
{
  _pinLink_t	tmppin;
  _nbPin = 16;
  _type = "Chipset 4008";
  for (unsigned int i = 0; i < _nbPin; i++)
    {
      tmppin._pin = nts::UNDEFINED;
      _pin.push_back(tmppin);
    }
  _pin[0]._type = PIN_IN;
  _pin[1]._type = PIN_IN;
  _pin[2]._type = PIN_IN;
  _pin[3]._type = PIN_IN;
  _pin[4]._type = PIN_IN;
  _pin[5]._type = PIN_IN;
  _pin[6]._type = PIN_IN;
  _pin[7]._type = PIN_UNDEF;
  _pin[8]._type = PIN_IN;
  _pin[9]._type = PIN_OUT;
  _pin[10]._type = PIN_OUT;
  _pin[11]._type = PIN_OUT;
  _pin[12]._type = PIN_OUT;
  _pin[13]._type = PIN_OUT;
  _pin[14]._type = PIN_IN;
  _pin[15]._type = PIN_UNDEF;
}

Component4008::~Component4008()
{
}

void		Component4008::output1()
{
  _pin[9]._pin = tristate_adder(_pin[6]._pin, _pin[5]._pin, _pin[8]._pin);
  _pin[8]._pin = tristate_adder_sum(_pin[6]._pin, _pin[5]._pin, _pin[8]._pin);
}

void		Component4008::output2()
{
  _pin[10]._pin = tristate_adder(_pin[4]._pin, _pin[3]._pin, _pin[8]._pin);
  _pin[8]._pin = tristate_adder_sum(_pin[4]._pin, _pin[3]._pin, _pin[8]._pin);
}

void		Component4008::output3()
{
  _pin[11]._pin = tristate_adder(_pin[2]._pin, _pin[1]._pin, _pin[8]._pin);
  _pin[8]._pin = tristate_adder_sum(_pin[2]._pin, _pin[1]._pin, _pin[8]._pin);

}

void		Component4008::output4()
{
  _pin[12]._pin = tristate_adder(_pin[0]._pin, _pin[14]._pin, _pin[8]._pin);
  _pin[13]._pin = tristate_adder_sum(_pin[0]._pin, _pin[14]._pin, _pin[8]._pin);

}

nts::Tristate	Component4008::Compute(size_t pin_num_this)
{
  nts::Tristate	save = _pin[8]._pin;
  output1();
  output2();
  output3();
  output4();
  _pin[8]._pin = save;
  return (_pin[pin_num_this - 1]._pin);
}
