//
//  ChessBoardTestHelpers.cpp
//  ChessPuzzlesLibrary
//
//  Created by Blake Caldwell on 1/11/14.
//  Copyright (c) 2014 Blake Caldwell. All rights reserved.
//

#include "ChessBoardTestHelpers.h"

extern "C" {
    #include "ChessBoard.h"
}

int helperEmptyValidLocations(char validLocations[65])
{
    int i;
    
    for(i = 0; i <= 65; i++)
    {
        validLocations[i] = '0';
    }
    validLocations[64] = 0;
    return 1;
}

int helperAddValidLocation(char validLocations[65], enum ChessBoardFile file, enum ChessBoardRank rank)
{
    validLocations[((rank-1) * 8) + file - 1] = '1';
    return 1;
}

int helperSetValidLocations(char validLocations[65], const char *locations[])
{
    const char *location;
    int rank;
    int file;
    
    helperEmptyValidLocations(validLocations);
    while(*locations)
    {
        location = *locations++;
        
        file = location[0] - 'A' + 1;
        rank = location[1] - '0';
        
        helperAddValidLocation(validLocations, (enum ChessBoardFile)file, (enum ChessBoardRank)rank);
    }
    
    return 1;
}