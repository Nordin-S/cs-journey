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
  signals:
    void spawnRandomEnemySignal();
    void spawnFormationSignal();
    void spawnMiniBossSignal();
    void spawnBossSignal();
    void setPlayerScoreSignal(const int &playerScore);

  public slots:
    void setPlayerScore(const int &playerScore);
    void spawnRandomEnemyHandler();
    void spawnFormationHandler();
    void spawnMiniBossHandler();
    void spawnBossHandler();

  private:
    int m_playerScore;
    QList<Enemy*> m_enemies;
    int m_formationSpawnThreshold;
    int m_miniBossSpawnThreshold;
    int m_bossSpawnThreshold;

    QTimer *m_formationSpawnTimer;
    QTimer *m_miniBossSpawnTimer;
    QTimer *m_bossSpawnTimer;
    QGraphicsScene *m_scene;
  };
} // metodik_invaders2

#endif //METODIK_INVADERS2_SPAWNHANDLER_H
