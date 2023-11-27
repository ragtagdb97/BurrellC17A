/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Donald
 *
 * Created on November 26, 2023, 1:32 PM
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>


using namespace std;

#include "Board.h"
#include "State.h"
#include "Game.h"

//Creating a template for the == operator
//To be used with the overloaded operator
//This will allow comparison of equality between various data types, including the Board class
template <typename T>
bool isEqual(const T& lhs, const T& rhs) {
    return lhs == rhs;
}

//Overloaded == operator for the Board class
bool operator==(const Board& lhs, const Board& rhs) {
    return lhs.board == rhs.board;
}

int main(int argc, char** argv) {
    //New game object
    //Other classes are inherited into this one
    Game game;
    game.play();    //Executes the loop for gameplay
    
    //Showing overloaded operator and template for equality
    //This does nothing but shows the two objects can be checked for equality using == operator
    Board board1;
    Board board2;
    
    //Template should also accept other data types 
    if (isEqual(board1, board2)) {
        cout << "The boards are equal." << endl;
    } else {
        cout << "The boards are not equal." << endl;
    }
    
    return 0;
}

