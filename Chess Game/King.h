#ifndef KING_H
#define KING_H

#include "Piece.h"


class King : public Piece
{
    public:
        King(std::string , std::string , std::string);
        ~King();
        bool isInCheck(const std::vector< Square* > &);
        bool isCastle();
        bool isMoveValid(std::string , const std::vector< Square* > &);
        bool isCastleValid(std::string , const std::vector< Square* > & , std::string , int , int);
        bool captureRange(std::string , const std::vector< Square* > &);

    protected:

    private:
        bool check;
        bool castle;
};

#endif // KING_H
