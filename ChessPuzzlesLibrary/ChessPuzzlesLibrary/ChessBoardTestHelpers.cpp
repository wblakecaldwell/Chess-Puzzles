//
//  ChessBoardTestHelpers.cpp
//  ChessPuzzlesLibrary
//
//  Created by Blake Caldwell on 1/11/14.
//  Copyright (c) 2014 Blake Caldwell. All rights reserved.
//

#include <stdio.h>
#include "ChessBoardTestHelpers.h"
#include <gtest/gtest.h>
#include <assert.h>
extern "C" {
    #include "ChessBoard.h"
}


int helperEmptyValidLocations(char validLocations[65])
{
    int i;
    
    for(i = 0; i <= 65; i++)
    {
        validLocations[i] = '0';
    }
    validLocations[64] = 0;
    return 1;
}

int helperAddValidLocation(char validLocations[65], enum ChessBoardFile file, enum ChessBoardRank rank)
{
    validLocations[((rank-1) * 8) + file - 1] = '1';
    return 1;
}

int helperSetValidLocations(char validLocations[65], const char *locations[])
{
    const char *location;
    int rank;
    int file;
    
    helperEmptyValidLocations(validLocations);
    while(*locations)
    {
        location = *locations++;
        
        file = location[0] - 'A' + 1;
        rank = location[1] - '0';
        
        helperAddValidLocation(validLocations, (enum ChessBoardFile)file, (enum ChessBoardRank)rank);
    }
    
    return 1;
}

int parseTestingBoard(char pieces[][8][8], struct ChessBoard *board, char expectedValidLocations[65], enum ChessBoardFile *pieceFile, enum ChessBoardRank *pieceRank)
{
    int numberOfExpectedValidLocations;
    int row, col;
    enum ChessBoardRank loopRank;
    enum ChessBoardFile loopFile;
    int foundTargetPiece;
    
    foundTargetPiece = 0;
    
    // testing with a fresh board
    initializeEmpty(board);
    helperEmptyValidLocations(expectedValidLocations);
    row = 0;
    numberOfExpectedValidLocations = 0;
    
    // Loop over the pieces string array, reading in both the board state and valid locations.
    // pieces starts at A8 and ends at H1.
    for(row=0; row<8; row++)
    {
        for(col=0; col<8; col++)
        {
            // need to swap coordinates - operations are done with A=0, but test
            // data is laid out as the board looks, with A=7.
            loopRank = (enum ChessBoardRank)(8-row);
            loopFile = (enum ChessBoardFile)(col + 1);
            
            assert(strlen(pieces[row][col]) == 3);
            
            // set the piece
            setPiece(board, pieces[row][col][1], loopFile, loopRank);
            
            // if the piece is surrounded with square brackets, add it as a valid location
            if(pieces[row][col][0] == '[' && pieces[row][col][2] == ']')
            {
                helperAddValidLocation(expectedValidLocations, loopFile, loopRank);
                numberOfExpectedValidLocations++;
            }
            else if(pieces[row][col][0] == '(' && pieces[row][col][2] == ')')
            {
                if(foundTargetPiece)
                {
                    assert(0);
                }
                *pieceFile = loopFile;
                *pieceRank = loopRank;
                foundTargetPiece = 1;
            }
        }
    }
    
    assert(foundTargetPiece == 1);
    
    return numberOfExpectedValidLocations;
}