//
// Component4001.hpp for  in /home/brunel_d/rendu/sem3/cpp/cpp_nanotekspice
// 
// Made by Axel Brunel
// Login   <brunel_d@epitech.net>
// 
// Started on  Wed Feb  8 14:33:27 2017 Axel Brunel
// Last update Fri Mar  3 02:58:05 2017 debrau_c
//

#ifndef COMPONENT4001_H_
# define COMPONENT4001_H_

#include "Component.hpp"

class Component4001 : public Component
{
public:
  Component4001(const std::string &);
  virtual ~Component4001();
  virtual nts::Tristate	Compute(size_t pin_num_this = 1);
private:
  void		output1();
  void		output2();
  void		output3();
  void		output4();
  std::string	_flag;
};

#endif /* !COMPONENT4001_H_ */
