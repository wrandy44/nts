//
// True.hpp for true in /home/brunel/Rendu/Semestre_3/CPP/nts/src
// 
// Made by Brunel Axel
// Login   <axel.brunel@epitech.eu>
// 
// Started on  Sat Mar  4 18:15:45 2017 Brunel Axel
// Last update Sat Mar  4 18:25:07 2017 Brunel Axel
//

#ifndef TRUE_H_
# define TRUE_H_

#include "Component.hpp"

class True : public Component
{
public:
  True(const std::string &);
  virtual ~True();
  virtual nts::Tristate	Compute(size_t pin_num_this = 1);
private:
  std::string	_flag;
};

#endif /* !TRUE_H_ */
