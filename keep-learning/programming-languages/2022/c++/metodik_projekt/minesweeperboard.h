//
// Created by nordi on 1/6/2023.
//

#ifndef METODIK_PROJEKT_MINESWEEPERBOARD_H
#define METODIK_PROJEKT_MINESWEEPERBOARD_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class MinesweeperBoard; }
QT_END_NAMESPACE

class MinesweeperBoard : public QWidget {
Q_OBJECT
    // Square size (in pixels)
    int squareSize;
    // Number of rows and columns in the game board
    int numRows;
    int numCols;

public:
    explicit MinesweeperBoard(QWidget *parent = nullptr);

    // Function to generate the initial game board
    void generateGameBoard(int difficulty, int numRows, int numCols);

    ~MinesweeperBoard() override;

    enum class SquareState {
        Hidden, // Square has not been revealed yet
        Marked, // Square has been marked as containing a mine
        Revealed // Square has been revealed
    };

    enum class SquareContent {
        Empty, // Square does not contain a mine
        Mine // Square contains a mine
    };

    // 2D array or vector to store game board data
    std::vector<std::vector<SquareState>> state;
    std::vector<std::vector<SquareContent>> content;

    // Function to handle mouse events and update the game board
    void handleMouseEvent(int row, int col, Qt::MouseButton button);

signals:

    // Signal to indicate that the game has been won or lost
    void gameOver(bool won);

protected:
    void paintEvent(QPaintEvent *event) override;

    void mousePressEvent(QMouseEvent *event) override;

private:
    Ui::MinesweeperBoard *ui;

};


#endif //METODIK_PROJEKT_MINESWEEPERBOARD_H
