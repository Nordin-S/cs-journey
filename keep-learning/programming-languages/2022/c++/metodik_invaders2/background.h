#ifndef METODIK_INVADERS2_BACKGROUND_H
#define METODIK_INVADERS2_BACKGROUND_H

#include <QGraphicsRectItem>
#include "BackgroundPixmapItem.h"

namespace metodik_invaders2 {
  class Background : public QObject, public QGraphicsPixmapItem {
  Q_OBJECT
  public:
    Background(int speed, int updateSpeed, QList<QString> imgPaths,
               QObject *parent = nullptr);

    void startTimer();
    void stopTimer();
    QList<BackgroundPixmapItem *> getInstances() const;
    virtual ~Background() override = default;


  public slots:

    void move();

  private:
    QTimer *m_backgroundTimer;
    int m_speed;
    int m_updateSpeed;
    QPixmap m_image;
    QList<QString> m_images;
    QList<BackgroundPixmapItem *> m_instances;

  };
} // namespace metodik_invaders2
#endif //METODIK_INVADERS2_BACKGROUND_H
