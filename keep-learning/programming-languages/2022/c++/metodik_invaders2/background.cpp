#include "background.h"
#include "BackgroundPixmapItem.h"

#include <QTimer>
#include <QGraphicsScene>

namespace metodik_invaders2 {
  Background::Background(int speed, int updateSpeed, QList<QString> imgPaths,
                         QObject *parent)
    : QObject(parent), m_speed(speed), m_updateSpeed(updateSpeed),
      m_images(imgPaths) {
    const int NUM_IMAGES = 3; // TODO: two should be enough!?

    if (m_images.size() > 1){
      m_image.load(m_images[rand() % m_images.size()]);
    } else {
      m_image.load(imgPaths[0]);
    }

    for (int i = 0; i < NUM_IMAGES; i++) {
      auto *instance = new BackgroundPixmapItem();
      instance->setPixmap(m_image);
      instance->setPos(0, -(i * m_image.height()));
      m_instances.append(instance);
      // Turn off collision detection for the pixmap item
      instance->setData(0, false);
    }

//    setData(0, false); // TODO: do we need this?

    m_backgroundTimer = new QTimer();
    connect(m_backgroundTimer, SIGNAL(timeout()), this, SLOT(move()));
//    m_backgroundTimer->start(m_updateSpeed);
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

  void Background::startTimer() {
    m_backgroundTimer->start(m_updateSpeed);
  }

  void Background::stopTimer() {
    m_backgroundTimer->stop();
  }

  QList<BackgroundPixmapItem *> Background::getInstances() const {
    return m_instances;
  }
}