#pragma once
#include "Piece.h"
class Rook :
	public Piece
{
public:
	Rook(bool color);
	bool moveFormat();
	~Rook();
};

