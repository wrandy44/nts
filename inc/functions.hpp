//
// fonctions.hpp for ad in /home/debrau_c/cours/cpp_nanotekspice/inc
// 
// Made by Carl DEBRAUWERE
// Login   <debrau_c@epitech.net>
// 
// Started on  Fri Feb 10 13:33:12 2017 Carl DEBRAUWERE
// Last update Thu Mar  2 23:03:12 2017 debrau_c
//

#ifndef FUNCTIONS_HPP
# define FUNCTIONS_HPP

#include <iostream>
#include <algorithm>
#include <string>
#include "Component.hpp"

void epurStr(std::string &str);
bool	sortComponentByNameSup(Component *a, Component *b);
bool	sortComponentByNameInf(Component *a, Component *b);
bool	bad_file_format(std::string const &ok);

#endif /* */
