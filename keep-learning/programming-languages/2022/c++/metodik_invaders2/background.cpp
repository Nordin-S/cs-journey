#include "background.h"

#include <QBrush>
#include <QTimer>
#include <QGraphicsScene>

namespace metodik_invaders2 {
  Background::Background(int speed, int updateSpeed, QList<QString> imgPaths,
                         QGraphicsScene *theScene, QObject *parent)
    : QObject(parent), m_speed(speed), m_updateSpeed(updateSpeed),
      m_images(imgPaths), m_theScene(theScene) {

    if (m_images.size() > 1)
      m_image.load(m_images[rand() % m_images.size()]);
    else
      m_image.load(imgPaths[0]);
    for (int i = 0; i < 3; i++) {
      QGraphicsPixmapItem *instance = new QGraphicsPixmapItem();
      instance->setPixmap(m_image);
      instance->setPos(0, -(i * m_image.height()));
      m_instances.append(instance);
      theScene->addItem(instance);
    }
    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(m_updateSpeed);
  }

  void Background::move() {
    for (int i = 0; i < m_instances.size(); i++) {
      m_instances[i]->setPos(0, m_instances[i]->y() + m_speed);
      if (m_instances[i]->y() > m_image.height()) {
        if (m_images.size() > 1) {
          m_image.load(m_images[rand() % m_images.size()]);
          m_instances[i]->setPixmap(m_image);
        }
        m_instances[i]->setPos(m_instances[i]->x(), -m_image.height());
      }
    }
  }
}