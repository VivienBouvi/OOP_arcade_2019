/*
** EPITECH PROJECT, 2020
** epitech
** File description:
** cpp
*/

#include <ncurses.h>
#include <string>

extern "C"
{
    void Display_Window(int x, int y)
    {
        (void) x;
        (void) y;
        initscr();
        keypad(stdscr, 1);
        noecho();
        refresh();
        getch();
        endwin();
    }
}
