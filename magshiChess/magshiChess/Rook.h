#pragma once
#include "Piece.h"
#include "SideFunctions.h"

class Rook :
	public Piece
{
public:
	Rook(bool color);
	bool moveFormat(std::string str);
	bool skippedPlayers(std::string str, Piece* const board[ENDOF_LENGTH][ENDOF_LENGTH]);
	~Rook();
};

