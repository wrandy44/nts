//
// True.cpp for true in /home/brunel/Rendu/Semestre_3/CPP/nts/src
// 
// Made by Brunel Axel
// Login   <axel.brunel@epitech.eu>
// 
// Started on  Sat Mar  4 18:06:02 2017 Brunel Axel
// Last update Sat Mar  4 18:24:32 2017 Brunel Axel
//

#include "True.hpp"

True::True(const std::string &name)
  : Component(name)
{
  _pinLink_t	tmppin;
  _nbPin = 1;
  _type = "Chipset True";
  for (unsigned int i = 0; i < _nbPin; i++)
    {
      tmppin._pin = nts::TRUE;
      tmppin._type = PIN_OUT;
      _pin.push_back(tmppin);
    }
}

True::~True()
{
}

nts::Tristate	True::Compute(size_t pin_num_this)
{
  if (pin_num_this != 1)
    std::cout << "Error !" << std::endl;
  return (nts::TRUE);
}
