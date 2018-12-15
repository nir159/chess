#include "Bishop.h"


/*
function will construct an Bishop object
input:
	color - indicator for field value of type to set
*/
Bishop::Bishop(bool color) : Piece::Piece('b') { // if color is false then set _type to White Piece
	if (color) { this->_type = 'B'; } // else if color is true set _type to Black Piece
}


Bishop::~Bishop()
{
}
