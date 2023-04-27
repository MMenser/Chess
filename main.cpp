#include "Board.h"

void testPawnMoves(Board board, int matrix[8][8]);
void testKnightMoves(Board board, int matrix[8][8]);
void testBishopMoves(Board board, int matrix[8][8]);
void testKingMoves(Board board, int matrix[8][8]);
void testQueenMoves(Board board, int matrix[8][8]);

int main(void) {

	int boardIntArr[8][8] = { 0 };

	Board board;
	int x = 0, y = 0;
	for (int i = 0; i < 16; i++) {
		x = board.getWhitePiece(i)->getX();
		y = board.getWhitePiece(i)->getY();
		if (x != -1) {
			boardIntArr[x][y] = board.getWhitePiece(i)->getColor();			//Black pieces become 1
		}
		
	}
	for (int i = 0; i < 16; i++) {
		x = board.getBlackPiece(i)->getX();
		y = board.getBlackPiece(i)->getY();
		if (x != -1) {							//If piece is captured, make x = -1
			boardIntArr[x][y] = board.getBlackPiece(i)->getColor();			//White pieces become -1
		}
		
	}
	testPawnMoves(board, boardIntArr);
	std::cout << endl;
	testKnightMoves(board, boardIntArr);
	std::cout << endl;
	testBishopMoves(board, boardIntArr);
	std::cout << endl;
	testQueenMoves(board, boardIntArr);
	std::cout << endl;
	testKingMoves(board, boardIntArr);

	bool gameEnd = false, white = true;

	while (!gameEnd) {
		for (int i = 0; i < 16; i++) {
			board.getWhitePiece(i)->updateLegalMoves(boardIntArr);
		}
		for (int i = 0; i < 16; i++) {
			board.getBlackPiece(i)->updateLegalMoves(boardIntArr);
		}
		board.chooseMove(white);

		for (int i = 0; i < 16; i++) {
			board.getWhitePiece(i)->updateLegalMoves(boardIntArr);
		}
		for (int i = 0; i < 16; i++) {
			board.getBlackPiece(i)->updateLegalMoves(boardIntArr);
		}
		white = false;
		board.chooseMove(white);





		gameEnd = true;
		
	}



	return 0;
}

void testPawnMoves(Board board, int matrix[8][8]) {
	Piece* pawn = board.getWhitePiece(0);
	dynamic_cast<Pawn*>(pawn)->updateLegalMoves(matrix);
	std::vector<std::string> moveVec = pawn->returnMoves();

	for (const auto& str : moveVec) {
		std::cout << str << " ";
	}
}

void testKnightMoves(Board board, int matrix[8][8]) {
	Piece* knight = board.getWhitePiece(10);
	knight->setX(4);
	knight->setY(4);
	dynamic_cast<Knight*>(knight)->updateLegalMoves(matrix);
	std::vector<std::string> moveVec = knight->returnMoves();

	for (const auto& str : moveVec) {
		std::cout << str << " ";
	}
}
void testBishopMoves(Board board, int matrix[8][8]) {
	Piece* bishop = board.getWhitePiece(12);
	dynamic_cast<Bishop*>(bishop)->updateLegalMoves(matrix);
	std::vector<std::string> moveVec = bishop->returnMoves();

	for (const auto& str : moveVec) {
		std::cout << str << " ";
	}

}
void testQueenMoves(Board board, int matrix[8][8]) {
	Piece* queen = board.getWhitePiece(14);
	dynamic_cast<Queen*>(queen)->updateLegalMoves(matrix);
	std::vector<std::string> moveVec = queen->returnMoves();

	for (const auto& str : moveVec) {
		std::cout << str << " ";
	}
}

void testKingMoves(Board board, int matrix[8][8]) {
	Piece* king = board.getBlackPiece(15);
	
	dynamic_cast<King*>(king)->updateLegalMoves(matrix);
	std::vector<std::string> moveVec = king->returnMoves();

	for (const auto& str : moveVec) {
		std::cout << str << " ";
	}
}


/*
boardIntArr[1][i] = -1;
		boardIntArr[6][i] = 1;		//Sets the pawns onto the board
	}						//Pawns = 1, Knight = 2, Bishop = 3, Rook = 4, Queen = 5, King = 6
	boardIntArr[0][0] = -4, boardIntArr[0][7] = -4, boardIntArr[7][0] = 4, boardIntArr[7][7] = 4;		//Sets rooks
	boardIntArr[0][1] = -2, boardIntArr[0][6] = -2, boardIntArr[7][1] = 2, boardIntArr[7][6] = 2;		//Sets knights
	boardIntArr[0][2] = -3, boardIntArr[0][5] = -3, boardIntArr[7][2] = 3, boardIntArr[7][5] = 3;		//Sets bishops
	boardIntArr[0][3] = 5, boardIntArr[0][4] = 6, boardIntArr[7][3] = 5, boardIntArr[7][4] = 6;			//Sets queens, kings
	*/