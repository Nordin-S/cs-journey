//
// Created by nordi on 2/9/2023.
//

#ifndef METODIK_INVADERS2_GAMESCENE_H
#define METODIK_INVADERS2_GAMESCENE_H

#include <QObject>
#include "SceneMaker.h"

namespace metodik_invaders2 {

  class GameScene : public SceneMaker {
    Q_OBJECT
  public:
    explicit GameScene(QObject *parent = nullptr);

    void buildScene() override;

    void activate() override;

    void deactivate() override;

    ~GameScene() override;

  public slots:
    void updateScore(int score);
    void updateHealth(int health);
  private:
//    QGraphicsPixmapItem *m_livesBar{}; // TODO: implement lives later
    QGraphicsPixmapItem *m_healthBar;
    QGraphicsPixmapItem *m_scoreBar;
    QGraphicsTextItem *m_scoreText;
  };
} // metodik_invaders2

#endif //METODIK_INVADERS2_GAMESCENE_H
