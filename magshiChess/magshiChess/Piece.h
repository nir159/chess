#pragma once
class Piece
{
protected:
	char _type;
public:
	Piece(char type);
	virtual bool moveFormat() = 0;
	char getType();
	~Piece();
};

