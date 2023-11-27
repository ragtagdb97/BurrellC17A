/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include "Board.h"

#include <iostream>
#include <vector>


using namespace std;

void Board::initBoard() {
        for (int i = 0; i < SIZE; i++) {
            vector<Player> row(SIZE, EMPTY);
            board.push_back(row);
        }
        board[3][3] = WHITE;
        board[4][4] = WHITE;
        board[3][4] = BLACK;
        board[4][3] = BLACK;
    }

void Board::printBoard() const {
    char colLabels[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    cout << "  ";
    for (int i = 0; i < SIZE; i++) {
        cout << colLabels[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < SIZE; i++) {
        cout << i + 1 << " ";
        for (int j = 0; j < SIZE; j++) {
            char symbol = (board[i][j] == BLACK) ? 'B' : ((board[i][j] == WHITE) ? 'W' : '.');
            cout << symbol << " ";
        }
        cout << endl;
    }
}