//
// Created by nordi on 1/6/2023.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MinesweeperBoard.h" resolved

#include <QPainter>
#include <QMouseEvent>
#include "minesweeperboard.h"
#include "ui_MinesweeperBoard.h"


MinesweeperBoard::MinesweeperBoard(QWidget *parent) :
        QWidget(parent), ui(new Ui::MinesweeperBoard) {
    ui->setupUi(this);
    // Initialize the game board data
    state = std::vector<std::vector<SquareState>>(10, std::vector<SquareState>(10, SquareState::Hidden));
    content = std::vector<std::vector<SquareContent>>(10, std::vector<SquareContent>(10, SquareContent::Empty));

    // Generate the game board, placing a certain number of mines randomly on the board
    generateGameBoard(1, 10, 10);
}

void MinesweeperBoard::generateGameBoard(int difficulty, int numRows, int numCols) {
    // Clear the current game board data
    state.clear();
    content.clear();

    // Initialize the game board data with the specified size
    this->numRows = numRows;
    this->numCols = numCols;

    this->squareSize = std::min(width() / numCols, height() / numRows);;

    state = std::vector<std::vector<SquareState>>(numRows, std::vector<SquareState>(numCols, SquareState::Hidden));
    content = std::vector<std::vector<SquareContent>>(numRows,
                                                      std::vector<SquareContent>(numCols, SquareContent::Empty));

    // Determine the number of mines to place on the game board based on the difficulty level
    int numMines;
    if (difficulty == 1) {
        numMines = 10; // Beginner difficulty: 10 mines
    } else if (difficulty == 2) {
        numMines = 20; // Intermediate difficulty: 20 mines
    } else {
        numMines = 30; // Expert difficulty: 30 mines
    }

    // Place a certain number of mines randomly on the game board
    while (numMines > 0) {
        int row = rand() % numRows; // Generate a random row index
        int col = rand() % numCols; // Generate a random column index
        if (content[row][col] != SquareContent::Mine) { // Make sure the square does not already contain a mine
            content[row][col] = SquareContent::Mine;
            numMines--;
        }
    }
}

void MinesweeperBoard::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    // Draw the game board
    for (int row = 0; row < numRows; row++) {
        for (int col = 0; col < numCols; col++) {
            // Determine the square's position and content based on its row and column indices
            int x = col * squareSize;
            int y = row * squareSize;
            SquareContent squareContent = content[row][col];

            // Draw the square based on its content
            if (squareSize)
                // Draw the square based on its content
                if (squareContent == SquareContent::Mine) {
                    painter.drawPixmap(x, y, squareSize, squareSize, QPixmap(":/images/mine.gif"));
                } else {
                    painter.drawRect(x, y, squareSize, squareSize);
                }
        }
    }
}

void MinesweeperBoard::mousePressEvent(QMouseEvent *event) {
    // Convert the mouse event coordinates to row and column indices on the game board
    int row = event->y() / squareSize;
    int col = event->x() / squareSize;

    // Pass the event to the handleMouseEvent() function to update the game board
    handleMouseEvent(row, col, event->button());
}

void MinesweeperBoard::handleMouseEvent(int row, int col, Qt::MouseButton button) {
    if (button == Qt::LeftButton) {
        // Left click: reveal the square
        if (state[row][col] == SquareState::Hidden) {
            state[row][col] = SquareState::Revealed;
            if (content[row][col] == SquareContent::Mine) {
                // Game over, player lost
                emit gameOver(false);
            } else {
                // Check for win condition
                // ...
            }
        }
    } else if (button == Qt::RightButton) {
        // Right click: mark/unmark the square as containing a mine
        if (state[row][col] == SquareState::Hidden) {
            state[row][col] = SquareState::Marked;
        } else if (state[row][col] == SquareState::Marked) {
            state[row][col] = SquareState::Hidden;
        }
    }
}

MinesweeperBoard::~MinesweeperBoard() {
    delete ui;
}
