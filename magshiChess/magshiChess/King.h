#pragma once
#include "Piece.h"
class King :
	public Piece
{
public:
	King(bool color);
	bool moveFormat();
	~King();
};

