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

#endif /* defined(__ChessPuzzlesLibrary__ChessBoardTestHelpers__) */
