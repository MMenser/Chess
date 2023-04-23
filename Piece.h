#pragma once


class Piece {
public:
	Piece(int newX, int newY, int newColor) {

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

private:
	int x, y, color; 

};