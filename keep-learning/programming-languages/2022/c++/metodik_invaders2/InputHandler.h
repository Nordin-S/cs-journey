//
// Created by nordi on 2/6/2023.
//

#ifndef METODIK_INVADERS2_INPUTHANDLER_H
#define METODIK_INVADERS2_INPUTHANDLER_H

#include <QObject>
#include <QKeyEvent>

namespace metodik_invaders2 {

  class InputHandler : public QObject {
  Q_OBJECT
  public:
    explicit InputHandler(QObject *parent = nullptr);
    ~InputHandler() = default;

    // event filter
    bool eventFilter(QObject *obj, QEvent *event) override;

    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);

    signals:
    void moveLeftDown();
    void moveLeftUp();
    void moveRightDown();
    void moveRightUp();
    void moveUpDown();
    void moveUpUp();
    void moveDownDown();
    void moveDownUp();
    void shootDown();
    void shootUp();

    void pausePressed();
  };

} // metodik_invaders2

#endif //METODIK_INVADERS2_INPUTHANDLER_H
