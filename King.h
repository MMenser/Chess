#pragma once
#include "Piece.h"

class King : public Piece {
public:
	King(int newX, int newY, int newColor) : Piece(newX, newY, newColor) {
		std::string newMove = to_string(this->x) + to_string(this->y);
		this->moves.push_back(newMove);
	}

	
	void updateLegalMoves(int board[8][8]) {

		this->moves.clear();

		std::string move;
		int moveCheck = 0, yMoveCheck;


		if(color == 1)
		{

			/////           This is Up Down moves   /////////////
			moveCheck = this->x + 1;													    //one down 
			if (moveCheck < 8 && board[this->x + 1][this->y] == 0 ) {
				move = to_string(this->x + 1) + to_string(this->y);
				this->moves.push_back(move);
			}
			moveCheck = this->x - 1;													    //one up 
			if (moveCheck >= 0 && board[this->x - 1][this->y] == 0) {
				move = to_string(this->x - 1) + to_string(this->y);
				this->moves.push_back(move);
			}
			
			//////          This is Left Right moves   ////////////
			
			moveCheck = this->y - 1;													    //one left
			if (moveCheck >= 0 && board[this->x ][this->y-1] == 0) {
				move = to_string(this->x) + to_string(this->y -1);
				this->moves.push_back(move);
			}
			moveCheck = this->y + 1;													    //one right
			if (moveCheck < 8 && board[this->x][this->y+1] == 0) {
				move = to_string(this->x) + to_string(this->y + 1);
				this->moves.push_back(move);
			}



			//////          Right Diagonal Moves       //////////

			moveCheck - this->x + 1;
			yMoveCheck = this->y + 1;
			if (moveCheck < 8 && yMoveCheck < 8 && board[moveCheck][yMoveCheck] != 0) {    //right down diaganol
				move = to_string(moveCheck) + to_string(yMoveCheck);
				this->moves.push_back(move);
			}

			moveCheck - this->x - 1;
			yMoveCheck = this->y + 1;
			if (moveCheck >= 0 && yMoveCheck < 8 && board[moveCheck][yMoveCheck] != 0) {    //right up diaganol
				move = to_string(moveCheck) + to_string(yMoveCheck);
				this->moves.push_back(move);
			}

			//////          Left  Diagonal Moves       //////////


			moveCheck = this->x - 1;
			yMoveCheck = this->y - 1;
			if (moveCheck >= 0  && yMoveCheck >= 0 && board[moveCheck][yMoveCheck] != 0) {    //left up diaganol
				move = to_string(moveCheck) + to_string(yMoveCheck);
				this->moves.push_back(move);
			}
			
			moveCheck - this->x + 1;
			yMoveCheck = this->y - 1;
			if (moveCheck < 8 && yMoveCheck >= 0 && board[moveCheck][yMoveCheck] != 0) {    // left down diaganol
				move = to_string(moveCheck) + to_string(yMoveCheck);
				this->moves.push_back(move);
			}


		}
		else
		{

		}



	}


};





// 24
//
