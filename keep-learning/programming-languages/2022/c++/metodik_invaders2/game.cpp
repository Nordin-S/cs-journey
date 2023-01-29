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

    // performance of view
    view->setCacheMode(QGraphicsView::CacheBackground);
    view->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    view->setOptimizationFlags(QGraphicsView::DontSavePainterState);
    view->setOptimizationFlags(QGraphicsView::DontAdjustForAntialiasing);

    // quality of view
    view->setRenderHint(QPainter::Antialiasing);
    view->setRenderHint(QPainter::SmoothPixmapTransform);
    view->setRenderHint(QPainter::TextAntialiasing);

//    view->setFixedSize(800, 1000);
//    view->setSceneRect(400, 200, 800, 1000);
//    view->showMaximized();
    view->setFixedSize(QApplication::primaryScreen()->size());
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scene->setSceneRect(0, 0, view->width(), view->height());

    view->showFullScreen();

    // TODO: move to background handler
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
    player = new Player(settings::ShipSpeeds::PlayerSpeed,
                        settings::Healths::PlayerHealth,
                        settings::UpdateMs::UMs10,
                        settings::MoveSteps::Move50,
                        settings::AmmoType::TypeLaser,
                        settings::AmmoDmgLvl::Dmg01,
                        settings::ShipTypes::Striker,
                        this);
    scene->addItem(player);
    player->setPosition(scene->width()/2, scene->height()-200);

    // TODO: generate enemy - needs enemy spawner class
    // Create a new enemy and add it to the scene
//    enemy = new Enemy(settings::ShipSpeeds::FighterSpeed,
//                      settings::Healths::FighterHealth,
//                      settings::UpdateMs::UMs50,
//                      settings::MoveSteps::Move70,
//                      settings::AmmoType::TypeLaser,
//                      settings::EnemyShipType, this);
//    scene->addItem(enemy);

    // Create a timer for the game loop
    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), scene, SLOT(advance()));
    connect(timer, SIGNAL(timeout()), scene, SLOT(update()));
    timer->start(1000 / 60);

    // Show the view
    view->setFocus();
    view->activateWindow();
    view->installEventFilter(this);

    bgMusic = new BackgroundMusic({"qrc:/resources/music/playTime01.mp3"});
    bgMusic->setVolume(10);

    view->setBackgroundBrush(Qt::black);
    view->show();
  }

  // TODO: move to input handler class and needs to be improved
  bool Game::eventFilter(QObject *obj, QEvent *event) {
    QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
    if (event->type() == QEvent::KeyPress) {
      if (keyEvent->key() == Qt::Key_Left) {
        player->setDirectionX(-1);
      }
      if (keyEvent->key() == Qt::Key_Right) {
        player->setDirectionX(1);
      }
      if(keyEvent->key() == Qt::Key_Up) {
        player->setDirectionY(-1);
      }
      if(keyEvent->key() == Qt::Key_Down) {
        player->setDirectionY(1);
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
        player->setDirectionX(0);
      }
      if (keyEvent->key() == Qt::Key_Right) {
        player->setDirectionX(0);
      }
      if(keyEvent->key() == Qt::Key_Up) {
        player->setDirectionY(0);
      }
      if(keyEvent->key() == Qt::Key_Down) {
        player->setDirectionY(0);
      }
    }
    return QObject::eventFilter(obj, event);
  }

  Game::~Game() {
    delete player;
    delete bgMusic;
  }
} // namespace metodik_invaders2