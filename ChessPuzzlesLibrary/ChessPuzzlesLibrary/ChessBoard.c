//
//  ChessBoard.c
//  ChessPuzzlesLibrary
//
//  Created by Blake Caldwell on 1/5/14.
//  Copyright (c) 2014 Blake Caldwell. All rights reserved.
//

#include <stdio.h>
#include <strings.h>
#include "ChessBoard.h"

/*
 * (PRIVATE) Return the pieces string index based on rank/file.
 */
int pieceIndexAt(enum ChessBoardRank rank, enum ChessBoardFile file)
{
    return ((rank-1) * 8) + file - 1;
}

/*
 * (PRIVATE) Return the color of the input piece.
 */
enum ChessPieceColor colorOf(char pieceValue)
{
    if('P' == pieceValue ||
       'R' == pieceValue ||
       'N' == pieceValue ||
       'B' == pieceValue ||
       'K' == pieceValue ||
       'Q' == pieceValue)
    {
        return WHITE;
    }
    
    if('p' == pieceValue ||
       'r' == pieceValue ||
       'n' == pieceValue ||
       'b' == pieceValue ||
       'k' == pieceValue ||
       'q' == pieceValue)
    {
        return BLACK;
    }
    
    return NO_PIECE;
}

int initializeForGame(struct ChessBoard *board)
{
    strcpy(board->pieces, "RNBQKBNRPPPPPPPP                                pppppppprnbqkbnr");
    return 1;
}

char pieceAt(struct ChessBoard *board, enum ChessBoardRank rank, enum ChessBoardFile file)
{
    return board->pieces[pieceIndexAt(rank, file)];
}

int movePiece(struct ChessBoard *board, enum ChessBoardRank rankFrom, enum ChessBoardFile fileFrom, enum ChessBoardRank rankTo, enum ChessBoardFile fileTo)
{
    char pieceFrom;
    char pieceTo;
    
    // make sure we're not moving to self
    if(rankFrom == rankTo && fileFrom == fileTo)
    {
        // moving to self - no good
        return 0;
    }
    
    // make sure there's a piece to move
    pieceFrom = pieceAt(board, rankFrom, fileFrom);
    if(' ' == pieceFrom || 0 == pieceFrom)
    {
        // there's no piece here
        return 0;
    }
    
    // make sure the target cell is valid
    pieceTo = pieceAt(board, rankTo, fileTo);
    if(0 == pieceTo)
    {
        // invalid destination
        return 0;
    }
    
    setPiece(board, ' ', rankFrom, fileFrom);
    setPiece(board, pieceFrom, rankTo, fileTo);
    return 1;
}

int setPiece(struct ChessBoard *board, char piece, enum ChessBoardRank rank, enum ChessBoardFile file)
{
    board->pieces[pieceIndexAt(rank, file)] = piece;
    return 1;
}

int validMoves(struct ChessBoard *board, enum ChessBoardRank rank, enum ChessBoardFile file, char validLocations[65])
{
    char pieceFrom;
    char pieceTo;
    int i;
    int validMoveCount;
    
    validMoveCount = 0;
    
    // make sure there's a piece to move
    pieceFrom = pieceAt(board, rank, file);
    if(' ' == pieceFrom || 0 == pieceFrom)
    {
        // there's no piece here
        return 0;
    }
    
    // initialize all positions to 0
    for(i=0; i<=65; i++)
    {
        validLocations[i] = '0';
    }
    validLocations[64] = 0;
    
    switch(pieceFrom)
    {
        case 'P':   // white pawn
            // * pawn can move forward (up) one space if nobody's in front
            if(' ' == pieceAt(board, rank+1, file))
            {
                validMoveCount++;
                validLocations[pieceIndexAt(rank+1, file)] = '1';
            }
            
            // * pawn can move two spaces foward (up) if on rank 2 and nobody's there
            if(R2 == rank && ' ' == pieceAt(board, rank+2, file))
            {
                validMoveCount++;
                validLocations[pieceIndexAt(4, file)] = '1';
            }
            
            // * pawn can move forward (up) diagonal if an opponent is there
            
            // check attack left
            pieceTo = pieceAt(board, rank+1, file-1);
            if(BLACK == colorOf(pieceTo))
            {
                // we can take this piece!
                validMoveCount++;
                validLocations[pieceIndexAt(rank+1, file-1)] = '1';
            }
            
            // check attack right
            pieceTo = pieceAt(board, rank+1, file+1);
            if(BLACK == colorOf(pieceTo))
            {
                validMoveCount++;
                validLocations[pieceIndexAt(rank+1, file+1)] = '1';
            }
            
            break;
        
        case 'p':   // black pawn
            // * pawn can move forward (down) one space if nobody's in front
            if(' ' == pieceAt(board, rank-1, file))
            {
                validMoveCount++;
                validLocations[pieceIndexAt(rank-1, file)] = '1';
            }
            
            // * pawn can move two spaces foward (down) if on rank 7
            if(R7 == rank && ' ' == pieceAt(board, rank-2, file))
            {
                validMoveCount++;
                validLocations[pieceIndexAt(rank-2, file)] = '1';
            }
            
            // * pawn can move foward (down) diagonal if an opponent is there
            
            // check attack left
            pieceTo = pieceAt(board, rank-1, file-1);
            if(WHITE == colorOf(pieceTo))
            {
                // we can take this piece!
                validMoveCount++;
                validLocations[pieceIndexAt(rank-1, file-1)] = '1';
            }
            
            // check attack right
            pieceTo = pieceAt(board, rank-1, file+1);
            if(WHITE == colorOf(pieceTo))
            {
                validMoveCount++;
                validLocations[pieceIndexAt(rank-1, file+1)] = '1';
            }
            break;
        
        case 'R':   // white rook
            // TODO
            break;
        
        case 'r':   // black rook
            // TODO
            break;
            
        case 'N':   // white knight
            // TODO
            break;
        
        case 'n':   // black knight
            // TODO
            break;
            
        case 'B':   // white bishop
            // TODO
            break;
            
        case 'b':   // black bishop
            // TODO
            break;
            
        case 'Q':   // white queen
            // TODO
            break;
            
        case 'q':   // black queen
            // TODO
            break;
            
        case 'K':   // white king
            // TODO
            break;
        
        case 'k':   // black king
            // TODO
            break;
            
        default:
            break;
    }
    
    return validMoveCount;
}