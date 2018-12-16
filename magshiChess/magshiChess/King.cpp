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

/*
function will check if Instruction is valid for current type of piece
Input:
	str - Instruction to check
Output:
	if Instruction is valid for current type of piece then return true, else return false
*/
bool King::moveFormat(std::string str) {
	if (abs(str[FIRST] - str[THIRD]) > 1 && abs(str[SECOND] - str[FORTH]) > 1) { return true; }
	return false;
}