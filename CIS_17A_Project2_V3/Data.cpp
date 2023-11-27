#include <iostream>
#include <fstream>
#include "Data.h"

using namespace std;

void Data::saveRes() {
    saveText();
    saveBin();
}

void Data::saveText() {
    fstream saveF("game_results.txt", ios::out | ios::app);
    if (saveF.is_open()) {
        saveF << "Black Count: " << blkCt << endl;
        saveF << "White Count: " << whtCt << endl;
        saveF << "----------------------" << endl;
        saveF.close();
        cout << "Results added to 'game_results.txt'." << endl;
    } else {
        cout << "Error: Could not open the text file." << endl;
    }
}

void Data::saveBin() {
    ofstream binF("data.dat", ios::binary | ios::app);
    if (binF.is_open()) {
        binF.write(reinterpret_cast<const char*>(&blkCt), sizeof(int));
        binF.write(reinterpret_cast<const char*>(&whtCt), sizeof(int));
        binF.close();
        cout << "Results added to 'data.dat'." << endl;
    } else {
        cout << "Error: Could not open the binary file." << endl;
    }
}

void Data::moreDat() {
    ifstream binF("data.dat", ios::binary);
    if (!binF.is_open()) {
        cout << "Error: Could not open the binary file for reading." << endl;
        return;
    }

    Data data; // No need for dynamic allocation

    int blkCt, whtCt;
    while (binF.read(reinterpret_cast<char*>(&blkCt), sizeof(int)) && binF.read(reinterpret_cast<char*>(&whtCt), sizeof(int))) {
        data.nGames++;
        data.totBlk += blkCt;
        data.totWht += whtCt;
        data.totOcc += whtCt + blkCt;
    }

    binF.close();

    cout << "\nTotal spaces occupied: " << data.totOcc << endl;
    cout << "Total games played:    " << data.nGames << endl;
    cout << "Total Black Count:     " << data.totBlk << endl;
    cout << "Total White Count:     " << data.totWht << endl;
}
