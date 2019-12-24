#include "Square.h"
#include "Piece.h"

Square::Square(std::string pos)
{
    position = pos;
    piece = NULL;
    white = black = 0;
}

Square::Square(std::string pos, Piece *p)
{
    position = pos;
    piece = p;
    white = black = 0;
}

Square::~Square()
{

}

bool Square::isEmpty() const
{
    if (piece == NULL)
        return true;
    else
        return false;
}

void Square::display() const
{
    if (isEmpty())
        std::cout << position;
    else
        piece->display();
    std::cout << " | ";

    if (position[0] == 'H')
        std::cout << '\n';
}

Piece * Square::getPiece() const
{
    return piece;
}

void Square::reset()
{
    white = black = 0;
}

void Square::addAttacker(std::string team)
{
    if (team == Global::Color[Global::Team::White])
        white++;
    else
        black++;
}

void Square::setPiece(Piece *p)
{
    piece = p;
}

void Square::removePiece()
{
    piece = NULL;
}

bool Square::isAttacked(std::string team)
{
    if (team == Global::Color[Global::Team::White])
    {
        if (black >= 1)
            return true;
    }
    else
    {
        if (white >= 1)
            return true;
    }
    return false;
}




