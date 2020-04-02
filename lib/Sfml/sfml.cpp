/*
** EPITECH PROJECT, 2020
** epitech
** File description:
** cpp
*/

#include <SFML/Graphics.hpp>

extern "C"
{
    void Create_rect(int x, int y)
    {
        sf::RectangleShape sprite;

        sprite.setSize(Vector2f(x, y));
        sprite.setOutlineThickness(1.0f);

    }
}
