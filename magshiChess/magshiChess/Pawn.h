#pragma once
#include "Piece.h"
class Pawn :
	public Piece
{
public:
	Pawn(char type);
	bool moveFormat(std::string instruction);
	~Pawn();
};


