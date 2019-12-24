#include "Constants.h"

extern const Global::DataType Global::NUM_SQUARES = 64;
extern const Global::DataType Global::NUM_PLAYERS = 2;
extern const Global::DataType Global::NUM_PAWNS = 8;
extern const Global::DataType Global::NUM_KINGS = 1;
extern const Global::DataType Global::NUM_MINOR = 2;

extern const std::string Global::Color[]
    {
        "White" , "Black" , "None"
    };

extern const std::string Global::PawnCol[] =
    {
        "A" , "B" , "C" , "D" , "E" , "F" , "G" , "H"
    };

extern const std::string Global::BishopCol[] =
    {
        "C" , "F"
    };

extern const std::string Global::KnightCol[] =
    {
        "B" , "G"
    };

extern const std::string Global::RookCol[] =
    {
        "A" , "H"
    };

extern const std::string Global::QueenCol[] =
    {
        "D"
    };

extern const std::string Global::KingCol[] =
    {
        "E"
    };

extern const std::string Global::Type[] =
    {
        "Pawn" , "Knight" , "Bishop" , "Rook" , "Queen" , "King" , "Empty"
    };

std::map< std::string , std::string > Global::Row =
    {
        { "White" , "1" } ,
        { "Black" , "8" }
    };

std::map< std::string , std::string > Global::PawnRow =
    {
        { "White" , "2" } ,
        { "Black" , "7" }
    };

std::map< std::string , std::string > Global::KingPos =
{
    { "White" , "E1" } ,
    { "Black" , "E8" }
};

std::map< std::string , std::string > Global::WhitePiece =
    {
        { "Pawn" , "P" } , { "Knight" , "N" } , { "Bishop" , "B" } , { "Rook" , "R" } , { "Queen" , "Q" } , { "King" , "K" }
    };

std::map< std::string , std::string > Global::BlackPiece =
    {
        { "Pawn" , "p" } , { "Knight" , "n" } , { "Bishop" , "b" } , { "Rook" , "r" } , { "Queen" , "q" } , { "King" , "k" }
    };


extern const std::string Global::Position[] =
    {
        "A8" , "B8" , "C8" , "D8" , "E8" , "F8" , "G8" , "H8" ,
        "A7" , "B7" , "C7" , "D7" , "E7" , "F7" , "G7" , "H7" ,
        "A6" , "B6" , "C6" , "D6" , "E6" , "F6" , "G6" , "H6" ,
        "A5" , "B5" , "C5" , "D5" , "E5" , "F5" , "G5" , "H5" ,
        "A4" , "B4" , "C4" , "D4" , "E4" , "F4" , "G4" , "H4" ,
        "A3" , "B3" , "C3" , "D3" , "E3" , "F3" , "G3" , "H3" ,
        "A2" , "B2" , "C2" , "D2" , "E2" , "F2" , "G2" , "H2" ,
        "A1" , "B1" , "C1" , "D1" , "E1" , "F1" , "G1" , "H1"
    };

std::map< std::string , int > Global::Index =
    {
        { "A8" , 0 } , { "B8" , 1 } , { "C8" , 2 } , { "D8" , 3 } , { "E8" , 4 } , { "F8" , 5 } , { "G8" , 6 } , { "H8" , 7 } ,
        { "A7" , 8 } , { "B7" , 9 } , { "C7" , 10 } , { "D7" , 11 } , { "E7" , 12 } , { "F7" , 13 } , { "G7" , 14 } , { "H7" , 15 } ,
        { "A6" , 16 } , { "B6" , 17 } , { "C6" , 18 } , { "D6" , 19 } , { "E6" , 20 } , { "F6" , 21 } , { "G6" , 22 } , { "H6" , 23 } ,
        { "A5" , 24 } , { "B5" , 25 } , { "C5" , 26 } , { "D5" , 27 } , { "E5" , 28 } , { "F5" , 29 } , { "G5" , 30 } , { "H5" , 31 } ,
        { "A4" , 32 } , { "B4" , 33 } , { "C4" , 34 } , { "D4" , 35 } , { "E4" , 36 } , { "F4" , 37 } , { "G4" , 38 } , { "H4" , 39 } ,
        { "A3" , 40 } , { "B3" , 41 } , { "C3" , 42 } , { "D3" , 43 } , { "E3" , 44 } , { "F3" , 45 } , { "G3" , 46 } , { "H3" , 47 } ,
        { "A2" , 48 } , { "B2" , 49 } , { "C2" , 50 } , { "D2" , 51 } , { "E2" , 52 } , { "F2" , 53 } , { "G2" , 54 } , { "H2" , 55 } ,
        { "A1" , 56 } , { "B1" , 57 } , { "C1" , 58 } , { "D1" , 59 } , { "E1" , 60 } , { "F1" , 61 } , { "G1" , 62 } , { "H1" , 63 }
    };


