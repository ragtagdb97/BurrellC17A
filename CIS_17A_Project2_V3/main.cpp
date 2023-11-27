
/* 
 * File:   main.cpp
 * Author: Donald
 *
 * Created on November 24, 2023, 8:50 AM
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <valarray>
#include <string>
#include <cstring>

using namespace std;

#include "Board.h"
#include "Move.h"
#include "Game.h"
#include "Data.h"

int main(int argc, char** argv) {
    Game game;
    Data data;
    
    game.play();
    
    data.saveRes();
    data.moreDat();
    
    return 0;
}

