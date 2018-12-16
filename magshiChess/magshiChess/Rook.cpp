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

/*
function will check if Instruction is valid for current type of piece
Input:
	str - Instruction to check
Output:
	if Instruction is valid for current type of piece then return true, else return false
*/
bool Rook::moveFormat(std::string str) {
	if (str[FIRST] != str[THIRD] && str[SECOND] != str[FORTH]) { return false; }
	return true;
}