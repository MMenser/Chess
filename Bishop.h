#pragma once
#include "Piece.h"
#include <string>
using std::string;

class Bishop : public Piece
{
public:

	Bishop(int newX, int newY, int newColor) : Piece(newX, newY, newColor)
	{

		std::string newMove = (this->x) + "," + this->y;
		this->moves.push_back(newMove);

		calculatePossibleMoves(newX, newY);

	}

	void calculatePossibleMoves(int row, int col)
	{
		this->moves.clear();


		int row_moves[] = { -1, -1, 1, 1 };
		int col_moves[] = { -1, 1, -1, 1 };
		string temp = "";

		for (int i = 0; i < 4; i++) {
			int newRow = row + row_moves[i];
			int newCol = col + col_moves[i];

			while (isValidPosition(newRow, newCol))
			{
				temp = std::to_string(newRow) + "," + std::to_string(newCol);
				this->moves.push_back(temp);
				newRow += row_moves[i];
				newCol += col_moves[i];
			}
		}
	}

	void printMoves()
	{
		for (const auto& str : moves) {
			std::cout << str << std::endl;
		}
	}


private:
};