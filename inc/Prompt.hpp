/*
** Prompt.hh for azd in /home/debrau_c/bin
** Made by Carl DEBRAUWERE
** Login   <debrau_c@epitech.net>
** 
** Started on  Mon Jan 16 09:33:45 2017 Carl DEBRAUWERE
// Last update Mon Feb 13 18:02:11 2017 Carl DEBRAUWERE
*/

#ifndef _PROMPT_H_
# define _PROMPT_H_

# include <iostream>
# include <fstream>
# include <string>
# include <map>
# include <regex>
# include "IComponent.hpp"
# include "Component4081.hpp"
# include "functions.hpp"
# include "Parser.hpp"
# include "VMachine.hpp"

#define COMMAND_NB 6

class InputVar{
  std::string	_name;
  int		_state;//Like tristate as IComponent
public:
  InputVar(std::string &str);
  ~InputVar();
  int	getState();
  std::string	getName();
  void		sayUndeclared();
};
  
class Prompt{
  nts::Parser		parse;
  bool			_done = 0;
  std::string		_line, _err, _command[COMMAND_NB];
  std::map<std::string, void (Prompt::*)(void)> _pointerMap;
  VMachine		vmachine;
public:
  Prompt();
  ~Prompt();
  bool	isCommand(std::string &str);
  bool	isInput();  
  int	set(int argc, char **argv);
  void	start();
  void	printError();
  //Commands
  void	exitCommand(void);
  void	displayCommand(void);
  void	inputCommand(void);
  void	simulateCommand(void);
  void	loopCommand(void);
  void  dumpCommand(void);
};

#endif /* Prompt */
