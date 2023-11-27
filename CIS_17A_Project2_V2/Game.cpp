#include <iomanip>
#include <vector>

using namespace std;

#include "Game.h"
#inclide "Move.h"

void Game::play() {
    while (true) {
        printBoard();
        cout << "Player: " << curPlyr << ", enter your move (e.g. C4 / OR 'exit' to quit): ";
        string move;    //String for move, e.g. D4, A1, etc. 
        cin >> move;    //Takes player move as a keyboard input
        
        if (move == "exit") {
            break;                    //This could exit the loop and end the game
        } else if (move == "reset") { //This could reset the game board if needed
            board.clear(); //Destroy all elements in the vector
            initBoard(); //Initialize to defaults
            blkCt = 2;  //Reset player scores
            whtCt = 2; 
            curPlyr = BLACK;   //Reset turns
            continue;
        }
        
        //Row/Column to move to
        int row = move[1] - '1';
        int col = move[0] - 'A';
        
        //Validates the chosen cell as a legal move (or not)
        if (move.isValid()) {
            move.doMove();
            if(curPlyr == BLACK) {
                blkCt++;
            } else {
                whtCt++;
            }
            //If current player is black, then new current player is white, else black
            curPlyr = (curPlyr == BLACK) ? WHITE : BLACK; 
        } else {
            cout << "Invalid move." << endl; 
        }
        
        //Check if board is full (end game)
        int openCt = 0; //Open tiles
        for (int i = 0; i < SIZE; i++) {   //size is the size of the board, both rows and cols are 8
            for (int j = 0; j < SIZE; j++) {   //so 8x8
                if (board[i][j] == EMPTY) {
                    openCt++;   //Increments for every discovered open tile
                }
            }
        }
        
        if (openCt == 0) {
            break; //Board is full; no more possible moves
        }
    }
}