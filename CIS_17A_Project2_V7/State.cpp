/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include "State.h"
#include "Board.h"
#include "Game.h"

#include <iostream>

using namespace std;

bool State::isValidMove(int row, int col) const {
// Check if the coordinates are within the board boundaries
if (row < 0 || row >= SIZE || col < 0 || col >= SIZE || getPlayer(row, col) != EMPTY) {
    return false;
}

// Check if the move flips at least one opponent's piece in any direction
for (int i = -1; i <= 1; ++i) {
    for (int j = -1; j <= 1; ++j) {
        // Skip the current position (i=0, j=0)
        if (i == 0 && j == 0) {
            continue;
        }

        // Check in the current direction (i, j)
        int currentRow = row + i;
        int currentCol = col + j;
        bool foundOpponent = false;

        while (currentRow >= 0 && currentRow < SIZE && currentCol >= 0 && currentCol < SIZE) {
            if (getPlayer(currentRow, currentCol) == EMPTY) {
                break;
            }
            if (getPlayer(currentRow, currentCol) == currentPlayer) {
                foundOpponent = true;
                break;
            }
            // Move to the next cell in the current direction
            currentRow += i;
            currentCol += j;
        }

        if (foundOpponent) {
            return true;
        }
    }
}

void State::doMove(int row, int col) {
    setPlayer(row, col, currentPlayer);
    switchPlayer();
}

void State::switchPlayer() {
    currentPlayer = (currentPlayer == BLACK) ? WHITE : BLACK;
}

bool State::isBoardFull() const {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (getPlayer(i, j) == EMPTY) {
                return false;
            }
        }
    }
    return true;
}

void State::resetGame() {
    initBoard();
    currentPlayer = BLACK;
}

Player State::getCurrentPlayer() const {
    return currentPlayer;
}