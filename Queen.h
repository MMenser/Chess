#pragma once
#pragma once
#include "Piece.h"

/////////////////////////////////
//											
//  I need to make the Black 
// Pieces(so copy paste)
// but finish Diagonal
//
/////////////////////////////////








class Queen : public Piece 
{
public:
	Queen(int newX, int newY, int newColor) : Piece(newX, newY, newColor) {
		std::string newMove = (this->x) + "," + this->y;
		this->moves.push_back(newMove);
	}


	void updateLegalMoves(int board[8][8])
	{

		if (color == 1) // 1 is white 0 is black
		{

			this->moves.clear();

			std::string move;
			int moveCheck = 0, yMoveCheck;
			int temp_x = this->x;
			int temp_y = this->y;


			//////////////////////////////////////////////////////// This is Down move   /////////////

			temp_x = this->x;
			temp_y = this->y;


			do
			{
				temp_x = temp_x + 1;													    //down 
				if (temp_x < 8 && board[temp_x][temp_y] == 0) {
					move += std::to_string(temp_x);
					move += std::to_string(temp_y);
					this->moves.push_back(move);
					move = "";
				}
				else if (temp_x < 8 && board[temp_x][temp_y] != 0 && board[temp_x][temp_y] < 0) {
					move = (temp_x)+"," + temp_y;
					move += std::to_string(temp_x);
					move += std::to_string(temp_y);
					this->moves.push_back(move);
					move = "";
				}

			} while (temp_x < 8 || board[temp_x][temp_y] == 0);


			//////////////////////////////////////////////////////   This is Up Move   //////////////

			temp_x = this->x;
			temp_y = this->y;

			do
			{
				temp_x = temp_x - 1;													    //up
				if (temp_x >= 0 && board[temp_x][temp_y] == 0) {
					move += std::to_string(temp_x);
					move += std::to_string(temp_y);
					this->moves.push_back(move);
					move = "";
				}
				else if (temp_x >= 0 && board[temp_x][temp_y] != 0 && board[temp_x][temp_y] < 0) {
					move += std::to_string(temp_x);
					move += std::to_string(temp_y);
					this->moves.push_back(move);
					move = "";
				}

			} while (temp_x >= 0 || board[temp_x][temp_y] == 0);


			///////////////////////////////////////////////////////   This is Left moves   ////////////


			temp_x = this->x;
			temp_y = this->y;

			do
			{
				temp_y = temp_y - 1;													    //left
				if (temp_y >= 0 && board[temp_x][temp_y] == 0) {
					move += std::to_string(temp_x);
					move += std::to_string(temp_y);
					this->moves.push_back(move);
					move = "";
				}
				else if (temp_y >= 0 && board[temp_x][temp_y] != 0 && board[temp_x][temp_y] < 0) {
					move += std::to_string(temp_x);
					move += std::to_string(temp_y);
					this->moves.push_back(move);
					move = "";
				}

			} while (temp_y >= 0 || board[temp_x][temp_y] == 0);


			////////////////////////////////////////////////////////   This is Right moves   ////////////


			temp_x = this->x;
			temp_y = this->y;

			do
			{
				temp_y = temp_y + 1;													    //Right
				if (temp_y < 8 && board[temp_x][temp_y] == 0) {
					move += std::to_string(temp_x);
					move += std::to_string(temp_y);
					this->moves.push_back(move);
					move = "";
				}
				else if (temp_y < 8 && board[temp_x][temp_y] != 0 && board[temp_x][temp_y] < 0) {
					move += std::to_string(temp_x);
					move += std::to_string(temp_y);
					this->moves.push_back(move);
					move = "";
				}

			} while (temp_y < 8 || board[temp_x][temp_y] == 0);


			/////////////////////////////////////////////////////////   Right Down Diagonal Moves    ////////////
			temp_x = this->x;
			temp_y = this->y;


			do
			{
				temp_x = temp_x + 1;
				temp_y = temp_y + 1;

				if (temp_x < 8 && temp_y < 8 && board[temp_x][temp_y] != 0) {    //right down diaganol
					move += std::to_string(temp_x);
					move += std::to_string(temp_y);
					this->moves.push_back(move);
					move = "";
				}

				else if (temp_y < 8 && temp_x < 8 && board[temp_x][temp_y] != 0 && board[temp_x][temp_y] < 0) {
					move += std::to_string(temp_x);
					move += std::to_string(temp_y);
					this->moves.push_back(move);
					move = "";
				}

			} while (temp_y < 8 || temp_x < 8 || board[temp_x][temp_y] == 0);

			/////////////////////////////////////////////////////////   Right Up Diagonal Moves    ////////////
			temp_x = this->x;
			temp_y = this->y;


			do
			{
				temp_x = temp_x - 1;
				temp_y = temp_y + 1;

				if (temp_x >= 0 && temp_y < 8 && board[temp_x][temp_y] != 0) {    //right down diaganol
					move += std::to_string(temp_x);
					move += std::to_string(temp_y);
					this->moves.push_back(move);
					move = "";
				}

				else if (temp_x >= 0 && temp_y < 8 && board[temp_x][temp_y] != 0 && board[temp_x][temp_y] < 0) {
					move += std::to_string(temp_x);
					move += std::to_string(temp_y);
					this->moves.push_back(move);
					move = "";
				}

			} while (temp_y < 8 || temp_x >= 0 || board[temp_x][temp_y] == 0);

			/////////////////////////////////////////////////////////   Left UP Diagonal Moves       //////////
			temp_x = this->x;
			temp_y = this->y;


			do
			{
				temp_x = temp_x - 1;
				temp_y = temp_y - 1;

				if (temp_x >= 0 && temp_y >= 0 && board[temp_x][temp_y] != 0) {    //right down diaganol
					move += std::to_string(temp_x);
					move += std::to_string(temp_y);
					this->moves.push_back(move);
					move = "";
				}

				else if (temp_x >= 0 && temp_y >= 0 && board[temp_x][temp_y] != 0 && board[temp_x][temp_y] < 0) {
					move += std::to_string(temp_x);
					move += std::to_string(temp_y);
					this->moves.push_back(move);
					move = "";
				}

			} while (temp_y >= 8 || temp_x >= 0 || board[temp_x][temp_y] == 0);



			/////////////////////////////////////////////////////////   Left  Down Diagonal Moves       //////////
			temp_x = this->x;
			temp_y = this->y;


			do
			{
				temp_x = temp_x + 1;
				temp_y = temp_y - 1;

				if (temp_y >= 0 && temp_x < 8 && board[temp_x][temp_y] != 0) {    //right down diaganol
					move += std::to_string(temp_x);
					move += std::to_string(temp_y);
					this->moves.push_back(move);
					move = "";
				}

				else if (temp_y >= 0 && temp_x < 8 && board[temp_x][temp_y] != 0 && board[temp_x][temp_y] < 0) {
					move += std::to_string(temp_x);
					move += std::to_string(temp_y);
					this->moves.push_back(move);
					move = "";
				}

			} while (temp_x < 8 || temp_y >= 0 || board[temp_x][temp_y] == 0);

		}/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////(This is where Black Pieces start)
		else
		{
		this->moves.clear();

		std::string move;
		int moveCheck = 0, yMoveCheck;
		int temp_x = this->x;
		int temp_y = this->y;


		//////////////////////////////////////////////////////// This is Down move   /////////////

		temp_x = this->x;
		temp_y = this->y;


		do
		{
			temp_x = temp_x + 1;													    //down 
			if (temp_x < 8 && board[temp_x][temp_y] == 0) {
				move += std::to_string(temp_x);
				move += std::to_string(temp_y);
				this->moves.push_back(move);
				move = "";
			}
			else if (temp_x < 8 && board[temp_x][temp_y] != 0 && board[temp_x][temp_y] > 0) {
				move += std::to_string(temp_x);
				move += std::to_string(temp_y);
				this->moves.push_back(move);
				move = "";
			}

		} while (temp_x < 8 || board[temp_x][temp_y] == 0);




		//////////////////////////////////////////////////////   This is Up Move   //////////////

		temp_x = this->x;
		temp_y = this->y;

		do
		{
			temp_x = temp_x - 1;													    //up
			if (temp_x >= 0 && board[temp_x][temp_y] == 0) {
				move += std::to_string(temp_x);
				move += std::to_string(temp_y);
				this->moves.push_back(move);
				move = "";
			}
			else if (temp_x >= 0 && board[temp_x][temp_y] != 0 && board[temp_x][temp_y] > 0) {
				move += std::to_string(temp_x);
				move += std::to_string(temp_y);
				this->moves.push_back(move);
				move = "";
			}

		} while (temp_x >= 0 || board[temp_x][temp_y] == 0);


		///////////////////////////////////////////////////////   This is Left moves   ////////////


		temp_x = this->x;
		temp_y = this->y;

		do
		{
			temp_y = temp_y - 1;													    //left
			if (temp_y >= 0 && board[temp_x][temp_y] == 0) {
				move += std::to_string(temp_x);
				move += std::to_string(temp_y);
				this->moves.push_back(move);
				move = "";
			}
			else if (temp_y >= 0 && board[temp_x][temp_y] != 0 && board[temp_x][temp_y] > 0) {
				move += std::to_string(temp_x);
				move += std::to_string(temp_y);
				this->moves.push_back(move);
				move = "";
			}

		} while (temp_y >= 0 || board[temp_x][temp_y] == 0);


		////////////////////////////////////////////////////////   This is Right moves   ////////////


		temp_x = this->x;
		temp_y = this->y;

		do
		{
			temp_y = temp_y + 1;													    //Right
			if (temp_y < 8 && board[temp_x][temp_y] == 0) {
				move += std::to_string(temp_x);
				move += std::to_string(temp_y);
				this->moves.push_back(move);
				move = "";
			}
			else if (temp_y < 8 && board[temp_x][temp_y] != 0 && board[temp_x][temp_y] > 0) {
				move += std::to_string(temp_x);
				move += std::to_string(temp_y);
				this->moves.push_back(move);
				move = "";
			}

		} while (temp_y < 8 || board[temp_x][temp_y] == 0);


		/////////////////////////////////////////////////////////   Right Down Diagonal Moves    ////////////
		temp_x = this->x;
		temp_y = this->y;


		do
		{
			temp_x = temp_x + 1;
			temp_y = temp_y + 1;

			if (temp_x < 8 && temp_y < 8 && board[temp_x][temp_y] != 0) {    //right down diaganol
				move += std::to_string(temp_x);
				move += std::to_string(temp_y);
				this->moves.push_back(move);
				move = "";
			}

			else if (temp_y < 8 && temp_x < 8 && board[temp_x][temp_y] != 0 && board[temp_x][temp_y] > 0) {
				move += std::to_string(temp_x);
				move += std::to_string(temp_y);
				this->moves.push_back(move);
				move = "";
			}

		} while (temp_y < 8 || temp_x < 8 || board[temp_x][temp_y] == 0);


		/////////////////////////////////////////////////////////   Right Up Diagonal Moves    ////////////



		temp_x = this->x;
		temp_y = this->y;


		do
		{
			temp_x = temp_x - 1;
			temp_y = temp_y + 1;

			if (temp_x >= 0 && temp_y < 8 && board[temp_x][temp_y] != 0) {    //right down diaganol
				move += std::to_string(temp_x);
				move += std::to_string(temp_y);
				this->moves.push_back(move);
				move = "";
			}

			else if (temp_x >= 0 && temp_y < 8 && board[temp_x][temp_y] != 0 && board[temp_x][temp_y] > 0) {
				move += std::to_string(temp_x);
				move += std::to_string(temp_y);
				this->moves.push_back(move);
				move = "";
			}

		} while (temp_y < 8 || temp_x >= 0 || board[temp_x][temp_y] == 0);





		/////////////////////////////////////////////////////////   Left UP Diagonal Moves       //////////


		temp_x = this->x;
		temp_y = this->y;


		do
		{
			temp_x = temp_x - 1;
			temp_y = temp_y - 1;

			if (temp_x >= 0 && temp_y >= 0 && board[temp_x][temp_y] != 0) {    //right down diaganol
				move += std::to_string(temp_x);
				move += std::to_string(temp_y);
				this->moves.push_back(move);
				move = "";
			}

			else if (temp_x >= 0 && temp_y >= 0 && board[temp_x][temp_y] != 0 && board[temp_x][temp_y] > 0) {
				move += std::to_string(temp_x);
				move += std::to_string(temp_y);
				this->moves.push_back(move);
				move = "";
			}

		} while (temp_y >= 8 || temp_x >= 0 || board[temp_x][temp_y] == 0);



		/////////////////////////////////////////////////////////   Left  Down Diagonal Moves       //////////



		temp_x = this->x;
		temp_y = this->y;


		do
		{
			temp_x = temp_x + 1;
			temp_y = temp_y - 1;

			if (temp_y >= 0 && temp_x < 8 && board[temp_x][temp_y] != 0) {    //right down diaganol
				move += std::to_string(temp_x);
				move += std::to_string(temp_y);
				this->moves.push_back(move);
				move = "";
			}

			else if (temp_y >= 0 && temp_x < 8 && board[temp_x][temp_y] != 0 && board[temp_x][temp_y] > 0) {
				move += std::to_string(temp_x);
				move += std::to_string(temp_y);
				this->moves.push_back(move);
				move = "";
			}

		} while (temp_x < 8 || temp_y >= 0 || board[temp_x][temp_y] == 0);
		}

	}
private:
};





// 24
//