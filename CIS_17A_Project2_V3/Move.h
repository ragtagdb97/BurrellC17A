/* 
 * File:   Move.h
 * Author: Donald
 *
 * Created on November 24, 2023, 9:10 AM
 */

#ifndef MOVE_H
#define MOVE_H

#include "Board.h"
#include <vector>

class Move : public Board {
public:
    Move(int r, int c, string m) {
        oppPlyr = (curPlyr == 'B') ? 'W' : 'B';
        col = c;
        row = r;
        mov = m;
    } 
    
    bool isValid();
    void doMove();
        
private:
    string mov;
    char oppPlyr;
    int row;
    int col;
};

#endif /* MOVE_H */

