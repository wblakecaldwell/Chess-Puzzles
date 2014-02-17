//
//  ChessBoard_BlackBishopTests.cpp
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

// test validMoves for left black bishop on a fresh board
TEST(ChessBoard_validMoves, leftBlackBishopWithFreshBoard)
{
    enum ChessBoardRank rank;               // rank of the piece we're watching
    enum ChessBoardFile file;               // file of the piece we're watching
    struct ChessBoard board;
    char expectedValidLocations[65];        // what we expect the valid moves to be
    int numberOfExpectedLocations;          // expected number of valid moves
    char validLocations[65];                // the valid moves that are determined
    
    numberOfExpectedLocations = parseTestingBoard((char [][8][8])
                                                  {
                                                      {" r "," n ","(b)"," q "," k "," b "," n "," r "},
                                                      {" p "," p "," p "," p "," p "," p "," p "," p "},
                                                      {"   ","   ","   ","   ","   ","   ","   ","   "},
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

// test validMoves for right black bishop on a fresh board
TEST(ChessBoard_validMoves, rightBlackBishopWithFreshBoard)
{
    enum ChessBoardRank rank;               // rank of the piece we're watching
    enum ChessBoardFile file;               // file of the piece we're watching
    struct ChessBoard board;
    char expectedValidLocations[65];        // what we expect the valid moves to be
    int numberOfExpectedLocations;          // expected number of valid moves
    char validLocations[65];                // the valid moves that are determined
    
    numberOfExpectedLocations = parseTestingBoard((char [][8][8])
                                                  {
                                                      {" r "," n "," b "," q "," k ","(b)"," n "," r "},
                                                      {" p "," p "," p "," p "," p "," p "," p "," p "},
                                                      {"   ","   ","   ","   ","   ","   ","   ","   "},
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

// test validMoves for right black bishop on an empty board - in middle
TEST(ChessBoard_validMoves, blackBishopWithEmptyBoardInMiddle)
{
    enum ChessBoardRank rank;               // rank of the piece we're watching
    enum ChessBoardFile file;               // file of the piece we're watching
    struct ChessBoard board;
    char expectedValidLocations[65];        // what we expect the valid moves to be
    int numberOfExpectedLocations;          // expected number of valid moves
    char validLocations[65];                // the valid moves that are determined
    
    numberOfExpectedLocations = parseTestingBoard((char [][8][8])
                                                  {
                                                      {"[ ]","   ","   ","   ","   ","   ","[ ]","   "},
                                                      {"   ","[ ]","   ","   ","   ","[ ]","   ","   "},
                                                      {"   ","   ","[ ]","   ","[ ]","   ","   ","   "},
                                                      {"   ","   ","   ","(b)","   ","   ","   ","   "},
                                                      {"   ","   ","[ ]","   ","[ ]","   ","   ","   "},
                                                      {"   ","[ ]","   ","   ","   ","[ ]","   ","   "},
                                                      {"[ ]","   ","   ","   ","   ","   ","[ ]","   "},
                                                      {"   ","   ","   ","   ","   ","   ","   ","[ ]"}
                                                  }, &board, expectedValidLocations, &file, &rank);
    
    // perform SUT and check that it returned the proper number of valid locations
    ASSERT_EQ(numberOfExpectedLocations, validMoves(&board, file, rank, validLocations));
    
    // compare the evaluated valid locations
    ASSERT_STREQ(expectedValidLocations, validLocations);
}

// test validMoves for right black bishop on an empty board - left side
TEST(ChessBoard_validMoves, blackBishopWithEmptyBoardLeftSide)
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
                                                      {"   ","   ","   ","[ ]","   ","   ","   ","   "},
                                                      {"   ","   ","[ ]","   ","   ","   ","   ","   "},
                                                      {"   ","[ ]","   ","   ","   ","   ","   ","   "},
                                                      {"(b)","   ","   ","   ","   ","   ","   ","   "},
                                                      {"   ","[ ]","   ","   ","   ","   ","   ","   "},
                                                      {"   ","   ","[ ]","   ","   ","   ","   ","   "},
                                                      {"   ","   ","   ","[ ]","   ","   ","   ","   "}
                                                  }, &board, expectedValidLocations, &file, &rank);
    
    // perform SUT and check that it returned the proper number of valid locations
    ASSERT_EQ(numberOfExpectedLocations, validMoves(&board, file, rank, validLocations));
    
    // compare the evaluated valid locations
    ASSERT_STREQ(expectedValidLocations, validLocations);
}

// test validMoves for right black bishop on an empty board - right side
TEST(ChessBoard_validMoves, blackBishopWithEmptyBoardRightSide)
{
    enum ChessBoardRank rank;               // rank of the piece we're watching
    enum ChessBoardFile file;               // file of the piece we're watching
    struct ChessBoard board;
    char expectedValidLocations[65];        // what we expect the valid moves to be
    int numberOfExpectedLocations;          // expected number of valid moves
    char validLocations[65];                // the valid moves that are determined
    
    numberOfExpectedLocations = parseTestingBoard((char [][8][8])
                                                  {
                                                      {"   ","   ","   ","[ ]","   ","   ","   ","   "},
                                                      {"   ","   ","   ","   ","[ ]","   ","   ","   "},
                                                      {"   ","   ","   ","   ","   ","[ ]","   ","   "},
                                                      {"   ","   ","   ","   ","   ","   ","[ ]","   "},
                                                      {"   ","   ","   ","   ","   ","   ","   ","(b)"},
                                                      {"   ","   ","   ","   ","   ","   ","[ ]","   "},
                                                      {"   ","   ","   ","   ","   ","[ ]","   ","   "},
                                                      {"   ","   ","   ","   ","[ ]","   ","   ","   "}
                                                  }, &board, expectedValidLocations, &file, &rank);
    
    // perform SUT and check that it returned the proper number of valid locations
    ASSERT_EQ(numberOfExpectedLocations, validMoves(&board, file, rank, validLocations));
    
    // compare the evaluated valid locations
    ASSERT_STREQ(expectedValidLocations, validLocations);
}

// test validMoves for right black bishop on an empty board - top left corner
TEST(ChessBoard_validMoves, blackBishopWithEmptyBoardTopLeftCorner)
{
    enum ChessBoardRank rank;               // rank of the piece we're watching
    enum ChessBoardFile file;               // file of the piece we're watching
    struct ChessBoard board;
    char expectedValidLocations[65];        // what we expect the valid moves to be
    int numberOfExpectedLocations;          // expected number of valid moves
    char validLocations[65];                // the valid moves that are determined
    
    numberOfExpectedLocations = parseTestingBoard((char [][8][8])
                                                  {
                                                      {"(b)","   ","   ","   ","   ","   ","   ","   "},
                                                      {"   ","[ ]","   ","   ","   ","   ","   ","   "},
                                                      {"   ","   ","[ ]","   ","   ","   ","   ","   "},
                                                      {"   ","   ","   ","[ ]","   ","   ","   ","   "},
                                                      {"   ","   ","   ","   ","[ ]","   ","   ","   "},
                                                      {"   ","   ","   ","   ","   ","[ ]","   ","   "},
                                                      {"   ","   ","   ","   ","   ","   ","[ ]","   "},
                                                      {"   ","   ","   ","   ","   ","   ","   ","[ ]"}
                                                  }, &board, expectedValidLocations, &file, &rank);
    
    // perform SUT and check that it returned the proper number of valid locations
    ASSERT_EQ(numberOfExpectedLocations, validMoves(&board, file, rank, validLocations));
    
    // compare the evaluated valid locations
    ASSERT_STREQ(expectedValidLocations, validLocations);
}

// test validMoves for right black bishop on an empty board - top right corner
TEST(ChessBoard_validMoves, blackBishopWithEmptyBoardTopRightCorner)
{
    enum ChessBoardRank rank;               // rank of the piece we're watching
    enum ChessBoardFile file;               // file of the piece we're watching
    struct ChessBoard board;
    char expectedValidLocations[65];        // what we expect the valid moves to be
    int numberOfExpectedLocations;          // expected number of valid moves
    char validLocations[65];                // the valid moves that are determined
    
    numberOfExpectedLocations = parseTestingBoard((char [][8][8])
                                                  {
                                                      {"   ","   ","   ","   ","   ","   ","   ","(b)"},
                                                      {"   ","   ","   ","   ","   ","   ","[ ]","   "},
                                                      {"   ","   ","   ","   ","   ","[ ]","   ","   "},
                                                      {"   ","   ","   ","   ","[ ]","   ","   ","   "},
                                                      {"   ","   ","   ","[ ]","   ","   ","   ","   "},
                                                      {"   ","   ","[ ]","   ","   ","   ","   ","   "},
                                                      {"   ","[ ]","   ","   ","   ","   ","   ","   "},
                                                      {"[ ]","   ","   ","   ","   ","   ","   ","   "}
                                                  }, &board, expectedValidLocations, &file, &rank);
    
    // perform SUT and check that it returned the proper number of valid locations
    ASSERT_EQ(numberOfExpectedLocations, validMoves(&board, file, rank, validLocations));
    
    // compare the evaluated valid locations
    ASSERT_STREQ(expectedValidLocations, validLocations);
}

// test validMoves for right black bishop on an empty board - bottom left corner
TEST(ChessBoard_validMoves, blackBishopWithEmptyBoardBottomLeftCorner)
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
                                                      {"   ","   ","   ","   ","   ","   ","[ ]","   "},
                                                      {"   ","   ","   ","   ","   ","[ ]","   ","   "},
                                                      {"   ","   ","   ","   ","[ ]","   ","   ","   "},
                                                      {"   ","   ","   ","[ ]","   ","   ","   ","   "},
                                                      {"   ","   ","[ ]","   ","   ","   ","   ","   "},
                                                      {"   ","[ ]","   ","   ","   ","   ","   ","   "},
                                                      {"(b)","   ","   ","   ","   ","   ","   ","   "}
                                                  }, &board, expectedValidLocations, &file, &rank);
    
    // perform SUT and check that it returned the proper number of valid locations
    ASSERT_EQ(numberOfExpectedLocations, validMoves(&board, file, rank, validLocations));
    
    // compare the evaluated valid locations
    ASSERT_STREQ(expectedValidLocations, validLocations);
}

// test validMoves for right black bishop on an empty board - bottom right corner
TEST(ChessBoard_validMoves, blackBishopWithEmptyBoardBottomRightCorner)
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
                                                      {"   ","[ ]","   ","   ","   ","   ","   ","   "},
                                                      {"   ","   ","[ ]","   ","   ","   ","   ","   "},
                                                      {"   ","   ","   ","[ ]","   ","   ","   ","   "},
                                                      {"   ","   ","   ","   ","[ ]","   ","   ","   "},
                                                      {"   ","   ","   ","   ","   ","[ ]","   ","   "},
                                                      {"   ","   ","   ","   ","   ","   ","[ ]","   "},
                                                      {"   ","   ","   ","   ","   ","   ","   ","(b)"}
                                                  }, &board, expectedValidLocations, &file, &rank);
    
    // perform SUT and check that it returned the proper number of valid locations
    ASSERT_EQ(numberOfExpectedLocations, validMoves(&board, file, rank, validLocations));
    
    // compare the evaluated valid locations
    ASSERT_STREQ(expectedValidLocations, validLocations);
}

// test validMoves for black bishop on an empty board - in middle - various pieces on board
TEST(ChessBoard_validMoves, blackBishopdInMiddleVariousPieces)
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
                                                      {"   ","[K]","   ","   ","   ","   ","   ","   "},
                                                      {"   ","   ","[ ]","   ","[B]","   ","   ","   "},
                                                      {"   ","   ","   ","(b)","   ","   ","   ","   "},
                                                      {"   ","   ","[ ]","   "," k ","   ","   ","   "},
                                                      {"   ","[ ]","   ","   ","   ","   ","   ","   "},
                                                      {"[ ]","   ","   ","   ","   ","   ","   ","   "},
                                                      {"   ","   ","   ","   ","   ","   ","   ","   "}
                                                  }, &board, expectedValidLocations, &file, &rank);
    
    // perform SUT and check that it returned the proper number of valid locations
    ASSERT_EQ(numberOfExpectedLocations, validMoves(&board, file, rank, validLocations));
    
    // compare the evaluated valid locations
    ASSERT_STREQ(expectedValidLocations, validLocations);
}

// test validMoves for right black bishop on an empty board - left side - various pieces on board
TEST(ChessBoard_validMoves, blackBishopLeftSideVariousPieces)
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
                                                      {"   ","   "," q ","   ","   ","   ","   ","   "},
                                                      {"   ","[ ]","   ","   ","   ","   ","   ","   "},
                                                      {"(b)","   ","   ","   ","   ","   ","   ","   "},
                                                      {"   ","[ ]","   ","   ","   ","   ","   ","   "},
                                                      {"   ","   ","[K]","   ","   ","   ","   ","   "},
                                                      {"   ","   ","   ","   ","   ","   ","   ","   "}
                                                  }, &board, expectedValidLocations, &file, &rank);
    
    // perform SUT and check that it returned the proper number of valid locations
    ASSERT_EQ(numberOfExpectedLocations, validMoves(&board, file, rank, validLocations));
    
    // compare the evaluated valid locations
    ASSERT_STREQ(expectedValidLocations, validLocations);
}

// test validMoves for right black bishop on an empty board - right side - various pieces on board
TEST(ChessBoard_validMoves, blackBishopRightSideVariousPieces)
{
    enum ChessBoardRank rank;               // rank of the piece we're watching
    enum ChessBoardFile file;               // file of the piece we're watching
    struct ChessBoard board;
    char expectedValidLocations[65];        // what we expect the valid moves to be
    int numberOfExpectedLocations;          // expected number of valid moves
    char validLocations[65];                // the valid moves that are determined
    
    numberOfExpectedLocations = parseTestingBoard((char [][8][8])
                                                  {
                                                      {"   ","   ","   ","[B]","   ","   ","   ","   "},
                                                      {"   ","   ","   ","   ","[ ]","   ","   ","   "},
                                                      {"   ","   ","   ","   ","   ","[ ]","   ","   "},
                                                      {"   ","   ","   ","   ","   ","   ","[ ]","   "},
                                                      {"   ","   ","   ","   ","   ","   ","   ","(b)"},
                                                      {"   ","   ","   ","   ","   ","   ","[ ]","   "},
                                                      {"   ","   ","   ","   ","   ","[K]","   ","   "},
                                                      {"   ","   ","   ","   ","   ","   ","   ","   "}
                                                  }, &board, expectedValidLocations, &file, &rank);
    
    // perform SUT and check that it returned the proper number of valid locations
    ASSERT_EQ(numberOfExpectedLocations, validMoves(&board, file, rank, validLocations));
    
    // compare the evaluated valid locations
    ASSERT_STREQ(expectedValidLocations, validLocations);
}

// test validMoves for right black bishop on an empty board - top left corner - various pieces on board
TEST(ChessBoard_validMoves, blackBishopTopLeftCornerVariousPieces)
{
    enum ChessBoardRank rank;               // rank of the piece we're watching
    enum ChessBoardFile file;               // file of the piece we're watching
    struct ChessBoard board;
    char expectedValidLocations[65];        // what we expect the valid moves to be
    int numberOfExpectedLocations;          // expected number of valid moves
    char validLocations[65];                // the valid moves that are determined
    
    numberOfExpectedLocations = parseTestingBoard((char [][8][8])
                                                  {
                                                      {"(b)","   ","   ","   ","   ","   ","   ","   "},
                                                      {"   ","[ ]","   ","   ","   ","   ","   ","   "},
                                                      {"   ","   ","[ ]","   ","   ","   ","   ","   "},
                                                      {"   ","   ","   ","[ ]","   ","   ","   ","   "},
                                                      {"   ","   ","   ","   ","[ ]","   ","   ","   "},
                                                      {"   ","   ","   ","   ","   "," b ","   ","   "},
                                                      {"   ","   ","   ","   ","   ","   ","   ","   "},
                                                      {"   ","   ","   ","   ","   ","   ","   ","   "}
                                                  }, &board, expectedValidLocations, &file, &rank);
    
    // perform SUT and check that it returned the proper number of valid locations
    ASSERT_EQ(numberOfExpectedLocations, validMoves(&board, file, rank, validLocations));
    
    // compare the evaluated valid locations
    ASSERT_STREQ(expectedValidLocations, validLocations);
}

// test validMoves for right black bishop on an empty board - top right corner - various pieces on board
TEST(ChessBoard_validMoves, blackBishopTopRightCornerVariousPieces)
{
    enum ChessBoardRank rank;               // rank of the piece we're watching
    enum ChessBoardFile file;               // file of the piece we're watching
    struct ChessBoard board;
    char expectedValidLocations[65];        // what we expect the valid moves to be
    int numberOfExpectedLocations;          // expected number of valid moves
    char validLocations[65];                // the valid moves that are determined
    
    numberOfExpectedLocations = parseTestingBoard((char [][8][8])
                                                  {
                                                      {"   ","   ","   ","   ","   ","   ","   ","(b)"},
                                                      {"   ","   ","   ","   ","   ","   ","[ ]","   "},
                                                      {"   ","   ","   ","   ","   ","[ ]","   ","   "},
                                                      {"   ","   ","   ","   ","[ ]","   ","   ","   "},
                                                      {"   ","   ","   ","[ ]","   ","   ","   ","   "},
                                                      {"   ","   ","[Q]","   ","   ","   ","   ","   "},
                                                      {"   ","   ","   ","   ","   ","   ","   ","   "},
                                                      {"   ","   ","   ","   ","   ","   ","   ","   "}
                                                  }, &board, expectedValidLocations, &file, &rank);
    
    // perform SUT and check that it returned the proper number of valid locations
    ASSERT_EQ(numberOfExpectedLocations, validMoves(&board, file, rank, validLocations));
    
    // compare the evaluated valid locations
    ASSERT_STREQ(expectedValidLocations, validLocations);
}

// test validMoves for right black bishop on an empty board - bottom left corner - various pieces on board
TEST(ChessBoard_validMoves, blackBishopBottomLeftCornerVariousPieces)
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
                                                      {"   ","   ","   "," Q ","   ","   ","   ","   "},
                                                      {"   ","   "," q ","   ","   ","   ","   ","   "},
                                                      {"   ","[ ]","   ","   ","   ","   ","   ","   "},
                                                      {"(b)","   ","   ","   ","   ","   ","   ","   "}
                                                  }, &board, expectedValidLocations, &file, &rank);
    
    // perform SUT and check that it returned the proper number of valid locations
    ASSERT_EQ(numberOfExpectedLocations, validMoves(&board, file, rank, validLocations));
    
    // compare the evaluated valid locations
    ASSERT_STREQ(expectedValidLocations, validLocations);
}

// test validMoves for right black bishop on an empty board - bottom right corner - various pieces on board
TEST(ChessBoard_validMoves, blackBishopBottomRightCornerVariousPieces)
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
                                                      {"   ","   ","   ","   ","   ","   ","   ","   "},
                                                      {"   ","   ","   ","   ","   ","   "," q ","   "},
                                                      {"   ","   ","   ","   ","   ","   ","   ","(b)"}
                                                  }, &board, expectedValidLocations, &file, &rank);
    
    // perform SUT and check that it returned the proper number of valid locations
    ASSERT_EQ(numberOfExpectedLocations, validMoves(&board, file, rank, validLocations));
    
    // compare the evaluated valid locations
    ASSERT_STREQ(expectedValidLocations, validLocations);
}

