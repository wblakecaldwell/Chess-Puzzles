//
//  ChessBoard_PawnTests.cpp
//  ChessPuzzlesLibrary
//
//  Tests to assert valid moves for white pawns.
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
TEST(ChessBoard_validMoves, pawnsWithFreshBoard)
{
    struct ChessBoard board;
    ChessBoardFile file;
    char validLocations[65];
    char expectedValidLocations[65];
    
    // testing with a fresh board
    initializeForGame(&board);
    
    // try each white pawn
    for(file = A; file <= H; file++)
    {
        // build up our resulted valid expections
        helperEmptyValidLocations(expectedValidLocations);
        helperAddValidLocation(expectedValidLocations, file, R3);
        helperAddValidLocation(expectedValidLocations, file, R4);
        
        ASSERT_EQ(2, validMoves(&board, file, R2, validLocations)) << "Expected 2 moves for white pawn at file: " << file;
        ASSERT_STREQ(expectedValidLocations, validLocations);
    }
    
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

// test validMoves for a white pawn with two attacks and no move forward
TEST(ChessBoard_validMoves, whitePawnWithTwoAttacksAndNoForward)
{
    struct ChessBoard board;
    char validLocations[65];
    char expectedValidLocations[65];
    
    // testing with a fresh board
    initializeForGame(&board);
    
    // move white pawn to d6 - should have two moves, attacking
    movePiece(&board, D, R2, D, R6);
    helperSetValidLocations(expectedValidLocations, (const char*[]){"C7", "E7", 0}); // note: replace E8 with E7
    ASSERT_EQ(2, validMoves(&board, D, R6, validLocations));
    ASSERT_STREQ(expectedValidLocations, validLocations);
}

// test validMoves for a white pawn with two attacks and valid move forward
TEST(ChessBoard_validMoves, whitePawnWithTwoAttacksAndEmptySpaceInFront)
{
    struct ChessBoard board;
    char validLocations[65];
    char expectedValidLocations[65];
    
    // testing with a fresh board
    initializeForGame(&board);
    
    // move white pawn to d6 - should have two moves, attacking
    movePiece(&board, D, R2, D, R6);
    
    // remove piece at D7, so we can move forward
    setPiece(&board, ' ', D, R7);
    
    helperEmptyValidLocations(expectedValidLocations);
    helperAddValidLocation(expectedValidLocations, C, R7);
    helperAddValidLocation(expectedValidLocations, D, R7);
    helperAddValidLocation(expectedValidLocations, E, R7);
    ASSERT_EQ(3, validMoves(&board, D, R6, validLocations));
    ASSERT_STREQ(expectedValidLocations, validLocations);
}

// test validMoves for a white pawn with left attack and valid move forward
TEST(ChessBoard_validMoves, whitePawnWithLeftAttackAndEmptySpaceInFront)
{
    struct ChessBoard board;
    char validLocations[65];
    char expectedValidLocations[65];
    
    // testing with a fresh board
    initializeForGame(&board);
    
    // move white pawn to d6 - should have two moves, attacking
    movePiece(&board, D, R2, D, R6);
    
    // remove pieces at D7 and E7 so we can move forward, and lose right attack
    setPiece(&board, ' ', D, R7);
    setPiece(&board, ' ', E, R7);
    
    helperEmptyValidLocations(expectedValidLocations);
    helperAddValidLocation(expectedValidLocations, C, R7);
    helperAddValidLocation(expectedValidLocations, D, R7);
    ASSERT_EQ(2, validMoves(&board, D, R6, validLocations));
    ASSERT_STREQ(expectedValidLocations, validLocations);
}

// test validMoves for a white pawn with right attack and valid move forward
TEST(ChessBoard_validMoves, whitePawnWithRightAttackAndEmptySpaceInFront)
{
    struct ChessBoard board;
    char validLocations[65];
    char expectedValidLocations[65];
    
    // testing with a fresh board
    initializeForGame(&board);
    
    // move white pawn to d6 - should have two moves, attacking
    movePiece(&board, D, R2, D, R6);
    
    // remove pieces at C7 and D7 so we can move forward and lose left attack
    setPiece(&board, ' ', C, R7);
    setPiece(&board, ' ', D, R7);
    
    helperEmptyValidLocations(expectedValidLocations);
    helperAddValidLocation(expectedValidLocations, D, R7);
    helperAddValidLocation(expectedValidLocations, E, R7);
    ASSERT_EQ(2, validMoves(&board, D, R6, validLocations));
    ASSERT_STREQ(expectedValidLocations, validLocations);
}

// test validMoves for a white pawn with left attack and no move forward
TEST(ChessBoard_validMoves, whitePawnWithLeftAttackAndNoForward)
{
    struct ChessBoard board;
    char validLocations[65];
    char expectedValidLocations[65];
    
    // testing with a fresh board
    initializeForGame(&board);
    
    // move white pawn to d6 - should have two moves, attacking
    movePiece(&board, D, R2, D, R6);
    
    // remove right attack
    setPiece(&board, ' ', E, R7);
    
    helperEmptyValidLocations(expectedValidLocations);
    helperAddValidLocation(expectedValidLocations, C, R7);
    ASSERT_EQ(1, validMoves(&board, D, R6, validLocations));
    ASSERT_STREQ(expectedValidLocations, validLocations);
}

// test validMoves for a white pawn with right attack and no move forward
TEST(ChessBoard_validMoves, whitePawnWithRightAttackAndNoForward)
{
    struct ChessBoard board;
    char validLocations[65];
    char expectedValidLocations[65];
    
    // testing with a fresh board
    initializeForGame(&board);
    
    // move white pawn to d6 - should have two moves, attacking
    movePiece(&board, D, R2, D, R6);
    
    // remove left attack
    setPiece(&board, ' ', C, R7);
    
    helperEmptyValidLocations(expectedValidLocations);
    helperAddValidLocation(expectedValidLocations, E, R7);
    ASSERT_EQ(1, validMoves(&board, D, R6, validLocations));
    ASSERT_STREQ(expectedValidLocations, validLocations);
}


// test validMoves for pawn with nowhere to go
TEST(ChessBoard_validMoves, pawnsWithNowhereToGo)
{
    struct ChessBoard board;
    char validLocations[65];
    char expectedLocations[65];
    
    initializeEmpty(&board);
    
    // two pawns on the same file, then make sure the one in back can't move
    setPiece(&board, 'P', D, R5);
    setPiece(&board, 'P', D, R6);
    
    
    // no moves expected
    helperEmptyValidLocations(expectedLocations);
    ASSERT_EQ(0, validMoves(&board, D, R5, validLocations));
    ASSERT_STREQ(expectedLocations, validLocations);
}