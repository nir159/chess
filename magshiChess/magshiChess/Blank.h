#pragma once
#include "Piece.h"
class Blank :
	public Piece
{
public:
	Blank();
	bool moveFormat(std::string str);
	~Blank();
};

