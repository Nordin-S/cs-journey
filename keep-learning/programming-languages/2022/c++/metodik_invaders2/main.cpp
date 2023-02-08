#include "game.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    metodik_invaders2::Game gameScene;
    return a.exec();
}
