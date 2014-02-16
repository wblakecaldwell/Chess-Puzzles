//
//  ChessBoard_BlackKnightTests.cpp
//  ChessPuzzlesLibrary
//
//  Created by Blake Caldwell on 2/16/14.
//  Copyright (c) 2014 Blake Caldwell. All rights reserved.
//

#include <stdio.h>
#include <gtest/gtest.h>
#include "ChessBoardTestHelpers.h"
extern "C" {
#include "ChessBoard.h"
}

// test validMoves for left Black knight on a fresh board
TEST(ChessBoard_validMoves, leftBlackKnightWithFreshBoard)
{
    enum ChessBoardRank rank;               // rank of the piece we're watching
    enum ChessBoardFile file;               // file of the piece we're watching
    struct ChessBoard board;
    char expectedValidLocations[65];        // what we expect the valid moves to be
    int numberOfExpectedLocations;          // expected number of valid moves
    char validLocations[65];                // the valid moves that are determined
    
    numberOfExpectedLocations = parseTestingBoard((char [][8][8])
                                                  {
                                                      {" r ","(n)"," b "," q "," k "," b "," n "," r "},
                                                      {" p "," p "," p "," p "," p "," p "," p "," p "},
                                                      {"[ ]","   ","[ ]","   ","   ","   ","   ","   "},
                                                      {"   ","   ","   ","   ","   ","   ","   ","   "},
                                                      {"   ","   ","   ","   ","   ","   ","   ","   "},
                                                      {"   ","   ","   ","   ","   ","   ","   ","   "},
                                                      {" P "," P "," P "," P "," P "," P "," P "," P "},
                                                      {" R "," N "," B "," Q "," K "," B "," N "," R "}
                                                  }, &board, expectedValidLocations, &file, &rank);
    
    // perform SUT and check that it returned the proper number of valid locations
    ASSERT_EQ(numberOfExpectedLocations, validMoves(&board, file, rank, validLocations));
    
    // compare the evaluated valid locations
    ASSERT_STREQ(expectedValidLocations, validLocations);
}

// test validMoves for right Black knight on a fresh board
TEST(ChessBoard_validMoves, rightBlackKnightWithFreshBoard)
{
    enum ChessBoardRank rank;               // rank of the piece we're watching
    enum ChessBoardFile file;               // file of the piece we're watching
    struct ChessBoard board;
    char expectedValidLocations[65];        // what we expect the valid moves to be
    int numberOfExpectedLocations;          // expected number of valid moves
    char validLocations[65];                // the valid moves that are determined
    
    numberOfExpectedLocations = parseTestingBoard((char [][8][8])
                                                  {
                                                      {" r "," n "," b "," q "," k "," b ","(n)"," r "},
                                                      {" p "," p "," p "," p "," p "," p "," p "," p "},
                                                      {"   ","   ","   ","   ","   ","[ ]","   ","[ ]"},
                                                      {"   ","   ","   ","   ","   ","   ","   ","   "},
                                                      {"   ","   ","   ","   ","   ","   ","   ","   "},
                                                      {"   ","   ","   ","   ","   ","   ","   ","   "},
                                                      {" P "," P "," P "," P "," P "," P "," P "," P "},
                                                      {" R "," N "," B "," Q "," K "," B "," N "," R "}
                                                  }, &board, expectedValidLocations, &file, &rank);
    
    // perform SUT and check that it returned the proper number of valid locations
    ASSERT_EQ(numberOfExpectedLocations, validMoves(&board, file, rank, validLocations));
    
    // compare the evaluated valid locations
    ASSERT_STREQ(expectedValidLocations, validLocations);
}

// test validMoves for right Black knight on an empty board - in middle
TEST(ChessBoard_validMoves, BlackKnightWithEmptyBoardInMiddle)
{
    enum ChessBoardRank rank;               // rank of the piece we're watching
    enum ChessBoardFile file;               // file of the piece we're watching
    struct ChessBoard board;
    char expectedValidLocations[65];        // what we expect the valid moves to be
    int numberOfExpectedLocations;          // expected number of valid moves
    char validLocations[65];                // the valid moves that are determined
    
    numberOfExpectedLocations = parseTestingBoard((char [][8][8])
                                                  {
                                                      {"   ","   ","   ","   ","   ","   ","   ","   "},
                                                      {"   ","   ","[ ]","   ","[ ]","   ","   ","   "},
                                                      {"   ","[ ]","   ","   ","   ","[ ]","   ","   "},
                                                      {"   ","   ","   ","(n)","   ","   ","   ","   "},
                                                      {"   ","[ ]","   ","   ","   ","[ ]","   ","   "},
                                                      {"   ","   ","[ ]","   ","[ ]","   ","   ","   "},
                                                      {"   ","   ","   ","   ","   ","   ","   ","   "},
                                                      {"   ","   ","   ","   ","   ","   ","   ","   "}
                                                  }, &board, expectedValidLocations, &file, &rank);
    
    // perform SUT and check that it returned the proper number of valid locations
    ASSERT_EQ(numberOfExpectedLocations, validMoves(&board, file, rank, validLocations));
    
    // compare the evaluated valid locations
    ASSERT_STREQ(expectedValidLocations, validLocations);
}

// test validMoves for right Black knight on an empty board - left side
TEST(ChessBoard_validMoves, BlackKnightWithEmptyBoardLeftSide)
{
    enum ChessBoardRank rank;               // rank of the piece we're watching
    enum ChessBoardFile file;               // file of the piece we're watching
    struct ChessBoard board;
    char expectedValidLocations[65];        // what we expect the valid moves to be
    int numberOfExpectedLocations;          // expected number of valid moves
    char validLocations[65];                // the valid moves that are determined
    
    numberOfExpectedLocations = parseTestingBoard((char [][8][8])
                                                  {
                                                      {"   ","   ","   ","   ","   ","   ","   ","   "},
                                                      {"   ","   ","   ","   ","   ","   ","   ","   "},
                                                      {"   ","[ ]","   ","   ","   ","   ","   ","   "},
                                                      {"   ","   ","[ ]","   ","   ","   ","   ","   "},
                                                      {"(n)","   ","   ","   ","   ","   ","   ","   "},
                                                      {"   ","   ","[ ]","   ","   ","   ","   ","   "},
                                                      {"   ","[ ]","   ","   ","   ","   ","   ","   "},
                                                      {"   ","   ","   ","   ","   ","   ","   ","   "}
                                                  }, &board, expectedValidLocations, &file, &rank);
    
    // perform SUT and check that it returned the proper number of valid locations
    ASSERT_EQ(numberOfExpectedLocations, validMoves(&board, file, rank, validLocations));
    
    // compare the evaluated valid locations
    ASSERT_STREQ(expectedValidLocations, validLocations);
}

// test validMoves for right Black knight on an empty board - right side
TEST(ChessBoard_validMoves, BlackKnightWithEmptyBoardRightSide)
{
    enum ChessBoardRank rank;               // rank of the piece we're watching
    enum ChessBoardFile file;               // file of the piece we're watching
    struct ChessBoard board;
    char expectedValidLocations[65];        // what we expect the valid moves to be
    int numberOfExpectedLocations;          // expected number of valid moves
    char validLocations[65];                // the valid moves that are determined
    
    numberOfExpectedLocations = parseTestingBoard((char [][8][8])
                                                  {
                                                      {"   ","   ","   ","   ","   ","   ","   ","   "},
                                                      {"   ","   ","   ","   ","   ","   ","   ","   "},
                                                      {"   ","   ","   ","   ","   ","   ","[ ]","   "},
                                                      {"   ","   ","   ","   ","   ","[ ]","   ","   "},
                                                      {"   ","   ","   ","   ","   ","   ","   ","(n)"},
                                                      {"   ","   ","   ","   ","   ","[ ]","   ","   "},
                                                      {"   ","   ","   ","   ","   ","   ","[ ]","   "},
                                                      {"   ","   ","   ","   ","   ","   ","   ","   "}
                                                  }, &board, expectedValidLocations, &file, &rank);
    
    // perform SUT and check that it returned the proper number of valid locations
    ASSERT_EQ(numberOfExpectedLocations, validMoves(&board, file, rank, validLocations));
    
    // compare the evaluated valid locations
    ASSERT_STREQ(expectedValidLocations, validLocations);
}

// test validMoves for right Black knight on an empty board - top left corner
TEST(ChessBoard_validMoves, BlackKnightWithEmptyBoardTopLeftCorner)
{
    enum ChessBoardRank rank;               // rank of the piece we're watching
    enum ChessBoardFile file;               // file of the piece we're watching
    struct ChessBoard board;
    char expectedValidLocations[65];        // what we expect the valid moves to be
    int numberOfExpectedLocations;          // expected number of valid moves
    char validLocations[65];                // the valid moves that are determined
    
    numberOfExpectedLocations = parseTestingBoard((char [][8][8])
                                                  {
                                                      {"(n)","   ","   ","   ","   ","   ","   ","   "},
                                                      {"   ","   ","[ ]","   ","   ","   ","   ","   "},
                                                      {"   ","[ ]","   ","   ","   ","   ","   ","   "},
                                                      {"   ","   ","   ","   ","   ","   ","   ","   "},
                                                      {"   ","   ","   ","   ","   ","   ","   ","   "},
                                                      {"   ","   ","   ","   ","   ","   ","   ","   "},
                                                      {"   ","   ","   ","   ","   ","   ","   ","   "},
                                                      {"   ","   ","   ","   ","   ","   ","   ","   "}
                                                  }, &board, expectedValidLocations, &file, &rank);
    
    // perform SUT and check that it returned the proper number of valid locations
    ASSERT_EQ(numberOfExpectedLocations, validMoves(&board, file, rank, validLocations));
    
    // compare the evaluated valid locations
    ASSERT_STREQ(expectedValidLocations, validLocations);
}

// test validMoves for right Black knight on an empty board - top right corner
TEST(ChessBoard_validMoves, BlackKnightWithEmptyBoardTopRightCorner)
{
    enum ChessBoardRank rank;               // rank of the piece we're watching
    enum ChessBoardFile file;               // file of the piece we're watching
    struct ChessBoard board;
    char expectedValidLocations[65];        // what we expect the valid moves to be
    int numberOfExpectedLocations;          // expected number of valid moves
    char validLocations[65];                // the valid moves that are determined
    
    numberOfExpectedLocations = parseTestingBoard((char [][8][8])
                                                  {
                                                      {"   ","   ","   ","   ","   ","   ","   ","(n)"},
                                                      {"   ","   ","   ","   ","   ","[ ]","   ","   "},
                                                      {"   ","   ","   ","   ","   ","   ","[ ]","   "},
                                                      {"   ","   ","   ","   ","   ","   ","   ","   "},
                                                      {"   ","   ","   ","   ","   ","   ","   ","   "},
                                                      {"   ","   ","   ","   ","   ","   ","   ","   "},
                                                      {"   ","   ","   ","   ","   ","   ","   ","   "},
                                                      {"   ","   ","   ","   ","   ","   ","   ","   "}
                                                  }, &board, expectedValidLocations, &file, &rank);
    
    // perform SUT and check that it returned the proper number of valid locations
    ASSERT_EQ(numberOfExpectedLocations, validMoves(&board, file, rank, validLocations));
    
    // compare the evaluated valid locations
    ASSERT_STREQ(expectedValidLocations, validLocations);
}

// test validMoves for right Black knight on an empty board - bottom left corner
TEST(ChessBoard_validMoves, BlackKnightWithEmptyBoardBottomLeftCorner)
{
    enum ChessBoardRank rank;               // rank of the piece we're watching
    enum ChessBoardFile file;               // file of the piece we're watching
    struct ChessBoard board;
    char expectedValidLocations[65];        // what we expect the valid moves to be
    int numberOfExpectedLocations;          // expected number of valid moves
    char validLocations[65];                // the valid moves that are determined
    
    numberOfExpectedLocations = parseTestingBoard((char [][8][8])
                                                  {
                                                      {"   ","   ","   ","   ","   ","   ","   ","   "},
                                                      {"   ","   ","   ","   ","   ","   ","   ","   "},
                                                      {"   ","   ","   ","   ","   ","   ","   ","   "},
                                                      {"   ","   ","   ","   ","   ","   ","   ","   "},
                                                      {"   ","   ","   ","   ","   ","   ","   ","   "},
                                                      {"   ","[ ]","   ","   ","   ","   ","   ","   "},
                                                      {"   ","   ","[ ]","   ","   ","   ","   ","   "},
                                                      {"(n)","   ","   ","   ","   ","   ","   ","   "}
                                                  }, &board, expectedValidLocations, &file, &rank);
    
    // perform SUT and check that it returned the proper number of valid locations
    ASSERT_EQ(numberOfExpectedLocations, validMoves(&board, file, rank, validLocations));
    
    // compare the evaluated valid locations
    ASSERT_STREQ(expectedValidLocations, validLocations);
}

// test validMoves for right Black knight on an empty board - bottom right corner
TEST(ChessBoard_validMoves, BlackKnightWithEmptyBoardBottomRightCorner)
{
    enum ChessBoardRank rank;               // rank of the piece we're watching
    enum ChessBoardFile file;               // file of the piece we're watching
    struct ChessBoard board;
    char expectedValidLocations[65];        // what we expect the valid moves to be
    int numberOfExpectedLocations;          // expected number of valid moves
    char validLocations[65];                // the valid moves that are determined
    
    numberOfExpectedLocations = parseTestingBoard((char [][8][8])
                                                  {
                                                      {"   ","   ","   ","   ","   ","   ","   ","   "},
                                                      {"   ","   ","   ","   ","   ","   ","   ","   "},
                                                      {"   ","   ","   ","   ","   ","   ","   ","   "},
                                                      {"   ","   ","   ","   ","   ","   ","   ","   "},
                                                      {"   ","   ","   ","   ","   ","   ","   ","   "},
                                                      {"   ","   ","   ","   ","   ","   ","[ ]","   "},
                                                      {"   ","   ","   ","   ","   ","[ ]","   ","   "},
                                                      {"   ","   ","   ","   ","   ","   ","   ","(n)"}
                                                  }, &board, expectedValidLocations, &file, &rank);
    
    // perform SUT and check that it returned the proper number of valid locations
    ASSERT_EQ(numberOfExpectedLocations, validMoves(&board, file, rank, validLocations));
    
    // compare the evaluated valid locations
    ASSERT_STREQ(expectedValidLocations, validLocations);
}

// test validMoves for right Black knight on an empty board - in middle - various pieces on board
TEST(ChessBoard_validMoves, BlackKnightdInMiddleVariousPieces)
{
    enum ChessBoardRank rank;               // rank of the piece we're watching
    enum ChessBoardFile file;               // file of the piece we're watching
    struct ChessBoard board;
    char expectedValidLocations[65];        // what we expect the valid moves to be
    int numberOfExpectedLocations;          // expected number of valid moves
    char validLocations[65];                // the valid moves that are determined
    
    numberOfExpectedLocations = parseTestingBoard((char [][8][8])
                                                  {
                                                      {"   ","   ","   ","   ","   ","   ","   ","   "},
                                                      {"   ","   ","[ ]","   ","[B]","   ","   ","   "},
                                                      {"   "," q ","   ","   ","   ","[K]","   ","   "},
                                                      {"   ","   ","   ","(n)","   ","   ","   ","   "},
                                                      {"   ","[P]","   ","   ","   ","[ ]","   ","   "},
                                                      {"   ","   "," k ","   "," b ","   ","   ","   "},
                                                      {"   ","   ","   ","   ","   ","   ","   ","   "},
                                                      {"   ","   ","   ","   ","   ","   ","   ","   "}
                                                  }, &board, expectedValidLocations, &file, &rank);
    
    // perform SUT and check that it returned the proper number of valid locations
    ASSERT_EQ(numberOfExpectedLocations, validMoves(&board, file, rank, validLocations));
    
    // compare the evaluated valid locations
    ASSERT_STREQ(expectedValidLocations, validLocations);
}

// test validMoves for right Black knight on an empty board - left side - various pieces on board
TEST(ChessBoard_validMoves, BlackKnightLeftSideVariousPieces)
{
    enum ChessBoardRank rank;               // rank of the piece we're watching
    enum ChessBoardFile file;               // file of the piece we're watching
    struct ChessBoard board;
    char expectedValidLocations[65];        // what we expect the valid moves to be
    int numberOfExpectedLocations;          // expected number of valid moves
    char validLocations[65];                // the valid moves that are determined
    
    numberOfExpectedLocations = parseTestingBoard((char [][8][8])
                                                  {
                                                      {"   ","   ","   ","   ","   ","   ","   ","   "},
                                                      {"   ","   ","   ","   ","   ","   ","   ","   "},
                                                      {"   "," k ","   ","   ","   ","   ","   ","   "},
                                                      {"   ","   ","[ ]","   ","   ","   ","   ","   "},
                                                      {"(n)","   ","   ","   ","   ","   ","   ","   "},
                                                      {"   ","   ","[P]","   ","   ","   ","   ","   "},
                                                      {"   ","[Q]","   ","   ","   ","   ","   ","   "},
                                                      {"   ","   ","   ","   ","   ","   ","   ","   "}
                                                  }, &board, expectedValidLocations, &file, &rank);
    
    // perform SUT and check that it returned the proper number of valid locations
    ASSERT_EQ(numberOfExpectedLocations, validMoves(&board, file, rank, validLocations));
    
    // compare the evaluated valid locations
    ASSERT_STREQ(expectedValidLocations, validLocations);
}

// test validMoves for right Black knight on an empty board - right side - various pieces on board
TEST(ChessBoard_validMoves, BlackKnightRightSideVariousPieces)
{
    enum ChessBoardRank rank;               // rank of the piece we're watching
    enum ChessBoardFile file;               // file of the piece we're watching
    struct ChessBoard board;
    char expectedValidLocations[65];        // what we expect the valid moves to be
    int numberOfExpectedLocations;          // expected number of valid moves
    char validLocations[65];                // the valid moves that are determined
    
    numberOfExpectedLocations = parseTestingBoard((char [][8][8])
                                                  {
                                                      {"   ","   ","   ","   ","   ","   ","   ","   "},
                                                      {"   ","   ","   ","   ","   ","   ","   ","   "},
                                                      {"   ","   ","   ","   ","   ","   ","[ ]","   "},
                                                      {"   ","   ","   ","   ","   ","[N]","   ","   "},
                                                      {"   ","   ","   ","   ","   ","   ","   ","(n)"},
                                                      {"   ","   ","   ","   ","   "," n ","   ","   "},
                                                      {"   ","   ","   ","   ","   ","   ","[K]","   "},
                                                      {"   ","   ","   ","   ","   ","   ","   ","   "}
                                                  }, &board, expectedValidLocations, &file, &rank);
    
    // perform SUT and check that it returned the proper number of valid locations
    ASSERT_EQ(numberOfExpectedLocations, validMoves(&board, file, rank, validLocations));
    
    // compare the evaluated valid locations
    ASSERT_STREQ(expectedValidLocations, validLocations);
}

// test validMoves for right Black knight on an empty board - top left corner - various pieces on board
TEST(ChessBoard_validMoves, BlackKnightTopLeftCornerVariousPieces)
{
    enum ChessBoardRank rank;               // rank of the piece we're watching
    enum ChessBoardFile file;               // file of the piece we're watching
    struct ChessBoard board;
    char expectedValidLocations[65];        // what we expect the valid moves to be
    int numberOfExpectedLocations;          // expected number of valid moves
    char validLocations[65];                // the valid moves that are determined
    
    numberOfExpectedLocations = parseTestingBoard((char [][8][8])
                                                  {
                                                      {"(n)","   ","   ","   ","   ","   ","   ","   "},
                                                      {"   ","   "," b ","   ","   ","   ","   ","   "},
                                                      {"   ","[K]","   ","   ","   ","   ","   ","   "},
                                                      {"   ","   ","   ","   ","   ","   ","   ","   "},
                                                      {"   ","   ","   ","   ","   ","   ","   ","   "},
                                                      {"   ","   ","   ","   ","   ","   ","   ","   "},
                                                      {"   ","   ","   ","   ","   ","   ","   ","   "},
                                                      {"   ","   ","   ","   ","   ","   ","   ","   "}
                                                  }, &board, expectedValidLocations, &file, &rank);
    
    // perform SUT and check that it returned the proper number of valid locations
    ASSERT_EQ(numberOfExpectedLocations, validMoves(&board, file, rank, validLocations));
    
    // compare the evaluated valid locations
    ASSERT_STREQ(expectedValidLocations, validLocations);
}

// test validMoves for right Black knight on an empty board - top right corner - various pieces on board
TEST(ChessBoard_validMoves, BlackKnightTopRightCornerVariousPieces)
{
    enum ChessBoardRank rank;               // rank of the piece we're watching
    enum ChessBoardFile file;               // file of the piece we're watching
    struct ChessBoard board;
    char expectedValidLocations[65];        // what we expect the valid moves to be
    int numberOfExpectedLocations;          // expected number of valid moves
    char validLocations[65];                // the valid moves that are determined
    
    numberOfExpectedLocations = parseTestingBoard((char [][8][8])
                                                  {
                                                      {"   ","   ","   ","   ","   ","   ","   ","(n)"},
                                                      {"   ","   ","   ","   ","   ","[Q]","   ","   "},
                                                      {"   ","   ","   ","   ","   ","   "," q ","   "},
                                                      {"   ","   ","   ","   ","   ","   ","   ","   "},
                                                      {"   ","   ","   ","   ","   ","   ","   ","   "},
                                                      {"   ","   ","   ","   ","   ","   ","   ","   "},
                                                      {"   ","   ","   ","   ","   ","   ","   ","   "},
                                                      {"   ","   ","   ","   ","   ","   ","   ","   "}
                                                  }, &board, expectedValidLocations, &file, &rank);
    
    // perform SUT and check that it returned the proper number of valid locations
    ASSERT_EQ(numberOfExpectedLocations, validMoves(&board, file, rank, validLocations));
    
    // compare the evaluated valid locations
    ASSERT_STREQ(expectedValidLocations, validLocations);
}

// test validMoves for right Black knight on an empty board - bottom left corner - various pieces on board
TEST(ChessBoard_validMoves, BlackKnightBottomLeftCornerVariousPieces)
{
    enum ChessBoardRank rank;               // rank of the piece we're watching
    enum ChessBoardFile file;               // file of the piece we're watching
    struct ChessBoard board;
    char expectedValidLocations[65];        // what we expect the valid moves to be
    int numberOfExpectedLocations;          // expected number of valid moves
    char validLocations[65];                // the valid moves that are determined
    
    numberOfExpectedLocations = parseTestingBoard((char [][8][8])
                                                  {
                                                      {"   ","   ","   ","   ","   ","   ","   ","   "},
                                                      {"   ","   ","   ","   ","   ","   ","   ","   "},
                                                      {"   ","   ","   ","   ","   ","   ","   ","   "},
                                                      {"   ","   ","   ","   ","   ","   ","   ","   "},
                                                      {"   ","   ","   ","   ","   ","   ","   ","   "},
                                                      {"   ","[B]","   ","   ","   ","   ","   ","   "},
                                                      {"   ","   "," b ","   ","   ","   ","   ","   "},
                                                      {"(n)","   ","   ","   ","   ","   ","   ","   "}
                                                  }, &board, expectedValidLocations, &file, &rank);
    
    // perform SUT and check that it returned the proper number of valid locations
    ASSERT_EQ(numberOfExpectedLocations, validMoves(&board, file, rank, validLocations));
    
    // compare the evaluated valid locations
    ASSERT_STREQ(expectedValidLocations, validLocations);
}

// test validMoves for right Black knight on an empty board - bottom right corner - various pieces on board
TEST(ChessBoard_validMoves, BlackKnightBottomRightCornerVariousPieces)
{
    enum ChessBoardRank rank;               // rank of the piece we're watching
    enum ChessBoardFile file;               // file of the piece we're watching
    struct ChessBoard board;
    char expectedValidLocations[65];        // what we expect the valid moves to be
    int numberOfExpectedLocations;          // expected number of valid moves
    char validLocations[65];                // the valid moves that are determined
    
    numberOfExpectedLocations = parseTestingBoard((char [][8][8])
                                                  {
                                                      {"   ","   ","   ","   ","   ","   ","   ","   "},
                                                      {"   ","   ","   ","   ","   ","   ","   ","   "},
                                                      {"   ","   ","   ","   ","   ","   ","   ","   "},
                                                      {"   ","   ","   ","   ","   ","   ","   ","   "},
                                                      {"   ","   ","   ","   ","   ","   ","   ","   "},
                                                      {"   ","   ","   ","   ","   ","   ","[Q]","   "},
                                                      {"   ","   ","   ","   ","   "," q ","   ","   "},
                                                      {"   ","   ","   ","   ","   ","   ","   ","(n)"}
                                                  }, &board, expectedValidLocations, &file, &rank);
    
    // perform SUT and check that it returned the proper number of valid locations
    ASSERT_EQ(numberOfExpectedLocations, validMoves(&board, file, rank, validLocations));
    
    // compare the evaluated valid locations
    ASSERT_STREQ(expectedValidLocations, validLocations);
}

