/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Game.h
 * Author: Donald
 *
 * Created on November 26, 2023, 12:59 PM
 */

#ifndef GAME_H
#define GAME_H

#include "Board.h"

#include <iostream>
#include <vector>

using namespace std;

class Game {
public:
    Game() : currentPlayer(Board::BLACK), blackCount(2), whiteCount(2) {}

    void play();

private:
    Board board;
    Board::Player currentPlayer;
    int blackCount;
    int whiteCount;

    bool isValidMove(int row, int col) const;

    void doMove(int row, int col);

    void switchPlayer();

    void updateCounts(int row, int col);

    bool isBoardFull() const;

    void resetGame();

    void saveResults() const;

    void displayData() const;
};

#endif /* GAME_H */

