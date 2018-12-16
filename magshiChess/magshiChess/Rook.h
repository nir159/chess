#pragma once
#include "Piece.h"
#include "SideFunctions.h"

class Rook :
	public Piece
{
public:
	Rook(bool color);
	bool moveFormat(std::string str);
	~Rook();
};

