#include "Pawn.h"


/*
function will construct an Pawn object
input:
	color - indicator for field value of type to set
*/
Pawn::Pawn(bool color) : Piece::Piece('p') { // if color is false then set _type to White Piece
	if (color) { this->_type = 'P'; } // else if color is true set _type to Black Piece
}


Pawn::~Pawn()
{
}
