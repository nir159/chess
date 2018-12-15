#pragma once
#include "Piece.h"
#include <string>

#define INSTRUCTION_LEN 4
#define ENDOF_LENGTH 8
#define PIECES_PER_PLAYER 16

class Board
{
private:
	Piece* Pieces[ENDOF_LENGTH][ENDOF_LENGTH];
public:
	Board();
	bool isValidRange(std::string str) const;
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

