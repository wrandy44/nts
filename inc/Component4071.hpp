/*
** Component4071.hh for azd in /home/debrau_c/bin
** Made by Carl DEBRAUWERE
** Login   <debrau_c@epitech.net>
** 
** Started on  Mon Jan 16 09:33:45 2017 Carl DEBRAUWERE
// Last update Fri Mar  3 02:49:33 2017 debrau_c
*/

#ifndef _COMPONENT4071_H_
# define _COMPONENT4071_H_

#include "Component.hpp"

class Component4071 : public Component{
public:
  Component4071(const std::string &n);
  virtual ~Component4071();
  virtual nts::Tristate	Compute(size_t pin_num_this = 1);
};

#endif /* Component4071 */
