/*
** EPITECH PROJECT, 2020
** epitech
** File description:
** cpp
*/

#include <ncurses.h>
#include <string>

void Display_Window(int x, int y)
{
    initscr();
    keypad(stdscr, 1);
    noecho();
    refresh();
    getch();
    endwin();

    return (0);
}
