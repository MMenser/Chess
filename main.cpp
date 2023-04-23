#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <iomanip>
#include <windows.h>
#include <vector>


using std::cin;
using std::cout;
using std::endl;

using std::ifstream;
using std::ofstream;
using std::fstream;

int main(void) {

	int board[8][8] = { 0 };
	for (int i = 0; i < 8; i++) {
		board[1][i] = -1;
		board[6][i] = 1;		//Sets the pawns onto the board
	}						//Pawns = 1, Knight = 2, Bishop = 3, Rook = 4, Queen = 5, King = 6
	board[0][0] = -4, board[0][7] = -4, board[7][0] = 4, board[7][7] = 4;		//Sets rooks
	board[0][1] = -2, board[0][6] = -2, board[7][1] = 2, board[7][6] = 2;		//Sets knights
	board[0][2] = -3, board[0][5] = -3, board[7][2] = 3, board[7][5] = 3;		//Sets bishops
	board[0][3] = 5, board[0][4] = 6, board[7][3] = 5, board[7][4] = 6;			//Sets queens, kings


	for (int i = 0; i < 8; i++) {
		for (int k = 0; k < 8; k++) {
			std::cout << board[i][k] << "|";
		}
		std::cout << "\n";
	}




	return 0;
}
// this is peter
// this is mason 
// this is shiven 
// test
// helllo
// testing new branch