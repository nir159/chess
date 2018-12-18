#include "Piece.h"

/*
function will construct an Piece object
input:
	type - field value to set
*/
Piece::Piece(char type) : _type(type) {
}

Piece::~Piece()
{
}

/*
Function will return an Piece class' type field
Input:
	[Void]
Output:
	Piece class' type field
*/
char Piece::getType() {
	return this->_type;
}

/*
Function will set the Piece class' type field
Input:
the type
Output:
[None]
*/
void Piece::setType(char type) {
	this->_type = type;
}
