//
// Input.cpp for ad in /home/debrau_c/cours/cpp_nanotekspice
// 
// Made by Carl DEBRAUWERE
// Login   <debrau_c@epitech.net>
// 
// Started on  Sat Feb 11 12:54:04 2017 Carl DEBRAUWERE
// Last update Sat Mar  4 21:38:27 2017 debrau_c
//

#include "Input.hpp"

Input::Input(const std::string &n):Component::Component(n){
  _pinLink_t	tmppin;
  _nbPin = 1;
  _type = "Input";
  for (unsigned int i = 0; i < _nbPin; i++)
    {
      tmppin._pin = nts::UNDEFINED;
      _pin.push_back(tmppin);
    }
  _pin[0]._type = PIN_OUT; 
};

Input::~Input(){};

nts::Tristate Input::Compute(size_t pin_num_this){}

void		Input::Dump(void) const{
    std::cout << _name << ":" << std::endl;
    std::cout << "Input - value: " << _pin[0]._pin << std::endl;
    std::cout << "\tpin #1: ";
    if (!_pin[0]._link.isLinked())
      std::cout << "NULL" << std::endl;
    else
      std::cout << "linked" << std::endl;
}
