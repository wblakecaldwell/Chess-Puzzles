//
//  ChessBoardTestHelpers.h
//  ChessPuzzlesLibrary
//
//  Created by Blake Caldwell on 1/11/14.
//  Copyright (c) 2014 Blake Caldwell. All rights reserved.
//

#ifndef __ChessPuzzlesLibrary__ChessBoardTestHelpers__
#define __ChessPuzzlesLibrary__ChessBoardTestHelpers__

#include <iostream>
#include <stdbool.h>

extern "C" {
    #include "ChessBoard.h"
}

/*
 * Initialize a validLocations array to all 0's.
 */
int helperEmptyValidLocations(char validLocations[65]);

/*
 * Add a valid location by rank and file.
 */
int helperAddValidLocation(char validLocations[65], enum ChessBoardFile file, enum ChessBoardRank rank);

/*
 * set the valid locations inside validLocations - valid locations are set 1, else 0. |locations| should be
 * in format A1, A2, B1, B2.
 */
int helperSetValidLocations(char validLocations[65], const char *locations[]);

/*
 * Parse the input testing board into a ChessBoard struct and array of expected valid locations.
 * The testing board is 8 rows of 8 strings. Rows are laid out as a board looks, visually, with white
 * on bottom. Each cell is a string of length 3. The middle position has the piece, and if we want 
 * to mark a cell as valid for the selected piece, then we surround it with square brackets. The position
 * we are testing is surrounded in parentheses - its location will be returned in pieceFile/pieceRank.
 *
 * Example:
 {
    {" r "," n "," b "," q "," k "," b "," n "," r "},
    {"[p]"," p "," p ","[p]"," p "," p ","[p]"," p "},
    {"   ","[ ]","   ","[ ]","   ","[ ]","   ","   "},
    {"   ","   ","[ ]","[ ]","[ ]","   ","   ","   "},
    {"[ ]","[ ]","[ ]","(Q)","[ ]","[ ]","[ ]","[ ]"},
    {"   ","   ","[ ]","[ ]","[ ]","   ","   ","   "},
    {" P "," P "," P "," P "," P "," P "," P "," P "},
    {" R "," N "," B ","   "," K "," B "," N "," R "}
 }
 *
 * returns the number of expected valid locations.
 */
int parseTestingBoard(char pieces[][8][8],
                      struct ChessBoard *board,
                      char expectedValidLocations[65],
                      enum ChessBoardFile *pieceFile,
                      enum ChessBoardRank *pieceRank,
                      bool ensureTargetPiece            // whether we assert that there's a piece in parens
                    );

#endif /* defined(__ChessPuzzlesLibrary__ChessBoardTestHelpers__) */
