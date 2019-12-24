#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <iostream>

class Piece;
class Square;
class Player;
/// pW & pB haven't been implemented
/// enpassant does not work correctly
typedef std::vector< Square* > VectorSquare;
typedef std::vector< Player* > VectorPlayer;

class Board
{
    public:
        Board();
        ~Board();
        void display() const;
        void updateAttack();
        void start();

    protected:

    private:
        VectorSquare board;
        VectorPlayer player;
        Piece * pW;
        Piece * pB;
        bool isGameOver(Player *);
        bool legal(std::string , std::string);
        void deletePiece(Player * , std::string);
        void deletePawn(Player * , std::string);
        bool isMoveLegal(std::string , std::string);
        bool isMove(std::string , std::string);
        void movePiece(std::string , std::string);
        void resetMove(std::string , std::string);
        bool isCapture(std::string , std::string);
        void capturePiece(std::string , std::string);
        void resetCapture(std::string , std::string);
        bool isCastle(std::string , std::string);
        void castleKing(std::string , std::string);
        void resetCastle(std::string , std::string);
        bool isEnpassant(std::string , std::string);
        void captureEnpassant(std::string , std::string);
        void resetEnpassant(std::string , std::string);
        bool isKingAttacked(Player *);
        void nextTurn(std::string);
        bool isPromote(std::string );
};

#endif // BOARD_H
