/*
** Component.hh for azd in /home/debrau_c/bin
** Made by Carl DEBRAUWERE
** Login   <debrau_c@epitech.net>
** 
** Started on  Mon Jan 16 09:33:45 2017 Carl DEBRAUWERE
// Last update Sat Mar  4 20:35:11 2017 debrau_c
*/

#ifndef _COMPONENT_H_
# define _COMPONENT_H_

#include <iostream>
#include <string>
#include <vector>
#include "IComponent.hpp"
#include "Link.hpp"

enum{
  PIN_IN = 0,
  PIN_OUT = 1,
  PIN_UNDEF = -1
};

class Component : public nts::IComponent
{
public:
  Component(const std::string &n);
  virtual		~Component();
  virtual nts::Tristate Compute(size_t pin_num_this = 1);
  virtual void		pushLink(size_t pin_num);
  void			SetLink(size_t pin_num_this,
				nts::IComponent &component,
				size_t pin_num_target);
  virtual void		Dump(void) const;
  void			setName(std::string const &name);  
  void			setType(std::string const &type);
  const std::string	&getName();
  const std::string	&getType();
  void			setPin(nts::Tristate t, size_t pin_num = 1);
  nts::Tristate		getPin(size_t num_pin = 1);
  void			pushLinkOutput();
protected:
  typedef struct		_pinLink_s
  {
    nts::Tristate			_pin;
    Link				_link;
    char				_type;//0 : in, 1 : out, -1 undefined
  }					_pinLink_t;
  int					_nbPin;
  std::vector<struct _pinLink_s>	_pin;
  std::string			_name;
  std::string			_type;//Chipset / Input / Output
  nts::Tristate			_value;
};

nts::Tristate operator!(nts::Tristate &a);
nts::Tristate operator&&(nts::Tristate &a, nts::Tristate &b);
nts::Tristate operator||(nts::Tristate &a, nts::Tristate &b);
nts::Tristate tristate_adder_sum(nts::Tristate &a, nts::Tristate &b, nts::Tristate &c);
nts::Tristate tristate_adder(nts::Tristate &a, nts::Tristate &b, nts::Tristate &c);
nts::Tristate tristate_nor(nts::Tristate &a, nts::Tristate &b);
nts::Tristate tristate_xor(nts::Tristate &a, nts::Tristate &b);
nts::Tristate tristate_nand(nts::Tristate &a, nts::Tristate &b);

#endif /* Component */
