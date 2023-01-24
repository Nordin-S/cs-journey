//
// Created by nordi on 1/7/2023.
//

#ifndef SUDOKU_SUDOKUGAME_H
#define SUDOKU_SUDOKUGAME_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class SudokuGame; }
QT_END_NAMESPACE

class SudokuGame : public QWidget {
    Q_OBJECT

public:
    explicit SudokuGame(QWidget *parent = nullptr);

    ~SudokuGame() override;

private:
    Ui::SudokuGame *ui;
};


#endif //SUDOKU_SUDOKUGAME_H
