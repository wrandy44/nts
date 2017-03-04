//
// Component.cpp for azd in /home/debrau_c/cours/cpp/cpp_nanotekspice
// 
// Made by debrau_c
// Login   <carl.debrauwere@epitech.eu>
// 
// Started on  Thu Mar  2 13:11:40 2017 debrau_c
// Last update Sat Mar  4 16:27:50 2017 debrau_c
//

#include "Component.hpp"

Component::Component(const std::string &n) {
  _name = n;
};
Component::~Component(){};
nts::Tristate Component::Compute(size_t pin_num_this){};

void Component::pushLink(size_t pin_num)
{
  std::cout << pin_num << std::endl;
  _pin[pin_num -1]._link.pushValue(_pin[pin_num - 1]._pin);
}
  
void		Component::SetLink(size_t pin_num_this,
			nts::IComponent &component,
			size_t pin_num_target){
  _pin[pin_num_this - 1]._link.set(component, pin_num_target);
};

void		Component::Dump(void) const{
  std::cout << _name << ":" << std::endl;
    std::cout << _type << std::endl;
    for (int i = 0; i < _nbPin; i++)
      {
	std::cout << "\tpin #" << i+1 << ": ";
	if (_pin[i]._pin == nts::UNDEFINED)
	  std::cout << "NULL" << std::endl;
	else
	  std::cout << _pin[i]._pin << std::endl;
      }
};

void			Component::setName(std::string const &name)
{
  _name = name;
}

void			Component::setType(std::string const &type)
{
  _type = type;
}
const std::string	&Component::getName(){return _name; };
const std::string	&Component::getType(){return _type; };

void			Component::setPin(nts::Tristate t, size_t pin_num){
  std::cout << "  :" <<pin_num << std::endl;
  if (pin_num <= _nbPin && pin_num > 0)
    _pin[pin_num - 1]._pin = t;
}

nts::Tristate operator!(nts::Tristate &a){
  if (a == nts::Tristate::TRUE)
    return nts::Tristate::FALSE;
  else if (a == nts::Tristate::UNDEFINED)
    return nts::Tristate::UNDEFINED;
  return nts::Tristate::TRUE;
}

nts::Tristate operator&&(nts::Tristate &a, nts::Tristate &b){
  if (a == nts::Tristate::TRUE && b == nts::Tristate::TRUE)
    return nts::Tristate::TRUE;
  return nts::Tristate::FALSE;
}

//
// 1 1 1
// 1 0 1
// 0 1 1
// 0 0 0
nts::Tristate operator||(nts::Tristate &a, nts::Tristate &b){
  if (a == nts::Tristate::TRUE && b == nts::Tristate::TRUE)
    return nts::Tristate::TRUE;
  else if (a == nts::Tristate::TRUE && b == nts::Tristate::FALSE)
    return nts::Tristate::TRUE;
  else if (a == nts::Tristate::FALSE && b == nts::Tristate::TRUE)
    return nts::Tristate::TRUE;
  else if (a == nts::Tristate::FALSE && b == nts::Tristate::FALSE)
    return nts::Tristate::FALSE;
}

// A B R
// 1 1 0
// 0 1 1
// 1 0 1
// 0 0 0
nts::Tristate	tristate_xor(nts::Tristate &a, nts::Tristate &b)
{
  if (a == nts::Tristate::UNDEFINED || b == nts::Tristate::UNDEFINED)
    return nts::Tristate::UNDEFINED;
  if (a && !b || !a && b)
    return nts::Tristate::TRUE;
  return nts::Tristate::FALSE;
}

// A B C Co S
// 0 0 0  0 0
// 0 0 1  0 1
// 0 1 0  0 1
// 0 1 1  1 0
// 1 0 0  0 1
// 1 0 1  1 0
// 1 1 0  1 0
// 1 1 1  1 1
nts::Tristate	tristate_adder_sum(nts::Tristate &a, nts::Tristate &b, nts::Tristate &c)
{
  if (a == nts::Tristate::UNDEFINED
      || b == nts::Tristate::UNDEFINED
      || c == nts::Tristate::UNDEFINED)
    return nts::Tristate::UNDEFINED;
  if ((!a && !b && !c) || (!a && !b && c) || (!a && b && !c) || (a && !b && !c))
    return nts::Tristate::FALSE;
  return nts::Tristate::TRUE;
}
nts::Tristate	tristate_adder(nts::Tristate &a, nts::Tristate &b, nts::Tristate &c)
{
  if (a == nts::Tristate::UNDEFINED
      || b == nts::Tristate::UNDEFINED
      || c == nts::Tristate::UNDEFINED)
    return nts::Tristate::UNDEFINED;
  if ((!a && !b && !c) || (!a && b && c) || (a && !b && c) || (a && b && !c))
    return nts::Tristate::FALSE;
  return nts::Tristate::TRUE;
}

// A B R
// 1 1 0
// 0 1 1
// 1 0 1
// 0 0 1
nts::Tristate	tristate_nand(nts::Tristate &a, nts::Tristate &b)
{
  if (a == nts::Tristate::UNDEFINED || b == nts::Tristate::UNDEFINED)
    return nts::Tristate::UNDEFINED;
  if (a && b) return nts::Tristate::FALSE;
  return nts::Tristate::TRUE;
}

// A B R
// 0 0 1
// 0 1 0
// 1 0 0
// 1 1 0
nts::Tristate tristate_nor(nts::Tristate &a, nts::Tristate &b)
{
  if (a == nts::Tristate::UNDEFINED || b == nts::Tristate::UNDEFINED)
    return nts::Tristate::UNDEFINED;
  if (!a && !b) return nts::Tristate::TRUE;
  return nts::Tristate::FALSE;
}
