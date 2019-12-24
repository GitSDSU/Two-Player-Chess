#include "Knight.h"
#include "Square.h"

Knight::Knight(std::string type , std::string color , std::string position) : Piece(type , color , position)
{
    //ctor
}

Knight::~Knight()
{
    //dtor
}

bool Knight::isMoveValid(std::string new_ , const std::vector< Square* > & board)
{
    std::string curr = getPosition();
    Piece * p = NULL;

    if (!board[Global::Index[new_]]->isEmpty())
        p = board[Global::Index[new_]]->getPiece();

    if (p != NULL)
    {
        if (p->getColor() == getColor())
            return false;
    }

    if (curr[0] + 1 == new_[0] && curr[1] + 2 == new_[1])
        return true;
    if (curr[0] + 2 == new_[0] && curr[1] + 1 == new_[1])
        return true;
    if (curr[0] + 2 == new_[0] && curr[1] - 1 == new_[1])
        return true;
    if (curr[0] + 1 == new_[0] && curr[1] - 2 == new_[1])
        return true;
    if (curr[0] - 1 == new_[0] && curr[1] - 2 == new_[1])
        return true;
    if (curr[0] - 2 == new_[0] && curr[1] - 1 == new_[1])
        return true;
    if (curr[0] - 2 == new_[0] && curr[1] + 1 == new_[1])
        return true;
    if (curr[0] - 1 == new_[0] && curr[1] + 2 == new_[1])
        return true;

    return false;
}

bool Knight::captureRange(std::string new_ , const std::vector< Square* > & )
{
    std::string curr = getPosition();

    if (curr[0] + 1 == new_[0] && curr[1] + 2 == new_[1])
        return true;
    if (curr[0] + 2 == new_[0] && curr[1] + 1 == new_[1])
        return true;
    if (curr[0] + 2 == new_[0] && curr[1] - 1 == new_[1])
        return true;
    if (curr[0] + 1 == new_[0] && curr[1] - 2 == new_[1])
        return true;
    if (curr[0] - 1 == new_[0] && curr[1] - 2 == new_[1])
        return true;
    if (curr[0] - 2 == new_[0] && curr[1] - 1 == new_[1])
        return true;
    if (curr[0] - 2 == new_[0] && curr[1] + 1 == new_[1])
        return true;
    if (curr[0] - 1 == new_[0] && curr[1] + 2 == new_[1])
        return true;

    return false;
}



