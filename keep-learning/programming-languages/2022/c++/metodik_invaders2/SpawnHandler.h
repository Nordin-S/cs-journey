//
// Created by nordi on 1/31/2023.
//

#ifndef METODIK_INVADERS2_SPAWNHANDLER_H
#define METODIK_INVADERS2_SPAWNHANDLER_H

#include <QObject>
#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include "enemy.h"

namespace metodik_invaders2 {

  class SpawnHandler : public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
    Q_PROPERTY(QPointF pos READ pos WRITE setPos)
  public:
    explicit SpawnHandler(const int &playerScore = 0, QGraphicsScene* scene = nullptr, QObject* parent = nullptr);
    ~SpawnHandler() override;

    void setFormationSpawnThreshold(const int &formationSpawnThreshold);

    void setMiniBossSpawnThreshold(const int &miniBossSpawnThreshold);

    void setBossSpawnThreshold(const int &bossSpawnThreshold);

    // get random enemy ship type given ship class
    settings::ShipTypes getRandomEnemyShipType(settings::ShipClass shipClass);
  signals:
    void spawnRandomEnemySignal();
    void spawnFormationSignal();
    void spawnMiniBossSignal();
    void spawnBossSignal();
    void setPlayerScoreSignal(const int &playerScore);
    void togglePauseSignal();
    void enemyDiedSignal(settings::ShipClass enemyShipClass);


  public slots:
    void setPlayerScore(const int &playerScore);
    void spawnRandomHandler();
    void spawnFormationHandler();
    void spawnMiniBossHandler();
    void spawnBossHandler();
    void enemyDiedHandler(settings::ShipClass enemyShipClass);

  private:
    int m_playerScore;
    QList<Enemy*> m_enemies;
    int m_formationSpawnThreshold;
    int m_miniBossSpawnThreshold;
    int m_bossSpawnThreshold;
    bool m_waitSpecialSpawn = false;

    QTimer *m_randomSpawnTimer;
    QTimer *m_formationSpawnTimer;
    QTimer *m_miniBossSpawnTimer;
    QTimer *m_bossSpawnTimer;
    QGraphicsScene *m_scene;

    int randomPosX() const;
  };
} // metodik_invaders2

#endif //METODIK_INVADERS2_SPAWNHANDLER_H
