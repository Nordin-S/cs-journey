#ifndef METODIK_INVADERS2_INVADERS_H
#define METODIK_INVADERS2_INVADERS_H

#include "backgroundmusic.h"

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Invaders; }
QT_END_NAMESPACE


namespace metodik_invaders2 {
  class Invaders : public QWidget {
  Q_OBJECT

  public:
    Invaders(QWidget *parent = nullptr);

    ~Invaders();

  private:
    Ui::Invaders *ui;
    BackgroundMusic *bgMusic;
  };
} // namespace metodik_invaders2
#endif // METODIK_INVADERS2_INVADERS_H
