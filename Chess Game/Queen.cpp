#include "Queen.h"
#include "Square.h"

Queen::Queen(std::string type , std::string color , std::string position) : Piece(type , color , position)
{
    //ctor
}

Queen::~Queen()
{
    //dtor
}

bool Queen::isMoveValid(std::string new_ , const std::vector< Square* > & board)
{
    if (isDiagonal(new_))
    {
        std::string curr = getPosition();
        std::string temp = curr;
        for (int i = 0; i < abs(new_[0] - curr[0]) - 1; i++)
        {
            if (new_[0] - curr[0] > 0)
                temp[0] += 1;
            else if (new_[0] - curr[0] < 0)
                temp[0] -= 1;
            if (new_[1] - curr[1] > 0)
                temp[1] += 1;
            else if (new_[1] - curr[1] < 0)
                temp[1] -= 1;
            if (!board[Global::Index[temp]]->isEmpty())
                return false;
        }
        Piece * piece = NULL;

        if (!board[Global::Index[new_]]->isEmpty())
            piece = board[Global::Index[new_]]->getPiece();

        if (piece != NULL)
        {
            if (piece->getColor() != getColor())
                return true;
        }
        else
            return true;
    }
    else if (isCardinal(new_))
    {
        std::string curr = getPosition();
        int n;
        (new_[0] - curr[0] != 0) ? n = abs(new_[0] - curr[0]) : n = abs(new_[1] - curr[1]);
        std::string temp = curr;
        for (int i = 0; i < n - 1; i++)
        {
            if (new_[0] - curr[0] > 0)
                temp[0] += 1;
            else if (new_[0] - curr[0] < 0)
                temp[0] -= 1;
            if (new_[1] - curr[1] > 0)
                temp[1] += 1;
            else if (new_[1] - curr[1] < 0)
                temp[1] -= 1;
            if (!board[Global::Index[temp]]->isEmpty())
                return false;
        }
        Piece * piece = NULL;
        if (!board[Global::Index[new_]]->isEmpty())
            piece = board[Global::Index[new_]]->getPiece();

        if (piece != NULL)
        {
            if (piece->getColor() != getColor())
                return true;
        }
        else
            return true;
    }
    return false;
}

bool Queen::captureRange(std::string new_ , const std::vector< Square* > & board)
{
    if (isDiagonal(new_))
    {
        std::string curr = getPosition();
        std::string temp = curr;

        for (int i = 0; i < abs(new_[0] - curr[0]) - 1; i++)
        {
            if (new_[0] - curr[0] > 0)
                temp[0] += 1;
            else if (new_[0] - curr[0] < 0)
                temp[0] -= 1;
            if (new_[1] - curr[1] > 0)
                temp[1] += 1;
            else if (new_[1] - curr[1] < 0)
                temp[1] -= 1;
            if (!board[Global::Index[temp]]->isEmpty())
                return false;
        }
        return true;
    }
    else if (isCardinal(new_))
    {
        std::string curr = getPosition();
        int n;
        (new_[0] - curr[0] != 0) ? n = abs(new_[0] - curr[0]) : n = abs(new_[1] - curr[1]);

        if (n == 1)
            return true;

        std::string temp = curr;

        for (int i = 0; i < n - 1; i++)
        {
            if (new_[0] - curr[0] > 0)
                temp[0] += 1;
            else if (new_[0] - curr[0] < 0)
                temp[0] -= 1;
            if (new_[1] - curr[1] > 0)
                temp[1] += 1;
            else if (new_[1] - curr[1] < 0)
                temp[1] -= 1;
            if (!board[Global::Index[temp]]->isEmpty())
                return false;
        }

        return true;
    }
    return false;
}

bool Queen::isDiagonal(std::string new_)
{
    std::string curr = getPosition();

    if (abs(new_[0] - curr[0]) != abs(new_[1] - curr[1]) || curr == new_)
        return false;

    return true;
}

bool Queen::isCardinal(std::string new_)
{
    std::string curr = getPosition();

    if (curr == new_)
        return false;

    if ((new_[0] - curr[0] == 0 && new_[1] - curr[1] == 0) || (new_[0] - curr[0] != 0 && new_[1] - curr[1] != 0))
        return false;

    return true;
}


