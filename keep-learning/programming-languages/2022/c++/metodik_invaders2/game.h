#ifndef METODIK_INVADERS2_GAME_H
#define METODIK_INVADERS2_GAME_H

#include <QObject>
#include <QVBoxLayout>
#include "spacecraft.h"
#include "enemy.h"
#include "backgroundmusic.h"
#include "SpawnHandler.h"
#include "player.h"

//class QGraphicsView;
//class QGraphicsScene;

namespace metodik_invaders2 {
  class Game : public QObject {
  Q_OBJECT

  public:
    Game();

    ~Game();

    bool eventFilter(QObject *obj, QEvent *event) override;

    QSet<int> pressedKeys;
  private:
    QGraphicsView *view;
    QGraphicsScene *scene;
    Player *player;
    int m_score;
    int m_lives;
    int m_health;
    int m_waveCount;
    Enemy *enemy;
    SpawnHandler *spawnHandler;
    BackgroundMusic *bgMusic;

    QWidget *widget;
  };

} // namespace metodik_invaders2
#endif // METODIK_INVADERS2_GAME_H
