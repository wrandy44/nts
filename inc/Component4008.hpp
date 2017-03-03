//
// Component4008.hpp for component4008 in /home/brunel/Rendu/Semestre_3/CPP/cpp_nanotekspice/src
// 
// Made by Brunel Axel
// Login   <axel.brunel@epitech.eu>
// 
// Started on  Thu Mar  2 17:08:37 2017 Brunel Axel
// Last update Thu Mar  2 22:15:28 2017 debrau_c
//

#ifndef COMPONENT4008_H_
# define COMPONENT4008_H_

#include "Component.hpp"

class Component4008 : public Component
{
public:
  Component4008(const std::string &);
  virtual ~Component4008();
  virtual nts::Tristate Compute(size_t pin_num_this = 1);
private:
  void		output1();
  void		output2();
  void		output3();
  void		output4();
  void		output5();
  void		output6();
  void		output7();
  void		output8();
  std::string	_flag;
};

#endif /* !COMPONENT4008_H_ */
