//
// Created by nordi on 2/1/2023.
//

#ifndef METODIK_INVADERS2_BACKGROUNDPIXMAPITEM_H
#define METODIK_INVADERS2_BACKGROUNDPIXMAPITEM_H

#include <QGraphicsPixmapItem>
#include <QObject>

namespace metodik_invaders2 {

  class BackgroundPixmapItem : public QObject, public QGraphicsPixmapItem {
  Q_OBJECT
  public:
    BackgroundPixmapItem() = default;

    ~BackgroundPixmapItem() override = default;
  protected:
    // override shape to prevent collision detection
    QPainterPath shape() const override {
      return *new QPainterPath();
    }
  };

} // metodik_invaders2

#endif //METODIK_INVADERS2_BACKGROUNDPIXMAPITEM_H
