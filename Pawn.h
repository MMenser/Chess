#pragma once
#include "Piece.h"

class Pawn : public Piece {
public:
	Pawn(int newX, int newY, int newColor) : Piece(newX, newY, newColor) {
		this->firstMove = true;

		if (color == 1) {
			std::string newMove;
			newMove += std::to_string(this->x + 2);
			newMove += std::to_string(this->y);
			this->moves.push_back(newMove);

			newMove = "";
			newMove += std::to_string(this->x + 1);
			newMove += std::to_string(this->y);
			this->moves.push_back(newMove);
		}
		else {
			std::string newMove;
			newMove += std::to_string(this->x - 2);
			newMove += std::to_string(this->y);
			this->moves.push_back(newMove);

			newMove = "";
			newMove += std::to_string(this->x - 1);
			newMove += std::to_string(this->y);
			this->moves.push_back(newMove);
		}
		
	}

	void updateLegalMoves(int board[8][8]) {
		this->moves.clear();

		std::string move;
		int moveCheck = 0, yMoveCheck = 0;

		if (color == 1) {				//Black
			moveCheck = this->x + 2;
			if (this->isValidPosition(moveCheck, this->y) && board[this->x + 2][this->y] == 0 && this->firstMove == true) {
				move += std::to_string(moveCheck);
				move += std::to_string(this->y);
				this->moves.push_back(move);
			}
			move = "";
			moveCheck = this->x + 1;
			if (this->isValidPosition(moveCheck, this->y) && board[this->x + 1][this->y] == 0) {
				move += std::to_string(moveCheck);
				move += std::to_string(this->y);
				this->moves.push_back(move);
			}
			move = "";
			moveCheck - this->x + 1;
			yMoveCheck = this->y + 1;
			if (this->isValidPosition(moveCheck, yMoveCheck) && board[moveCheck][yMoveCheck] > 0) {
				move += std::to_string(moveCheck);
				move += std::to_string(yMoveCheck);
				this->moves.push_back(move);
			}
			move = "";
			moveCheck - this->x + 1;
			yMoveCheck = this->y - 1;
			if (this->isValidPosition(moveCheck, yMoveCheck) && board[moveCheck][yMoveCheck] > 0) {
				move += std::to_string(moveCheck);
				move += std::to_string(yMoveCheck);
				this->moves.push_back(move);
			}
		}
		else {				//White 
			move = "";
			moveCheck = this->x - 2;
			if (this->isValidPosition(moveCheck, this->y) && board[this->x - 2][this->y] == 0 && this->firstMove == true) {
				move += std::to_string(moveCheck);
				move += std::to_string(this->y);
				this->moves.push_back(move);
			}
			move = "";
			moveCheck = this->x - 1;
			if (this->isValidPosition(moveCheck, this->y) && board[this->x - 1][this->y] == 0) {
				move += std::to_string(moveCheck);
				move += std::to_string(this->y);
				this->moves.push_back(move);
			}
			move = "";
			moveCheck - this->x - 1;
			yMoveCheck = this->y - 1;
			if (this->isValidPosition(moveCheck, yMoveCheck) && board[moveCheck][yMoveCheck] < 0) {
				move += std::to_string(moveCheck);
				move += std::to_string(yMoveCheck);
				this->moves.push_back(move);
			}
			move = "";
			moveCheck - this->x - 1;
			yMoveCheck = this->y + 1;
			if (this->isValidPosition(moveCheck, yMoveCheck) && board[moveCheck][yMoveCheck] < 0) {
				move += std::to_string(moveCheck);
				move += std::to_string(yMoveCheck);
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