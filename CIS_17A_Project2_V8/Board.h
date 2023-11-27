/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Board.h
 * Author: Donald
 *
 * Created on November 26, 2023, 1:33 PM
 */

#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <iostream>

using namespace std;

class Board {
public:
    enum Player { EMPTY, BLACK, WHITE };
    static const int SIZE = 8;

    Board() {
        initBoard();
    }
    
    // Overloaded == operator for the Board class
    friend bool operator==(const Board& lhs, const Board& rhs);
    
    void initBoard();

    void printBoard() const;

    Player getPlayer(int row, int col) const {
        return board[row][col];
    }

    void setPlayer(int row, int col, Player player) {
        board[row][col] = player;
    }

protected:
    vector<vector<Player>> board;
};

#endif /* BOARD_H */

