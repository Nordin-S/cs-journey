#ifndef QTINVADERS_H
#define QTINVADERS_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class QtInvaders; }
QT_END_NAMESPACE

class QtInvaders : public QMainWindow
{
    Q_OBJECT

public:
    QtInvaders(QWidget *parent = nullptr);
    ~QtInvaders();

private:
    Ui::QtInvaders *ui;
};
#endif // QTINVADERS_H
