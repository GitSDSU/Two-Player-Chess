#include "Player.h"
#include "Pawn.h"
#include "King.h"
#include "Bishop.h"
#include "Knight.h"
#include "Rook.h"
#include "Queen.h"

Player::Player(std::string team)
{
    color = team;
    (color == "White") ? name = "White Player" : name = "Black Player";

    for (int i = 0; i < Global::NUM_PAWNS; i++)
        piece.push_back(new Pawn(Global::Type[Global::Piece::Pawn] , color , Global::PawnCol[i] + Global::PawnRow[color]));
    for (int i = 0; i < Global::NUM_KINGS; i++)
        piece.push_back(new King(Global::Type[Global::Piece::King] , color , Global::KingCol[i] + Global::Row[color]));
    for (int i = 0; i < Global::NUM_MINOR; i++)
        piece.push_back(new Bishop(Global::Type[Global::Piece::Bishop] , color , Global::BishopCol[i] + Global::Row[color]));
    for (int i = 0; i < Global::NUM_MINOR; i++)
        piece.push_back(new Knight(Global::Type[Global::Piece::Knight] , color , Global::KnightCol[i] + Global::Row[color]));
    for (int i = 0; i < Global::NUM_MINOR; i++)
        piece.push_back(new Rook(Global::Type[Global::Piece::Rook] , color , Global::RookCol[i] + Global::Row[color]));
    for (int i = 0; i < Global::NUM_KINGS; i++)
        piece.push_back(new Queen(Global::Type[Global::Piece::Queen] , color , Global::QueenCol[i] + Global::Row[color]));
}

Player::~Player()
{
    for (auto it = piece.begin(); it != piece.end(); ++it)
        delete (*it);
    piece.clear();
}

bool Player::hasPiece(std::string pos) const
{
    for (auto it = piece.begin(); it != piece.end(); ++it)
    {
        if ((*it)->getPosition() == pos)
            return true;
    }
    return false;
}

Piece * Player::getPiece(std::string pos)
{
    for (auto it = piece.begin(); it != piece.end(); ++it)
    {
        if ((*it)->getPosition() == pos)
            return (*it);
    }
    return NULL;
}

bool Player::validInput(std::string pos)
{
    for (int i = 0; i < Global::NUM_SQUARES; i++)
    {
        if (pos == Global::Position[i])
            return true;
    }
    return false;
}

std::string Player::pickPiece()
{
    std::cout << name << ", choose a piece: ";
    std::string input;
    std::cin >> input;

    if (!hasPiece(input))
        input = pickPiece();

    return input;
}

std::string Player::pickSquare()
{
    std::cout << name << ", choose a square: " ;
    std::string input;
    std::cin >> input;
    return input;
}

void Player::deletePiece(std::string position)
{
    for (auto it = piece.begin(); it != piece.end(); ++it)
    {
        if ((*it)->getPosition() == position)
            { delete (*it); piece.erase(it); }
    }
}

std::string Player::findKing()
{
    for (auto it = piece.begin(); it != piece.end(); ++it)
    {
        if ((*it)->getType() == Global::Type[Global::Piece::King])
            return (*it)->getPosition();
    }
    return "Empty";
}

void Player::pawnPromotion(std::string pos)
{
    std::cout << "Promote pawn to (N)ight , (B)ishop , (R)ook , (Q)ueen: " ;
    std::string input;
    std::cin >> input;

    if (input == "N")
    {
        deletePiece(pos);
        piece.push_back(new Knight("Knight" , color , pos));
    }
    else if (input == "B")
    {
        deletePiece(pos);
        piece.push_back(new Knight("Bishop" , color , pos));
    }
    else if (input == "R")
    {
        deletePiece(pos);
        piece.push_back(new Knight("Rook" , color , pos));
    }
    else if (input == "Q")
    {
        deletePiece(pos);
        piece.push_back(new Knight("Queen" , color , pos));
    }
    else
    {
        pawnPromotion(pos);
    }
}

std::string Player::getName() const
{
    return name;
}

std::string Player::getColor() const
{
    return color;
}






