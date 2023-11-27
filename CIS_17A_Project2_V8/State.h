/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   State.h
 * Author: Donald
 *
 * Created on November 26, 2023, 1:33 PM
 */

#ifndef STATE_H
#define STATE_H

#include "Board.h"

class State : public Board {
public:
    State() : curPlyr(Board::BLACK) {}

    bool isValidMove(int row, int col) const;

    void doMove(int row, int col);

    void switchPlayer();

    bool isBoardFull() const;
    
    void resetGame() {
        initBoard();
        curPlyr = BLACK;
    }

    Player getCurPlyr() const {
        return curPlyr;
    }

private:
    Player curPlyr;
};

#endif /* STATE_H */

