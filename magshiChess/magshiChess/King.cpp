#include "King.h"

/*
function will construct an King object
input:
	type - field value of type to set
*/
King::King(char type) : Piece::Piece(type) { // set _type value by Parameter
}


King::~King()
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
bool King::moveFormat(std::string instruction, bool isPlayerDst, int currTurn) {
	if (abs(instruction[FIRST] - instruction[THIRD]) < TWO && abs(instruction[SECOND] - instruction[FORTH]) < TWO) { return true; }
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
bool King::hasSkippedPlayers(std::string instruction, Piece* const gameBoard[ENDOF_LENGTH][ENDOF_LENGTH]) {
	return false; // king can't skip players moves only one tile
}