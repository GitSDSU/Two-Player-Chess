#ifndef ROOK_H
#define ROOK_H

#include "Piece.h"


class Rook : public Piece
{
    public:
        Rook(std::string , std::string , std::string);
        ~Rook();
        bool isMoveValid(std::string , const std::vector< Square* > &);
        bool captureRange(std::string , const std::vector< Square* > &);

    protected:

    private:
};

#endif // ROOK_H
