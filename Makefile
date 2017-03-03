## Makefile for azd in /home/debrau_c/cours/cpp_nanotekspice
## 
## Made by Carl DEBRAUWERE
## Login   <debrau_c@epitech.net>
## 
## Started on  Wed Feb  8 14:31:57 2017 Carl DEBRAUWERE
## Last update Fri Mar  3 02:57:25 2017 debrau_c
##

NAME		= xxx

SRC		= src/main.cpp	\
		  src/Prompt.cpp	\
		  src/functions.cpp	\
		  src/Parser.cpp	\
		  src/Input.cpp		\
		  src/myExcept.cpp	\
		  src/Link.cpp		\
		  src/Component.cpp	\
	 	  src/Component4081.cpp	\
		  src/Component4001.cpp	\
		  src/Component4008.cpp	\
		  src/Component4069.cpp	\
		  src/Component4071.cpp	\
		  src/Component4512.cpp	

CC		= g++

OBJ		= $(SRC:.cpp=.o)

CPPFLAGS	= -Iinc/ -g -std=c++11

RM		= rm -rf

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ)

all:	$(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
