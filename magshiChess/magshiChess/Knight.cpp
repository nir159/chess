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
	if ((instruction[SECOND] - instruction[FORTH] == TWO || instruction[FORTH] - instruction[SECOND] == TWO) && (instruction[FIRST] - instruction[THIRD] == ONE || instruction[THIRD] - instruction[FIRST] == ONE)) { return true; }
	else if ((instruction[SECOND] - instruction[FORTH] == ONE || instruction[FORTH] - instruction[SECOND] == ONE) && (instruction[FIRST] - instruction[THIRD] == TWO || instruction[THIRD] - instruction[FIRST] == TWO)) { return true; }
	return false;
}

bool Knight::hasSkippedPlayers(std::string instruction, Piece* const gameBoard[ENDOF_LENGTH][ENDOF_LENGTH]) {
	return false;// Knight is allowed to skip players
}
