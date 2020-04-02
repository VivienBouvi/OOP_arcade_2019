/*
** EPITECH PROJECT, 2020
** include
** File description:
** snake
*/

class Snake {
public:
    Snake(sf::RenderWindow &window, int size);
    void Update(sf::Event &event);
    void Display();
    void SnakeGrows();
    void Move();
    void FoodGen();
    void Collisions();
    void Run();
private:
    sf::RenderWindow &Window;
    sf::CircleShape food;
    sf::Clock clock;
    int size;
    int score;
    int updaterate;
    float actualtime;
    int Left;
    int Right;
    int Up;
    int Down;
    std::vector<sf::RectangleShape> snake_tab;
};
