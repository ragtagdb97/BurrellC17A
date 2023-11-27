/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Game.h
 * Author: Donald
 *
 * Created on November 26, 2023, 1:33 PM
 */

#ifndef GAME_H
#define GAME_H

#include "Board.h"
#include "State.h"

using namespace std; 

class Game : public State {
public:
    Game() : blkCt(2), whtCt(2) {}

    void play();

private:
    int blkCt;
    int whtCt;

    void updateCounts(int row, int col) {
        (getCurPlyr() == BLACK) ? blkCt++ : whtCt++;
    }

    void saveResults() const;

    void displayData() const;
};

#endif /* GAME_H */

