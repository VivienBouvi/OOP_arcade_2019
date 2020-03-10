##
## EPITECH PROJECT, 2020
## OOP_arcade_2019
## File description:
## Makefile
##

GPP				=		g++

NAME			=		../lib_arcade_ncurses.so

SRC				=		ncurses.cpp

OBJ				=       $(SRC:.cpp=.o)

CPPFLAGS		=		-W -Wall -Wextra -ldl -shared -fPIC -lncurses

all:		$(NAME)

$(NAME): 	$(OBJ)
			$(GPP) -o $(NAME) $(OBJ) $(CPPFLAGS)

clean:
			$(RM) $(OBJ)


fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re