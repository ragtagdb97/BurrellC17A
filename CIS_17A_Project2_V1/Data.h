
/* 
 * File:   Data.h
 * Author: Donald
 *
 * Created on November 24, 2023, 9:24 AM
 */

#ifndef DATA_H
#define DATA_H



class Data {
public:
    Data() : blkCt(0), whtCt(0), nGames(0), totBlk(0), totWht(0), totOcc(0) {}
    Data(int w, int b) : blkCt(b), whtCt(w) {}
    
    void saveRes();
    void moreDat();
private:
    int blkCt;
    int whtCt;
    
    int nGames;
    int totBlk;
    int totWht;
    int totOcc;
};

#endif /* DATA_H */

