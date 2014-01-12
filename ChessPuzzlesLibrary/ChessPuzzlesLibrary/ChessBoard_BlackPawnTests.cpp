//
//  ChessBoard_BlackPawnTests.cpp
//  ChessPuzzlesLibrary
//
//  Tests to assert valid moves for black pawns.
//
//  Created by Blake Caldwell on 1/11/14.
//  Copyright (c) 2014 Blake Caldwell. All rights reserved.
//

#include <stdio.h>
#include <gtest/gtest.h>
#include "ChessBoardTestHelpers.h"
extern "C" {
    #include "ChessBoard.h"
}

// test validMoves for pawns on a fresh board
TEST(ChessBoard_validMoves, blackPawnsWithFreshBoard)
{
    struct ChessBoard board;
    ChessBoardFile file;
    char validLocations[65];
    char expectedValidLocations[65];
    
    // testing with a fresh board
    initializeForGame(&board);
    
    // try each black pawn
    for(file = A; file <= H; file++)
    {
        // build up our resulted valid expections
        helperEmptyValidLocations(expectedValidLocations);
        helperAddValidLocation(expectedValidLocations, file, R6);
        helperAddValidLocation(expectedValidLocations, file, R5);
        
        ASSERT_EQ(2, validMoves(&board, file, R7, validLocations));
        ASSERT_STREQ(expectedValidLocations, validLocations);
    }
}

// test validMoves for a black pawn with two attacks and no move forward
TEST(ChessBoard_validMoves, blackPawnWithTwoAttacksAndNoForward)
{
    struct ChessBoard board;
    char validLocations[65];
    char expectedValidLocations[65];
    
    // testing with a fresh board
    initializeForGame(&board);
    
    // move black pawn to d3 - should have two moves, attacking
    movePiece(&board, D, R7, D, R3);
    helperSetValidLocations(expectedValidLocations, (const char*[]){"C2", "E2", 0}); // note: replace E8 with E7
    ASSERT_EQ(2, validMoves(&board, D, R3, validLocations));
    ASSERT_STREQ(expectedValidLocations, validLocations);
}

// test validMoves for a black pawn with two attacks and valid move forward
TEST(ChessBoard_validMoves, blackPawnWithTwoAttacksAndEmptySpaceInFront)
{
    struct ChessBoard board;
    char validLocations[65];
    char expectedValidLocations[65];
    
    // testing with a fresh board
    initializeForGame(&board);
    
    // move black pawn to d3
    movePiece(&board, D, R7, D, R3);
    
    // remove piece at D2, so we can move forward
    setPiece(&board, ' ', D, R2);
    
    helperSetValidLocations(expectedValidLocations, (const char*[]){"C2", "D2", "E2", 0});
    ASSERT_EQ(3, validMoves(&board, D, R3, validLocations));
    ASSERT_STREQ(expectedValidLocations, validLocations);
}

// test validMoves for a black pawn with left attack and valid move forward
TEST(ChessBoard_validMoves, blackPawnWithLeftAttackAndEmptySpaceInFront)
{
    struct ChessBoard board;
    char validLocations[65];
    char expectedValidLocations[65];
    
    // testing with a fresh board
    initializeForGame(&board);
    
    // move black pawn to d3
    movePiece(&board, D, R7, D, R3);
    
    // remove pieces at D2 and E2 so we can move forward, and lose right attack
    setPiece(&board, ' ', D, R2);
    setPiece(&board, ' ', E, R2);
    
    helperSetValidLocations(expectedValidLocations, (const char*[]){"C2", "D2", 0});
    ASSERT_EQ(2, validMoves(&board, D, R3, validLocations));
    ASSERT_STREQ(expectedValidLocations, validLocations);
}

// test validMoves for a black pawn with right attack and valid move forward
TEST(ChessBoard_validMoves, blackPawnWithRightAttackAndEmptySpaceInFront)
{
    struct ChessBoard board;
    char validLocations[65];
    char expectedValidLocations[65];
    
    // testing with a fresh board
    initializeForGame(&board);
    
    // move black pawn to d3
    movePiece(&board, D, R7, D, R3);
    
    // remove pieces at C2 and D2 so we can move forward, and lose left attack
    setPiece(&board, ' ', C, R2);
    setPiece(&board, ' ', D, R2);
    
    helperSetValidLocations(expectedValidLocations, (const char*[]){"D2", "E2", 0});
    ASSERT_EQ(2, validMoves(&board, D, R3, validLocations));
    ASSERT_STREQ(expectedValidLocations, validLocations);
}

// test validMoves for a black pawn with left attack and no move forward
TEST(ChessBoard_validMoves, blackPawnWithLeftAttackAndNoForward)
{
    struct ChessBoard board;
    char validLocations[65];
    char expectedValidLocations[65];
    
    // testing with a fresh board
    initializeForGame(&board);
    
    // move black pawn to d3
    movePiece(&board, D, R7, D, R3);
    
    // remove right attack
    setPiece(&board, ' ', E, R2);
    
    helperSetValidLocations(expectedValidLocations, (const char*[]){"C2", 0});
    ASSERT_EQ(1, validMoves(&board, D, R3, validLocations));
    ASSERT_STREQ(expectedValidLocations, validLocations);
}

// test validMoves for a black pawn with right attack and no move forward
TEST(ChessBoard_validMoves, blackPawnWithRightAttackAndNoForward)
{
    struct ChessBoard board;
    char validLocations[65];
    char expectedValidLocations[65];
    
    // testing with a fresh board
    initializeForGame(&board);
    
    // move black pawn to d3
    movePiece(&board, D, R7, D, R3);
    
    // remove left attack
    setPiece(&board, ' ', C, R2);
    
    helperSetValidLocations(expectedValidLocations, (const char*[]){"E2", 0});
    ASSERT_EQ(1, validMoves(&board, D, R3, validLocations));
    ASSERT_STREQ(expectedValidLocations, validLocations);
}


// test validMoves for pawn with nowhere to go
TEST(ChessBoard_validMoves, blackPawnWithNowhereToGo)
{
    struct ChessBoard board;
    char validLocations[65];
    char expectedLocations[65];
    
    initializeEmpty(&board);
    
    // two pawns on the same file, then make sure the one in back can't move
    setPiece(&board, 'p', D, R5);
    setPiece(&board, 'p', D, R6);
    
    // no moves expected
    helperEmptyValidLocations(expectedLocations);
    ASSERT_EQ(0, validMoves(&board, D, R6, validLocations));
    ASSERT_STREQ(expectedLocations, validLocations);
}