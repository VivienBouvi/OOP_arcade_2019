##
## EPITECH PROJECT, 2020
## OOP_arcade_2019
## File description:
## Makefile
##

GPP				=		g++

NAME			=		arcade

SRC				=		core/main.cpp

OBJ				=       $(SRC:.cpp=.o)

CPPFLAGS		=		-W -Wall -Wextra -ldl

all:
			@make --no-print-directory -C ./lib
			@make --no-print-directory core

graphicals:
			@make --no-print-directory -C ./lib

core:		$(NAME)

$(NAME): 	$(OBJ)
			$(GPP) -o $(NAME) $(OBJ) $(CPPFLAGS)

clean:
			$(RM) $(OBJ)
			@make clean --no-print-directory -C ./lib

fclean:		clean
			$(RM) $(NAME)
			@make fclean --no-print-directory -C ./lib

re:			fclean all

.PHONY:		all clean fclean re core graphicals