#include "Rook.h"


/*
function will construct an Rook object
input:
	type - field value of type to set
*/
Rook::Rook(char type) : Piece::Piece(type) { // set _type value by Parameter
}


Rook::~Rook()
{
}

/*
function will check if Instruction is valid for current type of piece
Input:
	instruction - Instruction to check
Output:
	if Instruction is valid for current type of piece then return true, else return false
*/
bool Rook::moveFormat(std::string instruction) {
	if (instruction[FIRST] != instruction[THIRD] && instruction[SECOND] != instruction[FORTH]) { return false; }
	return true;
}

/*
function will check if the piece will skip any players by making the move
Input:
	instruction - Instruction to check
	gameBoard - game board
Output:
	if the piece will skip any players by making the move then return true, else return false
*/
bool Rook::hasSkippedPlayers(std::string instruction, Piece* const gameBoard[ENDOF_LENGTH][ENDOF_LENGTH]) {
	bool rightSide = false;
	int minRange, MaxRange, i = 0;

	if (instruction[FIRST] > instruction[THIRD]) { // checks if 1st Part's Char is Bigger then 2nd Part's Char
		/* Sets Fitting Values for Range & Side in for loop */
		minRange = instruction[THIRD] - STARTOF_TYPE_P2;
		MaxRange = instruction[FIRST] - STARTOF_TYPE_P2;
	}
	else if (instruction[FIRST] < instruction[THIRD]) { // checks if 2nd Part's Char is Bigger then 1st Part's Char
		/* Sets Fitting Values for Range & Side in for loop */
		MaxRange = instruction[THIRD] - STARTOF_TYPE_P2;
		minRange = instruction[FIRST] - STARTOF_TYPE_P2;
	}
	else if (instruction[SECOND] > instruction[FORTH]) { // checks if 1st Part's Num is Bigger then 2nd Part's Num
		/* Sets Fitting Values for Range & Side in for loop */
		rightSide = true;
		MaxRange = instruction[SECOND] - STARTOF_LENGTH_CHAR;
		minRange = instruction[FORTH] - STARTOF_LENGTH_CHAR;
	}
	else if (instruction[SECOND] < instruction[FORTH]) { // checks if 2nd Part's Num is Bigger then 1st Part's Num
		/* Sets Fitting Values for Range & Side in for loop */
		rightSide = true;
		minRange = instruction[SECOND] - STARTOF_LENGTH_CHAR;
		MaxRange = instruction[FORTH] - STARTOF_LENGTH_CHAR;
	}
	for (i = minRange + ONE; i < MaxRange; i++) { // runs on requested Range & Side in game gameBoard
		if (rightSide && gameBoard[ENDOF_LINE - i][instruction[FIRST] - STARTOF_TYPE_P2]->getType() != BLANK) { /* checks if Side is Length (Right Side) && if it is check if at Length Piece skips any Other Pieces */ return true; }
		else if (!rightSide && gameBoard[ENDOF_LINE - instruction[SECOND] + STARTOF_LENGTH_CHAR][i]->getType() != BLANK) { /* else if it is check if at Width Piece skips any Other Pieces */ return true; }
	}
	return false;
}