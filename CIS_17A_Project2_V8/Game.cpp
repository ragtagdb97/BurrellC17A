/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include "Game.h"
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

void Game::play() {
    while (true) {
        printBoard();
        cout << "Player: " << (getCurPlyr() == BLACK ? 'B' : 'W') << ", enter your move (e.g. C4 / OR 'exit' to quit): ";
        string move;
        cin >> move;

        if (move == "exit") {
            break;
        } else if (move == "reset") {
            resetGame();
            continue;
        }

        int row = move[1] - '1';
        int col = move[0] - 'A';

        if (isValidMove(row, col)) {
            doMove(row, col);
            updateCounts(row, col);
        } else {
            cout << "Invalid move." << endl;
        }

        if (isBoardFull()) {
            break;
        }
    }

    saveResults();
    displayData();
}

void Game::saveResults() const {
    ofstream saveFile("game_results.txt", ios::out | ios::app);
    if (saveFile.is_open()) {
        saveFile << "Black Count: " << blkCt << endl;
        saveFile << "White Count: " << whtCt << endl;
        saveFile << "----------------------" << endl;
        saveFile.close();
        cout << "Results added to 'game_results.txt'." << endl;
    } else {
        cout << "Error: Could not open the text file." << endl;
    }
}

void Game::displayData() const {
    ifstream binFile("data.dat", ios::binary);

    if (!binFile.is_open()) {
        cout << "Error opening the binary file." << endl;
        return;
    }
    
    
    //Hold the count for each variable taken from bin file (blkCt and whtCt)
    int bCt, wCt;   
    int totGame = 0, totBlk = 0, totWht = 0, totOcc = 0;

    while (binFile.read(reinterpret_cast<char*>(&bCt), sizeof(int)) && binFile.read(reinterpret_cast<char*>(&wCt), sizeof(int))) {
        //Increment the total games with each loop
        totGame++;
        //Add the appropriate quantity of either players pieces taken this loop
        totBlk += bCt;
        totWht += wCt;
        //The total spaces occupied is the sum of both players
        totOcc += bCt + wCt;
    }

    binFile.close();
    
    //Output the data gathered
    cout << "\nTotal Board Size:      " << SIZE << endl;
    cout << "Total spaces occupied: " << totOcc << endl;
    cout << "Total games played:    " << totGame << endl;
    cout << "Total Black Count:     " << totBlk << endl;
    cout << "Total White Count:     " << totWht << endl;
}