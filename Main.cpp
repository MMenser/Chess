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
    board_pic.loadFromFile("board.png");

   

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
    RenderWindow window(VideoMode(1440,1440), "Chess Board");
    Event event;

    float dx = 0, dy = 0;

    Board track_board;
    Sprite white_pieces[16];
    Sprite black_pieces[16];


    Sprite boardy(board_pic);
    boardy.setScale(1.06f, 1.05f);
   /* Piece temps;*/
    /*Sprite temp(B_K);
    temp.setPosition(225, 20);*/
    
    

    int b = 0;
   /* white piece traverse*/ // 0-7 pawns, 8-9 Rooks, 10-11knights, 12-13Bishops, 14-15 queen king
    for (int i = 0; i < 16; i++)
    {
        if (i < 8)
        {
            /*white_pieces[i].setTextureRect(IntRect(track_board.getWhitePiece(i)->getX() * 150, track_board.getWhitePiece(i)->getY() * 150, 150, 150));*/
            white_pieces[i].setTexture(W_P);
            white_pieces[i].setPosition(track_board.getWhitePiece(i)->getY() * 180, track_board.getWhitePiece(i)->getX() * 170);
           
        }
        if (i == 8 || i == 9)
        {
          /*  white_pieces[i].setTextureRect(IntRect(track_board.getWhitePiece(i)->getX() * 150, track_board.getWhitePiece(i)->getY() * 150, 150, 150));*/
            white_pieces[i].setTexture(W_R);
            white_pieces[i].setPosition(track_board.getWhitePiece(i)->getY() * 180, track_board.getWhitePiece(i)->getX() * 170);
            
        }
        if (i == 10 || i == 11)
        {
            /*white_pieces[i].setTextureRect(IntRect(track_board.getWhitePiece(i)->getX() * 150, track_board.getWhitePiece(i)->getY() * 150, 150, 150));*/
            white_pieces[i].setTexture(W_N);
            white_pieces[i].setPosition(track_board.getWhitePiece(i)->getY() * 180, track_board.getWhitePiece(i)->getX() * 170);
            
        }
        if (i == 12 || i == 13)
        {
            /*white_pieces[i].setTextureRect(IntRect(track_board.getWhitePiece(i)->getX() * 150, track_board.getWhitePiece(i)->getY() * 150, 150, 150));*/
            white_pieces[i].setTexture(W_B);
            white_pieces[i].setPosition(track_board.getWhitePiece(i)->getY() * 180, track_board.getWhitePiece(i)->getX() * 170);
            
        }
        if (i == 14)
        {
            /*white_pieces[i].setTextureRect(IntRect(track_board.getWhitePiece(i)->getX() * 150, track_board.getWhitePiece(i)->getY() * 150, 150, 150));*/
            white_pieces[i].setTexture(W_K);
            white_pieces[i].setPosition(track_board.getWhitePiece(i)->getY() * 180, track_board.getWhitePiece(i)->getX() * 170);
            
        }
        if (i == 15)
        {
            /*white_pieces[i].setTextureRect(IntRect(track_board.getWhitePiece(i)->getX() * 150, track_board.getWhitePiece(i)->getY() * 150, 150, 150));*/
            white_pieces[i].setTexture(W_Q);
            white_pieces[i].setPosition(track_board.getWhitePiece(i)->getY() * 180, track_board.getWhitePiece(i)->getX() * 170);
            
        }
        
    };
    //black pieces
    for (int i = 0; i < 16; i++)
    {
        if (i < 8)
        {
           /* black_pieces[i].setTextureRect(IntRect(track_board.getWhitePiece(i)->getX() * 50, track_board.getWhitePiece(i)->getY() * 50, 50, 50));*/
            black_pieces[i].setPosition(track_board.getBlackPiece(i)->getY() * 180, track_board.getBlackPiece(i)->getX() * 170);
            black_pieces[i].setTexture(B_P);
        }
        if (i == 8 || i == 9)
        {
           // black_pieces[i].setTextureRect(IntRect(track_board.getWhitePiece(i)->getX() * 50, track_board.getWhitePiece(i)->getY() * 50, 50, 50));
            black_pieces[i].setPosition(track_board.getBlackPiece(i)->getY() *180 , track_board.getBlackPiece(i)->getX() * 170);
             black_pieces[i].setTexture(B_R);
        }
        if (i == 10 || i == 11)
        {
            // black_pieces[i].setTextureRect(IntRect(track_board.getWhitePiece(i)->getX() * 50, track_board.getWhitePiece(i)->getY() * 50, 50, 50));
            black_pieces[i].setPosition(track_board.getBlackPiece(i)->getY() * 180, track_board.getBlackPiece(i)->getX() * 170);
            black_pieces[i].setTexture(B_N);
        }
        if (i == 12 || i == 13)
        {
            // black_pieces[i].setTextureRect(IntRect(track_board.getWhitePiece(i)->getX() * 50, track_board.getWhitePiece(i)->getY() * 50, 50, 50));
            black_pieces[i].setPosition(track_board.getBlackPiece(i)->getY() * 180, track_board.getBlackPiece(i)->getX() * 170);
            black_pieces[i].setTexture(B_B);
        }
        if (i == 14)
        {
            //  white_pieces[i].setTextureRect(IntRect(track_board.getWhitePiece(i)->getX() * 50, track_board.getWhitePiece(i)->getY() * 50, 50, 50));
            black_pieces[i].setPosition(track_board.getBlackPiece(i)->getY() * 180, track_board.getBlackPiece(i)->getX() * 170);
             black_pieces[i].setTexture(B_K);
        }
        if (i == 15)
        {
            // black_pieces[i].setTextureRect(IntRect(track_board.getWhitePiece(i)->getX() * 50, track_board.getWhitePiece(i)->getY() * 50, 50, 50));
            black_pieces[i].setPosition(track_board.getBlackPiece(i)->getY() * 180, track_board.getBlackPiece(i)->getX() * 170);
             black_pieces[i].setTexture(B_Q);
        }

    };



    bool check = false;

    while (window.isOpen())
    {
        //Vector2i location = Mouse::getPosition(window); // vector is made for ints
        //int x = location.x;
        //int y = location.y;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();
            }

        }

        window.clear(Color::White);
        window.draw(boardy);

        

        for (int i = 0; i < 16; i++)
        {
            window.draw(black_pieces[i]);
            window.draw(white_pieces[i]);

        }
        window.display();


    }


}

void testPawnMoves() {


}

//
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
//

    //int board[8][8] = { 0 };
    //for (int i = 0; i < 8; i++) {
    //    board[1][i] = -1;
    //    board[6][i] = 1;		//Sets the pawns onto the board
    //}						//Pawns = 1, Knight = 2, Bishop = 3, Rook = 4, Queen = 5, King = 6
    //board[0][0] = 4, board[0][7] = 4, board[7][0] = 4, board[7][7] = 4;		//Sets rooks
    //board[0][1] = 2, board[0][6] = 2, board[7][1] = 2, board[7][6] = 2;		//Sets knights
    //board[0][2] = 3, board[0][5] = 3, board[7][2] = 3, board[7][5] = 3;		//Sets bishops
    //board[0][3] = 5, board[0][4] = 6, board[7][3] = 5, board[7][4] = 6;		//Sets queens, kings

/*window.clear();*/
            //if (event.type == Event::MouseButtonPressed)
            //{
            //    if (event.key.code == Mouse::Left)
            //    {
            //        if (wk.getGlobalBounds().contains(location.x, location.y))
            //        {
            //            check = true;
            //            dx = location.x - wk.getPosition().x;
            //            dy = location.y - wk.getPosition().y;
            //        }
            //        // this is where check move
            //    }
            //}
            //if (event.type == Event::MouseButtonReleased)
            //{
            //    if (event.key.code == Mouse::Left)
            //    {
            //        check = false;
            //    }
            //}

            //if (check)
            //{
            //    wk.setPosition(location.x - dx, location.y - dy);
            //}