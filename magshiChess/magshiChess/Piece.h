#pragma once
#include <string>
#include "SideFunctions.h"

class Piece
{
protected:
	char _type;
public:
	Piece(char type);
	char getType();
	void setType(char type);
	virtual bool moveFormat(std::string instruction, bool isPlayerDst, int currTurn) = 0;
	virtual bool hasSkippedPlayers(std::string instruction, Piece* const gameBoard[ENDOF_LENGTH][ENDOF_LENGTH]) = 0;
	~Piece();
};

