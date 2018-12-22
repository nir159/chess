#include "Pawn.h"


/*
function will construct an Pawn object
input:
	type - field value of type to set
*/
Pawn::Pawn(char type) : Piece::Piece(type) { // set _type value by Parameter
}

Pawn::~Pawn()
{
}

/*
function will check if Instruction is valid for current type of piece
Input:
	instruction - Instruction to check
	isPlayerDst - if a player exists at destination
	whiteTurn - if it's the white player turn
Output:
	if Instruction is valid for current type of piece then return true, else return false
*/
bool Pawn::moveFormat(std::string instruction, bool isPlayerDst, int currTurn)
{
	if (getType() == BLACK_PAWN) { // if the current pawn is black
		if (instruction[SECOND] - STARTOF_LENGTH_CHAR == SIX && instruction[FORTH] - STARTOF_LENGTH_CHAR == FOUR && instruction[FIRST] == instruction[THIRD] && !isPlayerDst) { return true; }//trying to move 2 steps at the beggining
		else if (instruction[SECOND] - instruction[FORTH] == ONE && instruction[FIRST] == instruction[THIRD] && !isPlayerDst) { return true; }//trying to make one step and destination is free
		else if (instruction[SECOND] - instruction[FORTH] == ONE && (instruction[FIRST] - instruction[THIRD] == ONE || instruction[THIRD] - instruction[FIRST] == ONE) && isPlayerDst) { return true; }//trying to eat and there is player at destination
	}
	else {
		if (instruction[SECOND] - STARTOF_LENGTH_CHAR == ONE && instruction[FORTH] - STARTOF_LENGTH_CHAR == THREE && instruction[FIRST] == instruction[THIRD] && !isPlayerDst) { return true; }//trying to move 2 steps at the beggining
		else if (instruction[FORTH] - instruction[SECOND] == ONE && instruction[FIRST] == instruction[THIRD] && !isPlayerDst) { return true; }//trying to make one step and destination is free
		else if (instruction[FORTH] - instruction[SECOND] == ONE && (instruction[FIRST] - instruction[THIRD] == ONE || instruction[THIRD] - instruction[FIRST] == ONE) && isPlayerDst) { return true; }//trying to eat and there is player at destination
	}
	return false;
}

/*
function will check if the piece will skip any players by making the move
Input:
instruction - Instruction to check
gameBoard - game board
Output:
if the piece will skip any players by making the move then return true, else return false
*/
bool Pawn::hasSkippedPlayers(std::string instruction, Piece* const gameBoard[ENDOF_LENGTH][ENDOF_LENGTH]) {
	if (getType() == BLACK_PAWN && instruction[SECOND] - STARTOF_LENGTH_CHAR == SIX && instruction[FORTH] - STARTOF_LENGTH_CHAR == FOUR) {// if trying to move 2 steps at the beggining and skipped a player
		if (gameBoard[ENDOF_LINE - (instruction[SECOND] - ONE) + STARTOF_LENGTH_CHAR][instruction[FIRST] - STARTOF_TYPE_P2]->getType() != BLANK) { return false; }
	}
	else {
		if (gameBoard[ENDOF_LINE - (instruction[SECOND] + ONE) + STARTOF_LENGTH_CHAR][instruction[FIRST] - STARTOF_TYPE_P2]->getType() != BLANK) { return false; }
	}
	return false; // pawn can't skip players moves only one tile
}
