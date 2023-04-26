#pragma once
#include "Piece.h"

class Knight : public Piece {
public:
	Knight(int newX, int newY, int newColor) : Piece(newX, newY, newColor) {
		if (color == 1) {			//Black
			std::string move;
			move += std::to_string(this->x + 2);
			move += std::to_string(this->y + 1);
			this->moves.push_back(move);

			move = "";
			move += std::to_string(this->x + 2);
			move += std::to_string(this->y - 1);
			this->moves.push_back(move);
		}
		else {
			std::string move;
			move += std::to_string(this->x - 2);
			move += std::to_string(this->y + 1);
			this->moves.push_back(move);

			move = "";
			move += std::to_string(this->x - 2);
			move += std::to_string(this->y - 1);
			this->moves.push_back(move);
		}
	}

	void updateLegalMoves(int board[8][8]) {
		this->moves.clear();
		std::string move; 


		if (this->color == 0) {			//White
			if (isValidPosition(this->x + 2, this->y + 1) && board[this->x + 2][this->y + 1] <= 0) {
				move += std::to_string(this->x + 2);
				move += std::to_string(this->y + 1);
				this->moves.push_back(move);
			}
			move = "";
			if (isValidPosition(this->x + 2, this->y - 1) && board[this->x + 2][this->y - 1] <= 0) {
				move += std::to_string(this->x + 2);
				move += std::to_string(this->y - 1);
				this->moves.push_back(move);
			}
			move = "";
			if (isValidPosition(this->x - 2, this->y + 1) && board[this->x - 2][this->y + 1] <= 0) {
				move += std::to_string(this->x - 2);
				move += std::to_string(this->y + 1);
				this->moves.push_back(move);
			}
			move = "";
			if (isValidPosition(this->x - 2, this->y - 1) && board[this->x - 2][this->y - 1] <= 0) {
				move += std::to_string(this->x - 2);
				move += std::to_string(this->y - 1);
				this->moves.push_back(move);
			}
			move = "";
			if (isValidPosition(this->x + 1, this->y - 2) && board[this->x + 1][this->y - 2] <= 0) {
				move += std::to_string(this->x + 1);
				move += std::to_string(this->y - 2);
				this->moves.push_back(move);
			}
			move = "";
			if (isValidPosition(this->x - 1, this->y - 2) && board[this->x - 1][this->y - 2] <= 0) {
				move += std::to_string(this->x - 1);
				move += std::to_string(this->y - 2);
				this->moves.push_back(move);
			}
			move = "";
			if (isValidPosition(this->x + 1, this->y + 2) && board[this->x + 1][this->y + 2] <= 0) {
				move += std::to_string(this->x + 1);
				move += std::to_string(this->y + 2);
				this->moves.push_back(move);
			}
			move = "";
			if (isValidPosition(this->x - 1, this->y + 2) && board[this->x - 1][this->y + 2] <= 0) {
				move += std::to_string(this->x - 1);
				move += std::to_string(this->y + 2);
				this->moves.push_back(move);
			}
			move = "";

		}
		else {							//Black
			if (isValidPosition(this->x + 2, this->y + 1) && board[this->x + 2][this->y + 1] >= 0) {
				move += std::to_string(this->x + 2);
				move += std::to_string(this->y + 1);
				this->moves.push_back(move);
			}
			move = "";
			if (isValidPosition(this->x + 2, this->y - 1) && board[this->x + 2][this->y - 1] >= 0) {
				move += std::to_string(this->x + 2);
				move += std::to_string(this->y - 1);
				this->moves.push_back(move);
			}
			move = "";
			if (isValidPosition(this->x - 2, this->y + 1) && board[this->x - 2][this->y + 1] >= 0) {
				move += std::to_string(this->x - 2);
				move += std::to_string(this->y + 1);
				this->moves.push_back(move);
			}
			move = "";
			if (isValidPosition(this->x - 2, this->y - 1) && board[this->x - 2][this->y - 1] >= 0) {
				move += std::to_string(this->x - 2);
				move += std::to_string(this->y - 1);
				this->moves.push_back(move);
			}
			move = "";
			if (isValidPosition(this->x + 1, this->y - 2) && board[this->x + 1][this->y - 2] >= 0) {
				move += std::to_string(this->x + 1);
				move += std::to_string(this->y - 2);
				this->moves.push_back(move);
			}
			move = "";
			if (isValidPosition(this->x - 1, this->y - 2) && board[this->x - 1][this->y - 2] >= 0) {
				move += std::to_string(this->x - 1);
				move += std::to_string(this->y - 2);
				this->moves.push_back(move);
			}
			move = "";
			if (isValidPosition(this->x + 1, this->y + 2) && board[this->x + 1][this->y + 2] >= 0) {
				move += std::to_string(this->x + 1);
				move += std::to_string(this->y + 2);
				this->moves.push_back(move);
			}
			move = "";
			if (isValidPosition(this->x - 1, this->y + 2) && board[this->x - 1][this->y + 2] >= 0) {
				move += std::to_string(this->x - 1);
				move += std::to_string(this->y + 2);
				this->moves.push_back(move);
			}
			move = "";
		}

	}
private:

};