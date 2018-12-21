#pragma once
#include "Piece.h"
#include "SideFunctions.h"

class Rook :
	public Piece
{
public:
	Rook(char type);
	bool moveFormat(std::string str, bool isPlayerDst, int currTurn);
	bool hasSkippedPlayers(std::string instruction, Piece* const gameBoard[ENDOF_LENGTH][ENDOF_LENGTH]);
	~Rook();
};

