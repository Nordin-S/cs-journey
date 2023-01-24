#include "invaders.h"
#include "./ui_invaders.h"

#include <QDirIterator>
#include <QLabel>
#include <QMovie>
#include <QPixmap>
#include <QWidget>

namespace metodik_invaders2 {
//  Invaders::Invaders(QWidget *parent)
//    : QWidget(parent), ui(new Ui::Invaders) {
//    ui->setupUi(this);
//    this->showFullScreen();
//
//    auto myBgMovie = new QMovie(":/resources/bg/menuBg.gif");
//    ui->menuBgAnimContainer->setMovie(myBgMovie);
//    ui->menuBgAnimContainer->movie()->setScaledSize(this->size());
//    ui->menuFrame->resize(this->size());
//    ui->menuBgAnimContainer->resize(this->size());
//    ui->itemsFrame->resize(this->size());
//    myBgMovie->start();
//
////    bgMusic = new BackgroundMusic({"qrc:/resources/music/menu01.mp3"});
//    QLabel *gameTitle = new QLabel(ui->menuFrame);
//    int titleWidth = 800;
//    int titleHeight = 330;
//    ui->gameTitle->setGeometry(ui->menuFrame->width() / 2 - (titleWidth / 2),
//                               100, titleWidth, titleHeight);
//    gameTitle->setStyleSheet(
//      "image: url(:/resources/ui/spaceInvasion.png);");
//    gameTitle->setGeometry(ui->menuFrame->width() / 2 - (titleWidth / 2), 100,
//                           titleWidth, titleHeight);
//    gameTitle->setScaledContents(true);
//    gameTitle->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
//    gameTitle->show();
//
//    ui->playButton->setStyleSheet(
//      "image: url(:/resources/ui/buttonBlue.png);");
//    ui->playButton->setGeometry(
//      ui->menuFrame->width() / 2 - (ui->playButton->width() / 2), 500,
//      ui->playButton->width(), ui->playButton->height());
////    ui->playButton->setScaledContents(true);
//    ui->playButton->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
//    ui->playButton->show();
//
//    ui->exitButton->setStyleSheet(
//      "image: url(:/resources/ui/buttonRed.png);");
//    ui->exitButton->setGeometry(
//      ui->menuFrame->width() / 2 - (ui->exitButton->width() / 2), 600,
//      ui->exitButton->width(), ui->exitButton->height());
////    ui->exitButton->setScaledContents(true);




// =========== myyyyyyyyy ==========
Invaders::Invaders(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Invaders)
{
    ui->setupUi(this);
    this->showFullScreen();

    auto myBgMovie = new QMovie(":/resources/bg/menuBg.gif");
    ui->menuBgAnimContainer->setMovie(myBgMovie);
    ui->menuBgAnimContainer->movie()->setScaledSize(this->size());
    ui->menuFrame->resize(this->size());
    ui->menuBgAnimContainer->resize(this->size());
    ui->itemsFrame->resize(this->size());
    myBgMovie->start();

//    bgMusic = new BackgroundMusic({"qrc:/resources/music/menu01.mp3"});
    QLabel *gameTitle = new QLabel(ui->menuFrame);
    int titleWidth = 800;
    int titleHeight = 330;
    ui->gameTitle->setGeometry(ui->menuFrame->width() / 2 - (titleWidth / 2), 100, titleWidth, titleHeight);
    gameTitle->setStyleSheet("image: url(:resources/ui/spaceInvasion.png);");
    gameTitle->show();
  }

  Invaders::~Invaders() {
    delete ui;
  }

} // namespace metodik_invaders2