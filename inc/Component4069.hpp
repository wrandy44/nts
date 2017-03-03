/*
** Component4069.hh for azd in /home/debrau_c/bin
** Made by Carl DEBRAUWERE
** Login   <debrau_c@epitech.net>
** 
** Started on  Mon Jan 16 09:33:45 2017 Carl DEBRAUWERE
// Last update Thu Mar  2 20:41:03 2017 debrau_c
*/

#ifndef _COMPONENT4069_H_
# define _COMPONENT4069_H_

#include "IComponent.hpp"
#include "Component.hpp"

class Component4069 : public Component{
public:
  Component4069(std::string n);
  virtual ~Component4069();
  virtual nts::Tristate Compute(size_t pin_num_this = 1);
};

#endif /* Component4069 */
