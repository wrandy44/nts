/*
** Component4512.hh for azd in /home/debrau_c/bin
** Made by Carl DEBRAUWERE
** Login   <debrau_c@epitech.net>
** 
** Started on  Mon Jan 16 09:33:45 2017 Carl DEBRAUWERE
// Last update Fri Mar  3 02:09:14 2017 debrau_c
*/

#ifndef _COMPONENT4512_H_
# define _COMPONENT4512_H_

#include "Component.hpp"

class Component4512 : public Component{
public:
  
  Component4512(const std::string &n);
  virtual ~Component4512();
  virtual nts::Tristate	Compute(size_t pin_num_this = 1);
};

#endif /* Component4512 */
