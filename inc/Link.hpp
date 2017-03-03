//
// Link.hpp for azd in /home/debrau_c/cours/cpp_nanotekspice
// 
// Made by Carl DEBRAUWERE
// Login   <debrau_c@epitech.net>
// 
// Started on  Sat Feb 11 13:14:40 2017 Carl DEBRAUWERE
// Last update Fri Mar  3 02:18:07 2017 debrau_c
//

#ifndef _LINK_HPP_
# define _LINK_HPP_

# include "IComponent.hpp"

class Component;
class Link{
  nts::IComponent	*a;
  int			numPin;
public:
  Link(){ a = nullptr; };
  ~Link(){};
  const nts::IComponent	*get();
  void			set(nts::IComponent &b, int n);
  bool			isLinked() const;
  void			pushValue(nts::Tristate value);
};

#endif
