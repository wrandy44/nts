/*
** myExcept.cpp for azd in /home/debrau_c/bin
** Made by Carl DEBRAUWERE
** Login   <debrau_c@epitech.net>
** 
** Started on  Mon Jan 16 09:33:45 2017 Carl DEBRAUWERE
// Last update Mon Feb 27 15:22:11 2017 debrau_c
*/

#include "myExcept.hpp"

namespace nts{ 
  myExcept::myExcept(const std::string &n){
    err = n;
  } 
  myExcept::~myExcept(){
    
  }
}

std::ostream& operator<<(std::ostream &c, nts::myExcept &e)
{
  c << e.getErr();
  return c;
}
