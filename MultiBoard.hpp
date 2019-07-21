//
//  MultiBoard.hpp
//  Ultimate Tic Tac Toe
//
//  Created by Anuj Parakh on 4/16/18.
//  Copyright © 2018 Anuj Parakh. All rights reserved.
//

#ifndef MultiBoard_hpp
#define MultiBoard_hpp

#include "SingleBoard.hpp"

class MultiBoard
{
private:
    SingleBoard boards [MAX_ROWS] [MAX_COLS];
    
public:
    MultiBoard ();
    Player getPlayerAt (int row, int col, int boardRow, int boardCol);
    bool setPlayerAt (int row, int col, int boardRow, int boardCol, Player newPlayer);
    bool boardIsAvailable (int boardRow, int boardCol);
    SingleBoard convertToOneBoard ();
    Player getWinner ();
    void printBoards ();
    
};

#endif /* MultiBoard_hpp */
