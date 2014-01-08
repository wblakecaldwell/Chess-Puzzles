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
    // layout is A1->H1, A2->H2, ... A8->H8
    char pieces[65];
};

/*
 *  Initialize the input board for a new game.
 */
int initializeForGame(struct ChessBoard *board);

/*
 * Get the piece at the input rank and file, where rank is uppercased A-H, file is 1-8.
 * Return 0 on failure.
 */
char pieceAt(struct ChessBoard *board, char rank, int file);

/*
 * Move a piece to a new location, returning 1 if a piece was moved, 0 if no piece was moved.
 */
int movePiece(struct ChessBoard *board, char rankFrom, int fileFrom, char rankTo, int fileTo);

#endif
