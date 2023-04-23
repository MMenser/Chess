#pragma once

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

class Piece {
public:
	Piece(int newX, int newY, int newColor) {
		this->x = newX;
		this->y = newY;
		this->color = newColor;
	}

	virtual void updateLegalMoves(int board[8][8]) = 0;

	bool targetKing() {

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
	int x, y, color; 
	std::vector<std::string> moves;
};