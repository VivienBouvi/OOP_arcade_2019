/*
** EPITECH PROJECT, 2018
** 
** File description:
** 
*/

#include <QApplication>
#include <QPushButton>
 
void Display_Window(int x, int y, int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget fenetre;
    fenetre.setFixedSize(x, y);

    fenetre.show();
    return app.exec();
}
