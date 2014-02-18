//
//  ChessBoard_WhiteQueenTests.cpp
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

// test validMoves for left white queen on a fresh board
TEST(ChessBoard_validMoves, whiteQueenWithFreshBoard)
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
                                                      {" R "," N "," B ","(Q)"," K "," B "," N "," R "}
                                                  }, &board, expectedValidLocations, &file, &rank);
    
    // perform SUT and check that it returned the proper number of valid locations
    ASSERT_EQ(numberOfExpectedLocations, validMoves(&board, file, rank, validLocations));
    
    // compare the evaluated valid locations
    ASSERT_STREQ(expectedValidLocations, validLocations);
}

// test validMoves for right white queen on an empty board - in middle
TEST(ChessBoard_validMoves, whiteQueenWithEmptyBoardInMiddle)
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
                                                      {"[ ]","[ ]","[ ]","(Q)","[ ]","[ ]","[ ]","[ ]"},
                                                      {"   ","   ","[ ]","[ ]","[ ]","   ","   ","   "},
                                                      {"   ","[ ]","   ","[ ]","   ","[ ]","   ","   "},
                                                      {"[ ]","   ","   ","[ ]","   ","   ","[ ]","   "},
                                                      {"   ","   ","   ","[ ]","   ","   ","   ","[ ]"}
                                                  }, &board, expectedValidLocations, &file, &rank);
    
    // perform SUT and check that it returned the proper number of valid locations
    ASSERT_EQ(numberOfExpectedLocations, validMoves(&board, file, rank, validLocations));
    
    // compare the evaluated valid locations
    ASSERT_STREQ(expectedValidLocations, validLocations);
}

// test validMoves for right white queen on an empty board - left side
TEST(ChessBoard_validMoves, whiteQueenWithEmptyBoardLeftSide)
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
                                                      {"(Q)","[ ]","[ ]","[ ]","[ ]","[ ]","[ ]","[ ]"},
                                                      {"[ ]","[ ]","   ","   ","   ","   ","   ","   "},
                                                      {"[ ]","   ","[ ]","   ","   ","   ","   ","   "},
                                                      {"[ ]","   ","   ","[ ]","   ","   ","   ","   "}
                                                  }, &board, expectedValidLocations, &file, &rank);
    
    // perform SUT and check that it returned the proper number of valid locations
    ASSERT_EQ(numberOfExpectedLocations, validMoves(&board, file, rank, validLocations));
    
    // compare the evaluated valid locations
    ASSERT_STREQ(expectedValidLocations, validLocations);
}

// test validMoves for right white queen on an empty board - right side
TEST(ChessBoard_validMoves, whiteQueenWithEmptyBoardRightSide)
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
                                                      {"[ ]","[ ]","[ ]","[ ]","[ ]","[ ]","[ ]","(Q)"},
                                                      {"   ","   ","   ","   ","   ","   ","[ ]","[ ]"},
                                                      {"   ","   ","   ","   ","   ","[ ]","   ","[ ]"},
                                                      {"   ","   ","   ","   ","[ ]","   ","   ","[ ]"}
                                                  }, &board, expectedValidLocations, &file, &rank);
    
    // perform SUT and check that it returned the proper number of valid locations
    ASSERT_EQ(numberOfExpectedLocations, validMoves(&board, file, rank, validLocations));
    
    // compare the evaluated valid locations
    ASSERT_STREQ(expectedValidLocations, validLocations);
}

// test validMoves for right white queen on an empty board - top left corner
TEST(ChessBoard_validMoves, whiteQueenWithEmptyBoardTopLeftCorner)
{
    enum ChessBoardRank rank;               // rank of the piece we're watching
    enum ChessBoardFile file;               // file of the piece we're watching
    struct ChessBoard board;
    char expectedValidLocations[65];        // what we expect the valid moves to be
    int numberOfExpectedLocations;          // expected number of valid moves
    char validLocations[65];                // the valid moves that are determined
    
    numberOfExpectedLocations = parseTestingBoard((char [][8][8])
                                                  {
                                                      {"(Q)","[ ]","[ ]","[ ]","[ ]","[ ]","[ ]","[ ]"},
                                                      {"[ ]","[ ]","   ","   ","   ","   ","   ","   "},
                                                      {"[ ]","   ","[ ]","   ","   ","   ","   ","   "},
                                                      {"[ ]","   ","   ","[ ]","   ","   ","   ","   "},
                                                      {"[ ]","   ","   ","   ","[ ]","   ","   ","   "},
                                                      {"[ ]","   ","   ","   ","   ","[ ]","   ","   "},
                                                      {"[ ]","   ","   ","   ","   ","   ","[ ]","   "},
                                                      {"[ ]","   ","   ","   ","   ","   ","   ","[ ]"}
                                                  }, &board, expectedValidLocations, &file, &rank);
    
    // perform SUT and check that it returned the proper number of valid locations
    ASSERT_EQ(numberOfExpectedLocations, validMoves(&board, file, rank, validLocations));
    
    // compare the evaluated valid locations
    ASSERT_STREQ(expectedValidLocations, validLocations);
}

// test validMoves for right white queen on an empty board - top right corner
TEST(ChessBoard_validMoves, whiteQueenWithEmptyBoardTopRightCorner)
{
    enum ChessBoardRank rank;               // rank of the piece we're watching
    enum ChessBoardFile file;               // file of the piece we're watching
    struct ChessBoard board;
    char expectedValidLocations[65];        // what we expect the valid moves to be
    int numberOfExpectedLocations;          // expected number of valid moves
    char validLocations[65];                // the valid moves that are determined
    
    numberOfExpectedLocations = parseTestingBoard((char [][8][8])
                                                  {
                                                      {"[ ]","[ ]","[ ]","[ ]","[ ]","[ ]","[ ]","(Q)"},
                                                      {"   ","   ","   ","   ","   ","   ","[ ]","[ ]"},
                                                      {"   ","   ","   ","   ","   ","[ ]","   ","[ ]"},
                                                      {"   ","   ","   ","   ","[ ]","   ","   ","[ ]"},
                                                      {"   ","   ","   ","[ ]","   ","   ","   ","[ ]"},
                                                      {"   ","   ","[ ]","   ","   ","   ","   ","[ ]"},
                                                      {"   ","[ ]","   ","   ","   ","   ","   ","[ ]"},
                                                      {"[ ]","   ","   ","   ","   ","   ","   ","[ ]"}
                                                  }, &board, expectedValidLocations, &file, &rank);
    
    // perform SUT and check that it returned the proper number of valid locations
    ASSERT_EQ(numberOfExpectedLocations, validMoves(&board, file, rank, validLocations));
    
    // compare the evaluated valid locations
    ASSERT_STREQ(expectedValidLocations, validLocations);
}

// test validMoves for right white queen on an empty board - bottom left corner
TEST(ChessBoard_validMoves, whiteQueenWithEmptyBoardBottomLeftCorner)
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
                                                      {"(Q)","[ ]","[ ]","[ ]","[ ]","[ ]","[ ]","[ ]"}
                                                  }, &board, expectedValidLocations, &file, &rank);
    
    // perform SUT and check that it returned the proper number of valid locations
    ASSERT_EQ(numberOfExpectedLocations, validMoves(&board, file, rank, validLocations));
    
    // compare the evaluated valid locations
    ASSERT_STREQ(expectedValidLocations, validLocations);
}

// test validMoves for right white queen on an empty board - bottom right corner
TEST(ChessBoard_validMoves, whiteQueenWithEmptyBoardBottomRightCorner)
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
                                                      {"[ ]","[ ]","[ ]","[ ]","[ ]","[ ]","[ ]","(Q)"}
                                                  }, &board, expectedValidLocations, &file, &rank);
    
    // perform SUT and check that it returned the proper number of valid locations
    ASSERT_EQ(numberOfExpectedLocations, validMoves(&board, file, rank, validLocations));
    
    // compare the evaluated valid locations
    ASSERT_STREQ(expectedValidLocations, validLocations);
}

// test validMoves for white queen on an empty board - in middle - various pieces on board
TEST(ChessBoard_validMoves, whiteQueendInMiddleVariousPieces)
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
                                                      {"   ","[k]","   ","[p]","   ","   ","   ","   "},
                                                      {"   ","   ","[ ]","[ ]","[b]","   ","   ","   "},
                                                      {"   ","   "," P ","(Q)","[ ]","[p]","   ","   "},
                                                      {"   ","   ","[ ]","[ ]"," K ","   ","   ","   "},
                                                      {"   ","[ ]","   ","[ ]","   ","   ","   ","   "},
                                                      {"[ ]","   ","   ","[ ]","   ","   ","   ","   "},
                                                      {"   ","   ","   "," N ","   ","   ","   ","   "}
                                                  }, &board, expectedValidLocations, &file, &rank);
    
    // perform SUT and check that it returned the proper number of valid locations
    ASSERT_EQ(numberOfExpectedLocations, validMoves(&board, file, rank, validLocations));
    
    // compare the evaluated valid locations
    ASSERT_STREQ(expectedValidLocations, validLocations);
}

// test validMoves for right white queen on an empty board - left side - various pieces on board
TEST(ChessBoard_validMoves, whiteQueenLeftSideVariousPieces)
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
                                                      {"   ","   "," B ","   ","   ","   ","   ","   "},
                                                      {" P ","[ ]","   ","   ","   ","   ","   ","   "},
                                                      {"(Q)","[ ]","[ ]","[ ]","[p]","   ","   ","   "},
                                                      {"[ ]","[ ]","   ","   ","   ","   ","   ","   "},
                                                      {"[ ]","   ","[k]","   ","   ","   ","   ","   "},
                                                      {" N ","   ","   ","   ","   ","   ","   ","   "}
                                                  }, &board, expectedValidLocations, &file, &rank);
    
    // perform SUT and check that it returned the proper number of valid locations
    ASSERT_EQ(numberOfExpectedLocations, validMoves(&board, file, rank, validLocations));
    
    // compare the evaluated valid locations
    ASSERT_STREQ(expectedValidLocations, validLocations);
}

// test validMoves for right white queen on an empty board - right side - various pieces on board
TEST(ChessBoard_validMoves, whiteQueenRightSideVariousPieces)
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
                                                      {"   ","   ","   ","   ","[ ]","   ","   "," P "},
                                                      {"   ","   ","   ","   ","   ","[ ]","   ","[ ]"},
                                                      {"   ","   ","   ","   ","   ","   ","[ ]","[ ]"},
                                                      {"   ","   ","[p]","[ ]","[ ]","[ ]","[ ]","(Q)"},
                                                      {"   ","   ","   ","   ","   ","   ","[ ]","[ ]"},
                                                      {"   ","   ","   ","   ","   ","[k]","   ","[ ]"},
                                                      {"   ","   ","   ","   ","   ","   ","   ","[b]"}
                                                  }, &board, expectedValidLocations, &file, &rank);
    
    // perform SUT and check that it returned the proper number of valid locations
    ASSERT_EQ(numberOfExpectedLocations, validMoves(&board, file, rank, validLocations));
    
    // compare the evaluated valid locations
    ASSERT_STREQ(expectedValidLocations, validLocations);
}

// test validMoves for right white queen on an empty board - top left corner - various pieces on board
TEST(ChessBoard_validMoves, whiteQueenTopLeftCornerVariousPieces)
{
    enum ChessBoardRank rank;               // rank of the piece we're watching
    enum ChessBoardFile file;               // file of the piece we're watching
    struct ChessBoard board;
    char expectedValidLocations[65];        // what we expect the valid moves to be
    int numberOfExpectedLocations;          // expected number of valid moves
    char validLocations[65];                // the valid moves that are determined
    
    numberOfExpectedLocations = parseTestingBoard((char [][8][8])
                                                  {
                                                      {"(Q)","[ ]","[ ]","[ ]","[ ]","[k]","   ","   "},
                                                      {"[ ]","[ ]","   ","   ","   ","   ","   ","   "},
                                                      {"[ ]","   ","[ ]","   ","   ","   ","   ","   "},
                                                      {"[ ]","   ","   ","[ ]","   ","   ","   ","   "},
                                                      {"[ ]","   ","   ","   ","[ ]","   ","   ","   "},
                                                      {" Q ","   ","   ","   ","   "," B ","   ","   "},
                                                      {"   ","   ","   ","   ","   ","   ","   ","   "},
                                                      {"   ","   ","   ","   ","   ","   ","   ","   "}
                                                  }, &board, expectedValidLocations, &file, &rank);
    
    // perform SUT and check that it returned the proper number of valid locations
    ASSERT_EQ(numberOfExpectedLocations, validMoves(&board, file, rank, validLocations));
    
    // compare the evaluated valid locations
    ASSERT_STREQ(expectedValidLocations, validLocations);
}

// test validMoves for right white queen on an empty board - top right corner - various pieces on board
TEST(ChessBoard_validMoves, whiteQueenTopRightCornerVariousPieces)
{
    enum ChessBoardRank rank;               // rank of the piece we're watching
    enum ChessBoardFile file;               // file of the piece we're watching
    struct ChessBoard board;
    char expectedValidLocations[65];        // what we expect the valid moves to be
    int numberOfExpectedLocations;          // expected number of valid moves
    char validLocations[65];                // the valid moves that are determined
    
    numberOfExpectedLocations = parseTestingBoard((char [][8][8])
                                                  {
                                                      {"   ","   ","   ","   ","   ","   "," K ","(Q)"},
                                                      {"   ","   ","   ","   ","   ","   ","[ ]","[ ]"},
                                                      {"   ","   ","   ","   ","   ","[ ]","   ","[ ]"},
                                                      {"   ","   ","   ","   ","[ ]","   ","   ","[ ]"},
                                                      {"   ","   ","   ","[ ]","   ","   ","   ","[ ]"},
                                                      {"   ","   ","[q]","   ","   ","   ","   ","[ ]"},
                                                      {"   ","   ","   ","   ","   ","   ","   ","[ ]"},
                                                      {"   ","   ","   ","   ","   ","   ","   ","[k]"}
                                                  }, &board, expectedValidLocations, &file, &rank);
    
    // perform SUT and check that it returned the proper number of valid locations
    ASSERT_EQ(numberOfExpectedLocations, validMoves(&board, file, rank, validLocations));
    
    // compare the evaluated valid locations
    ASSERT_STREQ(expectedValidLocations, validLocations);
}

// test validMoves for right white queen on an empty board - bottom left corner - various pieces on board
TEST(ChessBoard_validMoves, whiteQueenBottomLeftCornerVariousPieces)
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
                                                      {" K ","   ","   ","   ","   ","   ","   ","   "},
                                                      {"[ ]","   ","   ","   ","   ","   ","   ","   "},
                                                      {"[ ]","   ","   "," q ","   ","   ","   ","   "},
                                                      {"[ ]","   "," Q ","   ","   ","   ","   ","   "},
                                                      {"[ ]","[ ]","   ","   ","   ","   ","   ","   "},
                                                      {"(Q)","[ ]","[ ]","[ ]","[ ]","[k]"," b ","   "}
                                                  }, &board, expectedValidLocations, &file, &rank);
    
    // perform SUT and check that it returned the proper number of valid locations
    ASSERT_EQ(numberOfExpectedLocations, validMoves(&board, file, rank, validLocations));
    
    // compare the evaluated valid locations
    ASSERT_STREQ(expectedValidLocations, validLocations);
}

// test validMoves for right white queen on an empty board - bottom right corner - various pieces on board
TEST(ChessBoard_validMoves, whiteQueenBottomRightCornerVariousPieces)
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
                                                      {"   ","   ","   ","   ","   "," k ","   ","[ ]"},
                                                      {"   ","   ","   ","   ","   ","   "," B ","[ ]"},
                                                      {"   ","   ","   ","   "," n ","[b]","[ ]","(Q)"}
                                                  }, &board, expectedValidLocations, &file, &rank);
    
    // perform SUT and check that it returned the proper number of valid locations
    ASSERT_EQ(numberOfExpectedLocations, validMoves(&board, file, rank, validLocations));
    
    // compare the evaluated valid locations
    ASSERT_STREQ(expectedValidLocations, validLocations);
}

