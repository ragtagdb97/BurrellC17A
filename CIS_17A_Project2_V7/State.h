/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   State.h
 * Author: Donald
 *
 * Created on November 26, 2023, 1:18 PM
 */

#ifndef STATE_H
#define STATE_H

#include "Board.h"
#include "Game.h"

class State : public Board {
public:
    State() : currentPlayer(Board::BLACK) {}

    bool isValidMove(int row, int col) const;

    void doMove(int row, int col);

    void switchPlayer();

    bool isBoardFull() const;
    
    void resetGame();

    Player getCurrentPlayer() const;

protected:
    Player currentPlayer;
};

#endif /* STATE_H */

