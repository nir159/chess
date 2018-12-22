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
	if (r->moveFormat(instruction, isPlayerDst, currTurn)) { // if trying to move like the rook
		_isRookFormat = true;
		return true;
	}
	else if (b->moveFormat(instruction, isPlayerDst, currTurn)) {// if trying to move like the bishop
		_isRookFormat = false;
		return true;
	}
	return false;
}

bool Queen::hasSkippedPlayers(std::string instruction, Piece* const gameBoard[ENDOF_LENGTH][ENDOF_LENGTH]) {
	if (_isRookFormat && r->hasSkippedPlayers(instruction, gameBoard)) { return true; } // if the move format is like the rook and rook didn't skip players
	else if (!_isRookFormat && b->hasSkippedPlayers(instruction, gameBoard)) { return true; } // if the move format is like the bishop and bishop didn't skip players
	return false;
}