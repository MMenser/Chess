#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <iomanip>
#include <windows.h>
#include <vector>
#include <SFML/Window.hpp>


using std::cin;
using std::cout;
using std::endl;

using std::ifstream;
using std::ofstream;
using std::fstream;

class Piece {
public:
	Piece(int newX, int newY, int newColor) {
		this->x = newX;
		this->y = newY;
		this->color = newColor;
		this->canTargetKing = false;
	}

	virtual void updateLegalMoves(int board[8][8]) {};

	bool targetKing() {
		return this->canTargetKing;			
	}

	bool isValidPosition(int row, int col) {
		return row >= 0 && row < 8 && col >= 0 && col < 8;
	}

	void setX(int newX) {
		this->x = newX;
	}

	void setY(int newY) {
		this->y = newY;
	}

	void setColor(int newColor) {
		this->color = newColor;
	}

	int getX() {
		return this->x;
	}

	int getY() {
		return this->y;
	}

	int getColor() {
		return this->color;
	}

	std::vector<std::string> returnMoves() {
		return this->moves;
	}

protected:
	int x, y, color;						//Color: 0 = white, 1 = black
	std::vector<std::string> moves;
	bool canTargetKing;						//If king has no moves and a piece targets king - checkmate 
};