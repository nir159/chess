#pragma once
#include "Piece.h"
#include "SideFunctions.h"
class King :
	public Piece
{
public:
	King(bool color);
	bool moveFormat(std::string instruction);
	bool skippedPlayers(std::string instruction, Piece* const gameBoard[ENDOF_LENGTH][ENDOF_LENGTH]);
	~King();
};

