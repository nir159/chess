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

bool skippedPlayers(std::string str, Piece* board[][ENDOF_LENGTH]) {
	bool rightSide = false;
	int minRange, MaxRange, i = 0;

	if (str[FIRST] > str[THIRD]) {
		minRange = str[THIRD] - STARTOF_TYPE_P1;
		MaxRange = str[FIRST] - STARTOF_TYPE_P1;
	}
	else if (str[FIRST] < str[THIRD]) {
		MaxRange = str[THIRD] - STARTOF_TYPE_P1;
		minRange = str[FIRST] - STARTOF_TYPE_P1;
	}
	else if (str[SECOND] > str[FORTH]) {
		rightSide = true;
		MaxRange = str[SECOND] - STARTOF_TYPE_P1;
		minRange = str[FORTH] - STARTOF_TYPE_P1;
	}
	else if (str[SECOND] < str[FORTH]) {
		rightSide = true;
		minRange = str[SECOND] - STARTOF_TYPE_P1;
		MaxRange = str[FORTH] - STARTOF_TYPE_P1;
	}
	for (i = minRange + 1; i < MaxRange; i++) {
		if (rightSide) {
			if (board[(str[FIRST] - STARTOF_TYPE_P1)][i]->getType() != BLANK) {
				return true;
			}
		}
		else {
			if (board[(char)(i + STARTOF_TYPE_P1)][str[SECOND]]->getType() != BLANK) {
				return true;
			}
		}
	}
	return false;
}