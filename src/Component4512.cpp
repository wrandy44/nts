/*
** Component4512.cpp for azd in /home/debrau_c/bin
** Made by Carl DEBRAUWERE
** Login   <debrau_c@epitech.net>
** 
** Started on  Mon Jan 16 09:33:45 2017 Carl DEBRAUWERE
// Last update Fri Mar  3 04:35:16 2017 debrau_c
*/

#include "Component4512.hpp"

Component4512::Component4512(const std::string &n):Component(n){
  _pinLink_t	tmppin;
  _nbPin = 16;
  _type = "Chipset 4512";
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
  _pin[7]._type = PIN_IN;
  _pin[8]._type = PIN_UNDEF;
  _pin[9]._type = PIN_IN;//Inhibit
  _pin[10]._type = PIN_IN;//A
  _pin[11]._type = PIN_IN;//B
  _pin[12]._type = PIN_IN;//C
  _pin[13]._type = PIN_OUT;//z
  _pin[14]._type = PIN_IN;//OE
  _pin[15]._type = PIN_UNDEF;
}

Component4512::~Component4512(){

}

nts::Tristate	Component4512::Compute(size_t pin_num_this)
{
  if (_pin[10]._pin == 0 &&
      _pin[11]._pin == 0 &&
      _pin[12]._pin == 0 &&
      _pin[9]._pin == 0 &&
      _pin[14]._pin == 0)
    _pin[13]._pin = _pin[0]._pin;
  if (_pin[10]._pin == 1 &&
      _pin[11]._pin == 0 &&
      _pin[12]._pin == 0 &&
      _pin[9]._pin == 0 &&
      _pin[14]._pin == 0)
    _pin[13]._pin = _pin[1]._pin;
  if (_pin[10]._pin == 0 &&
      _pin[11]._pin == 1 &&
      _pin[12]._pin == 0 &&
      _pin[9]._pin == 0 &&
      _pin[14]._pin == 0)
    _pin[13]._pin = _pin[2]._pin;
  
  if (_pin[10]._pin == 1 &&
      _pin[11]._pin == 1 &&
      _pin[12]._pin == 0 &&
      _pin[9]._pin == 0 &&
      _pin[14]._pin == 0)
    _pin[13]._pin = _pin[3]._pin;

  if (_pin[10]._pin == 0 &&
      _pin[11]._pin == 0 &&
      _pin[12]._pin == 1 &&
      _pin[9]._pin == 0 &&
      _pin[14]._pin == 0)
    _pin[13]._pin = _pin[4]._pin;


    if (_pin[10]._pin == 1 &&
      _pin[11]._pin == 0 &&
      _pin[12]._pin == 1 &&
      _pin[9]._pin == 0 &&
      _pin[14]._pin == 0)
    _pin[13]._pin = _pin[5]._pin;

    if (_pin[10]._pin == 0 &&
	_pin[11]._pin == 1 &&
	_pin[12]._pin == 1 &&
	_pin[9]._pin == 0 &&
	_pin[14]._pin == 0)
      _pin[13]._pin = _pin[6]._pin;

    if (_pin[10]._pin == 1 &&
	_pin[11]._pin == 1 &&
	_pin[12]._pin == 1 &&
	_pin[9]._pin == 0 &&
	_pin[14]._pin == 0)
      _pin[13]._pin = _pin[8]._pin;

    if (_pin[9]._pin == 1 &&
	_pin[14]._pin == 0)
      _pin[13]._pin = nts::Tristate::FALSE;
    if (_pin[14]._pin == 1)
      _pin[13]._pin = nts::Tristate::UNDEFINED;
}
