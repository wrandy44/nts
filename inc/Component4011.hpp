//
// Component4011.hpp for 4011 in /home/brunel/Rendu/Semestre_3/CPP/nts/inc
// 
// Made by Brunel Axel
// Login   <axel.brunel@epitech.eu>
// 
// Started on  Fri Mar  3 19:47:20 2017 Brunel Axel
// Last update Fri Mar  3 19:51:54 2017 Brunel Axel
//

#ifndef COMPONENT4011_H_
# define COMPONENT4011_H_

#include "Component.hpp"

class Component4011 : public Component
{
public:
  Component4011(const std::string &);
  virtual ~Component4011();
  virtual nts::Tristate Compute(size_t pin_num_this = 1);
private:
  std::string	_flag;
}

#endif /* !COMPONENT4011_H_ */
