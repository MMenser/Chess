#pragma once
#include "Piece.h"

class Pawn : public Piece {
public:
	Pawn(int newX, int newY, int newColor) : Piece(newX, newY, newColor) {
		this->firstMove = true;

		if (color == 1) {
			std::string newMove = (this->x + 2) + "," + this->y;
			this->moves.push_back(newMove);

			newMove = (this->x + 1) + "," + this->y;
			this->moves.push_back(newMove);
		}
		else {
			std::string newMove = (this->x - 2) + "," + this->y;
			this->moves.push_back(newMove);

			newMove = (this->x - 1) + "," + this->y;
			this->moves.push_back(newMove);
		}
		
	}

	void updateLegalMoves(int board[8][8]) {
		this->moves.clear();

		std::string move;
		int moveCheck = 0, yMoveCheck;

		if (color == 1) {				//Black
			moveCheck = this->x + 2;
			if (moveCheck < 8 && board[this->x + 2][this->y] == 0 && firstMove == true) {
				move = (this->x + 2) + "," + this->y;
				this->moves.push_back(move);
			}
			moveCheck = this->x + 1;
			if (moveCheck < 8 && board[this->x + 1][this->y] == 0) {
				move = (this->x + 1) + "," + this->y;
				this->moves.push_back(move);
			}
			moveCheck - this->x + 1;
			yMoveCheck = this->y + 1;
			if (moveCheck < 8 && yMoveCheck < 8 && board[moveCheck][yMoveCheck] > 0) {
				move = moveCheck + "," + yMoveCheck;
				this->moves.push_back(move);
			}
			moveCheck - this->x + 1;
			yMoveCheck = this->y - 1;
			if (moveCheck < 8 && yMoveCheck < 8 && board[moveCheck][yMoveCheck] > 0) {
				move = moveCheck + "," + yMoveCheck;
				this->moves.push_back(move);
			}
		}
		else {				//White 
			moveCheck = this->x - 2;
			if (moveCheck > -1 && board[this->x - 2][this->y] == 0 && firstMove == true) {
				move = (this->x - 2) + "," + this->y;
				this->moves.push_back(move);
			}
			moveCheck = this->x - 1;
			if (moveCheck > -1 && board[this->x - 1][this->y] == 0) {
				move = (this->x - 1) + "," + this->y;
				this->moves.push_back(move);
			}
			moveCheck - this->x - 1;
			yMoveCheck = this->y - 1;
			if (moveCheck > -1 && yMoveCheck > -1 && board[moveCheck][yMoveCheck] < 0) {
				move = moveCheck + "," + yMoveCheck;
				this->moves.push_back(move);
			}
			moveCheck - this->x - 1;
			yMoveCheck = this->y + 1;
			if (moveCheck > -1 && yMoveCheck < 8 && board[moveCheck][yMoveCheck] < 0) {
				move = moveCheck + "," + yMoveCheck;
				this->moves.push_back(move);
			}
		}
	}

	void firstMoveFalse() {
		this->firstMove = false;
	}

private:
	bool firstMove;
};