//
// Created by nordi on 1/31/2023.
//

#include <QObject>
#include <QGraphicsScene>
#include "SpawnHandler.h"
#include "enemy.h"

namespace metodik_invaders2 {
  SpawnHandler::SpawnHandler(const int &playerScore, QGraphicsScene *scene,
                             QObject *parent)
    : m_playerScore(playerScore),
      m_scene(scene),
      QObject(parent),
      m_formationSpawnThreshold(100),
      m_miniBossSpawnThreshold(500),
      m_bossSpawnThreshold(1000) {
    m_formationSpawnTimer = new QTimer(this);
    m_miniBossSpawnTimer = new QTimer(this);
    m_bossSpawnTimer = new QTimer(this);
    m_formationSpawnTimer->setInterval(10000);
    m_miniBossSpawnTimer->setInterval(1000);
    m_bossSpawnTimer->setInterval(1000);
    connect(m_formationSpawnTimer, &QTimer::timeout, [this]() {
      if (m_playerScore >= m_formationSpawnThreshold) {
        emit spawnFormationSignal();
        m_formationSpawnThreshold += 100;
      }
    });
    connect(m_miniBossSpawnTimer, &QTimer::timeout, [this]() {
      if (m_playerScore >= m_miniBossSpawnThreshold) {
        emit spawnMiniBossSignal();
        m_miniBossSpawnThreshold += 500;
      }
    });
    connect(m_bossSpawnTimer, &QTimer::timeout, [this]() {
      if (m_playerScore >= m_bossSpawnThreshold) {
        emit spawnBossSignal();
        m_bossSpawnThreshold += 1000;
      }
    });
    connect(this, &SpawnHandler::spawnRandomEnemySignal, this,
            &SpawnHandler::spawnRandomEnemyHandler);
    connect(this, &SpawnHandler::spawnFormationSignal, this,
            &SpawnHandler::spawnFormationHandler);
    connect(this, &SpawnHandler::spawnMiniBossSignal, this,
            &SpawnHandler::spawnMiniBossHandler);
    connect(this, &SpawnHandler::spawnBossSignal, this,
            &SpawnHandler::spawnBossHandler);
    connect(this, &SpawnHandler::setPlayerScoreSignal, this,
            &SpawnHandler::setPlayerScore);

    m_formationSpawnTimer->start();
    m_miniBossSpawnTimer->start();
    m_bossSpawnTimer->start();
  }

  SpawnHandler::~SpawnHandler() {
    delete m_formationSpawnTimer;
    delete m_miniBossSpawnTimer;
    delete m_bossSpawnTimer;
  }

  void SpawnHandler::setPlayerScore(const int &playerScore) {
    m_playerScore = playerScore;
  }

  void
  SpawnHandler::setFormationSpawnThreshold(const int &formationSpawnThreshold) {
    m_formationSpawnThreshold = formationSpawnThreshold;
  }

  void
  SpawnHandler::setMiniBossSpawnThreshold(const int &miniBossSpawnThreshold) {
    m_miniBossSpawnThreshold = miniBossSpawnThreshold;
  }

  void SpawnHandler::setBossSpawnThreshold(const int &bossSpawnThreshold) {
    m_bossSpawnThreshold = bossSpawnThreshold;
  }

  void SpawnHandler::spawnFormationHandler() {

    // Choose a random formation from the formation list
    int formationIndex = rand() % settings::formations.size();
    QList<QList<bool>> currentFormation = settings::formations[formationIndex];

    // Calculate the starting position of the formation
    int formationHeight = currentFormation.size();
    int formationWidth = currentFormation[0].size();
    int edgeOffset = 10;
    int rightBound = m_scene->width() - edgeOffset;
    int leftBound = edgeOffset;
    int shipSize = m_scene->width() / formationWidth - (2 * edgeOffset);
    int startX = shipSize / 2 + leftBound;

//    qDebug() << "scene height: " << m_scene->height();
//    qDebug() << "scene width: " << m_scene->width();
//    qDebug() << "scene rect: " << m_scene->sceneRect();
    int sceneHeightSpawnArea = m_scene->height() * 0.6f;

    int startY = (sceneHeightSpawnArea / formationHeight + shipSize / 2) -
                 m_scene->height();
    // TODO replace this with obove
//    int startY = (sceneHeightSpawnArea / formationHeight + shipSize / 2);

    // Spawn the ships in the formation
    for (int i = 0; i < formationHeight; ++i) {
      for (int j = 0; j < formationWidth; ++j) {
        if (currentFormation[i][j]) {
//          SpaceCraft *enemy = new SpaceCraft(QPointF(startX + j * shipSize, startY + i * shipSize), SpaceCraft::EnemyFighter);

          Enemy *enemy = new Enemy(settings::ShipSpeeds::FighterSpeed,
                                   settings::Healths::FighterHealth,
                                   settings::UpdateMs::UMs100,
                                   settings::MoveSteps::Move01,
                                   settings::AmmoType::TypeMissile,
                                   settings::AmmoDmgLvl::Dmg10,
                                   settings::ShipTypes::Viper,
                                   settings::EnemyShipType::Fighter,
                                   m_scene,
                                   parent());
          m_scene->addItem(enemy);
//          enemy->setZValue(std::numeric_limits<qreal>::max());

          enemy->setPosition(startX + j * shipSize, startY + i * shipSize);
//          enemyList.append(enemy);
        }
      }
    }
  }

  void SpawnHandler::spawnMiniBossHandler() {

  }

  void SpawnHandler::spawnBossHandler() {

  }

  void SpawnHandler::spawnRandomEnemyHandler() {

  }
} // metodik_invaders2