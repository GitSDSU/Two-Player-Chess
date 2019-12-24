#ifndef PIECE_H
#define PIECE_H

#include "Constants.h"
#include <vector>

class Square;

class Piece
{
    public:
        /// Constructor/Destructor
        Piece(std::string , std::string , std::string);
        virtual ~Piece();
        /// Getters
        std::string getPosition() const;
        std::string getColor() const;
        std::string getType() const;
        bool isFirstMove() const;
        /// Setters
        void setPosition(std::string);
        void notFirstMove();
        /// Extra
        void display() const;
        virtual bool isMoveValid(std::string , const std::vector< Square* > &) = 0;
        virtual bool captureRange(std::string , const std::vector< Square* > &) = 0;

    protected:

    private:
        std::string type;
        std::string color;
        std::string position;
        bool firstMove;
};

#endif // PIECE_H
