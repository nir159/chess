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
	if (instruction[FORTH] - instruction[SECOND] == ONE) { return true; }
	return false;
}