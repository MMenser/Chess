#pragma once

#include "Pawn.h"
#include "Knight.h"
#include "Bishop.h"
#include "Rook.h"
#include "Queen.h"
#include "King.h"


class Board {
public:
	Board() {
		this->bAlivePieces[0] = new Pawn(1, 0, 1);
		this->bAlivePieces[1] = new Pawn(1, 1, 1);
		this->bAlivePieces[2] = new Pawn(1, 2, 1);
		this->bAlivePieces[3] = new Pawn(1, 3, 1);
		this->bAlivePieces[4] = new Pawn(1, 4, 1);
		this->bAlivePieces[5] = new Pawn(1, 5, 1);
		this->bAlivePieces[6] = new Pawn(1, 6, 1);
		this->bAlivePieces[7] = new Pawn(1, 7, 1);
		this->bAlivePieces[8] = new Rook(0, 0, 1);
		this->bAlivePieces[9] = new Rook(0, 7, 1);
		this->bAlivePieces[10] = new Knight(0, 1, 1);
		this->bAlivePieces[11] = new Knight(0, 6, 1);
		this->bAlivePieces[12] = new Bishop(0, 2, 1);
		this->bAlivePieces[13] = new Bishop(0, 5, 1);
		this->bAlivePieces[14] = new Queen(0, 3, 1);
		this->bAlivePieces[15] = new King(0, 4, 1);


		this->wAlivePieces[0] = new Pawn(6, 0, -1);
		this->wAlivePieces[1] = new Pawn(6, 1, -1);
		this->wAlivePieces[2] = new Pawn(6, 2, -1);
		this->wAlivePieces[3] = new Pawn(6, 3, -1);
		this->wAlivePieces[4] = new Pawn(6, 4, -1);
		this->wAlivePieces[5] = new Pawn(6, 5, -1);
		this->wAlivePieces[6] = new Pawn(6, 6, -1);
		this->wAlivePieces[7] = new Pawn(6, 7, -1);
		this->wAlivePieces[8] = new Rook(7, 0, -1);
		this->wAlivePieces[9] = new Rook(7, 7, -1);
		this->wAlivePieces[10] = new Knight(7, 1, -1);
		this->wAlivePieces[11] = new Knight(7, 6, -1);
		this->wAlivePieces[12] = new Bishop(7, 2, -1);
		this->wAlivePieces[13] = new Bishop(7, 5, -1);
		this->wAlivePieces[14] = new Queen(7, 3, -1);
		this->wAlivePieces[15] = new King(7, 4, -1);
	}


	Piece* getWhitePiece(int index) {
		return this->wAlivePieces[index];
	}

	Piece* getBlackPiece(int index) {
		return this->bAlivePieces[index];
	}

	int letterToNum(char c) {
		int placeX = 0;

		if (c == 'A') {
			placeX = 0;
		}
		else if (c == 'B') {
			placeX = 1;
		}
		else if (c == 'C') {
			placeX = 2;
		}
		else if (c == 'D') {
			placeX = 3;
		}
		else if (c == 'E') {
			placeX = 4;
		}
		else if (c == 'F') {
			placeX = 5;
		}
		else if (c == 'G') {
			placeX = 6;
		}
		else if (c == 'H') {
			placeX = 7;
		}

		return placeX;
	}

	void chooseMove(bool white) {
		std::string str;
		int findX, findY, newX, newY;
		std::cout << "Enter the piece you want to move. EX: A2" << endl;
		cin >> str;
		findX = letterToNum(str[0]);
		findY = str[1] - 49;

		str = "";
		std::cout << "Enter where you want to move it. EX: A4" << endl;
		cin >> str;
		newX = letterToNum(str[0]);
		newY = str[1] - 49;

		std::string potentialMove;
		potentialMove += std::to_string(newX);
		potentialMove += std::to_string(newY);
		bool moveIsLegal = false;

		for (int i = 0; i < 16; i++) {
			if (white && this->getWhitePiece(i)->getX() == findX && this->getWhitePiece(i)->getY() == findY) {
				for (const auto& s : this->wAlivePieces[i]->returnMoves()) {
					if (s == potentialMove) {													//Check whether the potential move is in the pieces legal move vector
						moveIsLegal = true;
					}
				}

				if (moveIsLegal) {
					this->getWhitePiece(i)->setX(newX);					//Need to update legal moves in main for every piece 
					this->getWhitePiece(i)->setY(newY);
				}
				else {
					chooseMove(white);
				}
				
			}
			else if (!white && this->getBlackPiece(i)->getX() == findX && this->getBlackPiece(i)->getY() == findY) {
				for (const auto& s : this->bAlivePieces[i]->returnMoves()) {
					if (s == potentialMove) {
						moveIsLegal = true;
					}
				}

				if (moveIsLegal) {
					this->getBlackPiece(i)->setX(newX);
					this->getBlackPiece(i)->setY(newY);
				}
				else {
					chooseMove(white);
				}
			}
		}
	}

	void updateIntArr(int boardIntArr[8][8]) {
		int x = 0, y = 0;
		for (int i = 0; i < 16; i++) {
			x = this->getWhitePiece(i)->getX();
			y = this->getWhitePiece(i)->getY();
			if (x != -1) {
				boardIntArr[x][y] = this->getWhitePiece(i)->getColor();			//Black pieces become 1
			}

		}
		for (int i = 0; i < 16; i++) {
			x = this->getBlackPiece(i)->getX();
			y = this->getBlackPiece(i)->getY();
			if (x != -1) {							//If piece is captured, make x = -1
				boardIntArr[x][y] = this->getBlackPiece(i)->getColor();			//White pieces become -1
			}

		}
	}

	bool checkCheck(bool white) {
		int x, y;
		std::string kingPos;

		if (white) {
			x = this->wAlivePieces[15]->getX();
			y = this->wAlivePieces[15]->getY();
			
			kingPos += std::to_string(x);
			kingPos += std::to_string(y);


			for (int i = 0; i < 16; i++) {
				for (const auto& s : this->bAlivePieces[i]->returnMoves()) {
					if (s == kingPos) {												//Someone is currently targeting the white king
						return true;
					}
				}
			}
		}
		else {
			x = this->bAlivePieces[15]->getX();
			y = this->bAlivePieces[15]->getY();

			kingPos += std::to_string(x);
			kingPos += std::to_string(y);


			for (int i = 0; i < 16; i++) {
				for (const auto& s : this->wAlivePieces[i]->returnMoves()) {
					if (s == kingPos) {												//Someone is currently targeting the black king
						return true;
					}
				}
			}
		}

		return false;
	}

private:
	Piece* wAlivePieces[16];
	Piece* bAlivePieces[16];
	Piece* wDeadPieces[16];
	Piece* bDeadPieces[16];
};