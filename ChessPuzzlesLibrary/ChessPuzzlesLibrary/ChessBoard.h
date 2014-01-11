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
 * Chess piece color = white, black, or none.
 */
enum ChessPieceColor
{
    NO_PIECE = 0,
    WHITE = 1,
    BLACK = 2
};

/*
 * Represents the rank of a square on the board.
 */
enum ChessBoardRank
{
    R1 = 1,
    R2 = 2,
    R3 = 3,
    R4 = 4,
    R5 = 5,
    R6 = 6,
    R7 = 7,
    R8 = 8
};

/*
 * Represents the file of a square on the board.
 */
enum ChessBoardFile
{
    A = 1,
    B = 2,
    C = 3,
    D = 4,
    E = 5,
    F = 6,
    G = 7,
    H = 8
};

/*
 *  Representation of the chess board (rank, file): (0,0) = a1, (7,7) = h8. 9 wide so last position can hold NULL.
 */
struct ChessBoard
{
    // layout of the pieces on the board - lowercase = black, upper = white, space = empty
    // [space] = empty
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
char pieceAt(struct ChessBoard *board, enum ChessBoardRank rank, enum ChessBoardFile file);

/**
  * Set a piece on the board.
  */
int setPiece(struct ChessBoard *board, char piece, enum ChessBoardRank rank, enum ChessBoardFile file);

/*
 * Move a piece to a new location, returning 1 if a piece was moved, 0 if no piece was moved.
 */
int movePiece(struct ChessBoard *board, enum ChessBoardRank rankFrom, enum ChessBoardFile fileFrom, enum ChessBoardRank rankTo, enum ChessBoardFile fileTo);

/*
 * Figure out all of the valid squares for the piece at the input position, storing them in |validLocations| 
 * as either 0 (no) or 1 (yes).
 */
int validMoves(struct ChessBoard *board, enum ChessBoardRank rank, enum ChessBoardFile file, char validLocations[65]);

#endif
