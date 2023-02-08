#ifndef METODIK_INVADERS2_GAME_H
#define METODIK_INVADERS2_GAME_H

#include <QObject>
#include "spacecraft.h"
#include "enemy.h"
#include "backgroundmusic.h"
#include "SpawnHandler.h"
#include "player.h"
#include "InputHandler.h"
#include "GameMenu.h"

namespace metodik_invaders2 {

  enum GameState {
    MAINMENU,
    RUNNING,
    PAUSED,
    GAMEOVER
  };
  class Game : public QObject {
  Q_OBJECT

  public:
    Game();

    void setState(GameState state);

    GameState getState() const;

    ~Game();

//    bool eventFilter(QObject *obj, QEvent *event) override;

//    QSet<int> pressedKeys;

  public slots:
    void startGame();
    void togglePauseGame();
    void resumeGame();
    void gameOver();

  private:
    GameState m_state;
    int m_score;
    int m_lives;
    int m_health;
    int m_waveCount;
    QGraphicsView *view;
    InputHandler *m_inputHandler;
    GameMenu *startMenuScene;
    GameMenu *pauseMenuScene;
    GameMenu *gameOverMenuScene;
    GameMenu *gameScene;
    Player *player;
    SpawnHandler *spawnHandler;
    BackgroundMusic *bgMusic;

    void setupView();
    void setupMainMenuScene();
    void setupPauseMenuScene();
    void setupGameOverMenuScene();
    void setupGameScene();
    void setupGameBackground();
  };

} // namespace metodik_invaders2
#endif // METODIK_INVADERS2_GAME_H
