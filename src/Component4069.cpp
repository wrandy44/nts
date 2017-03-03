/*
** Component4069.cpp for azd in /home/debrau_c/bin
** Made by Carl DEBRAUWERE
** Login   <debrau_c@epitech.net>
** 
** Started on  Mon Jan 16 09:33:45 2017 Carl DEBRAUWERE
// Last update Thu Mar  2 22:20:27 2017 debrau_c
*/


#include "Component4069.hpp"

Component4069::Component4069(std::string n):Component(n){
  _pinLink_t	tmppin;
  _nbPin = 14;
  _type = "Chipset 4069";
  for (unsigned int i = 0; i < _nbPin; i++)
    {
      tmppin._pin = nts::UNDEFINED;
      _pin.push_back(tmppin);
    }
  _pin[0]._type = PIN_IN;
  _pin[1]._type = PIN_OUT;
  _pin[2]._type = PIN_IN;
  _pin[3]._type = PIN_OUT;
  _pin[4]._type = PIN_IN;
  _pin[5]._type = PIN_OUT;
  _pin[6]._type = PIN_UNDEF;
  _pin[7]._type = PIN_OUT;
  _pin[8]._type = PIN_IN;
  _pin[9]._type = PIN_OUT;
  _pin[10]._type = PIN_IN;
  _pin[11]._type = PIN_OUT;
  _pin[12]._type = PIN_IN;
  _pin[13]._type = PIN_UNDEF;
}

Component4069::~Component4069(){

}

nts::Tristate	Component4069::Compute(size_t pin_num_this)
{
  
  if (_pin[0]._pin != nts::Tristate::UNDEFINED)
    _pin[1]._pin = !_pin[0]._pin;
  else
    _pin[1]._pin = nts::Tristate::UNDEFINED;

  if (_pin[2]._pin != nts::Tristate::UNDEFINED)
    _pin[3]._pin = !_pin[2]._pin;
  else
    _pin[3]._pin = nts::Tristate::UNDEFINED;
  
  if (_pin[4]._pin != nts::Tristate::UNDEFINED)
    _pin[5]._pin = !_pin[4]._pin;
  else
    _pin[5]._pin = nts::Tristate::UNDEFINED;

  if (_pin[8]._pin != nts::Tristate::UNDEFINED)
    _pin[7]._pin = !_pin[8]._pin;
  else
    _pin[7]._pin = nts::Tristate::UNDEFINED;
  
  if (_pin[10]._pin != nts::Tristate::UNDEFINED)
    _pin[9]._pin = !_pin[10]._pin;
  else
    _pin[9]._pin = nts::Tristate::UNDEFINED;
  
  if (_pin[12]._pin != nts::Tristate::UNDEFINED)
    _pin[11]._pin = !_pin[12]._pin;
  else
    _pin[11]._pin = nts::Tristate::UNDEFINED;
}
