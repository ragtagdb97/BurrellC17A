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
#include "State.h"

#include <iostream>
#include <vector>

using namespace std;


class Game : public State {
public:
    Game() : currentPlayer(Board::BLACK), blackCount(2), whiteCount(2) {}

    void play();

private:
    int blackCount;
    int whiteCount;

    void updateCounts(int row, int col) {
        (getCurrentPlayer() == BLACK) ? blackCount++ : whiteCount++;
    }

    void saveResults() const;

    void displayData() const;
};

#endif /* GAME_H */

