#pragma once
#include <string>

class Piece
{
protected:
	char _type;
public:
	Piece(char type);
	virtual bool moveFormat(std::string str) = 0;
	char getType();
	~Piece();
};

