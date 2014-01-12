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
#include "ChessBoardTestHelpers.h"
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
TEST(ChessBoard_pieceAt, goodInput)
{
    struct ChessBoard board;
    enum ChessBoardRank rank;
    enum ChessBoardFile file;
    
    initializeForGame(&board);
    
    // check the empty cells
    for(rank = R3; rank <= R6; rank++)
    {
        for(file = A; file <= H; file++)
        {
            ASSERT_EQ(' ', pieceAt(&board, rank, file)) << rank << file << " not empty";
        }
    }
    
    // check the pawns
    for(file = A; file <= H; file++)
    {
        // white
        ASSERT_EQ('P', pieceAt(&board, R2, file)) << rank << 2 << " not a white pawn";
        
        // black
        ASSERT_EQ('p', pieceAt(&board, R7, file)) << rank << 7 << " not a black pawn";
    }
    
    // white pieces
    ASSERT_EQ('R', pieceAt(&board, R1, A)) << "White rook not at A1";
    ASSERT_EQ('N', pieceAt(&board, R1, B)) << "White knight not at B1";
    ASSERT_EQ('B', pieceAt(&board, R1, C)) << "White bishop not at C1";
    ASSERT_EQ('Q', pieceAt(&board, R1, D)) << "White queen not at D1";
    ASSERT_EQ('K', pieceAt(&board, R1, E)) << "White king not at E1";
    ASSERT_EQ('B', pieceAt(&board, R1, F)) << "White bishop not at F1";
    ASSERT_EQ('N', pieceAt(&board, R1, G)) << "White knight not at G1";
    ASSERT_EQ('R', pieceAt(&board, R1, H)) << "White rook not at H1";
    
    // black pieces
    ASSERT_EQ('r', pieceAt(&board, R8, A)) << "Black rook not at A8";
    ASSERT_EQ('n', pieceAt(&board, R8, B)) << "Black knight not at B8";
    ASSERT_EQ('b', pieceAt(&board, R8, C)) << "Black bishop not at C8";
    ASSERT_EQ('q', pieceAt(&board, R8, D)) << "Black queen not at D8";
    ASSERT_EQ('k', pieceAt(&board, R8, E)) << "Black king not at E8";
    ASSERT_EQ('b', pieceAt(&board, R8, F)) << "Black bishop not at F8";
    ASSERT_EQ('n', pieceAt(&board, R8, G)) << "Black knight not at G8";
    ASSERT_EQ('r', pieceAt(&board, R8, H)) << "Black rook not at H8";
}

// test movePiece failures
TEST(ChessBoard_movePiece, badInput)
{
    enum ChessBoardRank rank;
    enum ChessBoardFile file;
    struct ChessBoard board;
    
    initializeForGame(&board);
    
    ASSERT_EQ(0, movePiece(&board, R1, A, R1, A)) << "Moving a piece to itself didn't return failure as expected";
    
    // test moving from empty cells fails
    for(file = A; file <= H; file++)
    {
        for(rank = R3; rank <= R6; rank++)
        {
            ASSERT_EQ(0, movePiece(&board, rank, file, R1, A)) <<  "Trying to move from an empty cell at " << file << rank << " didn't return failure as expected";
        }
    }
}

// test movePiece successes
TEST(ChessBoard_movePiece, goodInput)
{
    struct ChessBoard board;
    initializeForGame(&board);
    
    ASSERT_EQ(1, movePiece(&board, R2, E, R4, E)) << "Moving piece from valid location to another valid location didn't return success.";
    ASSERT_EQ(' ', pieceAt(&board, R2, E)) << "After moving king's pawn, the old space wasn't empty";
    ASSERT_EQ('P', pieceAt(&board, R4, E)) << "After moving pawn, the new location didn't contain the pawn";
    
    // move black's queen's pawn to take this pawn - impossible move, but movePiece doesn't check
    ASSERT_EQ(1, movePiece(&board, R7, D, R4, E)) << "Moving piece from valid location to another valid location didn't return success.";
    ASSERT_EQ(' ', pieceAt(&board, R7, D)) << "After moving pawn, the old space wasn't empty";
    ASSERT_EQ('p', pieceAt(&board, R4, E)) << "After moving pawn, the new location didn't contain the pawn";
}




// test validMoves for pawns with nowhere to go
TEST(ChessBoard_validMoves, pawnsWithNowhereToGo)
{
    // TODO
}