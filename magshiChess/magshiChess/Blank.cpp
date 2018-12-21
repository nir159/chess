#include "Blank.h"

/*
function will construct an Blank object
input:
	[Void]
*/
Blank::Blank() : Piece::Piece('#') {
}


Blank::~Blank()
{
}

bool Blank::moveFormat(std::string str, bool isPlayerDst, int currTurn) {
	// can't move
	return false;
}

bool Blank::hasSkippedPlayers(std::string instruction, Piece* const gameBoard[ENDOF_LENGTH][ENDOF_LENGTH]) {
	return false;
}