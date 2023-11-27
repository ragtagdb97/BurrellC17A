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
    //This used to be in main on project 1
    //Annoying for converting to classes
    while (true) {
        board.printBoard();
        cout << "Player: " << (currentPlayer == Board::BLACK ? 'B' : 'W') << ", enter your move (e.g. C4 / OR 'exit' to quit): ";
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
            switchPlayer();
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

bool Game::isValidMove(int row, int col) const {
    //Check boundaries
    if (row < 0 || row >= Board::SIZE || col < 0 || col >= Board::SIZE || board.getPlayer(row, col) != Board::EMPTY) {
        return false;
    }

    //Move must capture an opponent piece
    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            //Skip position
            if (i == 0 && j == 0) {
                continue;
            }

            //Check in the current direction
            int currentRow = row + i;
            int currentCol = col + j;
            bool foundOpponent = false;

            while (currentRow >= 0 && currentRow < Board::SIZE && currentCol >= 0 && currentCol < Board::SIZE) {
                if (board.getPlayer(currentRow, currentCol) == Board::EMPTY) {
                    break;
                }
                if (board.getPlayer(currentRow, currentCol) == currentPlayer) {
                    foundOpponent = true;
                    break;
                }
                //Increment the cell number
                currentRow += i;
                currentCol += j;
            }

            if (foundOpponent) {
                return true;
            }
        }
    }

    //Move is invalid if nothing applies
    return false;
}

void Game::doMove(int row, int col) {
    board.setPlayer(row, col, currentPlayer);
    updateCounts(row, col);
}

void Game::switchPlayer() {
    currentPlayer = (currentPlayer == Board::BLACK) ? Board::WHITE : Board::BLACK;
}

void Game::updateCounts(int row, int col) {
    (currentPlayer == Board::BLACK) ? blackCount++ : whiteCount++;
}

bool Game::isBoardFull() const {
    for (int i = 0; i < Board::SIZE; i++) {
        for (int j = 0; j < Board::SIZE; j++) {
            if (board.getPlayer(i, j) == Board::EMPTY) {
                return false;
            }
        }
    }
    return true;
}

void Game::resetGame() {
    board.initBoard();
    blackCount = 2;
    whiteCount = 2;
    currentPlayer = Board::BLACK;
}

void Game::saveResults() const {
    //Save everything to a text file
    ofstream saveFile("game_results.txt", ios::out | ios::app);
    if (saveFile.is_open()) {
        saveFile << "Black Count: " << blackCount << endl;
        saveFile << "White Count: " << whiteCount << endl;
        saveFile << "----------------------" << endl;
        saveFile.close();
        cout << "Results added to 'game_results.txt'." << endl;
    } else {
        cout << "Error: Could not open the text file." << endl;
    }
}

void Game::displayData() const {
    //This is problematic
    //Supposed to read from the binary file and output accordingly.
    //Not working
    ifstream binFile("data.dat", ios::binary);

    if (!binFile.is_open()) {
        cout << "Error: Could not open the binary file for reading." << endl;
        return;
    }

    int blkCount, whtCount;
    int totalGames = 0, totalBlacks = 0, totalWhites = 0, totalOccupied = 0;

    while (binFile.read(reinterpret_cast<char*>(&blkCount), sizeof(int)) && binFile.read(reinterpret_cast<char*>(&whtCount), sizeof(int))) {
        totalGames++;
        totalBlacks += blkCount;
        totalWhites += whtCount;
        totalOccupied += blkCount + whtCount;
    }

    binFile.close();

    cout << "\nTotal Board Size:      " << Board::SIZE << endl;
    cout << "Total spaces occupied: " << totalOccupied << endl;
    cout << "Total games played:    " << totalGames << endl;
    cout << "Total Black Count:     " << totalBlacks << endl;
    cout << "Total White Count:     " << totalWhites << endl;
}