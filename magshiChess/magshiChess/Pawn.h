#pragma once
#include "Piece.h"
class Pawn :
	public Piece
{
public:
	Pawn(char type);
	bool moveFormat(std::string instruction);
	bool hasSkippedPlayers(std::string instruction, Piece* const gameBoard[ENDOF_LENGTH][ENDOF_LENGTH]);
	~Pawn();
};


