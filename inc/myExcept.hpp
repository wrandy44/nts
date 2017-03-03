/*
** myExcept.hh for azd in /home/debrau_c/bin
** Made by Carl DEBRAUWERE
** Login   <debrau_c@epitech.net>
** 
** Started on  Mon Jan 16 09:33:45 2017 Carl DEBRAUWERE
// Last update Mon Feb 27 15:21:51 2017 debrau_c
*/

#ifndef _MYEXCEPT_H_
# define _MYEXCEPT_H_

#include <iostream>
#include <string>
#include <exception>

namespace nts{
  class myExcept : public std::exception{
    std::string err;
  public:
    myExcept(const std::string &n);
    ~myExcept();
    std::string getErr() const { return err; }
  };
}
std::ostream& operator<<(std::ostream &c, nts::myExcept &e);

#endif /* myExcept */
