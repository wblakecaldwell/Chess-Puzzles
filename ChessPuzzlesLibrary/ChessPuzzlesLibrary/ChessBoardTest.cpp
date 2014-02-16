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
    int ret;
    
    ret = initializeForGame(&board);
    
    ASSERT_EQ(1, ret);
    ASSERT_STREQ("RNBQKBNRPPPPPPPP                                pppppppprnbqkbnr", board.pieces) << "Chess board pieces not stored as expected";
}

// test initializeWithPieces
TEST(ChessBoard_initializeWithPieces, success)
{
    struct ChessBoard board;
    int ret;
    
    ret = initializeWithPieces(&board, (const char*[])
            {"rnbqkbnr",
             "pppppppp",
             "        ",
             "        ",
             "        ",
             "        ",
             "PPPPPPPP",
             "RNBQKBNR"});

    ASSERT_EQ(1, ret);
    ASSERT_STREQ("RNBQKBNRPPPPPPPP                                pppppppprnbqkbnr", board.pieces) << "Chess board pieces not stored as expected";
}

// test boardArrayToBoardString
//TEST(ChessBoard_boardArrayToBoardString, success)
//{
//    int ret;
//    char boardStr[65];
//    char *boardArray[8];
//    
//    ret = boardArrayToBoardString(boardArray, boardStr);
//    
//    ASSERT_EQ(1, ret);
//    ASSERT_STREQ("RNBQKBNRPPPPPPPP                                pppppppprnbqkbnr", boardStr) << "Chess board pieces not stored as expected";
//
//}

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
            ASSERT_EQ(' ', pieceAt(&board, file, rank)) << rank << file << " not empty";
        }
    }
    
    // check the pawns
    for(file = A; file <= H; file++)
    {
        // white
        ASSERT_EQ('P', pieceAt(&board, file, R2)) << rank << 2 << " not a white pawn";
        
        // black
        ASSERT_EQ('p', pieceAt(&board, file, R7)) << rank << 7 << " not a black pawn";
    }
    
    // white pieces
    ASSERT_EQ('R', pieceAt(&board, A, R1)) << "White rook not at A1";
    ASSERT_EQ('N', pieceAt(&board, B, R1)) << "White knight not at B1";
    ASSERT_EQ('B', pieceAt(&board, C, R1)) << "White bishop not at C1";
    ASSERT_EQ('Q', pieceAt(&board, D, R1)) << "White queen not at D1";
    ASSERT_EQ('K', pieceAt(&board, E, R1)) << "White king not at E1";
    ASSERT_EQ('B', pieceAt(&board, F, R1)) << "White bishop not at F1";
    ASSERT_EQ('N', pieceAt(&board, G, R1)) << "White knight not at G1";
    ASSERT_EQ('R', pieceAt(&board, H, R1)) << "White rook not at H1";
    
    // black pieces
    ASSERT_EQ('r', pieceAt(&board, A, R8)) << "Black rook not at A8";
    ASSERT_EQ('n', pieceAt(&board, B, R8)) << "Black knight not at B8";
    ASSERT_EQ('b', pieceAt(&board, C, R8)) << "Black bishop not at C8";
    ASSERT_EQ('q', pieceAt(&board, D, R8)) << "Black queen not at D8";
    ASSERT_EQ('k', pieceAt(&board, E, R8)) << "Black king not at E8";
    ASSERT_EQ('b', pieceAt(&board, F, R8)) << "Black bishop not at F8";
    ASSERT_EQ('n', pieceAt(&board, G, R8)) << "Black knight not at G8";
    ASSERT_EQ('r', pieceAt(&board, H, R8)) << "Black rook not at H8";
}

// test movePiece failures
TEST(ChessBoard_movePiece, badInput)
{
    enum ChessBoardRank rank;
    enum ChessBoardFile file;
    struct ChessBoard board;
    
    initializeForGame(&board);
    
    ASSERT_EQ(0, movePiece(&board, A, R1, A, R1)) << "Moving a piece to itself didn't return failure as expected";
    
    // test moving from empty cells fails
    for(file = A; file <= H; file++)
    {
        for(rank = R3; rank <= R6; rank++)
        {
            ASSERT_EQ(0, movePiece(&board, file, rank, A, R1)) <<  "Trying to move from an empty cell at " << file << rank << " didn't return failure as expected";
        }
    }
}

// test movePiece successes
TEST(ChessBoard_movePiece, goodInput)
{
    struct ChessBoard board;
    initializeForGame(&board);
    
    ASSERT_EQ(1, movePiece(&board, E, R2, E, R4)) << "Moving piece from valid location to another valid location didn't return success.";
    ASSERT_EQ(' ', pieceAt(&board, E, R2)) << "After moving king's pawn, the old space wasn't empty";
    ASSERT_EQ('P', pieceAt(&board, E, R4)) << "After moving pawn, the new location didn't contain the pawn";
    
    // move black's queen's pawn to take this pawn - impossible move, but movePiece doesn't check
    ASSERT_EQ(1, movePiece(&board, D, R7, E, R4)) << "Moving piece from valid location to another valid location didn't return success.";
    ASSERT_EQ(' ', pieceAt(&board, D, R7)) << "After moving pawn, the old space wasn't empty";
    ASSERT_EQ('p', pieceAt(&board, E, R4)) << "After moving pawn, the new location didn't contain the pawn";
}

