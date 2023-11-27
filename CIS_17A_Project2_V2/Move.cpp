#include <iostream>
#include "Move.h"

using namespace std;

void Move::isValid() {
    if (row < 0 || row >= board.size() || col < 0 || col >= board[row].size() || board[row][col] != '.') {
        return false; //NOT valid if tile is outside of board bounds or occupied already by a player
    }
    
    char oppPlyr = (curPlyr == 'B') ? 'W' : 'B'; //Opponent is white if current is Black, and black if curr. is white
    bool valid = false; //Moves are usually not legal, so default false
    
    /*      Change in row:
     * -1 (up left), -1 (up right), -1 (up), 0 (right)
     * 1 (down right), 1 (down left), 1 (down), 0 (left)
    */
    int dr[] = {-1, -1, -1, 0, 1, 1, 1, 0};
    /*      Change in col:
     *  -1 (up left), 0 (up), 1 (up right), 1 (right)
     *  1 (down right), 0 (down), -1 (down left), -1 (left)
    */
    int dc[] = {-1, 0, 1, 1, 1, 0, -1, -1};
    
    for (int dir = 0; dir < 8; dir++) {
        //dir iterates over all possible moves (8 directions)
        int r = row + dr[dir];  //New row coordinate
        int c = col + dc[dir];  //New col coordinate
        
        bool found = false; //Found opponent piece and captured
        while (r >= 0 && r < board.size() && c >= 0 && c < board[r].size()) {
            if (board[r][c] == oppPlyr) {
                found = true; //Capture pieces if crossed by current player during move
            } else if (board[r][c] == curPlyr) {
                if (found) {
                    valid = true;  //If opponent is found (and player adjacent), it is valid
                }
                break;
            } else {
                break;
            }
            //These would be the potential new row and col coords
            r += dr[dir];
            c += dc[dir];
        }
    }
    
    return valid; //Determined if true/false above
}