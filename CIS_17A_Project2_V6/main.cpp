/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Donald
 *
 * Created on November 26, 2023, 12:59 PM
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

#include "Board.h"
#include "Game.h"


int main(int argc, char** argv) {
    //Create game object and call the play function
    Game game;
    game.play();
    
    return 0;
}

