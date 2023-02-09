#include "game.h"
#include "spacecraft.h"
#include "background.h"
#include "backgroundmusic.h"
#include "player.h"
#include "MenuScene.h"
#include "GameScene.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QTimer>
#include <QApplication>

namespace metodik_invaders2 {
  Game::Game()
    : m_state(settings::GameState::MAIN_MENU),
      m_score(0),
      m_lives(3),
      m_health(100),
      m_waveCount(0),
      view(new QGraphicsView()),
      m_inputHandler(new InputHandler()),
      startMenuScene(new MenuScene(this)),
      pauseMenuScene(new MenuScene(this)),
      gameOverMenuScene(new MenuScene(this)),
      m_bgMusic(new BackgroundMusic(this)) {

    setupView();

    setupMainMenuScene();
    setupPauseMenuScene();
    setupGameOverMenuScene();
    setupGameScene();

    showStartMenuScene();

    connect(m_inputHandler, &InputHandler::pausePressed, this,
            &Game::showPauseScene);
  }

  Game::~Game() {
    delete player;
    delete m_bgMusic;
    delete spawnHandler;
    delete gameScene;
    delete pauseMenuScene;
    delete gameOverMenuScene;
    delete startMenuScene;
    delete m_inputHandler;
    delete view;
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
                                      {":/resources/bg/nebulaAquaPink.png"});
    auto *galaxies = new Background(1, 90,
                                    {":/resources/bg/galaxies01.png",
                                     ":/resources/bg/galaxies02.png"});
    auto *bgStars1 = new Background(1, 80, {":/resources/bg/starsSmall1.png"});
    auto *bgStars2 = new Background(1, 60, {":/resources/bg/starsSmall2.png"});

    QList<QString> planetSlides = {":/resources/bg/planets01.png",
                                   ":/resources/bg/planets02.png",
                                   ":/resources/bg/planets03.png",
                                   ":/resources/bg/planets04.png"
    };
    auto *bgPlanets = new Background(2, 20, planetSlides);

    auto *bgStarWarp = new Background(6, 8,
                                      {":/resources/bg/starfieldWarp.png"});

    gameScene->addBackground(bgUniverse);
    gameScene->addBackground(galaxies);
    gameScene->addBackground(bgStars1);
    gameScene->addBackground(bgStars2);
    gameScene->addBackground(bgPlanets);
    gameScene->addBackground(bgStarWarp);
  }

  void Game::setupMainMenuScene() {
    startMenuScene->setSceneRect(0, 0, view->width(), view->height());
    // Create backgrounds and add it to this scene
    auto *bgUniverse = new Background(1, 100, {":/resources/bg/nebulaRed.png"});
    auto *bgStars1 = new Background(1, 80, {":/resources/bg/starsSmall1.png"});
    auto *bgStars2 = new Background(1, 60, {":/resources/bg/starsSmall2.png"});

    startMenuScene->addBackground(bgUniverse);
    startMenuScene->addBackground(bgStars1);
    startMenuScene->addBackground(bgStars2);

    startMenuScene->setTitleImg(":/resources/ui/spaceInvasion.png");

    // Create the quit button
    auto *startBtn = new MenuButton(
      QPixmap(":/resources/ui/startGame.png"),
      QPixmap(":/resources/ui/startGame_active.png"));
    startMenuScene->addButton(startBtn);
    connect(startBtn, &MenuButton::clicked, this, &Game::showGameScene);

    // Create the quit button
    auto *quitBtn = new MenuButton(
      QPixmap(":/resources/ui/quitGame.png"),
      QPixmap(":/resources/ui/quitGame_active.png"));
    startMenuScene->addButton(quitBtn);
    connect(quitBtn, &MenuButton::clicked, this,
            []() { QApplication::quit(); });

    startMenuScene->buildScene();
  }

  void Game::setupPauseMenuScene() {
    pauseMenuScene->setSceneRect(0, 0, view->width(), view->height());
    // Create backgrounds and add it to this scene
    auto *bgUniverse = new Background(1, 100, {":/resources/bg/nebulaBlue.png"});
    auto *bgStars1 = new Background(1, 80, {":/resources/bg/starsSmall1.png"});
    auto *bgStars2 = new Background(1, 60, {":/resources/bg/starsSmall2.png"});

    pauseMenuScene->addBackground(bgUniverse);
    pauseMenuScene->addBackground(bgStars1);
    pauseMenuScene->addBackground(bgStars2);

    //TODO: add a pause menu image
    pauseMenuScene->setTitleImg(":/resources/ui/spaceInvasion.png");

    // Create resume button
    auto *resumeBtn = new MenuButton(
      QPixmap(":/resources/ui/resumeGame.png"),
      QPixmap(":/resources/ui/resumeGame_active.png"));
    pauseMenuScene->addButton(resumeBtn);
    connect(resumeBtn, &MenuButton::clicked, this, &Game::showGameScene);

    // Create the quit button
    auto *quitBtn = new MenuButton(
      QPixmap(":/resources/ui/quitGame.png"),
      QPixmap(":/resources/ui/quitGame_active.png"));
    pauseMenuScene->addButton(quitBtn);
    connect(quitBtn, &MenuButton::clicked, this,
            []() { QApplication::quit(); });

    pauseMenuScene->buildScene();
  }

  void Game::setupGameOverMenuScene() {
    gameOverMenuScene->setSceneRect(0, 0, view->width(), view->height());
    // Create backgrounds and add it to this scene
    auto *bgUniverse = new Background(1, 100, {":/resources/bg/nebulaRed.png"});
    auto *bgStars1 = new Background(1, 80, {":/resources/bg/starsSmall1.png"});
    auto *bgStars2 = new Background(1, 60, {":/resources/bg/starsSmall2.png"});

    gameOverMenuScene->addBackground(bgUniverse);
    gameOverMenuScene->addBackground(bgStars1);
    gameOverMenuScene->addBackground(bgStars2);

    //TODO: add a gameOver menu image
    gameOverMenuScene->setTitleImg(":/resources/ui/spaceInvasion.png");

    // Create resume button
    auto *retryBtn = new MenuButton(
      QPixmap(":/resources/ui/retryGame.png"),
      QPixmap(":/resources/ui/retryGame_active.png"));
    gameOverMenuScene->addButton(retryBtn);
    connect(retryBtn, &MenuButton::clicked, this, &Game::retryGame);

    // Create the quit button
    auto *quitBtn = new MenuButton(
      QPixmap(":/resources/ui/quitGame.png"),
      QPixmap(":/resources/ui/quitGame_active.png"));
    gameOverMenuScene->addButton(quitBtn);
    connect(quitBtn, &MenuButton::clicked, this,
            []() { QApplication::quit(); });

    gameOverMenuScene->buildScene();
  }

  void Game::setupGameScene() {
    gameScene = new GameScene(this);
    gameScene->setSceneRect(0, 0, view->width(), view->height());
    setupGameBackground();

    // Create a gameSceneTimer for the game loop
    gameSceneTimer = new QTimer();
    connect(gameSceneTimer, SIGNAL(timeout()), gameScene, SLOT(advance()));
    connect(gameSceneTimer, SIGNAL(timeout()), gameScene, SLOT(update()));

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

    gameScene->buildScene();
  }

  void Game::showStartMenuScene() {
    m_state = settings::GameState::MAIN_MENU;
    m_bgMusic->setMusicPath("qrc:/resources/music/menuMusic01.mp3");
    view->setScene(startMenuScene);
    startMenuScene->activate();
    m_bgMusic->play();
    gameSceneTimer->stop();
  }

  void Game::showGameScene() {
    m_state = settings::GameState::RUNNING;
    pauseMenuScene->deactivate();
    gameOverMenuScene->deactivate();
    m_bgMusic->setMusicPath("qrc:/resources/music/playTime01.mp3");
    view->setScene(gameScene);
    gameScene->activate();
    gameSceneTimer->start(1000 / 60);
  }

  void Game::showPauseScene() {
    m_state = settings::GameState::PAUSED;
    gameScene->deactivate();
    gameOverMenuScene->deactivate();
    m_bgMusic->setMusicPath("qrc:/resources/music/menuMusic01.mp3");
    view->setScene(pauseMenuScene);
    pauseMenuScene->activate();
    gameSceneTimer->stop();
  }

  void Game::showGameOverScene() {
    m_state = settings::GameState::GAME_OVER;
    gameScene->deactivate();
    pauseMenuScene->deactivate();
    m_bgMusic->setMusicPath("qrc:/resources/music/gameOver01.mp3");
    view->setScene(gameOverMenuScene);
    gameSceneTimer->stop();
  }

  void Game::retryGame() {
    setupGameScene();
    showGameScene();
  }
} // namespace metodik_invaders2