//
//  SingleBoard.hpp
//  Ultimate Tic Tac Toe
//
//  Created by Anuj Parakh on 4/15/18.
//  Copyright © 2018 Anuj Parakh. All rights reserved.
//

#ifndef SingleBoard_hpp
#define SingleBoard_hpp

#include "Helper.h"


class SingleBoard
{
private:

    Player board [MAX_ROWS] [MAX_COLS];
    bool playerExistsAt (int row, int col);
    Player checkRowWinner ();
    Player checkColWinner ();
    Player checkDiagonalWinner ();
    
public:
    
    SingleBoard ();
    Player getPlayerAt (int row, int col);
    bool setPlayerAt (int row, int col, Player player);
    bool isFull ();
    bool isEmpty ();
    void printBoard ();
    Player getWinner ();
};

std::string convertPlayerToString (Player player);


#endif /* SingleBoard_hpp */
