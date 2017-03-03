//
// fonctions.cpp for s in /home/debrau_c/cours/cpp_nanotekspice/inc
// 
// Made by Carl DEBRAUWERE
// Login   <debrau_c@epitech.net>
// 
// Started on  Fri Feb 10 13:33:10 2017 Carl DEBRAUWERE
// Last update Thu Mar  2 23:02:26 2017 debrau_c
//

#include "functions.hpp"

/*
** Transform all "\t" and "  " by " "
** Delete coms represented by "#"
*/
void epurStr(std::string &s){
  if (s.find("#") != std::string::npos)
    s = s.substr(0, s.find("#"));
  while (s.find("\t") != std::string::npos)
    s.replace(s.find("\t"), 1, " ");
  while (s.find("  ") != std::string::npos)
    s.replace(s.find("  "), 2, " ");
}

bool	sortComponentByNameSup(Component *a, Component *b){
  return a->getName() > b->getName();
}

bool	sortComponentByNameInf(Component *a, Component *b){
  return a->getName() < b->getName();
}

bool	bad_file_format(std::string const &ok)
{
  size_t	pos;

  if ((pos = ok.find(".")) == std::string::npos)
    return (true);
  return (false);
}
