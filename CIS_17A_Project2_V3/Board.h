
/* 
 * File:   Board.h
 * Author: Donald
 *
 * Created on November 24, 2023, 8:57 AM
 */

#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <string>
#include <cstring>

using namespace std;

enum Player {blk='B', wht='W'};

class Board {
public:
    Board() : SIZE(8), EMPTY('.'), BLACK(blk), WHITE(wht), curPlyr(blk) {}
    //Board functions:
    void initBoard();       //Initialize starting positions on board
    void printBoard();      //Print the board and col/row letters/numbers
    
protected:
    vector<vector<char>> board; 
    const int SIZE;
    const char EMPTY;
    Player BLACK;
    Player WHITE;
    
    char curPlyr;
};

#endif /* BOARD_H */

