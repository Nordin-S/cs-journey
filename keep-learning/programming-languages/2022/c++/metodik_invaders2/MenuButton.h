//
// Created by nordi on 2/7/2023.
//

#ifndef METODIK_INVADERS2_MENUBUTTON_H
#define METODIK_INVADERS2_MENUBUTTON_H

#include <QGraphicsSceneMouseEvent>
#include <QGraphicsSceneHoverEvent>
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsLayoutItem>

namespace metodik_invaders2 {

  class MenuButton
    : public QObject, public QGraphicsPixmapItem {
  Q_OBJECT
  public:
   MenuButton(const QPixmap &pixmap, const QPixmap &pixmapHover,
               QGraphicsItem *parent = nullptr)
      : QGraphicsPixmapItem(pixmap, parent) {
      this->pixmapHover = pixmapHover;
      this->pixmapLeave = pixmap;
      setShapeMode(QGraphicsPixmapItem::BoundingRectShape);
      setAcceptHoverEvents(true);
    }

    void hoverEnterEvent(QGraphicsSceneHoverEvent *event) override {
      Q_UNUSED(event);
      setPixmap(pixmapHover);
    }

    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event) override {
      Q_UNUSED(event);
      setPixmap(pixmapLeave);
    }

  signals:

    void clicked();

  protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override {
      emit clicked();
    }

  private:
    QPixmap pixmapHover;
    QPixmap pixmapLeave;
  };
} // metodik_invaders2

#endif //METODIK_INVADERS2_MENUBUTTON_H
