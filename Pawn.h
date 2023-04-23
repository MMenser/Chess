#pragma once
#include "Piece.h"

class Pawn : public Piece {
public:
	Pawn(int newX, int newY, int newColor) : Piece(newX, newY, newColor) {
		this->firstMove = true;

		std::string newMove = (this->x + 2) + "," + this->y;
		this->moves.push_back(newMove);

		newMove = (this->x + 1) + "," + this->y;
		this->moves.push_back(newMove);
	}

	void updateLegalMoves(int board[8][8]) {
		this->moves.clear();
		if (board[this->x])
	}

private:
	bool firstMove;
};