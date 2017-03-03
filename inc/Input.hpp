//
// Input.hpp for azd in /home/debrau_c/cours/cpp_nanotekspice
// 
// Made by Carl DEBRAUWERE
// Login   <debrau_c@epitech.net>
// 
// Started on  Sat Feb 11 12:52:17 2017 Carl DEBRAUWERE
// Last update Wed Mar  1 14:20:30 2017 debrau_c
//

#ifndef _INPUT_H_
# define _INPUT_H_

#include <iostream>
#include <vector>
#include "Component.hpp"
#include "IComponent.hpp"
#include "Link.hpp"

class Input : public Component{
public:
  Input(const std::string &n);
  virtual ~Input();
  virtual nts::Tristate Compute(size_t pin_num_this = 1);
  virtual void		Dump(void) const;
};

#endif /* Input */
