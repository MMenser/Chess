#include "Board.h"

int main(void) {

	int boardIntArr[8][8] = { 0 };
	for (int i = 0; i < 8; i++) {
		boardIntArr[1][i] = -1;
		boardIntArr[6][i] = 1;		//Sets the pawns onto the board
	}						//Pawns = 1, Knight = 2, Bishop = 3, Rook = 4, Queen = 5, King = 6
	boardIntArr[0][0] = -4, boardIntArr[0][7] = -4, boardIntArr[7][0] = 4, boardIntArr[7][7] = 4;		//Sets rooks
	boardIntArr[0][1] = -2, boardIntArr[0][6] = -2, boardIntArr[7][1] = 2, boardIntArr[7][6] = 2;		//Sets knights
	boardIntArr[0][2] = -3, boardIntArr[0][5] = -3, boardIntArr[7][2] = 3, boardIntArr[7][5] = 3;		//Sets bishops
	boardIntArr[0][3] = 5, boardIntArr[0][4] = 6, boardIntArr[7][3] = 5, boardIntArr[7][4] = 6;			//Sets queens, kings


	for (int i = 0; i < 8; i++) {
		for (int k = 0; k < 8; k++) {
			std::cout << boardIntArr[i][k] << "|";
		}
		std::cout << "\n";
	}


	Board testBoard;
	Piece* wPawn = testBoard.getWhitePiece(10);

	dynamic_cast<Knight*>(wPawn)->updateLegalMoves(boardIntArr);
	std::vector<std::string> moveVec = wPawn->returnMoves();

	std::cout << moveVec[0];


	return 0;
}

void testPawnMoves() {
	

}


