#pragma once
#include "Piece.h"
#include "SideFunctions.h"

class Rook :
	public Piece
{
public:
	Rook(bool color);
	bool moveFormat(std::string str);
	bool hasSkippedPlayers(std::string instruction, Piece* const gameBoard[ENDOF_LENGTH][ENDOF_LENGTH]);
	~Rook();
};

