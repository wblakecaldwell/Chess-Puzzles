//
//  ChessBoard_PawnTests.cpp
//  ChessPuzzlesLibrary
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
        helperAddValidLocation(expectedValidLocations, R3, file);
        helperAddValidLocation(expectedValidLocations, R4, file);
        
        ASSERT_EQ(2, validMoves(&board, R2, file, validLocations));
        ASSERT_STREQ(expectedValidLocations, validLocations);
    }
    
    // try each black pawn
    for(file = A; file <= H; file++)
    {
        // build up our resulted valid expections
        helperEmptyValidLocations(expectedValidLocations);
        helperAddValidLocation(expectedValidLocations, R6, file);
        helperAddValidLocation(expectedValidLocations, R5, file);
        
        ASSERT_EQ(2, validMoves(&board, R7, file, validLocations));
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
    movePiece(&board, R2, D, R6, D);
    helperSetValidLocations(expectedValidLocations, (const char*[]){"C7", "E7", 0}); // note: replace E8 with E7
    ASSERT_EQ(2, validMoves(&board, R6, D, validLocations));
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
    movePiece(&board, R2, D, R6, D);
    
    // remove piece at D7, so we can move forward
    setPiece(&board, ' ', R7, D);
    
    helperEmptyValidLocations(expectedValidLocations);
    helperAddValidLocation(expectedValidLocations, R7, C);
    helperAddValidLocation(expectedValidLocations, R7, D);
    helperAddValidLocation(expectedValidLocations, R7, E);
    ASSERT_EQ(3, validMoves(&board, R6, D, validLocations));
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
    movePiece(&board, R2, D, R6, D);
    
    // remove pieces at D7 and E7 so we can move forward, and lose right attack
    setPiece(&board, ' ', R7, D);
    setPiece(&board, ' ', R7, E);
    
    helperEmptyValidLocations(expectedValidLocations);
    helperAddValidLocation(expectedValidLocations, R7, C);
    helperAddValidLocation(expectedValidLocations, R7, D);
    ASSERT_EQ(2, validMoves(&board, R6, D, validLocations));
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
    movePiece(&board, R2, D, R6, D);
    
    // remove pieces at C7 and D7 so we can move forward and lose left attack
    setPiece(&board, ' ', R7, C);
    setPiece(&board, ' ', R7, D);
    
    helperEmptyValidLocations(expectedValidLocations);
    helperAddValidLocation(expectedValidLocations, R7, D);
    helperAddValidLocation(expectedValidLocations, R7, E);
    ASSERT_EQ(2, validMoves(&board, R6, D, validLocations));
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
    movePiece(&board, R2, D, R6, D);
    
    // remove right attack
    setPiece(&board, ' ', R7, E);
    
    helperEmptyValidLocations(expectedValidLocations);
    helperAddValidLocation(expectedValidLocations, R7, C);
    ASSERT_EQ(1, validMoves(&board, R6, D, validLocations));
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
    movePiece(&board, R2, D, R6, D);
    
    // remove left attack
    setPiece(&board, ' ', R7, C);
    
    helperEmptyValidLocations(expectedValidLocations);
    helperAddValidLocation(expectedValidLocations, R7, E);
    ASSERT_EQ(1, validMoves(&board, R6, D, validLocations));
    ASSERT_STREQ(expectedValidLocations, validLocations);
}
