//
// Created by nordi on 1/7/2023.
//

// You may need to build the project (run Qt uic code generator) to get "ui_SudokuGame.h" resolved

#include "sudokugame.h"
#include "ui_SudokuGame.h"


SudokuGame::SudokuGame(QWidget *parent) :
        QWidget(parent), ui(new Ui::SudokuGame) {
    ui->setupUi(this);
}

SudokuGame::~SudokuGame() {
    delete ui;
}
