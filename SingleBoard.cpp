//
//  SingleBoard.cpp
//  Ultimate Tic Tac Toe
//
//  Created by Anuj Parakh on 4/15/18.
//  Copyright © 2018 Anuj Parakh. All rights reserved.
//

#include <iostream>
#include "SingleBoard.hpp"

using namespace std;

std::string convertPlayerToString (Player player)
{
    if (player == Player::Ax)
    {
        return "X";
    }
    else if (player == Player::Oh)
    {
        return "O";
    }
    else if (player == Player::No)
    {
        return "-";
    }
    
    return " ";
}

// Constructor for Single Board
SingleBoard::SingleBoard ()
{
    // Set all the players as No (Empty)
    for (int i = 0; i < MAX_ROWS; ++i)
    {
        for (int j = 0; j < MAX_COLS; ++j)
        {
            board [i] [j] = Player::No;
        }
    }
}

// Function to check if player exists at given row and colum
bool SingleBoard::playerExistsAt(int row, int col)
{
    // if out of range, return false
    if (row >= MAX_ROWS || col >= MAX_COLS)
        return false;
    
    // otherwise just return true
    return true;
}

// Function to get player at given row and column
Player SingleBoard::getPlayerAt(int row, int col)
{
    return board [row] [col];
}

// Function to set player at given row and column
bool SingleBoard::setPlayerAt(int row, int col, Player player)
{
    // if player doesnt exist at row and col return false
    if (!playerExistsAt(row, col))
    {
        return false;
    }
    
    // if position isn't empty return false
    if (board [row] [col] != Player::No)
    {
        return false;
    }
    
    // set the new player at that position
    board [row] [col] = player;
    
    // return true (successful)
    return true;
}

// Function to check if the board is full
bool SingleBoard::isFull ()
{
    // Go through the board
    for (int i = 0; i < MAX_ROWS; ++i)
    {
        for (int j = 0; j < MAX_COLS; ++j)
        {
            // If position is empty return false (not full)
            if (board [i] [j] == Player::No)
            {
                return false;
            }
        }
    }
    
    // Return true (means board is full)
    return true;
}

// Function to check if the board is empty
bool SingleBoard::isEmpty()
{
    // Go through the board
    for (int i = 0; i < MAX_ROWS; ++i)
    {
        for (int j = 0; j < MAX_COLS; ++j)
        {
            // If position is full return false (not empty)
            if (board [i] [j] != Player::No)
            {
                return false;
            }
        }
    }
    
    // Return true (means board is empty)
    return true;
}

// Function to print the board to cout
void SingleBoard::printBoard()
{
    // Go through the board
    for (int i = 0; i < MAX_ROWS; ++i)
    {
        for (int j = 0; j < MAX_COLS; ++j)
        {
            cout << convertPlayerToString (board [i] [j]) << " ";
        }
        
        cout << endl;
    }
}

Player SingleBoard::checkDiagonalWinner ()
{
    // go through all the players
    // Assume both \ and / diagonals have a winner
    bool foundWinnerOne = true;
    bool foundWinnerTwo = true;
    
    for (int rowIndex = 0; rowIndex < MAX_ROWS; ++rowIndex)
    {
        for (int colIndex = 0; colIndex < MAX_COLS; ++colIndex)
        {
            // for '\' diagonal
            if (rowIndex == colIndex)
            {
                if (board [rowIndex] [colIndex] == Player::No)
                {
                    foundWinnerOne = false;
                }
                
                if (board [rowIndex] [colIndex] != board [0] [0])
                {
                    foundWinnerOne = false;
                }
            }
            
            // for '/' diagonal
            if ((rowIndex + colIndex) == (MAX_ROWS - 1))
            {
                if (board [rowIndex] [colIndex] == Player::No)
                {
                    foundWinnerTwo = false;
                }
                
                if (board [rowIndex] [colIndex] != board [0] [MAX_ROWS - 1])
                {
                    foundWinnerTwo = false;
                }
                
            }
            
        }
        
        
        
    }
    
    // found winner for diagonal '\'
    if (foundWinnerOne)
    {
        return board [0] [0];
    }
    
    // found winner for diagonal '\'
    if (foundWinnerTwo)
    {
        return board [0] [MAX_ROWS - 1];
    }
    
    // if no winner return empty player
    return Player::No;
    
}

Player SingleBoard::checkRowWinner()
{
    // Go through all the rows
    for (int rowIndex = 0; rowIndex < MAX_ROWS; ++rowIndex)
    {
        // Assume this row has a winner
        bool foundWinner = true;
        
        // Go through all the columns
        for (int colIndex = 0; colIndex < MAX_COLS; ++colIndex)
        {
            // If found empty, no winner in that column
            if (board [rowIndex] [colIndex] == Player::No)
            {
                foundWinner = false;
                break;
            }
            
            // If not same as the first row, no one wins that row
            if (board [rowIndex] [colIndex] != board [rowIndex] [0])
            {
                foundWinner = false;
                break;
            }
        }
        
        // If found a winner
        if (foundWinner)
        {
            // return the player in the first column of the current row
            return board [rowIndex] [0];
        }
        
    }
    
    // No winner :(
    return Player::No;
}

Player SingleBoard::checkColWinner()
{
    // Go through all the rows
    for (int colIndex = 0; colIndex < MAX_ROWS; ++colIndex)
    {
        // Assume this row has a winner
        bool foundWinner = true;
        
        // Go through all the columns
        for (int rowIndex = 0; rowIndex < MAX_COLS; ++rowIndex)
        {
            // If found empty, no winner in that column
            if (board [rowIndex] [colIndex] == Player::No)
            {
                foundWinner = false;
                break;
            }
            
            // If not same as the first row, no one wins that row
            if (board [rowIndex] [colIndex] != board [0] [colIndex])
            {
                foundWinner = false;
                break;
            }
        }
        
        // If found a winner
        if (foundWinner)
        {
            // return the player in the first column of the current row
            return board [0] [colIndex];
        }
        
    }
    
    // No winner :(
    return Player::No;
}

// Function to get the winner of the board
Player SingleBoard::getWinner()
{
    // Find the winner in the row
    Player rowWinner = checkRowWinner();
    
    // Check if there actually is a winner, then return
    if (rowWinner != Player::No)
    {
        return rowWinner;
    }

    // Find the winner in the col
    Player colWinner = checkColWinner ();

    // Check if there actually is a winner, then return
    if (colWinner != Player::No)
    {
        return colWinner;
    }
    
    // Find the winner in the diagonals
    Player diagWinner = checkDiagonalWinner();
    
    // Check if there actually is a winner, then return
    if (diagWinner != Player::No)
    {
        return diagWinner;
    }
    
    // If board is full, no winner
    if (isFull())
    {
        return Player::No;
    }
    // otherwise no winner yet (DNE)
    else
    {
        return Player::DNE;
    }
}


