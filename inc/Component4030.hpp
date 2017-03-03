//
// Component4030.hpp for 4030 in /home/brunel/Rendu/Semestre_3/CPP/nts/src
// 
// Made by Brunel Axel
// Login   <axel.brunel@epitech.eu>
// 
// Started on  Fri Mar  3 22:04:13 2017 Brunel Axel
// Last update Fri Mar  3 22:07:32 2017 Brunel Axel
//

#ifndef COMPONENT4030_H_
# define COMPONENT4030_H_

#include "Component.hpp"

class Component4030 : public Component
{
public:
  Component4030(const std::string &);
  virtual ~Component4030();
  virtual nts::Tristate Compute(size_t pin_num_this = 1);
private:
  std::string	_flag;
};

#endif /* !COMPONENT4030_H_ */
