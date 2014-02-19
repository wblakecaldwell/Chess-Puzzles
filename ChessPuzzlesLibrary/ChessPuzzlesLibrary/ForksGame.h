//
//  ForksGame.h
//  ChessPuzzlesLibrary
//
//  Created by Blake Caldwell on 2/18/14.
//  Copyright (c) 2014 Blake Caldwell. All rights reserved.
//

#include "ChessBoard.h"

#ifndef ChessPuzzlesLibrary_ForksGame_h
#define ChessPuzzlesLibrary_ForksGame_h

/*
 * Find all of the squares that the input color is attacking with at least two pieces, storing them in |forkedSquares|
 * as either '0' (no) or '1' (yes). |forkedSquares| is in the same boardString format as validMoves - A1-H1, A2-H2, etc, 
 * null-terminated.
 *
 * return the number of forked squares.
 */
int findForkedSquares(struct ChessBoard *board, enum ChessPieceColor playerColor, char forkedSquares[65]);

#endif
