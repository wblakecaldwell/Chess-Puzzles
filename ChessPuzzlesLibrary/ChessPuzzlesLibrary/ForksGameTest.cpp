//
//  ForksGameTest.cpp
//  ChessPuzzlesLibrary
//
//  Created by Blake Caldwell on 2/18/14.
//  Copyright (c) 2014 Blake Caldwell. All rights reserved.
//

#include <stdio.h>
#include <gtest/gtest.h>
#include "ChessBoardTestHelpers.h"
extern "C" {
#include "ChessBoard.h"
#include "ForksGame.h"
}


// test findForkedSquares for a simple scenario
TEST(ForksGame_findForkedSquares, test1)
{
    enum ChessBoardRank rank;               // ignored
    enum ChessBoardFile file;               // ignored
    
    struct ChessBoard board;
    char expectedForkedSquares[65];
    int numberOfExpectedForkedSquares;
    char forkedSquares[65];
    
    numberOfExpectedForkedSquares = parseTestingBoard((char [][8][8])
                                                      {
                                                          {"   ","   ","   ","   ","   ","   ","   ","   "},
                                                          {"   ","   ","   ","   ","   ","   ","   ","   "},
                                                          {"   ","   ","[ ]","   ","[ ]","   ","   ","   "},
                                                          {"   ","[ ]","   ","   ","   ","   ","   ","   "},
                                                          {"   ","   "," Q "," N ","   ","   ","   ","   "},
                                                          {"   ","[ ]","   ","   ","   ","   ","   ","   "},
                                                          {"   ","   ","[ ]","   ","[ ]","   ","   ","   "},
                                                          {"   ","   ","   ","   ","   ","   ","   ","   "}
                                                      }, &board, expectedForkedSquares, &file, &rank, false);
    
    // perform SUT and check that it returned the proper number of valid locations
    ASSERT_EQ(numberOfExpectedForkedSquares, findForkedSquares(&board, WHITE, forkedSquares));
    
    // compare the evaluated valid locations
    ASSERT_STREQ(expectedForkedSquares, forkedSquares);
}

TEST(ForksGame_findForkedSquares, testIncludingPawn)
{
    enum ChessBoardRank rank;               // ignored
    enum ChessBoardFile file;               // ignored
    
    struct ChessBoard board;
    char expectedForkedSquares[65];
    int numberOfExpectedForkedSquares;
    char forkedSquares[65];
    
    numberOfExpectedForkedSquares = parseTestingBoard((char [][8][8])
                                                      {
                                                          {"   ","   ","   ","   ","   ","   ","   ","   "},
                                                          {"   ","   ","   ","   ","   ","   ","   ","   "},
                                                          {"   ","   ","[ ]","   ","[ ]","   ","   ","   "},
                                                          {"   ","[ ]","   ","[ ]","   ","[ ]","   ","   "},
                                                          {"   ","   "," Q "," N "," P ","   ","   ","   "},
                                                          {"   ","[ ]","   ","   ","   ","   ","   ","   "},
                                                          {"   ","   ","[ ]","   ","[ ]","   ","   ","   "},
                                                          {"   ","   ","   ","   ","   ","   ","   ","   "}
                                                      }, &board, expectedForkedSquares, &file, &rank, false);
    
    // perform SUT and check that it returned the proper number of valid locations
    ASSERT_EQ(numberOfExpectedForkedSquares, findForkedSquares(&board, WHITE, forkedSquares));
    
    // compare the evaluated valid locations
    ASSERT_STREQ(expectedForkedSquares, forkedSquares);
}

// TODO: MANY MORE TESTS
