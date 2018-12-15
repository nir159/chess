#include "Rook.h"


/*
function will construct an Rook object
input:
	color - indicator for field value of type to set
*/
Rook::Rook(bool color) : Piece::Piece('r') { // if color is false then set _type to White Piece
	if (color) { this->_type = 'R'; } // else if color is true set _type to Black Piece
}


Rook::~Rook()
{
}

bool Rook::moveFormat() {

}