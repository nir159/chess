#include "King.h"

/*
function will construct an King object
input:
	color - indicator for field value of type to set
*/
King::King(bool color) : Piece::Piece('r') { // if color is false then set _type to White Piece
	if (color) { this->_type = 'R'; } // else if color is true set _type to Black Piece
}


King::~King()
{
}