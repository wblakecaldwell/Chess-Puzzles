//
//  ChessBoard_WhiteBishopTests.cpp
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

// test validMoves for left white bishop on a fresh board
TEST(ChessBoard_validMoves, leftWhiteBishopWithFreshBoard)
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
                                                      {"   ","   ","   ","   ","   ","   ","   ","   "},
                                                      {" P "," P "," P "," P "," P "," P "," P "," P "},
                                                      {" R "," N ","(B)"," Q "," K "," B "," N "," R "}
                                                  }, &board, expectedValidLocations, &file, &rank);
    
    // perform SUT and check that it returned the proper number of valid locations
    ASSERT_EQ(numberOfExpectedLocations, validMoves(&board, file, rank, validLocations));
    
    // compare the evaluated valid locations
    ASSERT_STREQ(expectedValidLocations, validLocations);
}

// test validMoves for right white bishop on a fresh board
TEST(ChessBoard_validMoves, rightWhiteBishopWithFreshBoard)
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
                                                      {"   ","   ","   ","   ","   ","   ","   ","   "},
                                                      {" P "," P "," P "," P "," P "," P "," P "," P "},
                                                      {" R "," N "," B "," Q "," K ","(B)"," N "," R "}
                                                  }, &board, expectedValidLocations, &file, &rank);
    
    // perform SUT and check that it returned the proper number of valid locations
    ASSERT_EQ(numberOfExpectedLocations, validMoves(&board, file, rank, validLocations));
    
    // compare the evaluated valid locations
    ASSERT_STREQ(expectedValidLocations, validLocations);
}

// test validMoves for right white bishop on an empty board - in middle
TEST(ChessBoard_validMoves, whiteBishopWithEmptyBoardInMiddle)
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
                                                      {"   ","   ","   ","(B)","   ","   ","   ","   "},
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

// test validMoves for right white bishop on an empty board - left side
TEST(ChessBoard_validMoves, whiteBishopWithEmptyBoardLeftSide)
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
                                                      {"(B)","   ","   ","   ","   ","   ","   ","   "},
                                                      {"   ","[ ]","   ","   ","   ","   ","   ","   "},
                                                      {"   ","   ","[ ]","   ","   ","   ","   ","   "},
                                                      {"   ","   ","   ","[ ]","   ","   ","   ","   "}
                                                  }, &board, expectedValidLocations, &file, &rank);
    
    // perform SUT and check that it returned the proper number of valid locations
    ASSERT_EQ(numberOfExpectedLocations, validMoves(&board, file, rank, validLocations));
    
    // compare the evaluated valid locations
    ASSERT_STREQ(expectedValidLocations, validLocations);
}

// test validMoves for right white bishop on an empty board - right side
TEST(ChessBoard_validMoves, whiteBishopWithEmptyBoardRightSide)
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
                                                      {"   ","   ","   ","   ","   ","   ","   ","(B)"},
                                                      {"   ","   ","   ","   ","   ","   ","[ ]","   "},
                                                      {"   ","   ","   ","   ","   ","[ ]","   ","   "},
                                                      {"   ","   ","   ","   ","[ ]","   ","   ","   "}
                                                  }, &board, expectedValidLocations, &file, &rank);
    
    // perform SUT and check that it returned the proper number of valid locations
    ASSERT_EQ(numberOfExpectedLocations, validMoves(&board, file, rank, validLocations));
    
    // compare the evaluated valid locations
    ASSERT_STREQ(expectedValidLocations, validLocations);
}

// test validMoves for right white bishop on an empty board - top left corner
TEST(ChessBoard_validMoves, whiteBishopWithEmptyBoardTopLeftCorner)
{
    enum ChessBoardRank rank;               // rank of the piece we're watching
    enum ChessBoardFile file;               // file of the piece we're watching
    struct ChessBoard board;
    char expectedValidLocations[65];        // what we expect the valid moves to be
    int numberOfExpectedLocations;          // expected number of valid moves
    char validLocations[65];                // the valid moves that are determined
    
    numberOfExpectedLocations = parseTestingBoard((char [][8][8])
                                                  {
                                                      {"(B)","   ","   ","   ","   ","   ","   ","   "},
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

// test validMoves for right white bishop on an empty board - top right corner
TEST(ChessBoard_validMoves, whiteBishopWithEmptyBoardTopRightCorner)
{
    enum ChessBoardRank rank;               // rank of the piece we're watching
    enum ChessBoardFile file;               // file of the piece we're watching
    struct ChessBoard board;
    char expectedValidLocations[65];        // what we expect the valid moves to be
    int numberOfExpectedLocations;          // expected number of valid moves
    char validLocations[65];                // the valid moves that are determined
    
    numberOfExpectedLocations = parseTestingBoard((char [][8][8])
                                                  {
                                                      {"   ","   ","   ","   ","   ","   ","   ","(B)"},
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

// test validMoves for right white bishop on an empty board - bottom left corner
TEST(ChessBoard_validMoves, whiteBishopWithEmptyBoardBottomLeftCorner)
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
                                                      {"(B)","   ","   ","   ","   ","   ","   ","   "}
                                                  }, &board, expectedValidLocations, &file, &rank);
    
    // perform SUT and check that it returned the proper number of valid locations
    ASSERT_EQ(numberOfExpectedLocations, validMoves(&board, file, rank, validLocations));
    
    // compare the evaluated valid locations
    ASSERT_STREQ(expectedValidLocations, validLocations);
}

// test validMoves for right white bishop on an empty board - bottom right corner
TEST(ChessBoard_validMoves, whiteBishopWithEmptyBoardBottomRightCorner)
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
                                                      {"   ","   ","   ","   ","   ","   ","   ","(B)"}
                                                  }, &board, expectedValidLocations, &file, &rank);
    
    // perform SUT and check that it returned the proper number of valid locations
    ASSERT_EQ(numberOfExpectedLocations, validMoves(&board, file, rank, validLocations));
    
    // compare the evaluated valid locations
    ASSERT_STREQ(expectedValidLocations, validLocations);
}

// test validMoves for white bishop on an empty board - in middle - various pieces on board
TEST(ChessBoard_validMoves, whiteBishopdInMiddleVariousPieces)
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
                                                      {"   ","[k]","   ","   ","   ","   ","   ","   "},
                                                      {"   ","   ","[ ]","   ","[b]","   ","   ","   "},
                                                      {"   ","   ","   ","(B)","   ","   ","   ","   "},
                                                      {"   ","   ","[ ]","   "," K ","   ","   ","   "},
                                                      {"   ","[ ]","   ","   ","   ","   ","   ","   "},
                                                      {"[ ]","   ","   ","   ","   ","   ","   ","   "},
                                                      {"   ","   ","   ","   ","   ","   ","   ","   "}
                                                  }, &board, expectedValidLocations, &file, &rank);
    
    // perform SUT and check that it returned the proper number of valid locations
    ASSERT_EQ(numberOfExpectedLocations, validMoves(&board, file, rank, validLocations));
    
    // compare the evaluated valid locations
    ASSERT_STREQ(expectedValidLocations, validLocations);
}

// test validMoves for right white bishop on an empty board - left side - various pieces on board
TEST(ChessBoard_validMoves, whiteBishopLeftSideVariousPieces)
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
                                                      {"   ","   "," Q ","   ","   ","   ","   ","   "},
                                                      {"   ","[ ]","   ","   ","   ","   ","   ","   "},
                                                      {"(B)","   ","   ","   ","   ","   ","   ","   "},
                                                      {"   ","[ ]","   ","   ","   ","   ","   ","   "},
                                                      {"   ","   ","[k]","   ","   ","   ","   ","   "},
                                                      {"   ","   ","   ","   ","   ","   ","   ","   "}
                                                  }, &board, expectedValidLocations, &file, &rank);
    
    // perform SUT and check that it returned the proper number of valid locations
    ASSERT_EQ(numberOfExpectedLocations, validMoves(&board, file, rank, validLocations));
    
    // compare the evaluated valid locations
    ASSERT_STREQ(expectedValidLocations, validLocations);
}

// test validMoves for right white bishop on an empty board - right side - various pieces on board
TEST(ChessBoard_validMoves, whiteBishopRightSideVariousPieces)
{
    enum ChessBoardRank rank;               // rank of the piece we're watching
    enum ChessBoardFile file;               // file of the piece we're watching
    struct ChessBoard board;
    char expectedValidLocations[65];        // what we expect the valid moves to be
    int numberOfExpectedLocations;          // expected number of valid moves
    char validLocations[65];                // the valid moves that are determined
    
    numberOfExpectedLocations = parseTestingBoard((char [][8][8])
                                                  {
                                                      {"   ","   ","   ","[b]","   ","   ","   ","   "},
                                                      {"   ","   ","   ","   ","[ ]","   ","   ","   "},
                                                      {"   ","   ","   ","   ","   ","[ ]","   ","   "},
                                                      {"   ","   ","   ","   ","   ","   ","[ ]","   "},
                                                      {"   ","   ","   ","   ","   ","   ","   ","(B)"},
                                                      {"   ","   ","   ","   ","   ","   ","[ ]","   "},
                                                      {"   ","   ","   ","   ","   ","[k]","   ","   "},
                                                      {"   ","   ","   ","   ","   ","   ","   ","   "}
                                                  }, &board, expectedValidLocations, &file, &rank);
    
    // perform SUT and check that it returned the proper number of valid locations
    ASSERT_EQ(numberOfExpectedLocations, validMoves(&board, file, rank, validLocations));
    
    // compare the evaluated valid locations
    ASSERT_STREQ(expectedValidLocations, validLocations);
}

// test validMoves for right white bishop on an empty board - top left corner - various pieces on board
TEST(ChessBoard_validMoves, whiteBishopTopLeftCornerVariousPieces)
{
    enum ChessBoardRank rank;               // rank of the piece we're watching
    enum ChessBoardFile file;               // file of the piece we're watching
    struct ChessBoard board;
    char expectedValidLocations[65];        // what we expect the valid moves to be
    int numberOfExpectedLocations;          // expected number of valid moves
    char validLocations[65];                // the valid moves that are determined
    
    numberOfExpectedLocations = parseTestingBoard((char [][8][8])
                                                  {
                                                      {"(B)","   ","   ","   ","   ","   ","   ","   "},
                                                      {"   ","[ ]","   ","   ","   ","   ","   ","   "},
                                                      {"   ","   ","[ ]","   ","   ","   ","   ","   "},
                                                      {"   ","   ","   ","[ ]","   ","   ","   ","   "},
                                                      {"   ","   ","   ","   ","[ ]","   ","   ","   "},
                                                      {"   ","   ","   ","   ","   "," B ","   ","   "},
                                                      {"   ","   ","   ","   ","   ","   ","   ","   "},
                                                      {"   ","   ","   ","   ","   ","   ","   ","   "}
                                                  }, &board, expectedValidLocations, &file, &rank);
    
    // perform SUT and check that it returned the proper number of valid locations
    ASSERT_EQ(numberOfExpectedLocations, validMoves(&board, file, rank, validLocations));
    
    // compare the evaluated valid locations
    ASSERT_STREQ(expectedValidLocations, validLocations);
}

// test validMoves for right white bishop on an empty board - top right corner - various pieces on board
TEST(ChessBoard_validMoves, whiteBishopTopRightCornerVariousPieces)
{
    enum ChessBoardRank rank;               // rank of the piece we're watching
    enum ChessBoardFile file;               // file of the piece we're watching
    struct ChessBoard board;
    char expectedValidLocations[65];        // what we expect the valid moves to be
    int numberOfExpectedLocations;          // expected number of valid moves
    char validLocations[65];                // the valid moves that are determined
    
    numberOfExpectedLocations = parseTestingBoard((char [][8][8])
                                                  {
                                                      {"   ","   ","   ","   ","   ","   ","   ","(B)"},
                                                      {"   ","   ","   ","   ","   ","   ","[ ]","   "},
                                                      {"   ","   ","   ","   ","   ","[ ]","   ","   "},
                                                      {"   ","   ","   ","   ","[ ]","   ","   ","   "},
                                                      {"   ","   ","   ","[ ]","   ","   ","   ","   "},
                                                      {"   ","   ","[q]","   ","   ","   ","   ","   "},
                                                      {"   ","   ","   ","   ","   ","   ","   ","   "},
                                                      {"   ","   ","   ","   ","   ","   ","   ","   "}
                                                  }, &board, expectedValidLocations, &file, &rank);
    
    // perform SUT and check that it returned the proper number of valid locations
    ASSERT_EQ(numberOfExpectedLocations, validMoves(&board, file, rank, validLocations));
    
    // compare the evaluated valid locations
    ASSERT_STREQ(expectedValidLocations, validLocations);
}

// test validMoves for right white bishop on an empty board - bottom left corner - various pieces on board
TEST(ChessBoard_validMoves, whiteBishopBottomLeftCornerVariousPieces)
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
                                                      {"   ","   ","   "," q ","   ","   ","   ","   "},
                                                      {"   ","   "," Q ","   ","   ","   ","   ","   "},
                                                      {"   ","[ ]","   ","   ","   ","   ","   ","   "},
                                                      {"(B)","   ","   ","   ","   ","   ","   ","   "}
                                                  }, &board, expectedValidLocations, &file, &rank);
    
    // perform SUT and check that it returned the proper number of valid locations
    ASSERT_EQ(numberOfExpectedLocations, validMoves(&board, file, rank, validLocations));
    
    // compare the evaluated valid locations
    ASSERT_STREQ(expectedValidLocations, validLocations);
}

// test validMoves for right white bishop on an empty board - bottom right corner - various pieces on board
TEST(ChessBoard_validMoves, whiteBishopBottomRightCornerVariousPieces)
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
                                                      {"   ","   ","   ","   ","   ","   "," Q ","   "},
                                                      {"   ","   ","   ","   ","   ","   ","   ","(B)"}
                                                  }, &board, expectedValidLocations, &file, &rank);
    
    // perform SUT and check that it returned the proper number of valid locations
    ASSERT_EQ(numberOfExpectedLocations, validMoves(&board, file, rank, validLocations));
    
    // compare the evaluated valid locations
    ASSERT_STREQ(expectedValidLocations, validLocations);
}

