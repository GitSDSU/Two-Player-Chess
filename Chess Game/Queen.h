#ifndef QUEEN_H
#define QUEEN_H

#include "Piece.h"


class Queen : public Piece
{
    public:
        Queen(std::string , std::string , std::string);
        ~Queen();
        bool isMoveValid(std::string , const std::vector< Square* > &);
        bool captureRange(std::string , const std::vector< Square* > &);
        bool isDiagonal(std::string);
        bool isCardinal(std::string);

    protected:

    private:
};

#endif // QUEEN_H
