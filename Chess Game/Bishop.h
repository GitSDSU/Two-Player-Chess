#ifndef BISHOP_H
#define BISHOP_H

#include "Piece.h"


class Bishop : public Piece
{
    public:
        Bishop(std::string , std::string , std::string);
        ~Bishop();
        bool isMoveValid(std::string , const std::vector< Square* > &);
        bool captureRange(std::string , const std::vector< Square* > &);

    protected:

    private:
};

#endif // BISHOP_H
