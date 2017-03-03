/*
** Component4081.hh for azd in /home/debrau_c/bin
** Made by Carl DEBRAUWERE
** Login   <debrau_c@epitech.net>
** 
** Started on  Mon Jan 16 09:33:45 2017 Carl DEBRAUWERE
// Last update Wed Mar  1 18:24:14 2017 debrau_c
*/

#ifndef _COMPONENT4081_H_
# define _COMPONENT4081_H_

#include <iostream>
#include <vector>
#include "Component.hpp"
#include "IComponent.hpp"

class Component4081 : public Component{
public:
  Component4081(const std::string &n);
  virtual		~Component4081();
  virtual nts::Tristate Compute(size_t pin_num_this = 1);
  virtual void		Dump(void) const;
private:
  std::string		_flag;
};

#endif /* Component4081 */
