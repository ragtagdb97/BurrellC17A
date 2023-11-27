/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include "State.h"
#include <vector>

using namespace std;

bool State::isValidMove(int row, int col) const {
    //Check boundaries
    //(Does the move fall within the board boundaries) and is the tile open
    if (row < 0 || row >= SIZE || col < 0 || col >= SIZE || getPlayer(row, col) != EMPTY) {
        return false;
    }

    //Does the move capture an opponent tile?:
    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            //Skip current position
            if (i == 0 && j == 0) {
                continue;
            }

            //Check in current direction
            int curRow = row + i;
            int curCol = col + j;
            bool found = false;

            while (curRow >= 0 && curRow < SIZE && curCol >= 0 && curCol < SIZE) {
                if (getPlayer(curRow, curCol) == EMPTY) {
                    break;
                }
                if (getPlayer(curRow, curCol) == curPlyr) {
                    found = true;
                    break;
                }
                //Next cell in the given direction
                curRow += i;
                curCol += j;
            }

            if (found) {
                return true;
            }
        }
    }

    //If no opponent is found, it is an invalid move
    return false;
}

void State::doMove(int row, int col) {
    setPlayer(row, col, curPlyr);
    //Calls the function below to simply swap player name 
    switchPlayer();
}

void State::switchPlayer() {
    //Change player turn based on current player
    curPlyr = (curPlyr == BLACK) ? WHITE : BLACK;
}

bool State::isBoardFull() const {
    //Checks if there are any open spaces for the game to continue
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (getPlayer(i, j) == EMPTY) {
                return false;
            }
        }
    }
    return true;
}