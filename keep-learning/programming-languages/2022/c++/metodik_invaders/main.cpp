#include <QApplication>
#include <QTimer>
#include "gamemanager.h"
Q_DECLARE_METATYPE(GameManager*)

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    GameManager game;
    game.show();
//    QtInvaders invaders;
//    invaders.show();
//    QTimer timer;
//    QObject::connect(&timer, &QTimer::timeout, &game, &GameManager::update);
//    timer.start(20); // update every 20 milliseconds
    return a.exec();
}
