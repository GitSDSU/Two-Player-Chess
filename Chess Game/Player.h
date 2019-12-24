#ifndef PLAYER_H
#define PLAYER_H

#include "Piece.h"
#include <vector>

class Piece;

typedef std::vector< Piece* > VectorPiece;

class Player
{
    public:
        Player(std::string);
        ~Player();
        bool hasPiece(std::string) const;
        Piece * getPiece(std::string);
        bool validInput(std::string);
        std::string pickPiece();
        std::string pickSquare();
        void deletePiece(std::string);
        std::string findKing();
        void pawnPromotion(std::string);
        std::string getName() const;
        std::string getColor() const;

    protected:

    private:
        std::string name;
        std::string color;
        VectorPiece piece;
};

#endif // PLAYER_H
