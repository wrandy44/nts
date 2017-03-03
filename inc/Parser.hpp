//
// AParser.hpp for azd in /home/debrau_c/cours/cpp_nanotekspice
// 
// Made by Carl DEBRAUWERE
// Login   <debrau_c@epitech.net>
// 
// Started on  Fri Feb 10 12:55:51 2017 Carl DEBRAUWERE
// Last update Tue Feb 28 21:26:40 2017 debrau_c
//

#ifndef _PARSER_HPP_
# define _PARSER_HPP_

# include "IParser.hpp"

namespace nts{
  class Parser : public IParser{
    ASTNodeType _state;
    std::vector<std::string> inputs;
    std::vector<std::string>	tmpComp;
    std::vector<std::string>	tmpLink;
    std::vector<std::string>	tmpLinkEnd;
    
    //Only used on class
    void	parseDefault(t_ast_node &root);
  public:
    Parser();
    ~Parser();
    void feed(std::string const& input);
    void parseTree(t_ast_node& root);
    nts::t_ast_node *createTree();
    void createFinalTree(nts::t_ast_node *);
    void getBack();
    void	view(t_ast_node *);
    t_ast_node	*getSectionByLexeme(std::string const& l, t_ast_node *root);
    std::string	getSectionName(std::string const& input);
    void	pushComponent(std::string const& input, t_ast_node *root);
    void	pushLink(std::string const& input, t_ast_node *root);
    void	pushSection(std::string const& input, t_ast_node *root);
    void	pushDefault(std::string const& input, t_ast_node *root);
    std::string	getValueComp(std::string const& input);
    std::string	getLexemeComp(std::string const& input);
    ASTNodeType typeOf(std::string const& input);
    bool	check_dble_comp(std::vector<std::string> &view);
    
  };
}

#endif /* A_PARSER_HPP */
