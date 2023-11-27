#include <iostream>
#include <fstream>
#include "Data.h"

using namespace std;

void Data::saveRes() {
    //Text file to save individual game results
    fstream saveF("game_results.txt", ios::out | ios::app);
    if (saveF.is_open()) {
        //Formatted to be readable. 
        //Saves player stats for each game
        saveF << "Black Count: " << blkCt << endl;
        saveF << "White Count: " << whtCt << endl;
        saveF << "----------------------" << endl;
        saveF.close();
        cout << "Results added to 'game_results.txt'." << endl;
    } else {
        cout << "Error: Could not open the text file." << endl;
    }

    //Save results to a binary file
    ofstream binF("data.dat", ios::binary | ios::app);
    if (binF.is_open()) {
        //write blkCt/whtCt; 4 bytes to binF
        binF.write(reinterpret_cast<char*>(&blkCt), sizeof(int));
        binF.write(reinterpret_cast<char*>(&whtCt), sizeof(int));
        binF.close();
        cout << "Results added to 'data.dat'." << endl;
    } else {
        cout << "Error: Could not open the binary file." << endl;
    }
}

void Data::moreDat() {
    ifstream binF("data.dat", ios::binary);

    //Check if file opened
    if (!binF.is_open()) {
        cout << "Error: Could not open the binary file for reading." << endl;
        return;
    }
    //Some data to be gathered
    Data *data = new Data;
    
    int blkCt, whtCt;   //Original values
    while (binF.read(reinterpret_cast<char*>(&blkCt), sizeof(int)) && binF.read(reinterpret_cast<char*>(&whtCt), sizeof(int))) {
        data->nGames++;   //Number of games +1 for every loop (new loop after both white and black count are taken)
        data->totBlk += blkCt;    //Adds each count to the total for each player (from all games)
        data->totWht += whtCt;
        data->totOcc += whtCt + blkCt; 
    }
    
    binF.close();
    //Also outputs the data to console before ending program
    cout << "\nTotal spaces occupied: " << data->totOcc << endl;      //Total spaces occupied by either player, ever
    cout << "Total games played:    " << data->nGames << endl;
    cout << "Total Black Count:     " << data->totBlk << endl;
    cout << "Total White Count:     " << data->totWht << endl;
    
    //Delete the structure, as it is all stored/outputted
    delete data; 
    
}

