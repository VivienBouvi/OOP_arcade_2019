##
## EPITECH PROJECT, 2020
## OOP_arcade_2019
## File description:
## Makefile
##

NCURSES_DIR			=	./Ncurses

SFML_DIR			=	./Sfml/

NAME				=	lib

all:		$(NAME)

$(NAME):
			@make --no-print-directory -C $(NCURSES_DIR)
			@make --no-print-directory -C $(SFML_DIR)

clean:
			@make clean --no-print-directory -C $(NCURSES_DIR)
			@make clean --no-print-directory -C $(SFML_DIR)

fclean:
			@make fclean --no-print-directory -C $(NCURSES_DIR)
			@make fclean --no-print-directory -C $(SFML_DIR)

re:			fclean all

.PHONY:		all $(NAME) clean fclean re