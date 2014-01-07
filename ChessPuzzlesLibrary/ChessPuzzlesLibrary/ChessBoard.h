//
//  ChessBoard.h
//  ChessPuzzlesLibrary
//
//  Created by Blake Caldwell on 1/5/14.
//  Copyright (c) 2014 Blake Caldwell. All rights reserved.
//

#ifndef ChessPuzzlesLibrary_ChessBoard_h
#define ChessPuzzlesLibrary_ChessBoard_h

/*
 *  Representation of the chess board (rank, file): (0,0) = a1, (7,7) = h8. 9 wide so last position can hold NULL.
 */
struct ChessBoard
{
    // layout of the pieces on the board - lowercase = black, upper = white
    // 0 = empty
    // p = pawn
    // r = rook
    // n = knight
    // b = bishop
    // q = queen
    // k = king
    char *pieces[9];
};

/*
 *  Initialize the input board for a new game.
 */
int initializeForGame(struct ChessBoard *board);

#endif
