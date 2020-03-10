/*
** EPITECH PROJECT, 2020
** epitech
** File description:
** cpp
*/

#include <SFML/Graphics.hpp>

extern "C"
{
    void Display_Window(int x, int y)
    {
        sf::RenderWindow window(sf::VideoMode(x, y), "SFML works!");
        sf::CircleShape shape(100.f);

        shape.setFillColor(sf::Color::Green);
        while (window.isOpen())
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
            }
            window.clear();
            window.draw(shape);
            window.display();
        }
    }
}
