#pragma once
#include "Piece.h"
class Blank :
	public Piece
{
public:
	Blank();
	void isValidRange();
	void pieceExists();
	void noPiece();
	void isReachable();
	void isSelfChess();
	void isChess();
	void eat();
	void isSame();
	void makeMove();
	~Blank();
};

