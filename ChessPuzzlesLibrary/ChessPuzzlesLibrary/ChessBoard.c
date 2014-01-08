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
 * (PRIVATE) return the pieces string index based on rank/file.
 */
int pieceIndexAt(char rank, int file)
{
    return ((file-1) * 8) + rank - 'A';
}

int initializeForGame(struct ChessBoard *board)
{
    strcpy(board->pieces, "RNBQKBNRPPPPPPPP                                pppppppprnbqkbnr");
    return 1;
}

char pieceAt(struct ChessBoard *board, char rank, int file)
{
    if(rank < 'A' || rank > 'H' || file < 0 || file > 8)
    {
        return 0;
    }
    return board->pieces[pieceIndexAt(rank, file)];
}

int movePiece(struct ChessBoard *board, char rankFrom, int fileFrom, char rankTo, int fileTo)
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
    
    board->pieces[pieceIndexAt(rankFrom, fileFrom)] = ' ';
    board->pieces[pieceIndexAt(rankTo, fileTo)] = pieceFrom;
    return 1;
}