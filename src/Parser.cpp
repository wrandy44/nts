//
// Parser.cpp for zd in /home/debrau_c/cours/cpp_nanotekspice/src
// 
// Made by Carl DEBRAUWERE
// Login   <debrau_c@epitech.net>
// 
// Started on  Fri Feb 10 14:19:31 2017 Carl DEBRAUWERE
// Last update Wed Mar  1 12:59:48 2017 debrau_c
//

#include <regex>
#include <iostream>
#include "Parser.hpp"
#include "myExcept.hpp"

namespace nts{
  Parser::Parser(){ _state = ASTNodeType::DEFAULT; }
  std::string	nts::Parser::getValueComp(std::string const& input)
  {
    size_t	pos = input.find(' ') + 1;
    std::string	tmp;
    
    while (input[pos])
      {
	tmp += input[pos];
	pos++;
      }
    return tmp;
  }
  
  std::string	nts::Parser::getLexemeComp(std::string const& input)
  {
    std::string	tmp;
    int	i = 0;

    while (input[i] != ' ')
      {
	tmp += input[i];
	i++;
      }
    return tmp;
  }
  
  void	nts::Parser::pushComponent(std::string const& input, t_ast_node *root)
  {
    t_ast_node	*node;
    t_ast_node	*newNode;
    t_ast_node	*newNodeBis;
    std::string		stringTmp;
    
    node = getSectionByLexeme("chipsets", root); 
    newNode = new t_ast_node(new std::vector<t_ast_node *>);
    newNode->lexeme = getLexemeComp(input);
    newNode->type = ASTNodeType::COMPONENT;
    newNode->value = getValueComp(input);
    newNodeBis = new t_ast_node(new std::vector<t_ast_node *>);
    newNodeBis->lexeme = "NEWLINE";
    newNodeBis->type = ASTNodeType::NEWLINE;
    newNodeBis->value = "NEWLINE";
    newNode->children->push_back(newNodeBis);
    node->children->push_back(newNode);
  }
  
  t_ast_node	*Parser::getSectionByLexeme(std::string const& l, t_ast_node *root)
  {
    std::vector<t_ast_node *>::iterator	i;

    for (i = root->children->begin(); i != root->children->end(); i++)
      {
	if ((*i)->lexeme == l)
	  return (*i);
      }
    return (nullptr);
  }
  
  std::string	getLexemeLink(std::string const& in){ return (in.substr(0, in.find(":"))); }
  
  std::string	getLexemeLinkEnd(std::string const& in){
    std::string tmp;
    tmp = in.substr(in.find(" ") + 1, in.size() -1);
    return tmp.substr(0, tmp.find(":"));
  }
  std::string	getValueLink(std::string const& in){
    std::string tmp = in.substr(0, in.find(" "));
    return tmp.substr(tmp.find(":") + 1, tmp.size());
  }
  
  std::string	getValueLinkEnd(std::string const& in){
    std::string tmp;
    
    tmp = in.substr(in.find(" ") + 1, in.size() -1);
    return tmp.substr(tmp.find(":") + 1, tmp.size() -1);
  }
  
  void	Parser::pushLink(std::string const& input, t_ast_node *root){
    t_ast_node	*section;
    t_ast_node	*link;
    t_ast_node	*link_end;
    t_ast_node	*new_l;

    section = getSectionByLexeme("links", root);
    link = new t_ast_node(new std::vector<t_ast_node *>);
    link->lexeme = getLexemeLink(input);
    link->type = ASTNodeType::LINK;
    link->value = getValueLink(input);
    link_end = new t_ast_node(new std::vector<t_ast_node *>);
    link_end->lexeme = getLexemeLinkEnd(input);
    link_end->type = ASTNodeType::LINK_END;
    link_end->value = getValueLinkEnd(input);    
    new_l = new t_ast_node(new std::vector<t_ast_node *>);
    new_l->lexeme = "NEWLINE";
    new_l->value = "NEWLINE";
    new_l->type = ASTNodeType::NEWLINE;
    link->children->push_back(link_end);
    link_end->children->push_back(new_l);
    section->children->push_back(link);
  }

  std::string	Parser::getSectionName(std::string const& input){
    std::string	ret;

    ret = input.substr(1, input.size() -2);
    return ret;
  }

  void	Parser::pushSection(std::string const& input, t_ast_node *root){
    t_ast_node	*sect;
    std::string	lexeme;
    
    sect = new t_ast_node(new std::vector<t_ast_node *>);
    sect->lexeme = getSectionName(input);
    sect->value = input;
    sect->type = ASTNodeType::SECTION;
    root->children->push_back(sect);
  }
  
  void		Parser::pushDefault(const std::string &input, t_ast_node *root){
    t_ast_node	*def = new t_ast_node(new std::vector<t_ast_node *>);

    def = new t_ast_node(new std::vector<t_ast_node *>);
    def->lexeme = "0";
    def->value = input;
    def->type = ASTNodeType::DEFAULT;
    root->children->push_back(def);
  }
  
  ASTNodeType	Parser::typeOf(std::string const& input){
    std::regex	regCompo("^[a-zA-Z0-9]+[ ][a-zA-Z0-9().]+$");
    std::regex	regLink("^[a-zA-Z0-9]+[:][a-zA-Z0-9]+[ ][a-zA-Z0-9]+[:][a-zA-Z0-9]+$");
    std::regex	regSection("^[.][a-zA-Z]+[:]$");
    
    if (std::regex_match(input, regCompo))
      return ASTNodeType::COMPONENT;
    else if (std::regex_match(input, regLink))
      return ASTNodeType::LINK;
    else if (std::regex_match(input, regSection))
      return ASTNodeType::SECTION;
    return ASTNodeType::DEFAULT;
  }
  
  void	Parser::feed(std::string const& input)
  { inputs.push_back(input); }
  
  Parser::~Parser(){}

  bool	Parser::check_dble_comp(std::vector<std::string> &view)
  {
    int	k = 0;
    
    for (std::vector<std::string>::iterator i = view.begin();
	 i != view.end(); i++, k++)
      for (std::vector<std::string>::iterator j = view.begin() + k + 1;
	   j != view.end(); j++)
	if (*i == *j)
	  throw nts::myExcept(std::string("Error: '").append(*i).append("' already declared"));
    return false;
  }

  bool	component_undeclared(std::vector<std::string> &view, std::string &name)
  {
    for (std::vector<std::string>::iterator i = view.begin(); i != view.end() ; i++)
      if ((*i) == name)
	return false;
    return true;
  }

  void	Parser::parseDefault(t_ast_node &root)
  {
    for (std::vector<t_ast_node *>::iterator i = root.children->begin();
	 i != root.children->end(); i++)
      {
	if ((*i)->type == ASTNodeType::DEFAULT)
	  throw nts::myExcept(std::string("Error: unrecognized symbol '").append((*i)->value).append("'"));
    	else if ((*i)->type == ASTNodeType::COMPONENT)
	  tmpComp.push_back((*i)->value);
	else if ((*i)->type == ASTNodeType::SECTION)
	  {
	    if ((*i)->lexeme != "chipsets" && (*i)->lexeme != "links")
	      throw nts::myExcept(std::string("Error: unrecognized symbol '").
				  append((*i)->value).append("'"));
	  }
	else if ((*i)->type == ASTNodeType::LINK)
	  tmpLink.push_back((*i)->lexeme);
	else if ((*i)->type == ASTNodeType::LINK_END)
	  tmpLinkEnd.push_back((*i)->lexeme);
	parseDefault(*(*i));
      }
  }

  void	check_link_undeclared(std::vector<std::string> &c,
			      std::vector<std::string> &l,
			      std::vector<std::string> &le)
  {
    bool	seen = false;

    for (std::vector<std::string>::iterator i = l.begin(); i != l.end(); i++)
      {
	seen = false;
	for (std::vector<std::string>::iterator j = c.begin(); j != c.end(); j++)
	  if (*i == *j){
	    seen = true;
	  }
	if (!seen)
	  throw nts::myExcept(std::string("LinkError: ").append(*i).append(" undeclared"));
      }
    for (std::vector<std::string>::iterator i = le.begin(); i != le.end(); i++)
      {
	seen = false;
	for (std::vector<std::string>::iterator j = c.begin(); j != c.end(); j++)
	  if (*i == *j) seen = true;
	if (!seen)
	  throw nts::myExcept(std::string("LinkError: ").append(*i).append(" undeclared"));
      }
  }
  
  void	Parser::parseTree(t_ast_node& root){
    t_ast_node	*link, *chip;
    
    tmpComp.clear();
    tmpLink.clear();
    tmpLinkEnd.clear();
    parseDefault(root);//fill all tmp ^
    if ((link = getSectionByLexeme("links", &root)) == nullptr
	|| (chip = getSectionByLexeme("chipsets", &root)) == nullptr)
      throw nts::myExcept(std::string("No section"));
    check_dble_comp(tmpComp);
    check_link_undeclared(tmpComp, tmpLink, tmpLinkEnd);
  }
  
  t_ast_node	*Parser::createTree(){
    std::string	input;
    t_ast_node	*ret;
    
    ret = new t_ast_node(new std::vector<struct s_ast_node*>());
    ret->lexeme = "root";
    ret->value = "/";
    ret->type = ASTNodeType::SECTION;
    _state = ASTNodeType::DEFAULT;    
    for (std::vector<std::string>::iterator i = inputs.begin(); i != inputs.end(); i++)
      {
	input = *i;
	if (!input.empty())
	  {
	    if (typeOf(input) == ASTNodeType::SECTION)
	      {
		pushSection(input, ret);
		if (input == ".chipsets:")
		  _state = ASTNodeType::COMPONENT;
		else if (input == ".links:")
		  _state = ASTNodeType::LINK;
	      }
	    else if (typeOf(input) == ASTNodeType::COMPONENT
		     && _state == ASTNodeType::COMPONENT)
	      pushComponent(input, ret);
	    else if (typeOf(input) == ASTNodeType::LINK
		     && _state == ASTNodeType::LINK)
	      pushLink(input, ret);
	    else if (typeOf(input) == ASTNodeType::DEFAULT)
	      pushDefault(input, ret);
	  }
      }
    return ret;
  }  

  void	recurseView(t_ast_node *root, unsigned int nb){
    std::vector<t_ast_node *>::iterator	i;
    unsigned int	k = 0;
    if (root == NULL)
      return ;
    while (k < nb){
      if (k != nb - 1)
	std::cout << "|\t";
      else
	std::cout << "|-->";
      k++;
    }
    std::cout << "[" << root->lexeme << "] v:("<< root->value << ")" << std::endl;;
    for (i = root->children->begin(); i != root->children->end(); i++){
      recurseView((*i), nb+1);
    }
  }

  void	Parser::view(t_ast_node *root){
    recurseView(root, 0);
  }
}
