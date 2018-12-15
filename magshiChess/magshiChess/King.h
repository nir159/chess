#pragma once
#include "Piece.h"
#include "SideFunctions.h"
class King :
	public Piece
{
public:
	King(bool color);
	bool moveFormat(std::string str);
	~King();
};

