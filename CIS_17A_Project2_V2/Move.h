/* 
 * File:   Move.h
 * Author: Donald
 *
 * Created on November 24, 2023, 9:10 AM
 */

#ifndef MOVE_H
#define MOVE_H

#include "Board.h"

class Move : public Board {
public:
    Move(int r, int c) {
        oppPlyr = (curPlyr == 'B') ? 'W' : 'B';
        col = c;
        row = r;
    } 
    
    bool isValid();
    void doMove();
        
private:
    char oppPlyr;
    int row;
    int col;
};

#endif /* MOVE_H */

