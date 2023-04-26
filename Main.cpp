#define NOMINMAX

#include "Board.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>



int main(void) {


    Texture B_K, B_Q, B_N, B_R, B_B, B_P, W_K, W_Q, W_N, W_R, W_B, W_P, board_pic;

    B_K.loadFromFile("BLACK KING.png");
    B_Q.loadFromFile("BLACK QUEEN.png");
    B_N.loadFromFile("BLACK KNITE.png");
    B_R.loadFromFile("BLACK ROOK.png");
    B_B.loadFromFile("BLACK BISHOP.png");
    B_P.loadFromFile("BLACK PAWN.png");
    W_K.loadFromFile("white_king.png");
    W_Q.loadFromFile("WHITE QUEEN.png");
    W_N.loadFromFile("WHITE KNITE.png");
    W_R.loadFromFile("WHITE ROOK.png");
    W_B.loadFromFile("WHITE BISHOP.png");
    W_P.loadFromFile("WHITE PAWN.png");
    board_pic.loadFromFile("chessboard.png");

    Sprite boardy(board_pic);

  /* W_K.setSmooth(true);*/

    Sprite bk(B_K);
    Sprite bq(B_Q);
    Sprite bn(B_N);
    Sprite br(B_R);
    Sprite bb(B_B);
    Sprite bp(B_P);
    Sprite wk(W_K);
    Sprite wq(W_Q);
    Sprite wn(W_N);
    Sprite wr(W_R);
    Sprite wb(W_B);
    Sprite wp(W_P);



    system("dir");
    RenderWindow window(VideoMode(680, 420), "Chess Board");
    Event event;

    float dx = 0, dy = 0;

    Board track_board;

    int board[8][8] = { 0 };
    for (int i = 0; i < 8; i++) {
        board[1][i] = -1;
        board[6][i] = 1;		//Sets the pawns onto the board
    }						//Pawns = 1, Knight = 2, Bishop = 3, Rook = 4, Queen = 5, King = 6
    board[0][0] = -4, board[0][7] = -4, board[7][0] = 4, board[7][7] = 4;		//Sets rooks
    board[0][1] = -2, board[0][6] = -2, board[7][1] = 2, board[7][6] = 2;		//Sets knights
    board[0][2] = -3, board[0][5] = -3, board[7][2] = 3, board[7][5] = 3;		//Sets bishops
    board[0][3] = -5, board[0][4] = -6, board[7][3] = 5, board[7][4] = 6;		//Sets queens, kings



    







    bool check = false;

    while (window.isOpen())
    {
        Vector2i location = Mouse::getPosition(window); // vector is made for ints
        int x = location.x;
        int y = location.y;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();
            }
            window.clear();
            if (event.type == Event::MouseButtonPressed)
            {
                if (event.key.code == Mouse::Left)
                {
                    if (wk.getGlobalBounds().contains(location.x, location.y))
                    {
                        check = true;
                        dx = location.x - wk.getPosition().x;
                        dy = location.y - wk.getPosition().y;
                    }
                    // this is where check move
                }
            }
            if (event.type == Event::MouseButtonReleased)
            {
                if (event.key.code == Mouse::Left)
                {
                    check = false;
                }
            }

            if (check)
            {
                wk.setPosition(location.x - dx, location.y - dy);
            }


        }
        window.clear();
        window.draw(boardy);
        for (int i = 0; i < 32; i++)
        {

            window.draw(track_board.getWhitePiece(i)->image);
            window.draw(track_board.getBlackPiece(i)->image);
        }
        window.display();



    }

}

void testPawnMoves() {


}


//int boardIntArr[8][8] = { 0 };
//for (int i = 0; i < 8; i++) {
//    boardIntArr[1][i] = -1;
//    boardIntArr[6][i] = 1;		//Sets the pawns onto the board
//}						//Pawns = 1, Knight = 2, Bishop = 3, Rook = 4, Queen = 5, King = 6
//boardIntArr[0][0] = -4, boardIntArr[0][7] = -4, boardIntArr[7][0] = 4, boardIntArr[7][7] = 4;		//Sets rooks
//boardIntArr[0][1] = -2, boardIntArr[0][6] = -2, boardIntArr[7][1] = 2, boardIntArr[7][6] = 2;		//Sets knights
//boardIntArr[0][2] = -3, boardIntArr[0][5] = -3, boardIntArr[7][2] = 3, boardIntArr[7][5] = 3;		//Sets bishops
//boardIntArr[0][3] = 5, boardIntArr[0][4] = 6, boardIntArr[7][3] = 5, boardIntArr[7][4] = 6;			//Sets queens, kings
//
//
//for (int i = 0; i < 8; i++) {
//    for (int k = 0; k < 8; k++) {
//        std::cout << boardIntArr[i][k] << "|";
//    }
//    std::cout << "\n";
//}
//
//
//Board testBoard;
//Piece* wPawn = testBoard.getWhitePiece(10);
//
//dynamic_cast<Knight*>(wPawn)->updateLegalMoves(boardIntArr);
//std::vector<std::string> moveVec = wPawn->returnMoves();
//
//std::cout << moveVec[0];

