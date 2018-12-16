#pragma once
#include "Piece.h"
#include "SideFunctions.h"
class King :
	public Piece
{
public:
	King(bool color);
	bool moveFormat(std::string str);
	bool skippedPlayers(std::string str, Piece* const board[ENDOF_LENGTH][ENDOF_LENGTH]);
	~King();
};

