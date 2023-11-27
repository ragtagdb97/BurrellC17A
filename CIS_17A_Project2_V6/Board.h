/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Board.h
 * Author: Donald
 *
 * Created on November 26, 2023, 12:59 PM
 */

#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <vector>

using namespace std;

class Board {
public:
    
    //Player types OR tile type, in other words
    enum Player { EMPTY, BLACK, WHITE };
    static const int SIZE = 8;

    Board() {
        initBoard();
    }
    
    
    //Functions to build game board
    void initBoard();

    void printBoard() const;
    
    //Setters getters for player
    Player getPlayer(int row, int col) const {
        return board[row][col];
    }

    void setPlayer(int row, int col, Player player) {
        board[row][col] = player;
    }

private:
    vector<vector<Player>> board;
};

#endif /* BOARD_H */

