#include "Bishop.h"

/*
function will construct an Bishop object
input:
	type - field value of type to set
*/
Bishop::Bishop(char type) : Piece::Piece(type) { // set _type value by Parameter
}


Bishop::~Bishop()
{
}

bool Bishop::moveFormat(std::string instruction, bool isPlayerDst, int currTurn) {
	if (abs(instruction[SECOND]  - instruction[FORTH]) == abs(instruction[FIRST] - instruction[THIRD])) { return true; }
	return false;
}

bool Bishop::hasSkippedPlayers(std::string instruction, Piece* const gameBoard[ENDOF_LENGTH][ENDOF_LENGTH]) {
	int minWidth, maxWidth, minLength, maxLength, i = 0, j = 0;

	if (instruction[FIRST] > instruction[THIRD]) { // checks if 1st Part's Char is Bigger then 2nd Part's Char
												   /* Sets Fitting Values for Range & Side in for loop */
		minWidth = instruction[THIRD] - STARTOF_TYPE_P2;
		maxWidth = instruction[FIRST] - STARTOF_TYPE_P2;
	}
	else if (instruction[FIRST] < instruction[THIRD]) { // checks if 2nd Part's Char is Bigger then 1st Part's Char
														/* Sets Fitting Values for Range & Side in for loop */
		maxWidth = instruction[THIRD] - STARTOF_TYPE_P2;
		minWidth = instruction[FIRST] - STARTOF_TYPE_P2;
	}
	if (instruction[SECOND] > instruction[FORTH]) { // checks if 1st Part's Num is Bigger then 2nd Part's Num
														 /* Sets Fitting Values for Range & Side in for loop */
		maxLength = instruction[SECOND] - STARTOF_LENGTH_CHAR;
		minLength = instruction[FORTH] - STARTOF_LENGTH_CHAR;
	}
	else if (instruction[SECOND] < instruction[FORTH]) { // checks if 2nd Part's Num is Bigger then 1st Part's Num
														 /* Sets Fitting Values for Range & Side in for loop */
		minLength = instruction[SECOND] - STARTOF_LENGTH_CHAR;
		maxLength = instruction[FORTH] - STARTOF_LENGTH_CHAR;
	}
	for (i = maxLength - ONE, j = minWidth + ONE; i > minLength; i--, j++) { // runs on requested Range & Side in game gameBoard
		if (gameBoard[ENDOF_LINE - i][j]->getType() != BLANK) { /* checks if Side is Length (Right Side) && if it is check if at Length Piece skips any Other Pieces */ return true; }
	}
	return false;
}