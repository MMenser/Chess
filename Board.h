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


		this->wAlivePieces[0] = new Pawn(6, 0, 0);
		this->wAlivePieces[1] = new Pawn(6, 1, 0);
		this->wAlivePieces[2] = new Pawn(6, 2, 0);
		this->wAlivePieces[3] = new Pawn(6, 3, 0);
		this->wAlivePieces[4] = new Pawn(6, 4, 0);
		this->wAlivePieces[5] = new Pawn(6, 5, 0);
		this->wAlivePieces[6] = new Pawn(6, 6, 0);
		this->wAlivePieces[7] = new Pawn(6, 7, 0);
		this->wAlivePieces[8] = new Rook(7, 0, 0);
		this->wAlivePieces[9] = new Rook(7, 7, 0);
		this->wAlivePieces[10] = new Knight(7, 1, 0);
		this->wAlivePieces[11] = new Knight(7, 6, 0);
		this->wAlivePieces[12] = new Bishop(7, 2, 0);
		this->wAlivePieces[13] = new Bishop(7, 5, 0);
		this->wAlivePieces[14] = new Queen(7, 3, 0);
		this->wAlivePieces[15] = new King(7, 4, 0);
	}


	Piece* getWhitePiece(int index) {
		return this->wAlivePieces[index];
	}

	Piece* getBlackPiece(int index) {
		return this->wDeadPieces[index];
	}

private:
	Piece* wAlivePieces[16];
	Piece* bAlivePieces[16];
	Piece* wDeadPieces[16];
	Piece* bDeadPieces[16];
};