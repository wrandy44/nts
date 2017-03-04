/*
** Prompt.cpp for azd in /home/debrau_c/bin
** Made by Carl DEBRAUWERE
** Login   <debrau_c@epitech.net>
** 
** Started on  Mon Jan 16 09:33:45 2017 Carl DEBRAUWERE
// Last update Sat Mar  4 02:51:16 2017 debrau_c
*/

#include <iostream>
#include <fstream>
#include<string>
#include "myExcept.hpp"
#include "Prompt.hpp"

Prompt::Prompt(){
  _command[0] = "exit";
  _command[1] = "display";
  _command[2] = "input";
  _command[3] = "simulate";
  _command[4] = "loop";
  _command[5] = "dump";
  _pointerMap[_command[0]] = &Prompt::exitCommand;
  _pointerMap[_command[1]] = &Prompt::displayCommand;
  _pointerMap[_command[2]] = &Prompt::inputCommand;
  _pointerMap[_command[3]] = &Prompt::simulateCommand;
  _pointerMap[_command[4]] = &Prompt::loopCommand;
  _pointerMap[_command[5]] = &Prompt::dumpCommand;
}

Prompt::~Prompt(){

}

bool	Prompt::isCommand(std::string &str){
  for (unsigned int i = 0; i < COMMAND_NB; i++)
    if (str == _command[i])
      return true;
  return false;
}

bool	Prompt::isInput(){ return std::regex_match(_line, std::regex("[a-zA-Z0-9]*[=][0-1]")); }

int	Prompt::set(int argc, char **argv)
{
  nts::Parser		pars;
  nts::t_ast_node	*root;
  nts::t_ast_node	*finalTree;
  
  if (argc < 2) throw nts::myExcept("Usage: file.nts [[input=value] [...]]");
  if (bad_file_format(argv[1])) throw nts::myExcept("Error: bad file format");
  std::ifstream	file(argv[1]);
  if (!file) throw nts::myExcept(std::string("Error: ").append(argv[1]).append(" can't be open"));
  std::string line;
  while (getline(file, line)){
    epurStr(line);
    parse.feed(line);
  }
  epurStr(line);
  parse.feed(line);
  if ((root = parse.createTree()) == NULL)
    throw nts::myExcept("Can't create tree");
  parse.parseTree(*root);
  vmachine.setComponents(root);
  vmachine.setInput(argc, argv);
  vmachine.setPin(argc, argv);
  vmachine.setLinks(pars.getSectionByLexeme("links", root));
  //  vmachine.simulate();
  //vmachine.display();
  return 0;
};

void	Prompt::start(){
  while (!_done){
    std::cout << "> ";
    getline(std::cin, _line);
    if (!std::cin.eof()){
      if (isCommand(_line))
	(this->*_pointerMap[_line])();
      else if (isInput())
	(this->*_pointerMap["input"])();
      else if (!_line.empty())
	std::cout << "'" << _line <<"': unknown command" << std::endl;
    }
    else _done = 1;
  }
};

void	Prompt::printError(){
  std::cout  << _err << std::endl;
};

//Commands
void	Prompt::exitCommand(void){
  _done = 1;
}
void	Prompt::displayCommand(void){
  vmachine.display();
}
void	Prompt::inputCommand(void){
  InputVar resp(_line);

  if (vmachine.setInput(resp.getName(), resp.getState()))
    resp.sayUndeclared();
}
void	Prompt::simulateCommand(void){
  vmachine.simulate();
}
void	Prompt::loopCommand(void){
  std::cout << "In loopCommand()" << std::endl;
}
void  Prompt::dumpCommand(void){
  vmachine.Dump();
}



/*
**   Input Var 
**
*/

InputVar::InputVar(std::string &str){
  _name = str.substr(0, str.find('='));
  _state = str[str.size() - 1] - '0';
};
InputVar::~InputVar(){};
int	InputVar::getState(){ return _state; };
std::string	InputVar::getName(){ return _name; };

void		InputVar::sayUndeclared(){
  std::cout << "Error: \'" << _name << "\' is undeclared" << std::endl;
}
