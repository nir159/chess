#pragma once
#include "Piece.h"
#include "Rook.h"
#include "Bishop.h"
#include "SideFunctions.h"

class Queen :
	public Piece
{
	Piece *r = new Rook(ROOK);
	Piece *b = new Bishop(BISHOP);
	bool _isRookFormat;
public:
	Queen(char type);
	bool moveFormat(std::string instruction, bool isPlayerDst, int currTurn);
	bool hasSkippedPlayers(std::string instruction, Piece* const gameBoard[ENDOF_LENGTH][ENDOF_LENGTH]);
	~Queen();
};

