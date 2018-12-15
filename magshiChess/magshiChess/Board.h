#pragma once
#include "Piece.h"
#include "SideFunctions.h"
#include <string>
#include "SideFunctions.h"

class Board
{
private:
	Piece* _pieces[ENDOF_LENGTH][ENDOF_LENGTH];
	std::string _instruction;
	int _currPlayer;
public:
	Board();
	bool isValidRange() const;
	bool pieceExists() const;
	bool noPiece() const;
	void isReachable();
	void isSelfChess();
	bool isChess();
	void eat();
	bool isSame() const;
	void makeMove();
	~Board();
};

