##
## EPITECH PROJECT, 2020
## OOP_arcade_2019
## File description:
## Makefile
##

GPP				=		g++

NAME			=		../lib_arcade_sfml.so

SRC				=		sfml.cpp

OBJ				=       $(SRC:.cpp=.o)

CPPFLAGS		=		-W -Wall -Wextra -ldl -shared -fPIC -lsfml-audio -lsfml-window -lsfml-graphics -lsfml-system

all:		$(NAME)

$(NAME): 	$(OBJ)
			$(GPP) -o $(NAME) $(OBJ) $(CPPFLAGS)

clean:
			$(RM) $(OBJ)


fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re