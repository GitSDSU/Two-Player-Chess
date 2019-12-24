#ifndef PAWN_H
#define PAWN_H

#include "Piece.h"


class Pawn : public Piece
{
    public:
        Pawn(std::string , std::string , std::string);
        ~Pawn();
        bool isMoveValid(std::string , const std::vector< Square* > &);
        bool isCaptureValid(std::string);
        bool whitePawn(std::string , const std::vector< Square* > &);
        bool blackPawn(std::string , const std::vector< Square* > &);
        bool isEnpassant();
        bool isPromote();
        bool captureRange(std::string , const std::vector< Square* > &);

    protected:

    private:
        bool enpassant;
        bool promote;
};

#endif // PAWN_H
