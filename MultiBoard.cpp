//
//  MultiBoard.cpp
//  Ultimate Tic Tac Toe
//
//  Created by Anuj Parakh on 4/16/18.
//  Copyright © 2018 Anuj Parakh. All rights reserved.
//

#include "MultiBoard.hpp"
#include <iostream>

using namespace std;

MultiBoard::MultiBoard ()
{}

// Function to get the player from given board row and col at row and col
Player MultiBoard::getPlayerAt(int row, int col, int boardRow, int boardCol)
{
    return boards [boardRow] [boardCol].getPlayerAt(row, col);
}

// Function to set the given at given board row and col at row and col
bool MultiBoard::setPlayerAt(int row, int col, int boardRow, int boardCol, Player newPlayer)
{
    if (boards [boardRow] [boardCol].getWinner() != Player::DNE)
    {
        return false;
    }
    
    return boards [boardRow] [boardCol].setPlayerAt(row, col, newPlayer);
}

// Convert all of them to one board with each element the winner of the bigger board
SingleBoard MultiBoard::convertToOneBoard()
{
    // board to create
    SingleBoard oneBoard;
    
    // Go thorugh the boards
    for (int i = 0; i < MAX_ROWS; ++i)
    {
        for (int j = 0; j < MAX_COLS; ++j)
        {
            // Get the winner of the current board
            Player winner = boards [i] [j].getWinner();
            // If the winner is X or O set that player
            // Otherwise it's empty
            if (winner == Player::Ax || winner == Player::Oh)
                oneBoard.setPlayerAt(i, j, winner);
            else
                oneBoard.setPlayerAt(i, j, Player::No);
        }
    }
    
    // Return the created winner board
    return oneBoard;
}

// Function to get the winner of the multi boards
Player MultiBoard::getWinner()
{
    // Get the winner board
    SingleBoard winnerBoard = convertToOneBoard();
    
    // See if the winner board produces a winner
    Player winner = winnerBoard.getWinner();
    // Return only if winner is No i.e. board is full and noone won
    if (winner != Player::No)
    {
        return winner;
    }

    // Now see if the winner board has more Xs than Os
    int axCounter = 0;
    int ohCounter = 0;
    
    // Go through the board
    for (int i = 0; i < MAX_ROWS; ++i)
    {
        for (int j = 0; j < MAX_COLS; ++j)
        {
            // Increment X n O accordingly
            if (winnerBoard.getPlayerAt(i, j)== Player::Ax)
            {
                ++axCounter;
            }
            else if (winnerBoard.getPlayerAt(i, j) == Player::Oh)
            {
                ++ohCounter;
            }
        }
    }
    
    // See if either is more
    if (axCounter > ohCounter)
    {
        return Player::Ax;
    }
    else if (ohCounter > axCounter)
    {
        return Player::Oh;
    }
    
    // If no winner, it's a draw :(
    return Player::No;
}

// Function to print all the boards
void MultiBoard::printBoards()
{
    // Go through each of the board and print it accordingly with tabs in between
    for (int boardRowIndex = 0; boardRowIndex < MAX_ROWS; ++boardRowIndex)
    {
        for (int rowIndex = 0; rowIndex < MAX_ROWS; ++rowIndex)
        {
            for (int boardColIndex = 0; boardColIndex < MAX_COLS; ++boardColIndex)
            {
                for (int colIndex = 0; colIndex < MAX_ROWS; ++colIndex)
                {
                    cout << convertPlayerToString (boards [boardRowIndex] [boardColIndex].getPlayerAt(rowIndex, colIndex)) << " ";
                }
                
                cout << "\t";
            }
            
            cout << endl;
        }
        
        cout << endl << endl;
    }
}

// Function to check if board at given board row and col is available for playing
bool MultiBoard::boardIsAvailable(int boardRow, int boardCol)
{
    // makes sure that the winner of that board is DNE and not a valid winner
    return boards [boardRow] [boardCol].getWinner() == Player::DNE;
}
