//
// False.cpp for false in /home/brunel/Rendu/Semestre_3/CPP/nts
// 
// Made by Brunel Axel
// Login   <axel.brunel@epitech.eu>
// 
// Started on  Sat Mar  4 18:20:46 2017 Brunel Axel
// Last update Sat Mar  4 18:24:25 2017 Brunel Axel
//

#include "False.hpp"

False::False(const std::string &name)
  : Component(name)
{
  _pinLink_t	tmppin;
  _nbPin = 1;
  _type = "Chipset False";
  for (unsigned int i = 0; i < _nbPin; i++)
    {
      tmppin._pin = nts::FALSE;
      tmppin._type = PIN_OUT;
      _pin.push_back(tmppin);
    }
}

False::~False()
{
}

nts::Tristate	False::Compute(size_t pin_num_this)
{
  if (pin_num_this != 1)
    std::cout << "Error" << std::endl;
  return (nts::FALSE);
}
