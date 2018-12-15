#pragma once
#include "Piece.h"

#define SIDE_OF_BOARD 8
#define PIECES_PER_PLAYER 16

class Board
{
private:
	Piece* Pieces[SIDE_OF_BOARD][SIDE_OF_BOARD];
public:
	Board();
	void isValidRange();
	void pieceExists();
	void noPiece();
	void isReachable();
	void isSelfChess();
	void isChess();
	void eat();
	void isSame();
	void makeMove();
	~Board();
};

