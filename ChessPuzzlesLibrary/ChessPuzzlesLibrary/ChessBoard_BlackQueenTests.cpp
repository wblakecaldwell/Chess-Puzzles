//
//  ChessBoard_BlackQueenTests.cpp
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

// test validMoves for left black queen on a fresh board
TEST(ChessBoard_validMoves, blackQueenWithFreshBoard)
{
    enum ChessBoardRank rank;               // rank of the piece we're watching
    enum ChessBoardFile file;               // file of the piece we're watching
    struct ChessBoard board;
    char expectedValidLocations[65];        // what we expect the valid moves to be
    int numberOfExpectedLocations;          // expected number of valid moves
    char validLocations[65];                // the valid moves that are determined
    
    numberOfExpectedLocations = parseTestingBoard((char [][8][8])
                                                  {
                                                      {" r "," n "," b ","(q)"," k "," b "," n "," r "},
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

// test validMoves for right black queen on an empty board - in middle
TEST(ChessBoard_validMoves, blackQueenWithEmptyBoardInMiddle)
{
    enum ChessBoardRank rank;               // rank of the piece we're watching
    enum ChessBoardFile file;               // file of the piece we're watching
    struct ChessBoard board;
    char expectedValidLocations[65];        // what we expect the valid moves to be
    int numberOfExpectedLocations;          // expected number of valid moves
    char validLocations[65];                // the valid moves that are determined
    
    numberOfExpectedLocations = parseTestingBoard((char [][8][8])
                                                  {
                                                      {"[ ]","   ","   ","[ ]","   ","   ","[ ]","   "},
                                                      {"   ","[ ]","   ","[ ]","   ","[ ]","   ","   "},
                                                      {"   ","   ","[ ]","[ ]","[ ]","   ","   ","   "},
                                                      {"[ ]","[ ]","[ ]","(q)","[ ]","[ ]","[ ]","[ ]"},
                                                      {"   ","   ","[ ]","[ ]","[ ]","   ","   ","   "},
                                                      {"   ","[ ]","   ","[ ]","   ","[ ]","   ","   "},
                                                      {"[ ]","   ","   ","[ ]","   ","   ","[ ]","   "},
                                                      {"   ","   ","   ","[ ]","   ","   ","   ","[ ]"}
                                                  }, &board, expectedValidLocations, &file, &rank, true);
    
    // perform SUT and check that it returned the proper number of valid locations
    ASSERT_EQ(numberOfExpectedLocations, validMoves(&board, file, rank, VALID_MOVE, validLocations));
    
    // compare the evaluated valid locations
    ASSERT_STREQ(expectedValidLocations, validLocations);
}

// test validMoves for right black queen on an empty board - left side
TEST(ChessBoard_validMoves, blackQueenWithEmptyBoardLeftSide)
{
    enum ChessBoardRank rank;               // rank of the piece we're watching
    enum ChessBoardFile file;               // file of the piece we're watching
    struct ChessBoard board;
    char expectedValidLocations[65];        // what we expect the valid moves to be
    int numberOfExpectedLocations;          // expected number of valid moves
    char validLocations[65];                // the valid moves that are determined
    
    numberOfExpectedLocations = parseTestingBoard((char [][8][8])
                                                  {
                                                      {"[ ]","   ","   ","   ","[ ]","   ","   ","   "},
                                                      {"[ ]","   ","   ","[ ]","   ","   ","   ","   "},
                                                      {"[ ]","   ","[ ]","   ","   ","   ","   ","   "},
                                                      {"[ ]","[ ]","   ","   ","   ","   ","   ","   "},
                                                      {"(q)","[ ]","[ ]","[ ]","[ ]","[ ]","[ ]","[ ]"},
                                                      {"[ ]","[ ]","   ","   ","   ","   ","   ","   "},
                                                      {"[ ]","   ","[ ]","   ","   ","   ","   ","   "},
                                                      {"[ ]","   ","   ","[ ]","   ","   ","   ","   "}
                                                  }, &board, expectedValidLocations, &file, &rank, true);
    
    // perform SUT and check that it returned the proper number of valid locations
    ASSERT_EQ(numberOfExpectedLocations, validMoves(&board, file, rank, VALID_MOVE, validLocations));
    
    // compare the evaluated valid locations
    ASSERT_STREQ(expectedValidLocations, validLocations);
}

// test validMoves for right black queen on an empty board - right side
TEST(ChessBoard_validMoves, blackQueenWithEmptyBoardRightSide)
{
    enum ChessBoardRank rank;               // rank of the piece we're watching
    enum ChessBoardFile file;               // file of the piece we're watching
    struct ChessBoard board;
    char expectedValidLocations[65];        // what we expect the valid moves to be
    int numberOfExpectedLocations;          // expected number of valid moves
    char validLocations[65];                // the valid moves that are determined
    
    numberOfExpectedLocations = parseTestingBoard((char [][8][8])
                                                  {
                                                      {"   ","   ","   ","[ ]","   ","   ","   ","[ ]"},
                                                      {"   ","   ","   ","   ","[ ]","   ","   ","[ ]"},
                                                      {"   ","   ","   ","   ","   ","[ ]","   ","[ ]"},
                                                      {"   ","   ","   ","   ","   ","   ","[ ]","[ ]"},
                                                      {"[ ]","[ ]","[ ]","[ ]","[ ]","[ ]","[ ]","(q)"},
                                                      {"   ","   ","   ","   ","   ","   ","[ ]","[ ]"},
                                                      {"   ","   ","   ","   ","   ","[ ]","   ","[ ]"},
                                                      {"   ","   ","   ","   ","[ ]","   ","   ","[ ]"}
                                                  }, &board, expectedValidLocations, &file, &rank, true);
    
    // perform SUT and check that it returned the proper number of valid locations
    ASSERT_EQ(numberOfExpectedLocations, validMoves(&board, file, rank, VALID_MOVE, validLocations));
    
    // compare the evaluated valid locations
    ASSERT_STREQ(expectedValidLocations, validLocations);
}

// test validMoves for right black queen on an empty board - top left corner
TEST(ChessBoard_validMoves, blackQueenWithEmptyBoardTopLeftCorner)
{
    enum ChessBoardRank rank;               // rank of the piece we're watching
    enum ChessBoardFile file;               // file of the piece we're watching
    struct ChessBoard board;
    char expectedValidLocations[65];        // what we expect the valid moves to be
    int numberOfExpectedLocations;          // expected number of valid moves
    char validLocations[65];                // the valid moves that are determined
    
    numberOfExpectedLocations = parseTestingBoard((char [][8][8])
                                                  {
                                                      {"(q)","[ ]","[ ]","[ ]","[ ]","[ ]","[ ]","[ ]"},
                                                      {"[ ]","[ ]","   ","   ","   ","   ","   ","   "},
                                                      {"[ ]","   ","[ ]","   ","   ","   ","   ","   "},
                                                      {"[ ]","   ","   ","[ ]","   ","   ","   ","   "},
                                                      {"[ ]","   ","   ","   ","[ ]","   ","   ","   "},
                                                      {"[ ]","   ","   ","   ","   ","[ ]","   ","   "},
                                                      {"[ ]","   ","   ","   ","   ","   ","[ ]","   "},
                                                      {"[ ]","   ","   ","   ","   ","   ","   ","[ ]"}
                                                  }, &board, expectedValidLocations, &file, &rank, true);
    
    // perform SUT and check that it returned the proper number of valid locations
    ASSERT_EQ(numberOfExpectedLocations, validMoves(&board, file, rank, VALID_MOVE, validLocations));
    
    // compare the evaluated valid locations
    ASSERT_STREQ(expectedValidLocations, validLocations);
}

// test validMoves for right black queen on an empty board - top right corner
TEST(ChessBoard_validMoves, blackQueenWithEmptyBoardTopRightCorner)
{
    enum ChessBoardRank rank;               // rank of the piece we're watching
    enum ChessBoardFile file;               // file of the piece we're watching
    struct ChessBoard board;
    char expectedValidLocations[65];        // what we expect the valid moves to be
    int numberOfExpectedLocations;          // expected number of valid moves
    char validLocations[65];                // the valid moves that are determined
    
    numberOfExpectedLocations = parseTestingBoard((char [][8][8])
                                                  {
                                                      {"[ ]","[ ]","[ ]","[ ]","[ ]","[ ]","[ ]","(q)"},
                                                      {"   ","   ","   ","   ","   ","   ","[ ]","[ ]"},
                                                      {"   ","   ","   ","   ","   ","[ ]","   ","[ ]"},
                                                      {"   ","   ","   ","   ","[ ]","   ","   ","[ ]"},
                                                      {"   ","   ","   ","[ ]","   ","   ","   ","[ ]"},
                                                      {"   ","   ","[ ]","   ","   ","   ","   ","[ ]"},
                                                      {"   ","[ ]","   ","   ","   ","   ","   ","[ ]"},
                                                      {"[ ]","   ","   ","   ","   ","   ","   ","[ ]"}
                                                  }, &board, expectedValidLocations, &file, &rank, true);
    
    // perform SUT and check that it returned the proper number of valid locations
    ASSERT_EQ(numberOfExpectedLocations, validMoves(&board, file, rank, VALID_MOVE, validLocations));
    
    // compare the evaluated valid locations
    ASSERT_STREQ(expectedValidLocations, validLocations);
}

// test validMoves for right black queen on an empty board - bottom left corner
TEST(ChessBoard_validMoves, blackQueenWithEmptyBoardBottomLeftCorner)
{
    enum ChessBoardRank rank;               // rank of the piece we're watching
    enum ChessBoardFile file;               // file of the piece we're watching
    struct ChessBoard board;
    char expectedValidLocations[65];        // what we expect the valid moves to be
    int numberOfExpectedLocations;          // expected number of valid moves
    char validLocations[65];                // the valid moves that are determined
    
    numberOfExpectedLocations = parseTestingBoard((char [][8][8])
                                                  {
                                                      {"[ ]","   ","   ","   ","   ","   ","   ","[ ]"},
                                                      {"[ ]","   ","   ","   ","   ","   ","[ ]","   "},
                                                      {"[ ]","   ","   ","   ","   ","[ ]","   ","   "},
                                                      {"[ ]","   ","   ","   ","[ ]","   ","   ","   "},
                                                      {"[ ]","   ","   ","[ ]","   ","   ","   ","   "},
                                                      {"[ ]","   ","[ ]","   ","   ","   ","   ","   "},
                                                      {"[ ]","[ ]","   ","   ","   ","   ","   ","   "},
                                                      {"(q)","[ ]","[ ]","[ ]","[ ]","[ ]","[ ]","[ ]"}
                                                  }, &board, expectedValidLocations, &file, &rank, true);
    
    // perform SUT and check that it returned the proper number of valid locations
    ASSERT_EQ(numberOfExpectedLocations, validMoves(&board, file, rank, VALID_MOVE, validLocations));
    
    // compare the evaluated valid locations
    ASSERT_STREQ(expectedValidLocations, validLocations);
}

// test validMoves for right black queen on an empty board - bottom right corner
TEST(ChessBoard_validMoves, blackQueenWithEmptyBoardBottomRightCorner)
{
    enum ChessBoardRank rank;               // rank of the piece we're watching
    enum ChessBoardFile file;               // file of the piece we're watching
    struct ChessBoard board;
    char expectedValidLocations[65];        // what we expect the valid moves to be
    int numberOfExpectedLocations;          // expected number of valid moves
    char validLocations[65];                // the valid moves that are determined
    
    numberOfExpectedLocations = parseTestingBoard((char [][8][8])
                                                  {
                                                      {"[ ]","   ","   ","   ","   ","   ","   ","[ ]"},
                                                      {"   ","[ ]","   ","   ","   ","   ","   ","[ ]"},
                                                      {"   ","   ","[ ]","   ","   ","   ","   ","[ ]"},
                                                      {"   ","   ","   ","[ ]","   ","   ","   ","[ ]"},
                                                      {"   ","   ","   ","   ","[ ]","   ","   ","[ ]"},
                                                      {"   ","   ","   ","   ","   ","[ ]","   ","[ ]"},
                                                      {"   ","   ","   ","   ","   ","   ","[ ]","[ ]"},
                                                      {"[ ]","[ ]","[ ]","[ ]","[ ]","[ ]","[ ]","(q)"}
                                                  }, &board, expectedValidLocations, &file, &rank, true);
    
    // perform SUT and check that it returned the proper number of valid locations
    ASSERT_EQ(numberOfExpectedLocations, validMoves(&board, file, rank, VALID_MOVE, validLocations));
    
    // compare the evaluated valid locations
    ASSERT_STREQ(expectedValidLocations, validLocations);
}

// test validMoves for black queen on an empty board - in middle - various pieces on board
TEST(ChessBoard_validMoves, blackQueendInMiddleVariousPieces)
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
                                                      {"   ","[K]","   ","[P]","   ","   ","   ","   "},
                                                      {"   ","   ","[ ]","[ ]","[B]","   ","   ","   "},
                                                      {"   ","   "," p ","(q)","[ ]","[P]","   ","   "},
                                                      {"   ","   ","[ ]","[ ]"," k ","   ","   ","   "},
                                                      {"   ","[ ]","   ","[ ]","   ","   ","   ","   "},
                                                      {"[ ]","   ","   ","[ ]","   ","   ","   ","   "},
                                                      {"   ","   ","   "," n ","   ","   ","   ","   "}
                                                  }, &board, expectedValidLocations, &file, &rank, true);
    
    // perform SUT and check that it returned the proper number of valid locations
    ASSERT_EQ(numberOfExpectedLocations, validMoves(&board, file, rank, VALID_MOVE, validLocations));
    
    // compare the evaluated valid locations
    ASSERT_STREQ(expectedValidLocations, validLocations);
}

// test validMoves for right black queen on an empty board - left side - various pieces on board
TEST(ChessBoard_validMoves, blackQueenLeftSideVariousPieces)
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
                                                      {"   ","   "," b ","   ","   ","   ","   ","   "},
                                                      {" p ","[ ]","   ","   ","   ","   ","   ","   "},
                                                      {"(q)","[ ]","[ ]","[ ]","[P]","   ","   ","   "},
                                                      {"[ ]","[ ]","   ","   ","   ","   ","   ","   "},
                                                      {"[ ]","   ","[K]","   ","   ","   ","   ","   "},
                                                      {" n ","   ","   ","   ","   ","   ","   ","   "}
                                                  }, &board, expectedValidLocations, &file, &rank, true);
    
    // perform SUT and check that it returned the proper number of valid locations
    ASSERT_EQ(numberOfExpectedLocations, validMoves(&board, file, rank, VALID_MOVE, validLocations));
    
    // compare the evaluated valid locations
    ASSERT_STREQ(expectedValidLocations, validLocations);
}

// test validMoves for right black queen on an empty board - right side - various pieces on board
TEST(ChessBoard_validMoves, blackQueenRightSideVariousPieces)
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
                                                      {"   ","   ","   ","   ","[ ]","   ","   "," p "},
                                                      {"   ","   ","   ","   ","   ","[ ]","   ","[ ]"},
                                                      {"   ","   ","   ","   ","   ","   ","[ ]","[ ]"},
                                                      {"   ","   ","[P]","[ ]","[ ]","[ ]","[ ]","(q)"},
                                                      {"   ","   ","   ","   ","   ","   ","[ ]","[ ]"},
                                                      {"   ","   ","   ","   ","   ","[K]","   ","[ ]"},
                                                      {"   ","   ","   ","   ","   ","   ","   ","[B]"}
                                                  }, &board, expectedValidLocations, &file, &rank, true);
    
    // perform SUT and check that it returned the proper number of valid locations
    ASSERT_EQ(numberOfExpectedLocations, validMoves(&board, file, rank, VALID_MOVE, validLocations));
    
    // compare the evaluated valid locations
    ASSERT_STREQ(expectedValidLocations, validLocations);
}

// test validMoves for right black queen on an empty board - top left corner - various pieces on board
TEST(ChessBoard_validMoves, blackQueenTopLeftCornerVariousPieces)
{
    enum ChessBoardRank rank;               // rank of the piece we're watching
    enum ChessBoardFile file;               // file of the piece we're watching
    struct ChessBoard board;
    char expectedValidLocations[65];        // what we expect the valid moves to be
    int numberOfExpectedLocations;          // expected number of valid moves
    char validLocations[65];                // the valid moves that are determined
    
    numberOfExpectedLocations = parseTestingBoard((char [][8][8])
                                                  {
                                                      {"(q)","[ ]","[ ]","[ ]","[ ]","[K]","   ","   "},
                                                      {"[ ]","[ ]","   ","   ","   ","   ","   ","   "},
                                                      {"[ ]","   ","[ ]","   ","   ","   ","   ","   "},
                                                      {"[ ]","   ","   ","[ ]","   ","   ","   ","   "},
                                                      {"[ ]","   ","   ","   ","[ ]","   ","   ","   "},
                                                      {" q ","   ","   ","   ","   "," b ","   ","   "},
                                                      {"   ","   ","   ","   ","   ","   ","   ","   "},
                                                      {"   ","   ","   ","   ","   ","   ","   ","   "}
                                                  }, &board, expectedValidLocations, &file, &rank, true);
    
    // perform SUT and check that it returned the proper number of valid locations
    ASSERT_EQ(numberOfExpectedLocations, validMoves(&board, file, rank, VALID_MOVE, validLocations));
    
    // compare the evaluated valid locations
    ASSERT_STREQ(expectedValidLocations, validLocations);
}

// test validMoves for right black queen on an empty board - top right corner - various pieces on board
TEST(ChessBoard_validMoves, blackQueenTopRightCornerVariousPieces)
{
    enum ChessBoardRank rank;               // rank of the piece we're watching
    enum ChessBoardFile file;               // file of the piece we're watching
    struct ChessBoard board;
    char expectedValidLocations[65];        // what we expect the valid moves to be
    int numberOfExpectedLocations;          // expected number of valid moves
    char validLocations[65];                // the valid moves that are determined
    
    numberOfExpectedLocations = parseTestingBoard((char [][8][8])
                                                  {
                                                      {"   ","   ","   ","   ","   ","   "," k ","(q)"},
                                                      {"   ","   ","   ","   ","   ","   ","[ ]","[ ]"},
                                                      {"   ","   ","   ","   ","   ","[ ]","   ","[ ]"},
                                                      {"   ","   ","   ","   ","[ ]","   ","   ","[ ]"},
                                                      {"   ","   ","   ","[ ]","   ","   ","   ","[ ]"},
                                                      {"   ","   ","[Q]","   ","   ","   ","   ","[ ]"},
                                                      {"   ","   ","   ","   ","   ","   ","   ","[ ]"},
                                                      {"   ","   ","   ","   ","   ","   ","   ","[K]"}
                                                  }, &board, expectedValidLocations, &file, &rank, true);
    
    // perform SUT and check that it returned the proper number of valid locations
    ASSERT_EQ(numberOfExpectedLocations, validMoves(&board, file, rank, VALID_MOVE, validLocations));
    
    // compare the evaluated valid locations
    ASSERT_STREQ(expectedValidLocations, validLocations);
}

// test validMoves for right black queen on an empty board - bottom left corner - various pieces on board
TEST(ChessBoard_validMoves, blackQueenBottomLeftCornerVariousPieces)
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
                                                      {" k ","   ","   ","   ","   ","   ","   ","   "},
                                                      {"[ ]","   ","   ","   ","   ","   ","   ","   "},
                                                      {"[ ]","   ","   "," Q ","   ","   ","   ","   "},
                                                      {"[ ]","   "," q ","   ","   ","   ","   ","   "},
                                                      {"[ ]","[ ]","   ","   ","   ","   ","   ","   "},
                                                      {"(q)","[ ]","[ ]","[ ]","[ ]","[K]"," B ","   "}
                                                  }, &board, expectedValidLocations, &file, &rank, true);
    
    // perform SUT and check that it returned the proper number of valid locations
    ASSERT_EQ(numberOfExpectedLocations, validMoves(&board, file, rank, VALID_MOVE, validLocations));
    
    // compare the evaluated valid locations
    ASSERT_STREQ(expectedValidLocations, validLocations);
}

// test validMoves for right black queen on an empty board - bottom right corner - various pieces on board
TEST(ChessBoard_validMoves, blackQueenBottomRightCornerVariousPieces)
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
                                                      {"   ","   ","   ","   ","   "," K ","   ","[ ]"},
                                                      {"   ","   ","   ","   ","   ","   "," b ","[ ]"},
                                                      {"   ","   ","   ","   "," N ","[B]","[ ]","(q)"}
                                                  }, &board, expectedValidLocations, &file, &rank, true);
    
    // perform SUT and check that it returned the proper number of valid locations
    ASSERT_EQ(numberOfExpectedLocations, validMoves(&board, file, rank, VALID_MOVE, validLocations));
    
    // compare the evaluated valid locations
    ASSERT_STREQ(expectedValidLocations, validLocations);
}

