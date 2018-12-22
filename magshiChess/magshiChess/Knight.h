#pragma once
#include "Piece.h"
#include "SideFunctions.h"
class Knight :
	public Piece
{
public:
	Knight(char type);
	bool moveFormat(std::string instruction, bool isPlayerDst, int currTurn);
	bool hasSkippedPlayers(std::string instruction, Piece* const gameBoard[ENDOF_LENGTH][ENDOF_LENGTH]);
	~Knight();
};

