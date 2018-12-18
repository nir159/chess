#pragma once
#include "Piece.h"
class Blank :
	public Piece
{
public:
	Blank();
	bool moveFormat(std::string str);
	bool hasSkippedPlayers(std::string instruction, Piece* const gameBoard[ENDOF_LENGTH][ENDOF_LENGTH]);
	~Blank();
};

