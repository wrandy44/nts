//
// Link.cpp for azd in /home/debrau_c/cours/cpp/cpp_nanotekspice
// 
// Made by debrau_c
// Login   <carl.debrauwere@epitech.eu>
// 
// Started on  Thu Mar  2 11:14:04 2017 debrau_c
// Last update Thu Mar  2 13:32:16 2017 debrau_c
//


#include "Link.hpp"
#include "Component.hpp"

void			Link::pushValue(nts::Tristate value)
{
  Component	*tmp;

  tmp = dynamic_cast<Component *>(a);
  tmp->setPin( value, numPin);
}

bool			Link::isLinked() const
{
  return a != nullptr;
}

void			Link::set(nts::IComponent &b, int n)
{
  a = &b;
  numPin = n;
}

const nts::IComponent	*Link::get()
{
  return a;
}
