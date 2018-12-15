#include "Knight.h"


/*
function will construct an Knight object
input:
	color - indicator for field value of type to set
*/
Knight::Knight(bool color) : Piece::Piece('k') { // if color is false then set _type to White Piece
	if (color) { this->_type = 'K'; } // else if color is true set _type to Black Piece
}


Knight::~Knight()
{
}
