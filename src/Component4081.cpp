//
// Component4081.cpp for azd in /home/debrau_c/cours/cpp_nanotekspice
// 
// Made by Carl DEBRAUWERE
// Login   <debrau_c@epitech.net>
// 
// Started on  Wed Feb  8 18:21:48 2017 Carl DEBRAUWERE
// Last update Fri Mar  3 02:49:32 2017 debrau_c
//

#include "Component4081.hpp"

Component4081::Component4081(const std::string &n) : Component(n)
{
  _pinLink_t	tmppin;
  _nbPin = 14;
  _type = "Chipset 4081";
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
};
Component4081::~Component4081(){ };




nts::Tristate Component4081::Compute(size_t pin_num_this){
  _pin[2]._pin = (_pin[0]._pin && _pin[1]._pin);
  _pin[3]._pin = (_pin[4]._pin && _pin[5]._pin);
  _pin[9]._pin = (_pin[7]._pin && _pin[8]._pin);
  _pin[10]._pin = (_pin[11]._pin && _pin[11]._pin);
};



void		Component4081::Dump(void) const{
  std::cout << _name << ":" << std::endl;
  std::cout << _type << " " << _flag << std::endl;
  unsigned int i;
  for (i =0 ; i < _nbPin; ++i){
    if (_pin[0]._pin == nts::UNDEFINED)
      std::cout <<  "\tpin #" << i+1 << ": NULL" << std::endl;
    else
      std::cout <<  "\tpin #" << i+1 << ": "<< _pin[i]._pin << std::endl;
  }
};
