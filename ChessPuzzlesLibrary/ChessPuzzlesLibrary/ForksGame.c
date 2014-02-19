//
//  ForksGame.c
//  ChessPuzzlesLibrary
//
//  Created by Blake Caldwell on 2/18/14.
//  Copyright (c) 2014 Blake Caldwell. All rights reserved.
//

#include <stdio.h>
#include <strings.h>
#include <assert.h>
#include <stdlib.h>
#include "ForksGame.h"
#include "ChessBoard.h"

int findForkedSquares(struct ChessBoard *board, enum ChessPieceColor playerColor, char forkedSquares[65])
{
    char piece;
    int i, j, pieceCount, moveCount, rank, file, forkedSquareCount;
    char validLocations[16][65];    // 16 total pieces with valid moves stored in second dimension
    
    pieceCount = 0;
    forkedSquareCount = 0;
    
    // initialize the board strings
    initializeBoardString(forkedSquares);
    for(i=0; i<16; i++)
    {
        initializeBoardString(validLocations[i]);
    }
    
    // move across all squares, finding a piece with the input color, and giving it a row in validLocations
    for(file = 1; file <= 8; file ++)
    {
        for(rank = 1; rank <= 8; rank++)
        {
            piece = pieceAt(board, (enum ChessBoardFile)file, (enum ChessBoardRank)rank);
            if(colorOf(piece) == playerColor)
            {
                // we found one of our pieces - find out its valid attacking moves
                validMoves(board, (enum ChessBoardFile)file, (enum ChessBoardRank)rank, ATTACKING_SQUARE, validLocations[pieceCount]);
                
                pieceCount++;
            }
        }
    }
    
    // loop across all squares, finding those that have multiple valid moves on them
    for(i = 0; i < 65; i++)
    {
        moveCount = 0;
        
        // check which of our pieces can move here
        for(j = 0; j < pieceCount && moveCount < 2; j++)
        {
            if(validLocations[j][i] == '1')
            {
                if(++moveCount == 2)
                {
                    // it's a fork, stop looking for any other piece's attack on this square
                    forkedSquares[i] = '1';
                    forkedSquareCount ++;
                }
            }
        }
    }
    
    return forkedSquareCount;
}