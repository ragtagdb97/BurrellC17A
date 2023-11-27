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
    //Column names
    char colNm[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    cout << "  ";
    for (int i = 0; i < SIZE; i++) {
        //Output the appropriate column name
        cout << colNm[i] << " ";
    }
    
    cout << endl;
    
    for (int i = 0; i < SIZE; i++) {
        //Now do the same for the rows (1-8)
        cout << i + 1 << " ";
        for (int j = 0; j < SIZE; j++) {
            //symbol is the marker for either empty, black, or white occupied spaces
            char symbol = (board[i][j] == BLACK) ? 'B' : ((board[i][j] == WHITE) ? 'W' : '.');
            //So output the symbol and a space to make it readable
            cout << symbol << " ";
        }
        cout << endl;
    }
}