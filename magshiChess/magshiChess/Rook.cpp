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

/*
function will check if the piece will skip any players by making the move
Input:
	str - Instruction to check
	board - game board
Output:
	if the piece will skip any players by making the move then return true, else return false
*/
bool skippedPlayers(std::string str, Piece* const board[ENDOF_LENGTH][ENDOF_LENGTH]) {
	bool rightSide = false;
	int minRange, MaxRange, i = 0;

	if (str[FIRST] > str[THIRD]) { // checks if 1st Part's Char is Bigger then 2nd Part's Char
		/* Sets Fitting Values for Range & Side in for loop */
		minRange = str[THIRD] - STARTOF_TYPE_P1;
		MaxRange = str[FIRST] - STARTOF_TYPE_P1;
	}
	else if (str[FIRST] < str[THIRD]) { // checks if 2nd Part's Char is Bigger then 1st Part's Char
		/* Sets Fitting Values for Range & Side in for loop */
		MaxRange = str[THIRD] - STARTOF_TYPE_P1;
		minRange = str[FIRST] - STARTOF_TYPE_P1;
	}
	else if (str[SECOND] > str[FORTH]) { // checks if 1st Part's Num is Bigger then 2nd Part's Num
		/* Sets Fitting Values for Range & Side in for loop */
		rightSide = true;
		MaxRange = str[SECOND] - STARTOF_TYPE_P1;
		minRange = str[FORTH] - STARTOF_TYPE_P1;
	}
	else if (str[SECOND] < str[FORTH]) { // checks if 2nd Part's Num is Bigger then 1st Part's Num
		/* Sets Fitting Values for Range & Side in for loop */
		rightSide = true;
		minRange = str[SECOND] - STARTOF_TYPE_P1;
		MaxRange = str[FORTH] - STARTOF_TYPE_P1;
	}
	for (i = minRange + 1; i < MaxRange; i++) { // runs on requested Range & Side in game board
		if (rightSide && board[(str[FIRST] - STARTOF_TYPE_P1)][i]->getType() != BLANK) { /* checks if Side is Length (Right Side) && if it is check if at Length Piece skips any Other Pieces */ return true; }		
		else if (board[(char)(i + STARTOF_TYPE_P1)][str[SECOND]]->getType() != BLANK) { /* else if it is check if at Width Piece skips any Other Pieces */ return true; }	
	}
	return false;
}