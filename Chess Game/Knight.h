#ifndef KNIGHT_H
#define KNIGHT_H

#include "Piece.h"


class Knight : public Piece
{
    public:
        Knight(std::string , std::string , std::string);
        ~Knight();
        bool isMoveValid(std::string , const std::vector< Square* > &);
        bool captureRange(std::string , const std::vector< Square* > &);

    protected:

    private:
};

#endif // KNIGHT_H
