/*
** Clock.hh for azd in /home/debrau_c/bin
** Made by Carl DEBRAUWERE
** Login   <debrau_c@epitech.net>
** 
** Started on  Mon Jan 16 09:33:45 2017 Carl DEBRAUWERE
// Last update Sat Mar  4 02:22:49 2017 debrau_c
*/

#ifndef _CLOCK_H_
# define _CLOCK_H_

#include "Component.hpp"

class Clock : public Component{
public:
  Clock(const std::string &n);
  virtual ~Clock();
};

#endif /* Clock */
