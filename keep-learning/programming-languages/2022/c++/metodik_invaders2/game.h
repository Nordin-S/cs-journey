#ifndef METODIK_INVADERS2_GAME_H
#define METODIK_INVADERS2_GAME_H

#include <QObject>
#include "player.h"
#include "enemy.h"
#include "backgroundmusic.h"

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
    Enemy *enemy;
    BackgroundMusic *bgMusic;
  };

} // namespace metodik_invaders2
#endif // METODIK_INVADERS2_GAME_H
