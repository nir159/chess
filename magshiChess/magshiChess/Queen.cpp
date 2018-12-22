#include "Queen.h"

/*
function will construct an Queen object
input:
	type - field value of type to set
*/
Queen::Queen(char type) : Piece::Piece(type) { // set _type value by Parameter
}


Queen::~Queen()
{
}

bool Queen::moveFormat(std::string instruction, bool isPlayerDst, int currTurn) {
	if (r->moveFormat(instruction, isPlayerDst, currTurn)) {
		_isRookFormat = true;
		return true;
	}
	else if (b->moveFormat(instruction, isPlayerDst, currTurn)) {
		_isRookFormat = false;
		return true;
	}
	return false;
}

bool Queen::hasSkippedPlayers(std::string instruction, Piece* const gameBoard[ENDOF_LENGTH][ENDOF_LENGTH]) {
	if (_isRookFormat && r->hasSkippedPlayers(instruction, gameBoard)) { return true; }
	else if (!_isRookFormat && b->hasSkippedPlayers(instruction, gameBoard)) { return true; }
	return false;
}