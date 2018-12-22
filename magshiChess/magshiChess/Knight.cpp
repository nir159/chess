#include "Knight.h"


/*
function will construct an Knight object
input:
	type - field value of type to set
*/
Knight::Knight(char type) : Piece::Piece(type) { // set _type value by Parameter
}


Knight::~Knight()
{
}

bool Knight::moveFormat(std::string instruction, bool isPlayerDst, int currTurn) {
	if (abs(instruction[SECOND] - instruction[FORTH]) == TWO && abs(instruction[FIRST] - instruction[THIRD]) == ONE) { return true; }
	else if (abs(instruction[SECOND] - instruction[FORTH]) == ONE && abs(instruction[FIRST] - instruction[THIRD]) == TWO) { return true; }
	return false;
}

bool Knight::hasSkippedPlayers(std::string instruction, Piece* const gameBoard[ENDOF_LENGTH][ENDOF_LENGTH]) {
	return false;// Knight is allowed to skip players
}
