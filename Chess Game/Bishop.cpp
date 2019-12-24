#include "Bishop.h"
#include "Square.h"

Bishop::Bishop(std::string type , std::string color , std::string position) : Piece(type , color , position)
{
    //ctor
}

Bishop::~Bishop()
{
    //dtor
}
/// Seperate isMoveValid & isCaptureValid
bool Bishop::isMoveValid(std::string new_ , const std::vector< Square* > & board)
{
    std::string curr = getPosition();

    if (abs(new_[0] - curr[0]) != abs(new_[1] - curr[1]) || curr == new_)
        return false;

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

    return false;
}

bool Bishop::captureRange(std::string new_ , const std::vector< Square* > & board)
{   /// Returns true regardless of what board[new_] has (friendly/enemy piece , empty)
    std::string curr = getPosition();

    if (abs(new_[0] - curr[0]) != abs(new_[1] - curr[1]) || curr == new_)
        return false;

    if (abs(new_[0] - curr[0]) == 1)
        return true;

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






