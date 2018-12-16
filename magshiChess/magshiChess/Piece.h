#pragma once
#include <string>
#include "SideFunctions.h"

class Piece
{
protected:
	char _type;
public:
	Piece(char type);
	virtual bool moveFormat(std::string str) = 0;
	virtual bool skippedPlayers(std::string str, Piece* board[][ENDOF_LENGTH]) = 0;
	char getType();
	~Piece();
};

