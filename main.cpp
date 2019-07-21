//
//  main.cpp
//  Ultimate Tic Tac Toe
//
//  Created by Anuj Parakh on 4/15/18.
//  Copyright © 2018 Anuj Parakh. All rights reserved.
//

#include <iostream>
#include "MultiBoard.hpp"

using namespace std;

int main()
{
    
    MultiBoard board;
    Player currentPlayer = Player::Ax;
    int boardRow = 1;
    int boardCol = 1;
    

    
    while (board.getWinner() == Player::DNE)
    {
        cout << "The Board is " << endl << endl;
        board.printBoards();
        
        cout << "Turn : " << convertPlayerToString(currentPlayer) << endl;
        
        if (boardRow == -1)
        {
            cout << "Can play in any board row or col" << endl;
            cout << "Enter board row : ";
            cin >> boardRow;
            cout << "Enter board col : ";
            cin >> boardCol;
            
            --boardRow;
            --boardCol;
            
        }
        else
        {
            cout << "Board Row : " << boardRow + 1 << endl;
            cout << "Board Col : " << boardCol + 1 << endl;
        }
        
        int row, col;
        cout << "Enter row : ";
        cin >> row;
        cout << "Enter col : ";
        cin >> col;
        
        --row;
        --col;
        
        if (!board.setPlayerAt(row, col, boardRow, boardCol, currentPlayer))
        {
            cout << "Cannot play there.. try again!" << endl;
            continue;
        }
        
        if (currentPlayer == Player::Ax)
        {
            currentPlayer = Player::Oh;
        }
        else
        {
            currentPlayer = Player::Ax;
        }
        
        if (board.boardIsAvailable(row, col))
        {
            boardRow = row;
            boardCol = col;
        }
        
        else
        {
            boardRow = -1;
        }
        
        
    }
    
        if (board.getWinner() == Player::No)
        {
            cout << "NO WINNER.. YOU GUYS ARE BOOOOOORRIIIIIING" << endl;
        }
        else
        {
            cout << "AND THE WINNER IS... DRUMROLL PLEAAASEEEE... " << convertPlayerToString(board.getWinner()) << endl << endl << "This Player has shown the2 world how to play this awesome game of tic tac toe and absolutely and utterly humiliated the other player who should cry in shame.." << endl << endl;
        }
 
    return 0;
}
//    {
//        cout << "The Board is : " << endl << endl;
//        board.printBoards();
//        cout << "Turn : " << convertPlayerToString(currentPlayer) << endl << endl;
//        int row, col;
//        cout << "Enter row : ";
//        cin >> row;
//        cout << "Enter col : ";
//        cin >> col;
//
//        --row;
//        --col;
//
//        if (!board.setPlayerAt(row, col, currentPlayer))
//        {
//            cout << "Invalid Row and Column! Try again!" << endl;
//            continue;
//        }
//
//
//
//        if (currentPlayer == Player::Ax)
//        {
//            currentPlayer = Player::Oh;
//        }
//        else
//        {
//            currentPlayer = Player::Ax;
//        }
//
//        if (board.isFull())
//        {
//            break;
//        }
//    }
//
//    if (board.getWinner() == Player::No)
//    {
//        cout << "NO WINNER.. YOU GUYS ARE BOOOOOORRIIIIIING" << endl;
//    }
//    else
//    {
//        cout << "AND THE WINNER IS... DRUMROLL PLEAAASEEEE... " << convertPlayerToString(board.getWinner()) << endl << endl << "This Player has shown the2 world how to play this awesome game of tic tac toe and absolutely and utterly humiliated the other player who should cry in shame.." << endl << endl;
//    }
    
    
    

