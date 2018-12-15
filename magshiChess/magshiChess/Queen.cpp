#include "Queen.h"


/*
function will construct an Queen object
input:
	color - indicator for field value of type to set
*/
Queen::Queen(bool color) : Piece::Piece('q') { // if color is false then set _type to White Piece
	if (color) { this->_type = 'Q'; } // else if color is true set _type to Black Piece
}


Queen::~Queen()
{
}
