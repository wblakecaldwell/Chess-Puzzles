//
//  ChessBoard.c
//  ChessPuzzlesLibrary
//
//  Created by Blake Caldwell on 1/5/14.
//  Copyright (c) 2014 Blake Caldwell. All rights reserved.
//

#include <stdio.h>
#include "ChessBoard.h"

int initializeForGame(struct ChessBoard *board)
{
    board->pieces[7] = "rnbqkbnr";
    board->pieces[6] = "pppppppp";
    board->pieces[5] = "\0\0\0\0\0\0\0\0";
    board->pieces[4] = "\0\0\0\0\0\0\0\0";
    board->pieces[3] = "\0\0\0\0\0\0\0\0";
    board->pieces[2] = "\0\0\0\0\0\0\0\0";
    board->pieces[1] = "PPPPPPPP";
    board->pieces[0] = "RNBQKBNR";
    return 1;
}