//
//  ChessBoard_WhiteKnightTests.cpp
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

// test validMoves for left white knight on a fresh board
TEST(ChessBoard_validMoves, leftWhiteKnightWithFreshBoard)
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
                                                      {"   ","   ","   ","   ","   ","   ","   ","   "},
                                                      {"   ","   ","   ","   ","   ","   ","   ","   "},
                                                      {"   ","   ","   ","   ","   ","   ","   ","   "},
                                                      {"[ ]","   ","[ ]","   ","   ","   ","   ","   "},
                                                      {" P "," P "," P "," P "," P "," P "," P "," P "},
                                                      {" R ","(N)"," B "," Q "," K "," B "," N "," R "}
                                                  }, &board, expectedValidLocations, &file, &rank);
    
    // perform SUT and check that it returned the proper number of valid locations
    ASSERT_EQ(numberOfExpectedLocations, validMoves(&board, file, rank, validLocations));
    
    // compare the evaluated valid locations
    ASSERT_STREQ(expectedValidLocations, validLocations);
}

// test validMoves for right white knight on a fresh board
TEST(ChessBoard_validMoves, rightWhiteKnightWithFreshBoard)
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
                                                      {"   ","   ","   ","   ","   ","   ","   ","   "},
                                                      {"   ","   ","   ","   ","   ","   ","   ","   "},
                                                      {"   ","   ","   ","   ","   ","   ","   ","   "},
                                                      {"   ","   ","   ","   ","   ","[ ]","   ","[ ]"},
                                                      {" P "," P "," P "," P "," P "," P "," P "," P "},
                                                      {" R "," N "," B "," Q "," K "," B ","(N)"," R "}
                                                  }, &board, expectedValidLocations, &file, &rank);
    
    // perform SUT and check that it returned the proper number of valid locations
    ASSERT_EQ(numberOfExpectedLocations, validMoves(&board, file, rank, validLocations));
    
    // compare the evaluated valid locations
    ASSERT_STREQ(expectedValidLocations, validLocations);
}

// test validMoves for right white knight on an empty board - in middle
TEST(ChessBoard_validMoves, whiteKnightWithEmptyBoardInMiddle)
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
                                                      {"   ","   ","   ","(N)","   ","   ","   ","   "},
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

// test validMoves for right white knight on an empty board - left side
TEST(ChessBoard_validMoves, whiteKnightWithEmptyBoardLeftSide)
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
                                                      {"(N)","   ","   ","   ","   ","   ","   ","   "},
                                                      {"   ","   ","[ ]","   ","   ","   ","   ","   "},
                                                      {"   ","[ ]","   ","   ","   ","   ","   ","   "},
                                                      {"   ","   ","   ","   ","   ","   ","   ","   "}
                                                  }, &board, expectedValidLocations, &file, &rank);
    
    // perform SUT and check that it returned the proper number of valid locations
    ASSERT_EQ(numberOfExpectedLocations, validMoves(&board, file, rank, validLocations));
    
    // compare the evaluated valid locations
    ASSERT_STREQ(expectedValidLocations, validLocations);
}

// test validMoves for right white knight on an empty board - right side
TEST(ChessBoard_validMoves, whiteKnightWithEmptyBoardRightSide)
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
                                                      {"   ","   ","   ","   ","   ","   ","   ","(N)"},
                                                      {"   ","   ","   ","   ","   ","[ ]","   ","   "},
                                                      {"   ","   ","   ","   ","   ","   ","[ ]","   "},
                                                      {"   ","   ","   ","   ","   ","   ","   ","   "}
                                                  }, &board, expectedValidLocations, &file, &rank);
    
    // perform SUT and check that it returned the proper number of valid locations
    ASSERT_EQ(numberOfExpectedLocations, validMoves(&board, file, rank, validLocations));
    
    // compare the evaluated valid locations
    ASSERT_STREQ(expectedValidLocations, validLocations);
}

// test validMoves for right white knight on an empty board - top left corner
TEST(ChessBoard_validMoves, whiteKnightWithEmptyBoardTopLeftCorner)
{
    enum ChessBoardRank rank;               // rank of the piece we're watching
    enum ChessBoardFile file;               // file of the piece we're watching
    struct ChessBoard board;
    char expectedValidLocations[65];        // what we expect the valid moves to be
    int numberOfExpectedLocations;          // expected number of valid moves
    char validLocations[65];                // the valid moves that are determined
    
    numberOfExpectedLocations = parseTestingBoard((char [][8][8])
                                                  {
                                                      {"(N)","   ","   ","   ","   ","   ","   ","   "},
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

// test validMoves for right white knight on an empty board - top right corner
TEST(ChessBoard_validMoves, whiteKnightWithEmptyBoardTopRightCorner)
{
    enum ChessBoardRank rank;               // rank of the piece we're watching
    enum ChessBoardFile file;               // file of the piece we're watching
    struct ChessBoard board;
    char expectedValidLocations[65];        // what we expect the valid moves to be
    int numberOfExpectedLocations;          // expected number of valid moves
    char validLocations[65];                // the valid moves that are determined
    
    numberOfExpectedLocations = parseTestingBoard((char [][8][8])
                                                  {
                                                      {"   ","   ","   ","   ","   ","   ","   ","(N)"},
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

// test validMoves for right white knight on an empty board - bottom left corner
TEST(ChessBoard_validMoves, whiteKnightWithEmptyBoardBottomLeftCorner)
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
                                                      {"(N)","   ","   ","   ","   ","   ","   ","   "}
                                                  }, &board, expectedValidLocations, &file, &rank);
    
    // perform SUT and check that it returned the proper number of valid locations
    ASSERT_EQ(numberOfExpectedLocations, validMoves(&board, file, rank, validLocations));
    
    // compare the evaluated valid locations
    ASSERT_STREQ(expectedValidLocations, validLocations);
}

// test validMoves for right white knight on an empty board - bottom right corner
TEST(ChessBoard_validMoves, whiteKnightWithEmptyBoardBottomRightCorner)
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
                                                      {"   ","   ","   ","   ","   ","   ","   ","(N)"}
                                                  }, &board, expectedValidLocations, &file, &rank);
    
    // perform SUT and check that it returned the proper number of valid locations
    ASSERT_EQ(numberOfExpectedLocations, validMoves(&board, file, rank, validLocations));
    
    // compare the evaluated valid locations
    ASSERT_STREQ(expectedValidLocations, validLocations);
}

// test validMoves for right white knight on an empty board - in middle - various pieces on board
TEST(ChessBoard_validMoves, whiteKnightdInMiddleVariousPieces)
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
                                                      {"   ","   ","[ ]","   ","[b]","   ","   ","   "},
                                                      {"   "," Q ","   ","   ","   ","[k]","   ","   "},
                                                      {"   ","   ","   ","(N)","   ","   ","   ","   "},
                                                      {"   ","[p]","   ","   ","   ","[ ]","   ","   "},
                                                      {"   ","   "," K ","   "," B ","   ","   ","   "},
                                                      {"   ","   ","   ","   ","   ","   ","   ","   "},
                                                      {"   ","   ","   ","   ","   ","   ","   ","   "}
                                                  }, &board, expectedValidLocations, &file, &rank);
    
    // perform SUT and check that it returned the proper number of valid locations
    ASSERT_EQ(numberOfExpectedLocations, validMoves(&board, file, rank, validLocations));
    
    // compare the evaluated valid locations
    ASSERT_STREQ(expectedValidLocations, validLocations);
}

// test validMoves for right white knight on an empty board - left side - various pieces on board
TEST(ChessBoard_validMoves, whiteKnightLeftSideVariousPieces)
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
                                                      {"   "," K ","   ","   ","   ","   ","   ","   "},
                                                      {"   ","   ","[ ]","   ","   ","   ","   ","   "},
                                                      {"(N)","   ","   ","   ","   ","   ","   ","   "},
                                                      {"   ","   ","[p]","   ","   ","   ","   ","   "},
                                                      {"   ","[q]","   ","   ","   ","   ","   ","   "},
                                                      {"   ","   ","   ","   ","   ","   ","   ","   "}
                                                  }, &board, expectedValidLocations, &file, &rank);
    
    // perform SUT and check that it returned the proper number of valid locations
    ASSERT_EQ(numberOfExpectedLocations, validMoves(&board, file, rank, validLocations));
    
    // compare the evaluated valid locations
    ASSERT_STREQ(expectedValidLocations, validLocations);
}

// test validMoves for right white knight on an empty board - right side - various pieces on board
TEST(ChessBoard_validMoves, whiteKnightRightSideVariousPieces)
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
                                                      {"   ","   ","   ","   ","   ","[n]","   ","   "},
                                                      {"   ","   ","   ","   ","   ","   ","   ","(N)"},
                                                      {"   ","   ","   ","   ","   "," N ","   ","   "},
                                                      {"   ","   ","   ","   ","   ","   ","[k]","   "},
                                                      {"   ","   ","   ","   ","   ","   ","   ","   "}
                                                  }, &board, expectedValidLocations, &file, &rank);
    
    // perform SUT and check that it returned the proper number of valid locations
    ASSERT_EQ(numberOfExpectedLocations, validMoves(&board, file, rank, validLocations));
    
    // compare the evaluated valid locations
    ASSERT_STREQ(expectedValidLocations, validLocations);
}

// test validMoves for right white knight on an empty board - top left corner - various pieces on board
TEST(ChessBoard_validMoves, whiteKnightTopLeftCornerVariousPieces)
{
    enum ChessBoardRank rank;               // rank of the piece we're watching
    enum ChessBoardFile file;               // file of the piece we're watching
    struct ChessBoard board;
    char expectedValidLocations[65];        // what we expect the valid moves to be
    int numberOfExpectedLocations;          // expected number of valid moves
    char validLocations[65];                // the valid moves that are determined
    
    numberOfExpectedLocations = parseTestingBoard((char [][8][8])
                                                  {
                                                      {"(N)","   ","   ","   ","   ","   ","   ","   "},
                                                      {"   ","   "," B ","   ","   ","   ","   ","   "},
                                                      {"   ","[k]","   ","   ","   ","   ","   ","   "},
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

// test validMoves for right white knight on an empty board - top right corner - various pieces on board
TEST(ChessBoard_validMoves, whiteKnightTopRightCornerVariousPieces)
{
    enum ChessBoardRank rank;               // rank of the piece we're watching
    enum ChessBoardFile file;               // file of the piece we're watching
    struct ChessBoard board;
    char expectedValidLocations[65];        // what we expect the valid moves to be
    int numberOfExpectedLocations;          // expected number of valid moves
    char validLocations[65];                // the valid moves that are determined
    
    numberOfExpectedLocations = parseTestingBoard((char [][8][8])
                                                  {
                                                      {"   ","   ","   ","   ","   ","   ","   ","(N)"},
                                                      {"   ","   ","   ","   ","   ","[q]","   ","   "},
                                                      {"   ","   ","   ","   ","   ","   "," Q ","   "},
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

// test validMoves for right white knight on an empty board - bottom left corner - various pieces on board
TEST(ChessBoard_validMoves, whiteKnightBottomLeftCornerVariousPieces)
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
                                                      {"   ","[b]","   ","   ","   ","   ","   ","   "},
                                                      {"   ","   "," B ","   ","   ","   ","   ","   "},
                                                      {"(N)","   ","   ","   ","   ","   ","   ","   "}
                                                  }, &board, expectedValidLocations, &file, &rank);
    
    // perform SUT and check that it returned the proper number of valid locations
    ASSERT_EQ(numberOfExpectedLocations, validMoves(&board, file, rank, validLocations));
    
    // compare the evaluated valid locations
    ASSERT_STREQ(expectedValidLocations, validLocations);
}

// test validMoves for right white knight on an empty board - bottom right corner - various pieces on board
TEST(ChessBoard_validMoves, whiteKnightBottomRightCornerVariousPieces)
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
                                                      {"   ","   ","   ","   ","   ","   ","[q]","   "},
                                                      {"   ","   ","   ","   ","   "," Q ","   ","   "},
                                                      {"   ","   ","   ","   ","   ","   ","   ","(N)"}
                                                  }, &board, expectedValidLocations, &file, &rank);
    
    // perform SUT and check that it returned the proper number of valid locations
    ASSERT_EQ(numberOfExpectedLocations, validMoves(&board, file, rank, validLocations));
    
    // compare the evaluated valid locations
    ASSERT_STREQ(expectedValidLocations, validLocations);
}

