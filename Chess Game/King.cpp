#include "King.h"
#include "Square.h"

King::King(std::string type , std::string color , std::string position) : Piece(type , color , position)
{
    check = false;
    castle = false;
}

King::~King()
{
    //dtor
}

bool King::isInCheck(const std::vector< Square* > & board)
{
    if (board[Global::Index[getPosition()]]->isAttacked(getColor()))
        return true;
    else
        return false;
}

bool King::isCastle()
{
    if (castle)
    {
        castle = false;
        return !castle;
    }
    else
        return false;
}

bool King::isMoveValid(std::string new_ , const std::vector< Square* > & board)
{
    std::string curr = getPosition();
    int left , right;

    left = abs(new_[0] - curr[0]);
    right = abs(new_[1] - curr[1]);

    if (!board[Global::Index[new_]]->isEmpty())
    {
        Piece * p = board[Global::Index[new_]]->getPiece();
        if (left == 1 && right == 1 && p->getColor() != getColor())
            return true;
        if (left == 1 && right == 0 && p->getColor() != getColor())
            return true;
        if (left == 0 && right == 1 && p->getColor() != getColor())
            return true;
    }
    else
    {
        if (left == 1 && right == 1)
            return true;
        if (left == 1 && right == 0)
            return true;
        if (left == 0 && right == 1)
            return true;
    }

    if (isCastleValid(new_ , board, curr , left , right))
        return true;

    return false;
}

bool King::isCastleValid(std::string new_ , const std::vector< Square* > & board , std::string curr , int left , int right)
{
    if (getColor() == Global::Color[Global::Team::White])
    {
        if (curr[0] + 2 == new_[0] && curr[1] == new_[1] && isFirstMove() && getPosition() == "E1" && board[Global::Index["F1"]]->isEmpty() &&
            board[Global::Index["G1"]]->isEmpty() && !board[Global::Index["F1"]]->isAttacked(getColor()) && !board[Global::Index["G1"]]->isAttacked(getColor())
            && !board[Global::Index["H1"]]->isEmpty())
        {
            Piece * p = board[Global::Index["H1"]]->getPiece();
            if (p->isFirstMove() && p->getType() == Global::Type[Global::Piece::Rook])
                { castle = true; return true; }
        }
        if (curr[0] - 2 == new_[0] && curr[1] == new_[1] && isFirstMove() && getPosition() == "E1" && board[Global::Index["D1"]]->isEmpty() &&
            board[Global::Index["C1"]]->isEmpty() && !board[Global::Index["D1"]]->isAttacked(getColor()) && !board[Global::Index["C1"]]->isAttacked(getColor())
            && !board[Global::Index["A1"]]->isEmpty())
        {
            Piece * p = board[Global::Index["A1"]]->getPiece();
            if (p->isFirstMove() && p->getType() == Global::Type[Global::Piece::Rook])
                { castle = true; return true; }
        }
    }
    else
    {
        if (curr[0] + 2 == new_[0] && curr[1] == new_[1] && isFirstMove() && getPosition() == "E8" && board[Global::Index["F8"]]->isEmpty() &&
            board[Global::Index["G8"]]->isEmpty() && !board[Global::Index["F8"]]->isAttacked(getColor()) && !board[Global::Index["G8"]]->isAttacked(getColor())
            && !board[Global::Index["H8"]]->isEmpty())
        {
            Piece * p = board[Global::Index["H8"]]->getPiece();
            if (p->isFirstMove() && p->getType() == Global::Type[Global::Piece::Rook])
                { castle = true; return true; }
        }
        if (curr[0] - 2 == new_[0] && curr[1] == new_[1] && isFirstMove() && getPosition() == "E8" && board[Global::Index["D8"]]->isEmpty() &&
            board[Global::Index["C8"]]->isEmpty() && !board[Global::Index["D8"]]->isAttacked(getColor()) && !board[Global::Index["C8"]]->isAttacked(getColor())
            && !board[Global::Index["A8"]]->isEmpty())
        {
            Piece * p = board[Global::Index["A8"]]->getPiece();
            if (p->isFirstMove() && p->getType() == Global::Type[Global::Piece::Rook])
                { castle = true; return true; }
        }
    }
    return false;
}

bool King::captureRange(std::string new_ , const std::vector< Square* > & )
{
    std::string curr = getPosition();

    if (curr[0] == new_[0] && curr[1] + 1 == new_[1])
        return true; /// up
    if (curr[0] + 1 == new_[0] && curr[1] + 1 == new_[1])
        return true; /// right, up
    if (curr[0] + 1 == new_[0] && curr[1] == new_[1])
        return true; /// right
    if (curr[0] + 1 == new_[0] && curr[1] - 1 == new_[1])
        return true; /// right, down
    if (curr[0] == new_[0] && curr[1] - 1 == new_[1])
        return true; /// down
    if (curr[0] - 1 == new_[0] && curr[1] - 1 == new_[1])
        return true; /// left, down
    if (curr[0] - 1 == new_[0] && curr[1] == new_[1])
        return true; /// left
    if (curr[0] - 1 == new_[0] && curr[1] + 1 == new_[1])
        return true; /// left, up

    return false;
}






