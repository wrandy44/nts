//
// main.cpp for azd in /home/debrau_c/cours/cpp_nanotekspice
// 
// Made by Carl DEBRAUWERE
// Login   <debrau_c@epitech.net>
// 
// Started on  Wed Feb  8 17:18:40 2017 Carl DEBRAUWERE
// Last update Thu Mar  2 13:35:29 2017 debrau_c
//

#include <iostream>
#include <csignal>
#include "IComponent.hpp"
#include "Component.hpp"
#include "Component4081.hpp"
#include "Prompt.hpp"
#include "myExcept.hpp"

void	ctrl_c_handler(int x){
 
}


int	main(int argc, char **argv)
{
  Prompt	prompt;

  signal(SIGINT,ctrl_c_handler);
  try{
    prompt.set(argc, argv);
  }catch(nts::myExcept &e){
    std::cout<< e << std::endl;
    return 0;
  }
  prompt.start();
  return (0);
}
