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
Output:
	if Instruction is valid for current type of piece then return true, else return false
*/
bool Pawn::moveFormat(std::string instruction)
{
	if (instruction[FORTH] - instruction[SECOND] == ONE && instruction[FIRST] == instruction[THIRD]) { return true; }
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
	return false; // pawn can't skip players moves only one tile
}