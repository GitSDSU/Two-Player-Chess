#include "Piece.h"
#include <iostream>

Piece::Piece(std::string pieceType , std::string pieceColor , std::string piecePosition)
{
    type = pieceType;
    color = pieceColor;
    position = piecePosition;
    firstMove = true;
}

Piece::~Piece()
{
    //dtor
}

std::string Piece::getPosition() const
{
    return position;
}

std::string Piece::getColor() const
{
    return color;
}

std::string Piece::getType() const
{
    return type;
}

bool Piece::isFirstMove() const
{
    return firstMove;
}

void Piece::setPosition(std::string _new)
{
    position = _new;
}

void Piece::notFirstMove()
{
    firstMove = false;
}

void Piece::display() const
{
    if (color == Global::Color[Global::Team::White])
        std::cout << Global::WhitePiece[type] << " ";
    else
        std::cout << Global::BlackPiece[type] << " ";
}





