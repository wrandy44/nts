//
// VirtualMachine.hpp for azd in /home/debrau_c/cours/cpp_nanotekspice
// 
// Made by Carl DEBRAUWERE
// Login   <debrau_c@epitech.net>
// 
// Started on  Fri Feb 10 16:38:12 2017 Carl DEBRAUWERE
// Last update Sat Mar  4 17:54:48 2017 debrau_c
//

#ifndef _V_MACHINE_HPP_
# define _V_MACHINE_HPP_

# include "myExcept.hpp"
# include "Parser.hpp"
# include "IComponent.hpp"
# include "ComponentCreator.hpp"
# include <string>

class VMachine{
  std::vector<nts::IComponent *> _comp;
  nts::ComponentCreator		_compCrea;
public:
  VMachine(){};
  ~VMachine(){};
  void	setInput(int ac, char **av){
    std::vector<nts::IComponent *>::iterator i;
    for (i = _comp.begin(); i != _comp.end(); i++){
      Component *tmp = dynamic_cast<Component *>(*i);
      if (tmp->getType() == "Input" || tmp->getType() == "Clock")
	{
	  bool set = false;
	  for (int j = 2; j < ac; j++){
	    std::string argv = av[j];
	    if (argv.substr(0, argv.find("=")) == tmp->getName()){
	      int val = std::stoi(argv.substr(argv.find("=") + 1, argv.size()));
	      if (val != 0 && val != 1)
		throw nts::myExcept("InputError: Input value must be e. to 0 or 1");
	      tmp->setPin(nts::Tristate(val));
	      set = true;
	    }
	  }
	  if (set == false)
	    {
	      throw nts::myExcept(std::string("Error: '").append(dynamic_cast<Component *>(*i)->getName()).append("' not initialized"));  
	    } 
	}
    }
  }

  void		getAllChipsets(nts::t_ast_node *lex)
  {
    std::vector<nts::t_ast_node *>::iterator	i;
    nts::IComponent	*tmp;
    Component		*fck;

    if (lex == NULL)
      return ;
    for (i = lex->children->begin(); i != lex->children->end(); i++)
      {
        fck = dynamic_cast<Component *>(_compCrea.createComponent((*i)->lexeme, (*i)->value));
	tmp = dynamic_cast<Component *>(fck);
	_comp.push_back(tmp);
      }
  }

  void			setComponents(nts::t_ast_node *root)
  {
    nts::t_ast_node	*node;
    nts::Parser		*tmp;
    std::vector<nts::IComponent *>::iterator	i;

    node = tmp->getSectionByLexeme("chipsets", root);
    getAllChipsets(node);
    node = tmp->getSectionByLexeme("links", root);
  }
  
  void	setLinks(nts::t_ast_node *tree){
    std::vector<nts::t_ast_node *>::iterator i;
    std::vector<nts::t_ast_node *>::iterator j;
    
    for (i = tree->children->begin(); i != tree->children->end(); i++){
      for (j = (*i)->children->begin(); j != (*i)->children->end(); j++){
	if ((*j) != nullptr){
	  Component	*tmp, *tmp2;
	  tmp = getCompByName((*j)->lexeme);
	  tmp2 = getCompByName((*i)->lexeme);
	  if (tmp != nullptr && tmp2 != nullptr)
	    {
	      tmp->SetLink(std::stoi((*j)->value), *tmp2, std::stoi((*i)->value));
	      tmp2->SetLink(std::stoi((*i)->value), *tmp, std::stoi((*j)->value));
	    }
	}
      }
    }
  }
  
  void	Dump(){
    std::vector<nts::IComponent *>::iterator i;
    std::vector<Component *>::iterator j;
    std::vector<Component *> sorted;
    
    for (i = _comp.begin(); i != _comp.end(); i++)
      sorted.push_back(dynamic_cast<Component *>(*i));
    std::sort(sorted.begin(), sorted.end(), sortComponentByNameSup);
    for (j = sorted.end() - 1; j != sorted.begin() - 1; j--)
      (*j)->Dump();
  }
  
  void	setPin(int ac, char **av){
    for (int i = 2; i < ac; i++)
      {
	std::string tmpS = av[i];
	Component	*tmp = getCompByName(tmpS.substr(0, tmpS.find("=")));
	if (tmp != nullptr)
	  tmp->setPin(nts::Tristate(std::stoi(tmpS.substr(tmpS.find("=") + 1, tmpS.size()))));
      }
  }

  Component	*getCompByName(const std::string &n){
    for (std::vector<nts::IComponent *>::iterator i = _comp.begin(); i != _comp.end(); i++){
      Component	*tmp = dynamic_cast<Component *>(*i);
      if (tmp->getName() == n)
	return (tmp);
    }
    return nullptr;
  }

  bool		all_output_seted()
  {
    std::vector<nts::IComponent *>::iterator i;
    
    for (i = _comp.begin(); i != _comp.end(); i++)
      {
	Component *tmp = dynamic_cast<Component *>(*i);
	if (tmp->getType() == "Output")
	  {
	    if (tmp->getPin(1) == nts::Tristate::UNDEFINED)
	      return false;
	  }
      }
    return true;
  }
  
  void		simulate()
  {
    std::vector<nts::IComponent *> ins;

    
    //Push input
    for (std::vector<nts::IComponent *>::iterator i = _comp.begin(); i != _comp.end(); i++)
      {
	Component *tmp = dynamic_cast<Component *>(*i);
	if (tmp->getType() == "Output")
	  {
	    tmp->setPin(nts::Tristate::UNDEFINED);
	  }
	if (tmp->getType() == "Input")
	  {
	    tmp->pushLink(1);
	  }
      }
    //All Compute this
    int	j = 0;
    while (!all_output_seted() && ++j< 20)
      {
	for (std::vector<nts::IComponent *>::iterator i = _comp.begin(); i != _comp.end(); i++)
	  {
	    Component *tmp = dynamic_cast<Component *>(*i);

	    tmp->Compute();
	    tmp->pushLinkOutput();
	  }
      }
  }

  void	display()
  {
    std::vector<Component *> ins;

    //Push input
    for (std::vector<nts::IComponent *>::iterator i = _comp.begin(); i != _comp.end(); i++)
      {
	Component *tmp = dynamic_cast<Component *>(*i);
	
	if (tmp->getType() == "Output")
	  ins.push_back(tmp);
      }
    std::sort(ins.begin(), ins.end(), sortComponentByNameInf);
    for (std::vector<Component *>::iterator i = ins.begin(); i != ins.end(); i++)
      {
	std::cout << (*i)->getName() << "=" << (*i)->getPin() << std::endl;
      }
  }
  
  int	setInput(std::string name, size_t state)
  {
    std::vector<nts::IComponent *>::iterator i;
    for (i = _comp.begin(); i != _comp.end(); i++)
      {
	Component *tmp = dynamic_cast<Component *>(*i);
	if (tmp->getType() == "Input" && tmp->getName() == name)
	  {
	    if (state == 1) tmp->setPin(nts::Tristate::TRUE);
	    else if (state == 0) tmp->setPin(nts::Tristate::FALSE);
	    else tmp->setPin(nts::Tristate::UNDEFINED);
	    return (0);
	  }
      }
    return (1);
  }
  
};

# endif /*_VIRTUAL_MACHIN_HPP_ */
