/*
** EPITECH PROJECT, 2020
** main
** File description:
** snake
*/

#include <iostream>
#include <SFML/Graphics.hpp>
#include "snake.hpp"

using namespace std;
using namespace sf;

Snake::Snake(RenderWindow &window, int size) : Window(window), size(size)
{
    updaterate = 200;
    Left = 0;
    Right = 1;
    Up = 0;
    Down = 0;
    score = 0;
    srand(std::time(0));
    SnakeGrows();
    SnakeGrows();
    SnakeGrows();
    food.setRadius(size / 2);
    food.setFillColor(Color::Magenta);
    FoodGen();
}

void Snake::Move()
{
    int i = snake_tab.size() - 1;

    if (actualtime < updaterate)
        actualtime += clock.restart().asMilliseconds();
    else {
        actualtime = 0.0f;
        if (snake_tab.size() > 1) {
            while (i > 0) {
                snake_tab[i].setPosition(Vector2f(snake_tab[i-1].getPosition().x, snake_tab[i-1].getPosition().y));
                i--;
            }
        }
        if (Left)
            snake_tab[0].move(-32, 0);
        if (Right)
            snake_tab[0].move(32, 0);
        if (Up)
            snake_tab[0].move(0, -32);
        if (Down)
            snake_tab[0].move(0, 32);
        Collisions();
    }
}

void Snake::SnakeGrows()
{
    RectangleShape sprite;

    sprite.setSize(Vector2f(32, 32));
    sprite.setOutlineThickness(1.0f);
    //Create_rect(sprite, 32, 32);
    sprite.setOutlineColor(Color::White);
    //SetColor_rect(sprite, "White");
    if (snake_tab.empty()) {
        sprite.setFillColor(Color::Red);
        //SetColor_rect(sprite, "Red");
        sprite.setPosition(320, 256);
        //SetPosition_rect(sprite, 320, 256);
    } else {
        sprite.setFillColor(Color::Yellow);
        //SetColor_rect(sprite, "Yellow");
        sprite.setPosition(snake_tab[snake_tab.size() - 1].getPosition().x - sprite.getSize().x, snake_tab[snake_tab.size() - 1].getPosition().y);
        //SetPosition_rect(sprite, snake_tab[snake_tab.size() - 1].getPosition().x - sprite.getSize().x, snake_tab[snake_tab.size() - 1].getPosition().y);
    }
    snake_tab.push_back(sprite);
}

void Snake::FoodGen()
{
    int x = rand() % (Window.getSize().x / size);
    int y = rand() % (Window.getSize().y / size);
    int i = 0;

    while (i < snake_tab.size()) {
        food.setPosition(x * size, y * size);
        i++;
    }
}

void Snake::Collisions()
{
    int i = 3;

    if (snake_tab[0].getPosition().x < 0 || snake_tab[0].getPosition().y < 0 ||
        snake_tab[0].getPosition().x + snake_tab[0].getSize().x > Window.getSize().x ||
        snake_tab[0].getPosition().y + snake_tab[0].getSize().y > Window.getSize().y) {
        //Game_lost(Window, score);
        Window.close();
        cout << "You reached a score of " << score << endl;
    } if (snake_tab[0].getPosition().x == food.getPosition().x && snake_tab[0].getPosition().y == food.getPosition().y) {
        FoodGen();
        SnakeGrows();
        score = score + 1;
    } while (i < snake_tab.size()) {
        if(snake_tab[0].getPosition().x == snake_tab[i].getPosition().x && snake_tab[0].getPosition().y == snake_tab[i].getPosition().y) {
            //Game_lost(Window, score);
            Window.close();
            cout << "You reached a score of " << score << endl;
        }
        i++;
    }
}

void Snake::Update(Event &event)
{
    //keyboard handling
    if (event.key.code == Keyboard::Left) {
            if (!Left && !Right) {
                Left = 1;
                Right = 0;
                Up = 0;
                Down = 0;
            }
    } if (event.key.code == Keyboard::Right) {
            if (!Left && !Right) {
                Left = 0;
                Right = 1;
                Up = 0;
                Down = 0;
            }
    } if (event.key.code == Keyboard::Up) {
            if (!Up && !Down) {
                Left = 0;
                Right = 0;
                Up = 1;
                Down = 0;
            }
    } if (event.key.code == Keyboard::Down) {
            if (!Up && !Down) {
                Left = 0;
                Right = 0;
                Up = 0;
                Down = 1;
            }
    }
}

void Snake::Display()
{
    int i = 0;

    Window.draw(food);
    while (i < snake_tab.size()) {
        Window.draw(snake_tab[i]);
        i++;
    }
}

int main(int ac, char **av)
{
    RenderWindow window(VideoMode(800, 640), "Window");
    Snake snake(window, 32);

    window.setFramerateLimit(60);
    window.setKeyRepeatEnabled(false);
    //Set_Window(window);
    while (window.isOpen()) {
        snake.Move();
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
            if (event.type == Event::KeyPressed)
		snake.Update(event);
        }
        window.clear(Color(0,255,0));
        //Window_clear(0, 255, 0);
        snake.Display();
	window.display();
        //Window_display(window);
    }
    return (0);
}
