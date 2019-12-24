#ifndef CONSTANTS_H_INCLUDED
#define CONSTANTS_H_INCLUDED

#include <iostream>
#include <map>

namespace Global
{
    typedef int DataType;

    extern const DataType NUM_SQUARES;
    extern const DataType NUM_PLAYERS;
    extern const DataType NUM_PAWNS;
    extern const DataType NUM_KINGS;
    extern const DataType NUM_MINOR;

    enum Piece { Pawn , Knight , Bishop , Rook , Queen , King , Empty };
    enum Team { White , Black , None };
    enum Action { Move , Capture , Castle , Enpassant };

    extern const std::string Color[];
    extern const std::string Position[];
    extern const std::string Type[];

    extern const std::string PawnCol[];
    extern const std::string BishopCol[];
    extern const std::string KnightCol[];
    extern const std::string RookCol[];
    extern const std::string QueenCol[];
    extern const std::string KingCol[];

    extern std::map< std::string , std::string > Row;
    extern std::map< std::string , std::string > PawnRow;
    extern std::map< std::string , std::string > KingPos;
    extern std::map< std::string , std::string > WhitePiece;
    extern std::map< std::string , std::string > BlackPiece;
    extern std::map< std::string , int > Index;

}

#endif // CONSTANTS_H_INCLUDED
