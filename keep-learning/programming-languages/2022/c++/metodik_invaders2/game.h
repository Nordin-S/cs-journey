#ifndef METODIK_INVADERS2_GAME_H
#define METODIK_INVADERS2_GAME_H

#include <QObject>
#include "spacecraft.h"
#include "enemy.h"
#include "backgroundmusic.h"
#include "SpawnHandler.h"
#include "player.h"
#include "InputHandler.h"
#include "MenuScene.h"
#include "GameScene.h"

namespace metodik_invaders2 {

  class Game : public QObject {
  Q_OBJECT

  public:
    Game();

    void setState(settings::GameState state);

    settings::GameState getState() const;

    ~Game();

//    bool eventFilter(QObject *obj, QEvent *event) override;

//    QSet<int> pressedKeys;

  public slots:
    void showGameScene();
    void showPauseScene();
    void retryGame();
    void showGameOverScene();
    void showStartMenuScene();

  private:
    settings::GameState m_state;
    QTimer *gameSceneTimer;
    int m_score;
    int m_lives;
    int m_health;
    int m_waveCount;
    QGraphicsView *view;
    InputHandler *m_inputHandler;
    MenuScene *startMenuScene;
    MenuScene *pauseMenuScene;
    MenuScene *gameOverMenuScene;
    GameScene *gameScene;
    BackgroundMusic *m_bgMusic;
    Player *player;
    SpawnHandler *spawnHandler;

    void setupView();
    void setupMainMenuScene();
    void setupPauseMenuScene();
    void setupGameOverMenuScene();
    void setupGameScene();
    void setupGameBackground();
  };
} // namespace metodik_invaders2
#endif // METODIK_INVADERS2_GAME_H
