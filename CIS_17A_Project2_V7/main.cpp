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
#include "State.h"


int main(int argc, char** argv) {
    
    Game game;
    game.play();
    
    return 0;
}

