//
// ComponentCreator.hpp for azd in /home/debrau_c/cours/cpp_nanotekspice
// 
// Made by Carl DEBRAUWERE
// Login   <debrau_c@epitech.net>
// 
// Started on  Fri Feb 10 23:16:48 2017 Carl DEBRAUWERE
// Last update Fri Mar  3 22:03:42 2017 Brunel Axel
//

#ifndef COMPONENT_CREATOR_HPP
# define COMPONENT_CREATOR_HPP

# include <map>
# include "IComponent.hpp"
# include "Input.hpp"
# include "Output.hpp"
# include "Component4011.hpp"
# include "Component4001.hpp"
# include "Component4008.hpp"
# include "Component4030.hpp"
# include "Component4081.hpp"
# include "Component4069.hpp"
# include "Component4071.hpp"
# include "myExcept.hpp"

namespace nts{
  class ComponentCreator{
    std::map<std::string, IComponent *(ComponentCreator::*)(const std::string &) const> _ptr;
    std::vector<std::string> reco;//recgnized chipset
  public:
    ComponentCreator(){
      _ptr["4081"] = &ComponentCreator::create4081;
      _ptr["4001"] = &ComponentCreator::create4001;
      _ptr["4011"] = &ComponentCreator::create4011;
      _ptr["4030"] = &ComponentCreator::create4030;
      _ptr["4008"] = &ComponentCreator::create4008;
      _ptr["4069"] = &ComponentCreator::create4069;
      _ptr["4071"] = &ComponentCreator::create4071;
      _ptr["output"] = &ComponentCreator::createOutput;
      _ptr["input"] = &ComponentCreator::createInput;
      reco.push_back("4081");
      reco.push_back("4001");
      reco.push_back("4011");
      reco.push_back("4008");
      reco.push_back("4030");
      reco.push_back("4069");
      reco.push_back("4071");
      reco.push_back("output");
      reco.push_back("input");
    };
    ~ComponentCreator(){};
    IComponent *createComponent(const std::string &type,
				const std::string &value){
      IComponent	*ret;
      for (std::vector<std::string>::iterator i = reco.begin(); i != reco.end(); i++)
	{
	  if (type == *i)
	    return (this->*_ptr[type])(value);
	}
      throw myExcept(std::string("Error: unrecognized symbol '").append(type).append("'"));
      return NULL;
    };
    IComponent *create4081(const std::string &value) const{
      IComponent	*ret = new Component4081(value);
      return ret;
    };
    IComponent *create4001(const std::string &value) const{
      IComponent	*ret = new Component4001(value);
      return ret;
    };
    IComponent *create4011(const std::string &value) const{
      IComponent	*ret = new Component4011(value);
      return ret;
    };
    IComponent *create4008(const std::string &value) const{
      IComponent	*ret = new Component4008(value);
      return ret;
    };    
    IComponent *create4030(const std::string &value) const{
      IComponent	*ret = new Component4030(value);
      return ret;
    };    
    IComponent *create4069(const std::string &value) const{
      IComponent	*ret = new Component4069(value);
      return ret;
    };
    IComponent *create4071(const std::string &value) const{
      IComponent	*ret = new Component4071(value);
      return ret;
    };
    IComponent *createInput(const std::string &value) const{
      IComponent	*ret = new Input(value);
      return ret;
    };
    IComponent *createOutput(const std::string &value) const{
      IComponent	*ret = new Output(value);
      return ret;
    };
    //IComponent * create4013(const std::string &value) const;
    //IComponent * create4040(const std::string &value) const;
  };
}
#endif /* COMPONENT_CREATOR_HPP */
