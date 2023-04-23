#pragma once
#include "Piece.h"

class Pawn : public Piece {
public:
	Pawn(int newX, int newY, int newColor) : Piece(newX, newY, newColor) {
		std::string newMove = (this->x + 2) + "," + this->y;
		this->moves.push_back(newMove);

		newMove = (this->x + 1) + "," + this->y;
		this->moves.push_back(newMove);
	}
private:
};