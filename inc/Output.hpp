//
// Output.hpp for azd in /home/debrau_c/cours/cpp_nanotekspice
// 
// Made by Carl DEBRAUWERE
// Login   <debrau_c@epitech.net>
// 
// Started on  Sat Feb 11 12:53:12 2017 Carl DEBRAUWERE
// Last update Sat Mar  4 20:37:18 2017 debrau_c
//

#ifndef _OUTPUT_H_
# define _OUTPUT_H_

#include <iostream>
#include <vector>
#include "Component.hpp"
#include "IComponent.hpp"

class Output : public Component{
  bool	setted;
public:
  Output(const std::string &n):Component::Component(n){
    _type = "Output";
    _nbPin = 1;
    
    for (unsigned int i = 0; i < _nbPin; i++){
      _pin.push_back((_pinLink_t){nts::UNDEFINED});
    }
  };
  virtual ~Output(){};
  virtual nts::Tristate Compute(size_t pin_num_this = 1){};
  virtual void		Dump(void) const{
    std::cout << _name << ":" << std::endl;
    std::cout << "Output - value: " << _pin[0]._pin << std::endl;
    for (int i = 0; i < _nbPin; i++)
      {
	std::cout << "\tpin #" << i+1 << ": ";
	if (_pin[i]._link.isLinked())
	  std::cout << "linked" << std::endl;
	else
	  std::cout << "NULL" << std::endl;
      }
  };
};

#endif /* Output */
