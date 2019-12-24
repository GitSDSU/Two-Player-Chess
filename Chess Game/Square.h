#ifndef SQUARE_H
#define SQUARE_H

#include <iostream>

class Piece;

class Square
{
    public:
        Square(std::string);
        Square(std::string , Piece *);
        ~Square();
        bool isEmpty() const;
        void display() const;
        Piece * getPiece() const;
        void reset();
        void addAttacker(std::string);
        void setPiece(Piece *);
        void removePiece();
        bool isAttacked(std::string);

    protected:

    private:
        std::string position;
        Piece * piece;
        int white;
        int black;
};

#endif // SQUARE_H
