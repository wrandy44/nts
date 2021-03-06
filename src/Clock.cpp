/*
** Clock.cpp for azd in /home/debrau_c/bin
** Made by Carl DEBRAUWERE
** Login   <debrau_c@epitech.net>
** 
** Started on  Mon Jan 16 09:33:45 2017 Carl DEBRAUWERE
// Last update Sat Mar  4 16:35:56 2017 debrau_c
*/

#include "Clock.hpp"

Clock::Clock(const std::string &n):Component::Component(n){
  _pinLink_t	tmppin;
  _nbPin = 1;
  _type = "Clock";
  for (unsigned int i = 0; i < _nbPin; i++)
    {
      tmppin._pin = nts::UNDEFINED;
      tmppin._type = PIN_OUT;
      _pin.push_back(tmppin);
    }
}

Clock::~Clock(){

}

nts::Tristate	Clock::Compute(size_t pin_num_this)
{
  _pin[0]._pin = !_pin[0]._pin;
}
