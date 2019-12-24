#include "Pawn.h"
#include "Square.h"

Pawn::Pawn(std::string type , std::string color , std::string position) : Piece(type , color , position)
{
    enpassant = false;
    promote = false;
}

Pawn::~Pawn()
{

}

bool Pawn::isMoveValid(std::string _new , const std::vector< Square* > &board)
{
    if (getColor() == Global::Color[Global::Team::White])
        return whitePawn(_new , board);
    else if (getColor() == Global::Color[Global::Team::Black])
        return blackPawn(_new , board);
    else
        return false;
}

bool Pawn::whitePawn(std::string _new , const std::vector< Square* > & board)
{
    std::string curr = getPosition();
    std::string enpass = _new;
    std::string one = curr;
    std::string two = curr;

    enpass[1] -= 1;
    one[1] += 1;
    two[1] += 2;

    Piece * pN = board[Global::Index[_new]]->getPiece();
    Piece * pE = board[Global::Index[enpass]]->getPiece();

    if (curr[0] == _new[0] && curr[1] + 1 == _new[1] && board[Global::Index[one]]->isEmpty())
    {   /// Move 1 square
        if (_new[1] == '8')
            promote = true;
        return true;
    }

    if (curr[0] == _new[0] && curr[1] + 2 == _new[1] && curr[1] == '2' && board[Global::Index[one]]->isEmpty() && board[Global::Index[two]]->isEmpty())
        return true; /// Move 2 square
    if (pE != NULL) /// Enpassant
    {
        if (curr[0] + 1 == _new[0] && curr[1] + 1 == _new[1] && curr[1] == '5' && pE->getColor() == Global::Color[Global::Team::Black] &&
            pE->getType() == Global::Type[Global::Piece::Pawn] && pE->isFirstMove())
        {
            enpassant = true;
            return true;
        }
        if (curr[0] - 1 == _new[0] && curr[1] + 1 == _new[1] && curr[1] == '5' && pE->getColor() == Global::Color[Global::Team::Black] &&
            pE->getType() == Global::Type[Global::Piece::Pawn] && pE->isFirstMove())
        {
            enpassant = true;
            return true;
        }
    }
    if (pN != NULL) /// Capture
    {
        if (curr[0] + 1 == _new[0] && curr[1] + 1 == _new[1] && pN->getColor() == Global::Color[Global::Team::Black])
        {
            if (_new[1] == '8')
                promote = true;
            return true;
        }
        if (curr[0] - 1 == _new[0] && curr[1] + 1 == _new[1] && pN->getColor() == Global::Color[Global::Team::Black])
        {
            if (_new[1] == '8')
                promote = true;
            return true;
        }
    }
    return false;
}

bool Pawn::blackPawn(std::string _new , const std::vector< Square* > & board)
{
    std::string curr = getPosition();
    std::string one = curr;
    std::string two = curr;
    std::string enpass = _new;

    one[1] -= 1;
    two[1] -= 2;
    enpass[1] += 1;

    Piece * pN = board[Global::Index[_new]]->getPiece();
    Piece * pE = board[Global::Index[enpass]]->getPiece();

    if (curr[0] == _new[0] && curr[1] == _new[1] + 1 && board[Global::Index[one]]->isEmpty())
    {   /// Move 1 square
        if (_new[1] == '1')
            promote = true;
        return true;
    }
    if (curr[0] == _new[0] && curr[1] == _new[1] + 2 && curr[1] == '7' && board[Global::Index[one]]->isEmpty() && board[Global::Index[two]]->isEmpty())
        return true; /// Move 2 square
    if (pE != NULL) /// Enpassant
    {
        if (curr[0] == _new[0] + 1 && curr[1] == _new[1] + 1 && curr[1] == '4' && pE->getColor() == Global::Color[Global::Team::White] &&
            pE->getType() == Global::Type[Global::Piece::Pawn] && pE->isFirstMove())
        {
            enpassant = true;
            return true;
        }
        if (curr[0] == _new[0] - 1 && curr[1] == _new[1] + 1 && curr[1] == '4' && pE->getColor() == Global::Color[Global::Team::White] &&
            pE->getType() == Global::Type[Global::Piece::Pawn] && pE->isFirstMove())
        {
            enpassant = true;
            return true;
        }
    }
    if (pN != NULL) /// Capture
    {
        if (curr[0] == _new[0] + 1 && curr[1] == _new[1] + 1 && pN->getColor() == Global::Color[Global::Team::White])
        {
            if (_new[1] == '1')
                promote = true;
            return true;
        }
        if (curr[0] == _new[0] - 1 && curr[1] == _new[1] + 1 && pN->getColor() == Global::Color[Global::Team::White])
        {
            if (_new[1] == '1')
                promote = true;
            return true;
        }
    }
    return false;
}

bool Pawn::isEnpassant()
{
    if (enpassant)
    {
        enpassant = false;
        return !enpassant;
    }
    else
        return false;
}

bool Pawn::isPromote()
{
    if (promote)
    {
        promote = false;
        return !promote;
    }
    else
        return false;
}

bool Pawn::captureRange(std::string new_ , const std::vector< Square* > &)
{
    std::string curr = getPosition();

    if ((curr[0] + 1 == new_[0] || curr[0] - 1 == new_[0]) && curr[1] + 1 == new_[1] && getColor() == Global::Color[Global::Team::White])
        return true;
    if ((curr[0] + 1 == new_[0] || curr[0] - 1 == new_[0]) && curr[1] - 1 == new_[1] && getColor() == Global::Color[Global::Team::Black])
        return true;

    return false;
}




