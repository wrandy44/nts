//
// Component4008.hpp for component4008 in /home/brunel/Rendu/Semestre_3/CPP/cpp_nanotekspice/src
// 
// Made by Brunel Axel
// Login   <axel.brunel@epitech.eu>
// 
// Started on  Thu Mar  2 17:08:37 2017 Brunel Axel
// Last update Fri Mar  3 15:17:11 2017 Brunel Axel
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
  void		output_1();
  void		output_2();
  void		output_3();
  void		output_4();
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
