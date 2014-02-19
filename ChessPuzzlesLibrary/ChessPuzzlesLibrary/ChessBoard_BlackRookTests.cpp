//
//  ChessBoard_BlackRookTests.cpp
//  ChessPuzzlesLibrary
//
//  Tests to assert valid moves for black rooks.
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

// test validMoves for left black rook on a fresh board
TEST(ChessBoard_validMoves, leftBlackRookWithFreshBoard)
{
    enum ChessBoardRank rank;               // rank of the piece we're watching
    enum ChessBoardFile file;               // file of the piece we're watching
    struct ChessBoard board;
    char expectedValidLocations[65];        // what we expect the valid moves to be
    int numberOfExpectedLocations;          // expected number of valid moves
    char validLocations[65];                // the valid moves that are determined
    
    numberOfExpectedLocations = parseTestingBoard((char [][8][8])
                                                  {
                                                      {"(r)"," n "," b "," q "," k "," b "," n "," r "},
                                                      {" p "," p "," p "," p "," p "," p "," p "," p "},
                                                      {"   ","   ","   ","   ","   ","   ","   ","   "},
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

// test validMoves for right black rook on a fresh board
TEST(ChessBoard_validMoves, rightBlackRookWithFreshBoard)
{
    enum ChessBoardRank rank;               // rank of the piece we're watching
    enum ChessBoardFile file;               // file of the piece we're watching
    struct ChessBoard board;
    char expectedValidLocations[65];        // what we expect the valid moves to be
    int numberOfExpectedLocations;          // expected number of valid moves
    char validLocations[65];                // the valid moves that are determined
    
    numberOfExpectedLocations = parseTestingBoard((char [][8][8])
                                                  {
                                                      {" r "," n "," b "," q "," k "," b "," n ","(r)"},
                                                      {" p "," p "," p "," p "," p "," p "," p "," p "},
                                                      {"   ","   ","   ","   ","   ","   ","   ","   "},
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

// test validMoves for a black rook in the middle of an empty board, at E3
TEST(ChessBoard_validMoves, blackRookInMiddleOfEmptyBoard)
{
    enum ChessBoardRank rank;               // rank of the piece we're watching
    enum ChessBoardFile file;               // file of the piece we're watching
    struct ChessBoard board;
    char expectedValidLocations[65];        // what we expect the valid moves to be
    int numberOfExpectedLocations;          // expected number of valid moves
    char validLocations[65];                // the valid moves that are determined
    
    numberOfExpectedLocations = parseTestingBoard((char [][8][8])
                                                  {
                                                      {"   ","   ","   ","   ","[ ]","   ","   ","   "},
                                                      {"   ","   ","   ","   ","[ ]","   ","   ","   "},
                                                      {"   ","   ","   ","   ","[ ]","   ","   ","   "},
                                                      {"   ","   ","   ","   ","[ ]","   ","   ","   "},
                                                      {"   ","   ","   ","   ","[ ]","   ","   ","   "},
                                                      {"[ ]","[ ]","[ ]","[ ]","(r)","[ ]","[ ]","[ ]"},
                                                      {"   ","   ","   ","   ","[ ]","   ","   ","   "},
                                                      {"   ","   ","   ","   ","[ ]","   ","   ","   "}
                                                  }, &board, expectedValidLocations, &file, &rank, true);
    
    // perform SUT and check that it returned the proper number of valid locations
    ASSERT_EQ(numberOfExpectedLocations, validMoves(&board, file, rank, VALID_MOVE, validLocations));
    
    // compare the evaluated valid locations
    ASSERT_STREQ(expectedValidLocations, validLocations);
}


// test validMoves for a black rook in the lower left corner of an empty board, at A1
TEST(ChessBoard_validMoves, blackRookLowerLeftCornerOfEmptyBoard)
{
    enum ChessBoardRank rank;               // rank of the piece we're watching
    enum ChessBoardFile file;               // file of the piece we're watching
    struct ChessBoard board;
    char expectedValidLocations[65];        // what we expect the valid moves to be
    int numberOfExpectedLocations;          // expected number of valid moves
    char validLocations[65];                // the valid moves that are determined
    
    numberOfExpectedLocations = parseTestingBoard((char [][8][8])
                                                  {
                                                      {"[ ]","   ","   ","   ","   ","   ","   ","   "},
                                                      {"[ ]","   ","   ","   ","   ","   ","   ","   "},
                                                      {"[ ]","   ","   ","   ","   ","   ","   ","   "},
                                                      {"[ ]","   ","   ","   ","   ","   ","   ","   "},
                                                      {"[ ]","   ","   ","   ","   ","   ","   ","   "},
                                                      {"[ ]","   ","   ","   ","   ","   ","   ","   "},
                                                      {"[ ]","   ","   ","   ","   ","   ","   ","   "},
                                                      {"(r)","[ ]","[ ]","[ ]","[ ]","[ ]","[ ]","[ ]"}
                                                  }, &board, expectedValidLocations, &file, &rank, true);
    
    // perform SUT and check that it returned the proper number of valid locations
    ASSERT_EQ(numberOfExpectedLocations, validMoves(&board, file, rank, VALID_MOVE, validLocations));
    
    // compare the evaluated valid locations
    ASSERT_STREQ(expectedValidLocations, validLocations);
}

// test validMoves for a black rook in the lower right corner of an empty board, at H1
TEST(ChessBoard_validMoves, blackRookLowerRightCornerOfEmptyBoard)
{
    enum ChessBoardRank rank;               // rank of the piece we're watching
    enum ChessBoardFile file;               // file of the piece we're watching
    struct ChessBoard board;
    char expectedValidLocations[65];        // what we expect the valid moves to be
    int numberOfExpectedLocations;          // expected number of valid moves
    char validLocations[65];                // the valid moves that are determined
    
    numberOfExpectedLocations = parseTestingBoard((char [][8][8])
                                                  {
                                                      {"   ","   ","   ","   ","   ","   ","   ","[ ]"},
                                                      {"   ","   ","   ","   ","   ","   ","   ","[ ]"},
                                                      {"   ","   ","   ","   ","   ","   ","   ","[ ]"},
                                                      {"   ","   ","   ","   ","   ","   ","   ","[ ]"},
                                                      {"   ","   ","   ","   ","   ","   ","   ","[ ]"},
                                                      {"   ","   ","   ","   ","   ","   ","   ","[ ]"},
                                                      {"   ","   ","   ","   ","   ","   ","   ","[ ]"},
                                                      {"[ ]","[ ]","[ ]","[ ]","[ ]","[ ]","[ ]","(r)"}
                                                  }, &board, expectedValidLocations, &file, &rank, true);
    
    // perform SUT and check that it returned the proper number of valid locations
    ASSERT_EQ(numberOfExpectedLocations, validMoves(&board, file, rank, VALID_MOVE, validLocations));
    
    // compare the evaluated valid locations
    ASSERT_STREQ(expectedValidLocations, validLocations);
}

// test validMoves for a black rook in the top left corner of an empty board, at A8
TEST(ChessBoard_validMoves, blackRookTopLeftCornerOfEmptyBoard)
{
    enum ChessBoardRank rank;               // rank of the piece we're watching
    enum ChessBoardFile file;               // file of the piece we're watching
    struct ChessBoard board;
    char expectedValidLocations[65];        // what we expect the valid moves to be
    int numberOfExpectedLocations;          // expected number of valid moves
    char validLocations[65];                // the valid moves that are determined
    
    numberOfExpectedLocations = parseTestingBoard((char [][8][8])
                                                  {
                                                      {"(r)","[ ]","[ ]","[ ]","[ ]","[ ]","[ ]","[ ]"},
                                                      {"[ ]","   ","   ","   ","   ","   ","   ","   "},
                                                      {"[ ]","   ","   ","   ","   ","   ","   ","   "},
                                                      {"[ ]","   ","   ","   ","   ","   ","   ","   "},
                                                      {"[ ]","   ","   ","   ","   ","   ","   ","   "},
                                                      {"[ ]","   ","   ","   ","   ","   ","   ","   "},
                                                      {"[ ]","   ","   ","   ","   ","   ","   ","   "},
                                                      {"[ ]","   ","   ","   ","   ","   ","   ","   "}
                                                  }, &board, expectedValidLocations, &file, &rank, true);
    
    // perform SUT and check that it returned the proper number of valid locations
    ASSERT_EQ(numberOfExpectedLocations, validMoves(&board, file, rank, VALID_MOVE, validLocations));
    
    // compare the evaluated valid locations
    ASSERT_STREQ(expectedValidLocations, validLocations);
}

// test validMoves for a black rook in the top right corner of an empty board, at H8
TEST(ChessBoard_validMoves, blackRookTopRightCornerOfEmptyBoard)
{
    enum ChessBoardRank rank;               // rank of the piece we're watching
    enum ChessBoardFile file;               // file of the piece we're watching
    struct ChessBoard board;
    char expectedValidLocations[65];        // what we expect the valid moves to be
    int numberOfExpectedLocations;          // expected number of valid moves
    char validLocations[65];                // the valid moves that are determined
    
    numberOfExpectedLocations = parseTestingBoard((char [][8][8])
                                                  {
                                                      {"[ ]","[ ]","[ ]","[ ]","[ ]","[ ]","[ ]","(r)"},
                                                      {"   ","   ","   ","   ","   ","   ","   ","[ ]"},
                                                      {"   ","   ","   ","   ","   ","   ","   ","[ ]"},
                                                      {"   ","   ","   ","   ","   ","   ","   ","[ ]"},
                                                      {"   ","   ","   ","   ","   ","   ","   ","[ ]"},
                                                      {"   ","   ","   ","   ","   ","   ","   ","[ ]"},
                                                      {"   ","   ","   ","   ","   ","   ","   ","[ ]"},
                                                      {"   ","   ","   ","   ","   ","   ","   ","[ ]"}
                                                  }, &board, expectedValidLocations, &file, &rank, true);
    
    // perform SUT and check that it returned the proper number of valid locations
    ASSERT_EQ(numberOfExpectedLocations, validMoves(&board, file, rank, VALID_MOVE, validLocations));
    
    // compare the evaluated valid locations
    ASSERT_STREQ(expectedValidLocations, validLocations);
}

TEST(ChessBoard_validMoves, blackRookInMiddleOfCrowdedBoard)
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
                                                      {" p "," p "," p "," p "," p "," p "," p "," p "},
                                                      {"   ","   ","   ","[ ]","   ","   ","   ","   "},
                                                      {"   ","   ","   ","[ ]","   ","   ","   ","   "},
                                                      {"[ ]","[ ]","[ ]","(r)","[ ]","[ ]","[ ]","[ ]"},
                                                      {"   ","   ","   ","[ ]","   ","   ","   ","   "},
                                                      {" P "," P "," P ","[P]"," P "," P "," P "," P "},
                                                      {"   "," N "," B "," Q "," K "," B "," N "," R "}
                                                  }, &board, expectedValidLocations, &file, &rank, true);
    
    // perform SUT and check that it returned the proper number of valid locations
    ASSERT_EQ(numberOfExpectedLocations, validMoves(&board, file, rank, VALID_MOVE, validLocations));
    
    // compare the evaluated valid locations
    ASSERT_STREQ(expectedValidLocations, validLocations);
}
