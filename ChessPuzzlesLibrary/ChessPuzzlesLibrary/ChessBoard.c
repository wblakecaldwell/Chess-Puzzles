//
//  ChessBoard.c
//  ChessPuzzlesLibrary
//
//  Created by Blake Caldwell on 1/5/14.
//  Copyright (c) 2014 Blake Caldwell. All rights reserved.
//

#include <stdio.h>
#include <strings.h>
#include <assert.h>
#include "ChessBoard.h"

/*
 * (PRIVATE) Return the pieces string index based on rank/file.
 */
int pieceIndexAt(enum ChessBoardFile file, enum ChessBoardRank rank)
{
    return ((rank-1) * 8) + file - 1;
}

/*
 * (PRIVATE) Return the color of the input piece.
 */
enum ChessPieceColor colorOf(char pieceValue)
{
    if('P' == pieceValue ||
       'R' == pieceValue ||
       'N' == pieceValue ||
       'B' == pieceValue ||
       'K' == pieceValue ||
       'Q' == pieceValue)
    {
        return WHITE;
    }
    
    if('p' == pieceValue ||
       'r' == pieceValue ||
       'n' == pieceValue ||
       'b' == pieceValue ||
       'k' == pieceValue ||
       'q' == pieceValue)
    {
        return BLACK;
    }
    
    return NO_PIECE;
}

int initializeForGame(struct ChessBoard *board)
{
    strcpy(board->pieces, "RNBQKBNRPPPPPPPP                                pppppppprnbqkbnr");
    return 1;
}

int initializeWithPieces(struct ChessBoard *board, const char *pieces[8])
{
    char boardStr[65];
    
    boardArrayToBoardString(pieces, boardStr);
    
    strcpy(board->pieces, boardStr);
    return 1;
}

int boardArrayToBoardString(const char *pieces[8], char boardStr[65])
{
    int boardRow;
    int piecesRow;
    int i;
    
    // board is stored as a string from A1-H1, A2-H2. Input is A8-H8, A7-H7, so flip it
    for(piecesRow=7, boardRow=0; piecesRow>=0; piecesRow--, boardRow++)
    {
        assert(strlen(pieces[piecesRow]) == 8);
        
        // copy the chars from pieces to boardStr
        for(i=0; i<8; i++)
        {
            boardStr[boardRow*8 + i] = pieces[piecesRow][i];
        }
    }
    boardStr[64] = '\0';
    return 1;
}

int initializeEmpty(struct ChessBoard *board)
{
    strcpy(board->pieces, "                                                                ");
    return 1;
}

char pieceAt(struct ChessBoard *board, enum ChessBoardFile file, enum ChessBoardRank rank)
{
    return board->pieces[pieceIndexAt(file, rank)];
}

int movePiece(struct ChessBoard *board, enum ChessBoardFile fileFrom, enum ChessBoardRank rankFrom, enum ChessBoardFile fileTo, enum ChessBoardRank rankTo)
{
    char pieceFrom;
    char pieceTo;
    
    // make sure we're not moving to self
    if(rankFrom == rankTo && fileFrom == fileTo)
    {
        // moving to self - no good
        return 0;
    }
    
    // make sure there's a piece to move
    pieceFrom = pieceAt(board, fileFrom, rankFrom);
    if(' ' == pieceFrom || 0 == pieceFrom)
    {
        // there's no piece here
        return 0;
    }
    
    // make sure the target cell is valid
    pieceTo = pieceAt(board, fileTo, rankTo);
    if(0 == pieceTo)
    {
        // invalid destination
        return 0;
    }
    
    setPiece(board, ' ', fileFrom, rankFrom);
    setPiece(board, pieceFrom, fileTo, rankTo);
    return 1;
}

int setPiece(struct ChessBoard *board, char piece, enum ChessBoardFile file, enum ChessBoardRank rank)
{
    board->pieces[pieceIndexAt(file, rank)] = piece;
    return 1;
}

int validMoves(struct ChessBoard *board, enum ChessBoardFile file, enum ChessBoardRank rank, char validLocations[65])
{
    enum ChessPieceColor pieceColor;
    char pieceFrom;
    char pieceTo;
    int i;
    int validMoveCount;
    enum ChessPieceColor thisPieceColor;
    
    validMoveCount = 0;
    
    // make sure there's a piece to move
    pieceFrom = pieceAt(board, file, rank);
    if(' ' == pieceFrom || 0 == pieceFrom)
    {
        // there's no piece here
        return 0;
    }
    
    // initialize all positions to 0
    for(i=0; i<=65; i++)
    {
        validLocations[i] = '0';
    }
    validLocations[64] = 0;
    
    switch(pieceFrom)
    {
        case 'P':   // white pawn
            // * pawn can move forward (up) one space if nobody's in front
            if(' ' == pieceAt(board, file, rank+1))
            {
                validMoveCount++;
                validLocations[pieceIndexAt(file, (enum ChessBoardRank)(rank+1))] = '1';
            }
            
            // * pawn can move two spaces foward (up) if on rank 2 and nobody's there
            if(R2 == rank && ' ' == pieceAt(board, file, rank+2))
            {
                validMoveCount++;
                validLocations[pieceIndexAt(file, 4)] = '1';
            }
            
            // * pawn can move forward (up) diagonal if an opponent is there
            
            // check attack left
            if(file > A)
            {
                pieceTo = pieceAt(board, file-1, rank+1);
                if(BLACK == colorOf(pieceTo))
                {
                    // we can take this piece!
                    validMoveCount++;
                    validLocations[pieceIndexAt(file-1, rank+1)] = '1';
                }
            }
            
            // check attack right
            if(file < H)
            {
                pieceTo = pieceAt(board, file+1, rank+1);
                if(BLACK == colorOf(pieceTo))
                {
                    validMoveCount++;
                    validLocations[pieceIndexAt(file+1, rank+1)] = '1';
                }
            }
            
            break;
        
        case 'p':   // black pawn
            // * pawn can move forward (down) one space if nobody's in front
            if(' ' == pieceAt(board, (enum ChessBoardFile)file, (enum ChessBoardRank)rank-1))
            {
                validMoveCount++;
                validLocations[pieceIndexAt((enum ChessBoardFile)file, rank-1)] = '1';
            }
            
            // * pawn can move two spaces foward (down) if on rank 7
            if(R7 == rank && ' ' == pieceAt(board, file, rank-2))
            {
                validMoveCount++;
                validLocations[pieceIndexAt(file, rank-2)] = '1';
            }
            
            // * pawn can move foward (down) diagonal if an opponent is there
            
            // check attack left
            if(file > A)
            {
                pieceTo = pieceAt(board, file-1, rank-1);
                if(WHITE == colorOf(pieceTo))
                {
                    // we can take this piece!
                    validMoveCount++;
                    validLocations[pieceIndexAt((enum ChessBoardFile)file-1, (enum ChessBoardRank)rank-1)] = '1';
                }
            }
            
            // check attack right
            if(file < H)
            {
                pieceTo = pieceAt(board, file+1, rank-1);
                if(WHITE == colorOf(pieceTo))
                {
                    validMoveCount++;
                    validLocations[pieceIndexAt((enum ChessBoardFile)file+1, (enum ChessBoardRank)rank-1)] = '1';
                }
            }
            break;
        
        case 'R':   // white rook
        case 'r':   // black rook
            if('R' == pieceFrom)
            {
                thisPieceColor = WHITE;
            }
            else
            {
                thisPieceColor = BLACK;
            }
            
            // check how far we can move left
            for(i = file-1; i >= 1; i--)
            {
                pieceTo = pieceAt(board, i, rank);
                // make sure there's no white piece here
                pieceColor = colorOf(pieceTo);
                if(thisPieceColor == pieceColor)
                {
                    // ran into our pice - we're done
                    break;
                }
                
                if(NO_PIECE == pieceColor)
                {
                    // we can move here
                    validMoveCount++;
                    validLocations[pieceIndexAt((enum ChessBoardFile)i, (enum ChessBoardRank)rank)] = '1';
                }
                else
                {
                    // we hit opposing piece - can move here, but no further
                    validMoveCount++;
                    validLocations[pieceIndexAt((enum ChessBoardFile)i, (enum ChessBoardRank)rank)] = '1';
                    break;
                }
            }
            
            // check how far we can move right
            for(i = file+1; i <= 8; i++)
            {
                pieceTo = pieceAt(board, i, rank);
                // make sure there's no white piece here
                pieceColor = colorOf(pieceTo);
                if(thisPieceColor == pieceColor)
                {
                    // ran into our pice - we're done
                    break;
                }
                
                if(NO_PIECE == pieceColor)
                {
                    // we can move here
                    validMoveCount++;
                    validLocations[pieceIndexAt((enum ChessBoardFile)i, (enum ChessBoardRank)rank)] = '1';
                }
                else
                {
                    // we hit opposing piece - can move here, but no further
                    validMoveCount++;
                    validLocations[pieceIndexAt((enum ChessBoardFile)i, (enum ChessBoardRank)rank)] = '1';
                    break;
                }
            }
            
            // check how far we can move up
            for(i = rank+1; i <= 8; i++)
            {
                pieceTo = pieceAt(board, file, i);
                // make sure there's no white piece here
                pieceColor = colorOf(pieceTo);
                if(thisPieceColor == pieceColor)
                {
                    // ran into our pice - we're done
                    break;
                }
                
                if(NO_PIECE == pieceColor)
                {
                    // we can move here
                    validMoveCount++;
                    validLocations[pieceIndexAt((enum ChessBoardFile)file, (enum ChessBoardRank)i)] = '1';
                }
                else
                {
                    // we hit opposing piece - can move here, but no further
                    validMoveCount++;
                    validLocations[pieceIndexAt((enum ChessBoardFile)file, (enum ChessBoardRank)i)] = '1';
                    break;
                }
                
            }
            
            // check how far we can move down
            for(i = rank-1; i >= 1; i--)
            {
                pieceTo = pieceAt(board, file, i);
                // make sure there's no white piece here
                pieceColor = colorOf(pieceTo);
                if(thisPieceColor == pieceColor)
                {
                    // ran into our piece - we're done
                    break;
                }
                
                if(NO_PIECE == pieceColor)
                {
                    // we can move here
                    validMoveCount++;
                    validLocations[pieceIndexAt((enum ChessBoardFile)file, (enum ChessBoardRank)i)] = '1';
                }
                else
                {
                    // we hit opposing piece - can move here, but no further
                    validMoveCount++;
                    validLocations[pieceIndexAt((enum ChessBoardFile)file, (enum ChessBoardRank)i)] = '1';
                    break;
                }
            }
            
            break;
        
        case 'N':   // white knight
            // TODO
            break;
        
        case 'n':   // black knight
            // TODO
            break;
            
        case 'B':   // white bishop
            // TODO
            break;
            
        case 'b':   // black bishop
            // TODO
            break;
            
        case 'Q':   // white queen
            // TODO
            break;
            
        case 'q':   // black queen
            // TODO
            break;
            
        case 'K':   // white king
            // TODO
            break;
        
        case 'k':   // black king
            // TODO
            break;
            
        default:
            break;
    }
    
    return validMoveCount;
}