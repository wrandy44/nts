## Makefile for azd in /home/debrau_c/cours/cpp_nanotekspice
## 
## Made by Carl DEBRAUWERE
## Login   <debrau_c@epitech.net>
## 
## Started on  Wed Feb  8 14:31:57 2017 Carl DEBRAUWERE
## Last update Sat Mar  4 18:32:53 2017 Brunel Axel
##

NAME		= xxx

SRC		= src/main.cpp	\
		  src/Prompt.cpp	\
		  src/functions.cpp	\
		  src/Parser.cpp	\
		  src/Input.cpp		\
		  src/myExcept.cpp	\
		  src/False.cpp		\
		  src/True.cpp		\
		  src/Link.cpp		\
		  src/Component.cpp	\
	 	  src/Component4081.cpp	\
		  src/Component4001.cpp	\
		  src/Component4011.cpp	\
		  src/Component4030.cpp	\
		  src/Component4008.cpp	\
		  src/Component4069.cpp	\
		  src/Component4071.cpp	\
	  	  src/Clock.cpp

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
