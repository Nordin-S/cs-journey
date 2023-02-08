#include "game.h"
#include "spacecraft.h"
#include "background.h"
#include "backgroundmusic.h"
#include "player.h"
#include "GameMenu.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QTimer>
#include <QApplication>

namespace metodik_invaders2 {
  Game::Game()
    : m_state(MAINMENU),
      m_score(0),
      m_lives(3),
      m_health(100),
      m_waveCount(0),
      view(new QGraphicsView()),
      m_inputHandler(new InputHandler()),
      startMenuScene(new GameMenu(this)),
      pauseMenuScene(new GameMenu(this)),
      gameOverMenuScene(new GameMenu(this)),
      gameScene(new GameMenu(this)) {

    setupView();
    setupGameScene();
    setupMainMenuScene();
    setupPauseMenuScene();
    setupGameOverMenuScene();

    view->setScene(startMenuScene);

    connect(m_inputHandler, &InputHandler::pausePressed, this,
            &Game::togglePauseGame);


    bgMusic = new BackgroundMusic({"qrc:/resources/music/menu01.mp3"});

  }

  Game::~Game() {
    delete player;
    delete bgMusic;
    delete spawnHandler;
    delete view;
    delete gameScene;
  }

  void Game::setupView() {
    // performance of view
    view->setCacheMode(QGraphicsView::CacheBackground);
    view->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    view->setOptimizationFlags(QGraphicsView::DontSavePainterState);
//    view->setOptimizationFlags(QGraphicsView::DontAdjustForAntialiasing);

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

    // Show the view
    view->setFocus();
    view->activateWindow();
    view->installEventFilter(m_inputHandler);
    view->showFullScreen();
  }

  void Game::setupGameBackground() {
    // Create a new background and add it to the gameScene
    auto *bgUniverse = new Background(1, 100,
                                      {":/resources/bg/nebulaAquaPink.png"},
                                      gameScene);
    auto *galaxies = new Background(1, 90,
                                    {":/resources/bg/galaxies01.png",
                                     ":/resources/bg/galaxies02.png"},
                                    gameScene);
    auto *bgStars1 = new Background(1, 80,
                                    {":/resources/bg/starsSmall1.png"},
                                    gameScene);
    auto *bgStars2 = new Background(1, 60,
                                    {":/resources/bg/starsSmall2.png"},
                                    gameScene);

    QList<QString> planetSlides = {":/resources/bg/planets01.png",
                                   ":/resources/bg/planets02.png",
                                   ":/resources/bg/planets03.png",
                                   ":/resources/bg/planets04.png",
    };
    auto *bgPlanets = new Background(2, 20, planetSlides, gameScene);

    auto *bgStarWarp = new Background(6, 8,
                                      {":/resources/bg/starfieldWarp.png"},
                                      gameScene);
  }

  void Game::setupMainMenuScene() {
    startMenuScene->setSceneRect(0, 0, view->width(), view->height());

    // Create backgrounds and add it to this scene
    auto *bgUniverse = new Background(1, 100,
                                      {":/resources/bg/nebulaRed.png"},
                                      startMenuScene);
    auto *bgStars1 = new Background(1, 80,
                                    {":/resources/bg/starsSmall1.png"},
                                    startMenuScene);
    auto *bgStars2 = new Background(1, 60,
                                    {":/resources/bg/starsSmall2.png"},
                                    startMenuScene);

    startMenuScene->setTitleImg(":/resources/ui/spaceInvasion.png");

    // Create the quit button
    auto *startBtn = new MenuButton(
      QPixmap(":/resources/ui/startGame.png"),
      QPixmap(":/resources/ui/startGame_active.png"));
    startMenuScene->addButton(startBtn);
    connect(startBtn, &MenuButton::clicked, this, &Game::startGame);

    // Create the quit button
    auto *quitBtn = new MenuButton(
      QPixmap(":/resources/ui/quitGame.png"),
      QPixmap(":/resources/ui/quitGame_active.png"));
    startMenuScene->addButton(quitBtn);
    connect(quitBtn, &MenuButton::clicked, this,
            []() { QApplication::quit(); });

    startMenuScene->buildMenu();
  }

  void Game::setupPauseMenuScene() {
    pauseMenuScene->setSceneRect(0, 0, view->width(), view->height());
  }

  void Game::setupGameOverMenuScene() {
    gameOverMenuScene->setSceneRect(0, 0, view->width(), view->height());
  }

  void Game::setupGameScene() {
    gameScene->setSceneRect(0, 0, view->width(), view->height());
    setupGameBackground();

    // Create a new player and add it to the gameScene
    player = new Player(settings::ShipSpeeds::PlayerSpeed,
                        settings::Healths::PlayerHealth,
                        settings::UpdateMs::UMs200,
                        settings::MoveSteps::Move01,
                        settings::AmmoType::TypeLaser,
                        settings::AmmoDmgLvl::Dmg10,
                        settings::ShipTypes::Striker,
                        this);
    gameScene->addItem(player);
    player->setPosition(gameScene->width() / 2, gameScene->height() - 200);
    player->setZValue(std::numeric_limits<qreal>::max());

    spawnHandler = new SpawnHandler(100, gameScene, this);

  }

  void Game::startGame() {
    m_state = RUNNING;
    view->setScene(gameScene);
//    bgMusic->play(); // change to game music
    // Create a gameSceneTimer for the game loop
    QTimer *gameSceneTimer = new QTimer();
    connect(gameSceneTimer, SIGNAL(timeout()), gameScene, SLOT(advance()));
    connect(gameSceneTimer, SIGNAL(timeout()), gameScene, SLOT(update()));
    gameSceneTimer->start(1000 / 60);
  }

  void Game::togglePauseGame() {

  }

  void Game::resumeGame() {

  }

  void Game::gameOver() {

  }
} // namespace metodik_invaders2