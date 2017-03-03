/*
** Component4071.cpp for azd in /home/debrau_c/bin
** Made by Carl DEBRAUWERE
** Login   <debrau_c@epitech.net>
** 
** Started on  Mon Jan 16 09:33:45 2017 Carl DEBRAUWERE
// Last update Fri Mar  3 02:48:43 2017 debrau_c
*/

#include "Component4071.hpp"

Component4071::Component4071(const std::string &n):Component(n){
  _pinLink_t	tmppin;
  _nbPin = 14;
  _type = "Chipset 4071";
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

Component4071::~Component4071(){

}

nts::Tristate	Component4071::Compute(size_t pin_num_this)
{
  _pin[2]._pin = (_pin[0]._pin || _pin[1]._pin);
  _pin[3]._pin = (_pin[4]._pin || _pin[5]._pin);
  _pin[9]._pin = (_pin[7]._pin || _pin[8]._pin);
  _pin[10]._pin = (_pin[11]._pin || _pin[11]._pin);
}
