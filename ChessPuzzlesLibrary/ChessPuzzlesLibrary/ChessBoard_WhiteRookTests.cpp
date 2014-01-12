//
//  ChessBoard_WhiteRookTests.cpp
//  ChessPuzzlesLibrary
//
//  Tests to assert valid moves for white rooks.
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

// test validMoves for white rook on a fresh board
TEST(ChessBoard_validMoves, whiteRookWithFreshBoard)
{
    struct ChessBoard board;
    char validLocations[65];
    char expectedValidLocations[65];
    
    // testing with a fresh board
    initializeForGame(&board);
    
    // try white rook at A1
    helperSetValidLocations(expectedValidLocations, (const char*[]){0});
    ASSERT_EQ(0, validMoves(&board, A, R1, validLocations));
    ASSERT_STREQ(expectedValidLocations, validLocations);
    
    // try white rook at A8
    helperSetValidLocations(expectedValidLocations, (const char*[]){0});
    ASSERT_EQ(0, validMoves(&board, A, R8, validLocations));
    ASSERT_STREQ(expectedValidLocations, validLocations);
}

// test validMoves for a white rook in the middle of an empty board, at E3
TEST(ChessBoard_validMoves, whiteRookInMiddleOfEmptyBoard)
{
    struct ChessBoard board;
    char validLocations[65];
    char expectedValidLocations[65];
    
    // testing with a fresh board
    initializeEmpty(&board);
    
    // put white rook at E3
    setPiece(&board, 'R', E, R3);
    
    helperSetValidLocations(expectedValidLocations, (const char*[]){
        "A3", "B3", "C3", "D3", "F3", "G3", "H3", "E1", "E2", "E4", "E5", "E6", "E7", "E8", 0});
    ASSERT_EQ(14, validMoves(&board, E, R3, validLocations));
    ASSERT_STREQ(expectedValidLocations, validLocations);
}

// test validMoves for a white rook in the lower left corner of an empty board, at A1
TEST(ChessBoard_validMoves, whiteRookLowerLeftCornerOfEmptyBoard)
{
    struct ChessBoard board;
    char validLocations[65];
    char expectedValidLocations[65];
    
    // testing with a fresh board
    initializeEmpty(&board);
    
    // put white rook at A1
    setPiece(&board, 'R', A, R1);
    
    helperSetValidLocations(expectedValidLocations, (const char*[]){
        "A2", "A3", "A4", "A5", "A6", "A7", "A8", "B1", "C1", "D1", "E1", "F1", "G1", "H1", 0});
    ASSERT_EQ(14, validMoves(&board, A, R1, validLocations));
    ASSERT_STREQ(expectedValidLocations, validLocations);
}

// test validMoves for a white rook in the lower right corner of an empty board, at H1
TEST(ChessBoard_validMoves, whiteRookLowerRightCornerOfEmptyBoard)
{
    struct ChessBoard board;
    char validLocations[65];
    char expectedValidLocations[65];
    
    // testing with a fresh board
    initializeEmpty(&board);
    
    // put white rook at A1
    setPiece(&board, 'R', H, R1);
    
    helperSetValidLocations(expectedValidLocations, (const char*[]){
        "H2", "H3", "H4", "H5", "H6", "H7", "H8",  "A1", "B1", "C1", "D1", "E1", "F1", "G1", 0});
    ASSERT_EQ(14, validMoves(&board, H, R1, validLocations));
    ASSERT_STREQ(expectedValidLocations, validLocations);
}

// test validMoves for a white rook in the top left corner of an empty board, at A8
TEST(ChessBoard_validMoves, whiteRookTopLeftCornerOfEmptyBoard)
{
    struct ChessBoard board;
    char validLocations[65];
    char expectedValidLocations[65];
    
    // testing with a fresh board
    initializeEmpty(&board);
    
    // put white rook at A1
    setPiece(&board, 'R', A, R8);
    
    helperSetValidLocations(expectedValidLocations, (const char*[]){
        "A1", "A2", "A3", "A4", "A5", "A6", "A7", "B8", "C8", "D8", "E8", "F8", "G8", "H8", 0});
    ASSERT_EQ(14, validMoves(&board, A, R8, validLocations));
    ASSERT_STREQ(expectedValidLocations, validLocations);
}

// test validMoves for a white rook in the top right corner of an empty board, at H8
TEST(ChessBoard_validMoves, whiteRookTopRightCornerOfEmptyBoard)
{
    struct ChessBoard board;
    char validLocations[65];
    char expectedValidLocations[65];
    
    // testing with a fresh board
    initializeEmpty(&board);
    
    // put white rook at A1
    setPiece(&board, 'R', H, R8);
    
    helperSetValidLocations(expectedValidLocations, (const char*[]){
        "H1", "H2", "H3", "H4", "H5", "H6", "H7",  "A8", "B8", "C8", "D8", "E8", "F8", "G8", 0});
    ASSERT_EQ(14, validMoves(&board, H, R8, validLocations));
    ASSERT_STREQ(expectedValidLocations, validLocations);
}

// test validMoves for a white rook in the middle of the board at E3, but with 2 white and 2 black pieces in the way
TEST(ChessBoard_validMoves, whiteRookInMiddleOfBoardWithOtherPieces)
{
    struct ChessBoard board;
    char validLocations[65];
    char expectedValidLocations[65];
    
    // testing with a fresh board
    initializeEmpty(&board);
    
    // put white rook at E3
    setPiece(&board, 'R', E, R3);
    
    // put a white knight in the way two spaces below (one square available)
    setPiece(&board, 'N', E, R1);
    
    // put a white bishop in the way two spaces right (one square available)
    setPiece(&board, 'B', G, R3);
    
    // put a black pawn three to the left (four squares available)
    setPiece(&board, 'p', B, R3);
    
    // put a black king 4 above
    setPiece(&board, 'k', E, R7); // (five squares available)
    
    helperSetValidLocations(expectedValidLocations, (const char*[]){
        "E2", "F3", "B3", "C3", "D3", "E4", "E5", "E6", "E7", 0});
    ASSERT_EQ(9, validMoves(&board, E, R3, validLocations));
    ASSERT_STREQ(expectedValidLocations, validLocations);
}