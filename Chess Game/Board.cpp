#include "Board.h"
#include "Square.h"
#include "Constants.h"
#include "Player.h"
#include "Pawn.h"
#include "King.h"

Board::Board()
{
    for (int i = 0; i < Global::NUM_PLAYERS; i++)
        player.push_back(new Player(Global::Color[i]));

    for (int i = 0; i < Global::NUM_SQUARES; i++)
    {
        if (player[0]->hasPiece(Global::Position[i]))
            board.push_back(new Square(Global::Position[i] , player[0]->getPiece(Global::Position[i])));
        else if (player[1]->hasPiece(Global::Position[i]))
            board.push_back(new Square(Global::Position[i] , player[1]->getPiece(Global::Position[i])));
        else
            board.push_back(new Square(Global::Position[i]));
    }
    pW = pB = NULL;
}

Board::~Board()
{
    for (auto it = player.begin(); it != player.end(); ++it)
        delete (*it);
    player.clear();

    for (auto it = board.begin(); it != board.end(); ++it)
        delete (*it);
    board.clear();
}

void Board::display() const
{
    std::cout << '\n' << '\n';
    for (auto it = board.begin(); it != board.end(); ++it)
        (*it)->display();
    std::cout << '\n' << '\n';
}

void Board::updateAttack()
{
    Piece * p = NULL;

    for(int i = 0; i < Global::NUM_SQUARES; i++)
        board[i]->reset();

    for (int i = 0; i < Global::NUM_SQUARES; i++)
    {
        if (!board[i]->isEmpty())
        {
            if (player[0]->hasPiece(Global::Position[i]))
                p = player[0]->getPiece(Global::Position[i]);
            else
                p = player[1]->getPiece(Global::Position[i]);

            for (int j = 0; j < Global::NUM_SQUARES; j++)
            {
                if (p->captureRange(Global::Position[j] , board))
                    board[j]->addAttacker(p->getColor());
            }
        }
    }
}

void Board::start()
{
    Player * currentPlayer = player[0];
    Piece * p;
    int playerTurn = Global::Team::White;
    std::string piece , square;

    while (!isGameOver(currentPlayer))
    {
        if (playerTurn == Global::Team::White)
        {
            piece = player[0]->pickPiece();
            square = player[0]->pickSquare();
            p = player[0]->getPiece(piece);
            if (p->isMoveValid(square , board))
            {
                if (legal(piece , square))
                {
                    playerTurn = Global::Team::Black;
                    currentPlayer = player[1];
                }
                updateAttack();
                display();
            }
        }
        else
        {
            piece = player[1]->pickPiece();
            square = player[1]->pickSquare();
            p = player[1]->getPiece(piece);
            if (p->isMoveValid(square , board))
            {
                if (legal(piece , square))
                {
                    playerTurn = Global::Team::White;
                    currentPlayer = player[0];
                }
                updateAttack();
                display();
            }
        }
    }
}

bool Board::isGameOver(Player * thisPlayer)
{
    for (int i = 0; i < Global::NUM_SQUARES; i++)
    {
        if (thisPlayer->hasPiece(Global::Position[i]))
        {
            for (int j = 0; j < Global::NUM_SQUARES; j++)
            {
                if (isMoveLegal(Global::Position[i] , Global::Position[j]))
                    return false;
            }
        }
    }

    if (thisPlayer->getColor() == Global::Color[Global::Team::White])
    {
        if (!isKingAttacked(thisPlayer))
            std::cout << "Stalemate.";
        else
            std::cout << "Black Player wins!!!";
    }
    else
    {
        if (!isKingAttacked(thisPlayer))
            std::cout << "Stalemate.";
        else
            std::cout << "White Player wins!!!";
    }

    return true;
}

bool Board::legal(std::string old_ , std::string new_)
{
    bool isLegal = false;

    Player * thisPlayer = NULL;
    (player[0]->hasPiece(old_)) ? thisPlayer = player[0] : thisPlayer = player[1];

    if (isMove(old_ , new_))
    {
        movePiece(old_ , new_);
        if (!isKingAttacked(thisPlayer))
        {
            isLegal = true;
            if (isPromote(new_))
            {
                Piece * p = board[Global::Index[new_]]->getPiece();
                if (p->getColor() == Global::Color[Global::Team::White])
                {
                    player[0]->pawnPromotion(new_);
                    board[Global::Index[new_]]->setPiece(player[0]->getPiece(new_));
                }
                else
                {
                    player[1]->pawnPromotion(new_);
                    board[Global::Index[new_]]->setPiece(player[1]->getPiece(new_));
                }
            }
            nextTurn(new_);
        }
        else
            resetMove(old_ , new_);
    }
    else if (isCapture(old_ , new_))
    {
        Player * otherPlayer = NULL;
        (player[0]->hasPiece(new_)) ? otherPlayer = player[0] : otherPlayer = player[1];
        capturePiece(old_ , new_);
        if (!isKingAttacked(thisPlayer))
        {
            isLegal = true;
            deletePiece(otherPlayer , new_);
            if (isPromote(new_))
            {
                Piece * p = board[Global::Index[new_]]->getPiece();
                if (p->getColor() == Global::Color[Global::Team::White])
                {
                    player[0]->pawnPromotion(new_);
                    board[Global::Index[new_]]->setPiece(player[0]->getPiece(new_));
                }
                else
                {
                    player[1]->pawnPromotion(new_);
                    board[Global::Index[new_]]->setPiece(player[1]->getPiece(new_));
                }
            }
            nextTurn(new_);
        }
        else
            resetCapture(old_ , new_);
    }
    else if (isCastle(old_ , new_))
    {
        castleKing(old_ , new_);
        if (!isKingAttacked(thisPlayer))
        {
            isLegal = true;
            nextTurn(new_);
        }
        else
            resetCastle(old_ , new_);
    }
    else if (isEnpassant(old_ , new_))
    {
        Player * otherPlayer = NULL;
        (player[0]->hasPiece(old_)) ? otherPlayer = player[1] : otherPlayer = player[0];
        captureEnpassant(old_ , new_);
        if (!isKingAttacked(thisPlayer))
        {
            isLegal = true;
            deletePawn(otherPlayer , new_);
            nextTurn(new_);
        }
        else
            resetEnpassant(old_ , new_);
    }

    return isLegal;
}

void Board::deletePiece(Player * thisPlayer , std::string new_)
{
    thisPlayer->deletePiece(new_);
}

void Board::deletePawn(Player * thisPlayer , std::string new_)
{
    std::string enpassant = new_;

    (thisPlayer->getColor() == Global::Color[Global::Team::White]) ? enpassant[1] -= 1 : enpassant[1] += 1;

    thisPlayer->deletePiece(enpassant);
}

bool Board::isMoveLegal(std::string old_ , std::string new_)
{
    bool legal = false;

    Player * thisPlayer = NULL;
    (player[0]->hasPiece(old_)) ? thisPlayer = player[0] : thisPlayer = player[1];

    if (isMove(old_ , new_))
    {
        movePiece(old_ , new_);
        if (!isKingAttacked(thisPlayer))
            legal = true;
        resetMove(old_ , new_);
    }
    else if (isCapture(old_ , new_))
    {
        capturePiece(old_ , new_);
        if (!isKingAttacked(thisPlayer))
            legal = true;
        resetCapture(old_ , new_);
    }
    else if (isCastle(old_ , new_))
    {
        castleKing(old_ , new_);
        if (!isKingAttacked(thisPlayer))
            legal = true;
        resetCastle(old_ , new_);
    }
    else if (isEnpassant(old_ , new_))
    {
        captureEnpassant(old_ , new_);
        if (!isKingAttacked(thisPlayer))
            legal = true;
        resetEnpassant(old_ , new_);
    }
    return legal;
}

bool Board::isMove(std::string old_ , std::string new_)
{
    Piece * p = board[Global::Index[old_]]->getPiece();

    if (!p->isMoveValid(new_ , board))
        return false;

    if (!board[Global::Index[new_]]->isEmpty())
        return false;

    if (p->getType() == Global::Type[Global::Piece::Pawn])
    {
        Pawn * pawn = dynamic_cast< Pawn* > (p);
        if (pawn->isEnpassant())
            return false;
    }
    if (p->getType() == Global::Type[Global::Piece::King])
    {
        King * king = dynamic_cast< King* > (p);
        if (king->isCastle())
            return false;
    }
    return true;
}

void Board::movePiece(std::string old_ , std::string new_)
{
    Piece * p = board[Global::Index[old_]]->getPiece();

    board[Global::Index[old_]]->removePiece();
    board[Global::Index[new_]]->setPiece(p);
    p->setPosition(new_);
}

void Board::resetMove(std::string old_ , std::string new_)
{
    Piece * p = board[Global::Index[new_]]->getPiece();

    board[Global::Index[old_]]->setPiece(p);
    board[Global::Index[new_]]->removePiece();
    p->setPosition(old_);
}

bool Board::isCapture(std::string old_ , std::string new_)
{
    if (board[Global::Index[new_]]->isEmpty())
        return false;

    Piece * pOld , * pNew;
    pOld = board[Global::Index[old_]]->getPiece();
    pNew = board[Global::Index[new_]]->getPiece();

    if (!pOld->isMoveValid(new_ , board))
        return false;

    if (pOld->getColor() == pNew->getColor())
        return false;

    return true;
}

void Board::capturePiece(std::string old_ , std::string new_)
{
    Piece * pOld = board[Global::Index[old_]]->getPiece();

    board[Global::Index[new_]]->removePiece();
    board[Global::Index[old_]]->removePiece();
    board[Global::Index[new_]]->setPiece(pOld);
    pOld->setPosition(new_);
}

void Board::resetCapture(std::string old_ , std::string new_)
{
    Piece * pOld = board[Global::Index[new_]]->getPiece();

    board[Global::Index[new_]]->removePiece();
    board[Global::Index[old_]]->setPiece(pOld);
    pOld->setPosition(old_);

    Player * thisPlayer = NULL;

   (player[0]->hasPiece(new_)) ? thisPlayer = player[0] : thisPlayer = player[1];

   board[Global::Index[new_]]->setPiece(thisPlayer->getPiece(new_));
}

bool Board::isCastle(std::string old_ , std::string new_)
{
    Piece * p = board[Global::Index[old_]]->getPiece();

    if (!board[Global::Index[new_]]->isEmpty())
        return false;

    if (!p->isMoveValid(new_ , board))
        return false;

    if (p->getType() != Global::Type[Global::Piece::King])
        return false;

    King * king = dynamic_cast< King* > (p);

    if (!king->isCastle())
        return false;

    return true;
}

void Board::castleKing(std::string old_ , std::string new_)
{
    Piece * pKing , * pRook;
    std::string castle;
    std::string temp;
    pKing = board[Global::Index[old_]]->getPiece();

    if (new_ == "C1")
        castle = "A1";
    if (new_ == "G1")
        castle = "H1";
    if (new_ == "C8")
        castle = "A8";
    if (new_ == "G8")
        castle = "H8";

    temp = new_;

    if (new_[0] == 'C')
        temp[0] += 1;
    else
        temp[0] -= 1;

    pRook = board[Global::Index[castle]]->getPiece();

    board[Global::Index[old_]]->removePiece();
    board[Global::Index[castle]]->removePiece();
    board[Global::Index[new_]]->setPiece(pKing);
    board[Global::Index[temp]]->setPiece(pRook);
    pKing->setPosition(new_);
    pRook->setPosition(temp);
}

void Board::resetCastle(std::string old_ , std::string new_)
{
    Piece * pKing , * pRook;
    std::string castle;
    std::string temp;
    pKing = board[Global::Index[new_]]->getPiece();

    if (new_ == "C1")
        castle = "A1";
    if (new_ == "G1")
        castle = "H1";
    if (new_ == "C8")
        castle = "A8";
    if (new_ == "G8")
        castle = "H8";

    temp = new_;

    if (new_[0] == 'C')
        temp[0] += 1;
    else
        temp[0] -= 1;

    pRook = board[Global::Index[temp]]->getPiece();

    board[Global::Index[new_]]->removePiece();
    board[Global::Index[temp]]->removePiece();
    board[Global::Index[old_]]->setPiece(pKing);
    board[Global::Index[castle]]->setPiece(pRook);
    pKing->setPosition(old_);
    pRook->setPosition(castle);
}

bool Board::isEnpassant(std::string old_ , std::string new_)
{
    Piece * p = board[Global::Index[old_]]->getPiece();

    if (p->getType() != Global::Type[Global::Piece::Pawn])
        return false;

    if (!p->isMoveValid(new_ , board))
        return false;

    Pawn * pawn = dynamic_cast< Pawn* > (p);

    if (!pawn->isEnpassant())
        return false;

    return true;
}

void Board::captureEnpassant(std::string old_ , std::string new_)
{
    Piece * p = board[Global::Index[old_]]->getPiece();
    std::string enpassant = new_;

    (p->getColor() == Global::Color[Global::Team::White]) ? enpassant[1] -= 1 : enpassant[1] += 1;

    board[Global::Index[old_]]->removePiece();
    board[Global::Index[enpassant]]->removePiece();
    board[Global::Index[new_]]->setPiece(p);
    p->setPosition(new_);
}

void Board::resetEnpassant(std::string old_ , std::string new_)
{
    Piece * p = board[Global::Index[new_]]->getPiece();
    std::string enpassant = new_;

    (p->getColor() == Global::Color[Global::Team::White]) ? enpassant[1] -= 1 : enpassant[1] += 1;

    board[Global::Index[new_]]->removePiece();
    board[Global::Index[old_]]->setPiece(p);
    p->setPosition(old_);

    Player * thisPlayer = NULL;

    (player[0]->hasPiece(enpassant)) ? thisPlayer = player[0] : thisPlayer = player[1];

    board[Global::Index[enpassant]]->setPiece(thisPlayer->getPiece(enpassant));
}

bool Board::isKingAttacked(Player * thisPlayer)
{
    updateAttack();

    King * king = dynamic_cast< King* > (board[Global::Index[thisPlayer->findKing()]]->getPiece());

    if (king->isInCheck(board))
        return true;
    else
        return false;
}

void Board::nextTurn(std::string pos)
{
    Piece * p = board[Global::Index[pos]]->getPiece();

    if (p->getColor() == Global::Color[Global::Team::White])
    {
        if (pW == NULL)
            pW = p;
        else
        {
            pW->notFirstMove();
            pW = p;
        }
    }
    else
    {
        if (pB == NULL)
            pB = p;
        else
        {
            pB->notFirstMove();
            pB = p;
        }
    }

}

bool Board::isPromote(std::string pos)
{
    Piece * p = board[Global::Index[pos]]->getPiece();

    if (p->getType() == Global::Type[Global::Piece::Pawn])
    {
        Pawn * pawn = dynamic_cast< Pawn* > (p);
        if (pawn->isPromote())
            return true;
    }

    return false;
}







