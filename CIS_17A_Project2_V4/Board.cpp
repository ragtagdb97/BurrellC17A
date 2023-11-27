#include "Board.h"
#include <iostream>

using namespace std; 

void Board::initBoard() {
    for (int i = 0; i < SIZE; i++) {
        vector<char> row(SIZE, EMPTY);
        board.push_back(row);
    }
    board[3][3] = WHITE; //Default starting position 1
    board[4][4] = WHITE; //Second white piece
    board[3][4] = BLACK; //First white piece starting position
    board[4][3] = BLACK; //Second black piece
}

void Board::printBoard() {
    char *col = new char[8]; 
    char *cols = new char[8];
    col[0] = 'A'; col[1] = 'B'; col[2] = 'C';
    col[3] = 'D'; col[4] = 'E'; col[5] = 'F';
    col[6] = 'G'; col[7] = 'H';
    strcpy(cols, col);  //Only to prove I can use char arrays and some library functions
    cout << "  ";
    for (int i = 0; i < SIZE; i++) {
        cout << cols[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < SIZE; i++) {
        cout << i+1 << " "; //Increases row name by one to start at 1
        for (int j = 0; j < SIZE; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    delete[] col;
    delete[] cols; //Deallocate memory
}