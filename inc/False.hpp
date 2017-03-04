//
// False.hpp for false in /home/brunel/Rendu/Semestre_3/CPP/nts
// 
// Made by Brunel Axel
// Login   <axel.brunel@epitech.eu>
// 
// Started on  Sat Mar  4 18:17:42 2017 Brunel Axel
// Last update Sat Mar  4 18:24:51 2017 Brunel Axel
//

#ifndef FALSE_H_
# define FALSE_H_

#include "Component.hpp"

class False : public Component
{
public:
  False(const std::string &);
  virtual	~False();
  virtual nts::Tristate	Compute(size_t pin_num_this = 1);
private:
  std::string	_flag;
};

#endif /* !FALSE_H_ */
