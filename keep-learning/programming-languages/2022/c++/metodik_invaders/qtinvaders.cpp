#include "qtinvaders.h"
#include "./ui_qtinvaders.h"

QtInvaders::QtInvaders(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::QtInvaders)
{
    ui->setupUi(this);
}

QtInvaders::~QtInvaders()
{
    delete ui;
}

