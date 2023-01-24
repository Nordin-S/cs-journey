#include "game.h"
#include "invaders.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

//    Invaders w;
////    w.setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
//    w.setWindowState(Qt::WindowMaximized);
//    w.showFullScreen();
    metodik_invaders2::Game gameScene;
    return a.exec();
}
