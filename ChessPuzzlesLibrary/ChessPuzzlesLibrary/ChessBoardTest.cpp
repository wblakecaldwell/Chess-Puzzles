//
//  ChessBoardTest.c
//  ChessPuzzlesLibrary
//
//  Created by Blake Caldwell on 1/5/14.
//  Copyright (c) 2014 Blake Caldwell. All rights reserved.
//

#include <stdio.h>
#include <gtest/gtest.h>

extern "C" {
#include "ChessBoard.h"
}

TEST(ChessBoard, initializeForGame)
{
    struct ChessBoard board;
    initializeForGame(&board);
    
    ASSERT_STREQ("rnbqkbnr", board.pieces[7]);
    ASSERT_STREQ("pppppppp", board.pieces[6]);
    ASSERT_STREQ("\0\0\0\0\0\0\0\0", board.pieces[5]);
    ASSERT_STREQ("\0\0\0\0\0\0\0\0", board.pieces[4]);
    ASSERT_STREQ("\0\0\0\0\0\0\0\0", board.pieces[3]);
    ASSERT_STREQ("\0\0\0\0\0\0\0\0", board.pieces[2]);
    ASSERT_STREQ("PPPPPPPP", board.pieces[1]);
    ASSERT_STREQ("RNBQKBNR", board.pieces[0]);
}