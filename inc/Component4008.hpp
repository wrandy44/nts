//
// Component4008.hpp for component4008 in /home/brunel/Rendu/Semestre_3/CPP/cpp_nanotekspice/src
// 
// Made by Brunel Axel
// Login   <axel.brunel@epitech.eu>
// 
// Started on  Thu Mar  2 17:08:37 2017 Brunel Axel
// Last update Sat Mar  4 03:36:51 2017 Brunel Axel
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
  std::string	_flag;
};

#endif /* !COMPONENT4008_H_ */
