#include "game.h"
#include "player.h"
#include "enemy.h"
#include "background.h"
#include "backgroundmusic.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QTimer>
#include <QKeyEvent>
#include <QApplication>

namespace metodik_invaders2 {
  Game::Game() {
    // Create a new scene and view
    scene = new QGraphicsScene();
    view = new QGraphicsView(scene);
//    view->setFixedSize(800, 1000);
//    view->setSceneRect(400, 200, 800, 1000);
//    view->showMaximized();
    view->setFixedSize(QApplication::primaryScreen()->size());
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scene->setSceneRect(0, 0, view->width(), view->height());

    view->showFullScreen();

    Background *bgUniverse = new Background(1, 100,
                                            {":/resources/bg/nebulaAquaPink.png"},
                                            scene);
    Background *galaxies = new Background(1, 90,
                                          {":/resources/bg/galaxies01.png",
                                           ":/resources/bg/galaxies02.png"},
                                          scene);
    Background *bgStars1 = new Background(1, 80,
                                          {":/resources/bg/starsSmall1.png"},
                                          scene);
    Background *bgStars2 = new Background(1, 60,
                                          {":/resources/bg/starsSmall2.png"},
                                          scene);

    QList<QString> planetSlides = {":/resources/bg/planets01.png",
                                   ":/resources/bg/planets02.png",
                                   ":/resources/bg/planets03.png",
                                   ":/resources/bg/planets04.png",
    };
    Background *bgPlanets = new Background(2, 20, planetSlides, scene);

    Background *bgStarWarp = new Background(6, 8,
                                            {":/resources/bg/starfieldWarp.png"},
                                            scene);

    // Create a new player and add it to the scene
    player = new Player(static_cast<int>(settings::SHIP_SPEEDS::PLAYER_SPEED),
                      static_cast<int>(settings::HEALTHS::PLAYER_HEALTH),
                      static_cast<int>(settings::UPDATE_MS::uMS01),
                      settings::AMMO_TYPE::LASER_SMALL,
                      settings::ENEMY_SHIP_TYPE::FIGHTER, this);
    scene->addItem(player);
    player->setPosition(view->width(), view->height());


    // Create a new enemy and add it to the scene
    enemy = new Enemy(static_cast<int>(settings::SHIP_SPEEDS::FIGHTER_SPEED),
                      static_cast<int>(settings::HEALTHS::FIGTHER_HEALTH),
                      static_cast<int>(settings::UPDATE_MS::uMS01),
                      settings::ENEMY_SHIP_TYPE::FIGHTER, this);
    scene->addItem(enemy);

    // Create a timer for the game loop
    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), scene, SLOT(advance()));
    connect(timer, SIGNAL(timeout()), scene, SLOT(update()));
    timer->start(1000 / 60);

    // Show the view
    view->setFocus();
    view->activateWindow();
    view->installEventFilter(this);


//    bgMusic = new BackgroundMusic({"qrc:/resources/music/playTime01.mp3"});

    view->setBackgroundBrush(Qt::black);
    view->show();

//    qDebug() << "View has focus: " << view->hasFocus();
//    qDebug() << "Player has focus: " << player->hasFocus();
  }


  bool Game::eventFilter(QObject *obj, QEvent *event) {
    QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
    if (event->type() == QEvent::KeyPress) {
      if (keyEvent->key() == Qt::Key_Left) {
        player->stopMoveRight();
        player->moveLeft();
      }
      if (keyEvent->key() == Qt::Key_Right) {
        player->stopMoveLeft();
        player->moveRight();
      }
      if (keyEvent->key() == Qt::Key_Space) {
        player->startShooting();
      }
    }
    if (event->type() == QEvent::KeyRelease) {
      if (keyEvent->key() == Qt::Key_Space) {
        player->stopShooting();
      }
      if (keyEvent->key() == Qt::Key_Left) {
        player->stopMoveLeft();
      }
      if (keyEvent->key() == Qt::Key_Right) {
        player->stopMoveRight();
      }
    }
    return QObject::eventFilter(obj, event);
  }

  Game::~Game() {
    delete player;
    // TODO: should delete this one aswell
//    delete bgMusic;
  }
} // namespace metodik_invaders2