//
//  ChessBoard_WhitePawnTests.cpp
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
TEST(ChessBoard_validMoves, whitePawnsWithFreshBoard)
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
        
        ASSERT_EQ(2, validMoves(&board, file, R2, VALID_MOVE, validLocations)) << "Expected 2 moves for white pawn at file: " << file;
        ASSERT_STREQ(expectedValidLocations, validLocations);
    }
}

// test validMoves for a white pawn with two attacks and no move forward
TEST(ChessBoard_validMoves, whitePawnWithTwoAttacksAndNoForward)
{
    enum ChessBoardRank rank;               // rank of the piece we're watching
    enum ChessBoardFile file;               // file of the piece we're watching
    struct ChessBoard board;
    char expectedValidLocations[65];        // what we expect the valid moves to be
    int numberOfExpectedLocations;          // expected number of valid moves
    char validLocations[65];                // the valid moves that are determined
    
    numberOfExpectedLocations = parseTestingBoard((char [][8][8])
                                                  {
                                                      {" r "," n "," b "," q "," k "," b "," n "," r "},
                                                      {" p "," p ","[p]"," p ","[p]"," p "," p "," p "},
                                                      {"   ","   ","   ","(P)","   ","   ","   ","   "},
                                                      {"   ","   ","   ","   ","   ","   ","   ","   "},
                                                      {"   ","   ","   ","   ","   ","   ","   ","   "},
                                                      {"   ","   ","   ","   ","   ","   ","   ","   "},
                                                      {" P "," P "," P ","   "," P "," P "," P "," P "},
                                                      {" R "," N "," B "," Q "," K "," B "," N "," R "}
                                                  }, &board, expectedValidLocations, &file, &rank, true);
    
    // perform SUT and check that it returned the proper number of valid locations
    ASSERT_EQ(numberOfExpectedLocations, validMoves(&board, file, rank, VALID_MOVE, validLocations));
    
    // compare the evaluated valid locations
    ASSERT_STREQ(expectedValidLocations, validLocations);
}

// test validMoves for a white pawn with two attacks and valid move forward
TEST(ChessBoard_validMoves, whitePawnWithTwoAttacksAndEmptySpaceInFront)
{
    enum ChessBoardRank rank;               // rank of the piece we're watching
    enum ChessBoardFile file;               // file of the piece we're watching
    struct ChessBoard board;
    char expectedValidLocations[65];        // what we expect the valid moves to be
    int numberOfExpectedLocations;          // expected number of valid moves
    char validLocations[65];                // the valid moves that are determined
    
    numberOfExpectedLocations = parseTestingBoard((char [][8][8])
                                                  {
                                                      {" r "," n "," b "," q "," k "," b "," n "," r "},
                                                      {" p "," p ","[p]","[ ]","[p]"," p "," p "," p "},
                                                      {"   ","   ","   ","(P)","   ","   ","   ","   "},
                                                      {"   ","   ","   ","   ","   ","   ","   ","   "},
                                                      {"   ","   ","   ","   ","   ","   ","   ","   "},
                                                      {"   ","   ","   ","   ","   ","   ","   ","   "},
                                                      {" P "," P "," P ","   "," P "," P "," P "," P "},
                                                      {" R "," N "," B "," Q "," K "," B "," N "," R "}
                                                  }, &board, expectedValidLocations, &file, &rank, true);
    
    // perform SUT and check that it returned the proper number of valid locations
    ASSERT_EQ(numberOfExpectedLocations, validMoves(&board, file, rank, VALID_MOVE, validLocations));
    
    // compare the evaluated valid locations
    ASSERT_STREQ(expectedValidLocations, validLocations);
}

// test validMoves for a white pawn with left attack and valid move forward
TEST(ChessBoard_validMoves, whitePawnWithLeftAttackAndEmptySpaceInFront)
{
    enum ChessBoardRank rank;               // rank of the piece we're watching
    enum ChessBoardFile file;               // file of the piece we're watching
    struct ChessBoard board;
    char expectedValidLocations[65];        // what we expect the valid moves to be
    int numberOfExpectedLocations;          // expected number of valid moves
    char validLocations[65];                // the valid moves that are determined
    
    numberOfExpectedLocations = parseTestingBoard((char [][8][8])
                                                  {
                                                      {" r "," n "," b "," q "," k "," b "," n "," r "},
                                                      {" p "," p ","[p]","[ ]","   "," p "," p "," p "},
                                                      {"   ","   ","   ","(P)","   ","   ","   ","   "},
                                                      {"   ","   ","   ","   ","   ","   ","   ","   "},
                                                      {"   ","   ","   ","   ","   ","   ","   ","   "},
                                                      {"   ","   ","   ","   ","   ","   ","   ","   "},
                                                      {" P "," P "," P ","   "," P "," P "," P "," P "},
                                                      {" R "," N "," B "," Q "," K "," B "," N "," R "}
                                                  }, &board, expectedValidLocations, &file, &rank, true);
    
    // perform SUT and check that it returned the proper number of valid locations
    ASSERT_EQ(numberOfExpectedLocations, validMoves(&board, file, rank, VALID_MOVE, validLocations));
    
    // compare the evaluated valid locations
    ASSERT_STREQ(expectedValidLocations, validLocations);
}

// test validMoves for a white pawn with right attack and valid move forward
TEST(ChessBoard_validMoves, whitePawnWithRightAttackAndEmptySpaceInFront)
{
    enum ChessBoardRank rank;               // rank of the piece we're watching
    enum ChessBoardFile file;               // file of the piece we're watching
    struct ChessBoard board;
    char expectedValidLocations[65];        // what we expect the valid moves to be
    int numberOfExpectedLocations;          // expected number of valid moves
    char validLocations[65];                // the valid moves that are determined
    
    numberOfExpectedLocations = parseTestingBoard((char [][8][8])
                                                  {
                                                      {" r "," n "," b "," q "," k "," b "," n "," r "},
                                                      {" p "," p ","   ","[ ]","[p]"," p "," p "," p "},
                                                      {"   ","   ","   ","(P)","   ","   ","   ","   "},
                                                      {"   ","   ","   ","   ","   ","   ","   ","   "},
                                                      {"   ","   ","   ","   ","   ","   ","   ","   "},
                                                      {"   ","   ","   ","   ","   ","   ","   ","   "},
                                                      {" P "," P "," P ","   "," P "," P "," P "," P "},
                                                      {" R "," N "," B "," Q "," K "," B "," N "," R "}
                                                  }, &board, expectedValidLocations, &file, &rank, true);
    
    // perform SUT and check that it returned the proper number of valid locations
    ASSERT_EQ(numberOfExpectedLocations, validMoves(&board, file, rank, VALID_MOVE, validLocations));
    
    // compare the evaluated valid locations
    ASSERT_STREQ(expectedValidLocations, validLocations);
}

// test validMoves for a white pawn with right attack and valid move forward
TEST(ChessBoard_validMoves, whitePawnWithRightAttackAndEmptySpaceInFront2)
{
    enum ChessBoardRank rank;               // rank of the piece we're watching
    enum ChessBoardFile file;               // file of the piece we're watching
    struct ChessBoard board;
    char expectedValidLocations[65];        // what we expect the valid moves to be
    int numberOfExpectedLocations;          // expected number of valid moves
    char validLocations[65];                // the valid moves that are determined
    
    numberOfExpectedLocations = parseTestingBoard((char [][8][8])
                                                  {
                                                      {" r "," n "," b "," q "," k "," b "," n "," r "},
                                                      {" p "," p "," Q ","[ ]","[p]"," p "," p "," p "},
                                                      {"   ","   ","   ","(P)","   ","   ","   ","   "},
                                                      {"   ","   ","   ","   ","   ","   ","   ","   "},
                                                      {"   ","   ","   ","   ","   ","   ","   ","   "},
                                                      {"   ","   ","   ","   ","   ","   ","   ","   "},
                                                      {" P "," P "," P ","   "," P "," P "," P "," P "},
                                                      {" R "," N "," B "," Q "," K "," B "," N "," R "}
                                                  }, &board, expectedValidLocations, &file, &rank, true);
    
    // perform SUT and check that it returned the proper number of valid locations
    ASSERT_EQ(numberOfExpectedLocations, validMoves(&board, file, rank, VALID_MOVE, validLocations));
    
    // compare the evaluated valid locations
    ASSERT_STREQ(expectedValidLocations, validLocations);
}

// test validMoves for a white pawn with left attack and no move forward
TEST(ChessBoard_validMoves, whitePawnWithLeftAttackAndNoForward)
{
    enum ChessBoardRank rank;               // rank of the piece we're watching
    enum ChessBoardFile file;               // file of the piece we're watching
    struct ChessBoard board;
    char expectedValidLocations[65];        // what we expect the valid moves to be
    int numberOfExpectedLocations;          // expected number of valid moves
    char validLocations[65];                // the valid moves that are determined
    
    numberOfExpectedLocations = parseTestingBoard((char [][8][8])
                                                  {
                                                      {" r "," n "," b "," q "," k "," b "," n "," r "},
                                                      {" p "," p ","[p]"," p ","   "," p "," p "," p "},
                                                      {"   ","   ","   ","(P)","   ","   ","   ","   "},
                                                      {"   ","   ","   ","   ","   ","   ","   ","   "},
                                                      {"   ","   ","   ","   ","   ","   ","   ","   "},
                                                      {"   ","   ","   ","   ","   ","   ","   ","   "},
                                                      {" P "," P "," P ","   "," P "," P "," P "," P "},
                                                      {" R "," N "," B "," Q "," K "," B "," N "," R "}
                                                  }, &board, expectedValidLocations, &file, &rank, true);
    
    // perform SUT and check that it returned the proper number of valid locations
    ASSERT_EQ(numberOfExpectedLocations, validMoves(&board, file, rank, VALID_MOVE, validLocations));
    
    // compare the evaluated valid locations
    ASSERT_STREQ(expectedValidLocations, validLocations);
}

// test validMoves for a white pawn with right attack and no move forward
TEST(ChessBoard_validMoves, whitePawnWithRightAttackAndNoForward)
{
    enum ChessBoardRank rank;               // rank of the piece we're watching
    enum ChessBoardFile file;               // file of the piece we're watching
    struct ChessBoard board;
    char expectedValidLocations[65];        // what we expect the valid moves to be
    int numberOfExpectedLocations;          // expected number of valid moves
    char validLocations[65];                // the valid moves that are determined
    
    numberOfExpectedLocations = parseTestingBoard((char [][8][8])
                                                  {
                                                      {" r "," n "," b "," q "," k "," b "," n "," r "},
                                                      {" p "," p ","   "," p ","[p]"," p "," p "," p "},
                                                      {"   ","   ","   ","(P)","   ","   ","   ","   "},
                                                      {"   ","   ","   ","   ","   ","   ","   ","   "},
                                                      {"   ","   ","   ","   ","   ","   ","   ","   "},
                                                      {"   ","   ","   ","   ","   ","   ","   ","   "},
                                                      {" P "," P "," P ","   "," P "," P "," P "," P "},
                                                      {" R "," N "," B "," Q "," K "," B "," N "," R "}
                                                  }, &board, expectedValidLocations, &file, &rank, true);
    
    // perform SUT and check that it returned the proper number of valid locations
    ASSERT_EQ(numberOfExpectedLocations, validMoves(&board, file, rank, VALID_MOVE, validLocations));
    
    // compare the evaluated valid locations
    ASSERT_STREQ(expectedValidLocations, validLocations);
}


// test validMoves for white pawn with nowhere to go
TEST(ChessBoard_validMoves, whitePawnWithNowhereToGo)
{
    enum ChessBoardRank rank;               // rank of the piece we're watching
    enum ChessBoardFile file;               // file of the piece we're watching
    struct ChessBoard board;
    char expectedValidLocations[65];        // what we expect the valid moves to be
    int numberOfExpectedLocations;          // expected number of valid moves
    char validLocations[65];                // the valid moves that are determined
    
    numberOfExpectedLocations = parseTestingBoard((char [][8][8])
                                                  {
                                                      {" r "," n "," b "," q "," k "," b "," n "," r "},
                                                      {" p "," p ","   "," p ","   "," p "," p "," p "},
                                                      {"   ","   ","   ","(P)","   ","   ","   ","   "},
                                                      {"   ","   ","   ","   ","   ","   ","   ","   "},
                                                      {"   ","   ","   ","   ","   ","   ","   ","   "},
                                                      {"   ","   ","   ","   ","   ","   ","   ","   "},
                                                      {" P "," P "," P ","   "," P "," P "," P "," P "},
                                                      {" R "," N "," B "," Q "," K "," B "," N "," R "}
                                                  }, &board, expectedValidLocations, &file, &rank, true);
    
    // perform SUT and check that it returned the proper number of valid locations
    ASSERT_EQ(numberOfExpectedLocations, validMoves(&board, file, rank, VALID_MOVE, validLocations));
    
    // compare the evaluated valid locations
    ASSERT_STREQ(expectedValidLocations, validLocations);
}

// test validMoves for pawn with attack from A file
TEST(ChessBoard_validMoves, whitePawnWithAttackOnAFile)
{
    enum ChessBoardRank rank;               // rank of the piece we're watching
    enum ChessBoardFile file;               // file of the piece we're watching
    struct ChessBoard board;
    char expectedValidLocations[65];        // what we expect the valid moves to be
    int numberOfExpectedLocations;          // expected number of valid moves
    char validLocations[65];                // the valid moves that are determined
    
    numberOfExpectedLocations = parseTestingBoard((char [][8][8])
                                                  {
                                                      {" r "," n "," b "," q "," k "," b "," n "," r "},
                                                      {" p ","[p]"," p "," p "," p "," p "," p "," p "},
                                                      {"(P)","   ","   ","   ","   ","   ","   ","   "},
                                                      {"   ","   ","   ","   ","   ","   ","   ","   "},
                                                      {"   ","   ","   ","   ","   ","   ","   ","   "},
                                                      {"   ","   ","   ","   ","   ","   ","   ","   "},
                                                      {"   "," P "," P "," P "," P "," P "," P "," P "},
                                                      {" R "," N "," B "," Q "," K "," B "," N "," R "}
                                                  }, &board, expectedValidLocations, &file, &rank, true);
    
    // perform SUT and check that it returned the proper number of valid locations
    ASSERT_EQ(numberOfExpectedLocations, validMoves(&board, file, rank, VALID_MOVE, validLocations));
    
    // compare the evaluated valid locations
    ASSERT_STREQ(expectedValidLocations, validLocations);
}

// test validMoves for pawn with attack from H file
TEST(ChessBoard_validMoves, whitePawnWithAttackOnHFile)
{
    enum ChessBoardRank rank;               // rank of the piece we're watching
    enum ChessBoardFile file;               // file of the piece we're watching
    struct ChessBoard board;
    char expectedValidLocations[65];        // what we expect the valid moves to be
    int numberOfExpectedLocations;          // expected number of valid moves
    char validLocations[65];                // the valid moves that are determined
    
    numberOfExpectedLocations = parseTestingBoard((char [][8][8])
                                                  {
                                                      {" r "," n "," b "," q "," k "," b "," n "," r "},
                                                      {" p "," p "," p "," p "," p "," p ","[p]"," p "},
                                                      {"   ","   ","   ","   ","   ","   ","   ","(P)"},
                                                      {"   ","   ","   ","   ","   ","   ","   ","   "},
                                                      {"   ","   ","   ","   ","   ","   ","   ","   "},
                                                      {"   ","   ","   ","   ","   ","   ","   ","   "},
                                                      {" P "," P "," P "," P "," P "," P "," P "," P "},
                                                      {" R "," N "," B "," Q "," K "," B "," N "," R "}
                                                  }, &board, expectedValidLocations, &file, &rank, true);
    
    // perform SUT and check that it returned the proper number of valid locations
    ASSERT_EQ(numberOfExpectedLocations, validMoves(&board, file, rank, VALID_MOVE, validLocations));
    
    // compare the evaluated valid locations
    ASSERT_STREQ(expectedValidLocations, validLocations);
}