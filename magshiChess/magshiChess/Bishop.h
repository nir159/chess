#pragma once
#include "Piece.h"
class Bishop :
	public Piece
{
public:
	Bishop(char type);
	bool moveFormat(std::string instruction, bool isPlayerDst, int currTurn);
	bool hasSkippedPlayers(std::string instruction, Piece* const gameBoard[ENDOF_LENGTH][ENDOF_LENGTH]);
	~Bishop();
};

