
/* 
 * File:   Game.h
 * Author: Donald
 *
 * Created on November 26, 2023, 10:06 AM
 */

#ifndef GAME_H
#define GAME_H

#include <vector>
#include "Board.h"
#include "Move.h"

class Game : public Board {
public:
    Game() : whtCt(2), blkCt(2), curPlyr(blk) {}
    
    void play();     //Gameplay function
    
private:
    int blkCt;
    int whtCt;
    
    Move move;
};

#endif /* GAME_H */

