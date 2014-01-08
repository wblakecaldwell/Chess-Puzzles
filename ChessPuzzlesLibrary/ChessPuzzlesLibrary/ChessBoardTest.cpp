//
//  ChessBoardTest.c
//  ChessPuzzlesLibrary
//
//  Test fixture for ChessBoard.
//
//  Created by Blake Caldwell on 1/5/14.
//  Copyright (c) 2014 Blake Caldwell. All rights reserved.
//

#include <stdio.h>
#include <gtest/gtest.h>

extern "C" {
#include "ChessBoard.h"
}

// test the board initialization
TEST(ChessBoard_initializeForGame, boardPiecesString)
{
    struct ChessBoard board;
    initializeForGame(&board);
    
    ASSERT_STREQ("RNBQKBNRPPPPPPPP                                pppppppprnbqkbnr", board.pieces) << "Chess board pieces not stored as expected";
}

// Test pieceAt for every piece in an initialized board
TEST(ChessBoard_pieceAt, badInput)
{
    struct ChessBoard board;
    initializeForGame(&board);
    
    ASSERT_EQ(0, pieceAt(&board, 'a', 1)) << "Lowercase rank didn't return failure as expected";
    ASSERT_EQ(0, pieceAt(&board, '&', 1)) << "Non-alpha rank didn't return failure as expected";
    ASSERT_EQ(0, pieceAt(&board, 'I', 1)) << "Rank > 'H' didn't return failure as expected";
    ASSERT_EQ(0, pieceAt(&board, 'A', 0)) << "File less than 1 didn't return failure as expected";
    ASSERT_EQ(0, pieceAt(&board, 'a', 9)) << "File > 8 didn't return failure as expected";
}

// Test pieceAt for every piece in an initialized board
TEST(ChessBoard_pieceAt, goodInput)
{
    struct ChessBoard board;
    initializeForGame(&board);
    
    // check the empty cells
    for(char rank = 'A'; rank <= 'H'; rank++)
    {
        for(int file = 3; file <= 6; file++)
        {
            ASSERT_EQ(' ', pieceAt(&board, rank, file)) << rank << file << " not empty";
        }
    }
    
    // check the pawns
    for(char rank = 'A'; rank <= 'H'; rank++)
    {
        // white
        ASSERT_EQ('P', pieceAt(&board, rank, 2)) << rank << 2 << " not a white pawn";
        
        // black
        ASSERT_EQ('p', pieceAt(&board, rank, 7)) << rank << 7 << " not a black pawn";
    }
    
    // white pieces
    ASSERT_EQ('R', pieceAt(&board, 'A', 1)) << "White rook not at A1";
    ASSERT_EQ('N', pieceAt(&board, 'B', 1)) << "White knight not at B1";
    ASSERT_EQ('B', pieceAt(&board, 'C', 1)) << "White bishop not at C1";
    ASSERT_EQ('Q', pieceAt(&board, 'D', 1)) << "White queen not at D1";
    ASSERT_EQ('K', pieceAt(&board, 'E', 1)) << "White king not at E1";
    ASSERT_EQ('B', pieceAt(&board, 'F', 1)) << "White bishop not at F1";
    ASSERT_EQ('N', pieceAt(&board, 'G', 1)) << "White knight not at G1";
    ASSERT_EQ('R', pieceAt(&board, 'H', 1)) << "White rook not at H1";
    
    // black pieces
    ASSERT_EQ('r', pieceAt(&board, 'A', 8)) << "Black rook not at A8";
    ASSERT_EQ('n', pieceAt(&board, 'B', 8)) << "Black knight not at B8";
    ASSERT_EQ('b', pieceAt(&board, 'C', 8)) << "Black bishop not at C8";
    ASSERT_EQ('q', pieceAt(&board, 'D', 8)) << "Black queen not at D8";
    ASSERT_EQ('k', pieceAt(&board, 'E', 8)) << "Black king not at E8";
    ASSERT_EQ('b', pieceAt(&board, 'F', 8)) << "Black bishop not at F8";
    ASSERT_EQ('n', pieceAt(&board, 'G', 8)) << "Black knight not at G8";
    ASSERT_EQ('r', pieceAt(&board, 'H', 8)) << "Black rook not at H8";
}

// test movePiece failures
TEST(ChessBoard_movePiece, badInput)
{
    struct ChessBoard board;
    initializeForGame(&board);
    
    ASSERT_EQ(0, movePiece(&board, 'A', 1, 'A', 1)) << "Moving a piece to itself didn't return failure as expected";
    
    // test moving from empty cells fails
    for(char rank = 'A'; rank <= 'H'; rank++)
    {
        for(int file = 3; file <= 6; file++)
        {
            ASSERT_EQ(0, movePiece(&board, rank, file, 'A', 1)) <<  "Trying to move from an empty cell at " << rank << file << " didn't return failure as expected";
        }
    }
    
    ASSERT_EQ(0, movePiece(&board, 'I', 1, 'A', 1)) << "Moving from an invalid cell didn't return failure as expected";
    ASSERT_EQ(0, movePiece(&board, 'B', 1, 'I', 1)) << "Moving to an invalid cell didn't return failure as expected";
}

// test movePiece successes
TEST(ChessBoard_movePiece, goodInput)
{
    struct ChessBoard board;
    initializeForGame(&board);
    
    ASSERT_EQ(1, movePiece(&board, 'E', 2, 'E', 4)) << "Moving piece from valid location to another valid location didn't return success.";
    ASSERT_EQ(' ', pieceAt(&board, 'E', 2)) << "After moving king's pawn, the old space wasn't empty";
    ASSERT_EQ('P', pieceAt(&board, 'E', 4)) << "After moving pawn, the new location didn't contain the pawn";
    
    // move black's queen's pawn to take this pawn - impossible move, but movePiece doesn't check
    ASSERT_EQ(1, movePiece(&board, 'D', 7, 'E', 4)) << "Moving piece from valid location to another valid location didn't return success.";
    ASSERT_EQ(' ', pieceAt(&board, 'D', 7)) << "After moving pawn, the old space wasn't empty";
    ASSERT_EQ('p', pieceAt(&board, 'E', 4)) << "After moving pawn, the new location didn't contain the pawn";
}