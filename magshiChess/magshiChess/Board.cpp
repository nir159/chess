#include "Board.h"


Board::Board()
{
	// if (str.length() == INSTRUCTION_LEN)
}


Board::~Board()
{
}

/*
function will check if Instuction is in the correct format and the parameters in it are in the valid range
Input:
	[Void]
Output:
	if Instuction is in the correct format and the parameters in it are in the valid range then return true, else return false
*/
bool Board::isValidRange() const {
	if (SideFunctions::isCharInstructionValid(_instruction[FIRST]) && SideFunctions::isNumInstructionValid(_instruction[SECOND]) && SideFunctions::isCharInstructionValid(_instruction[THIRD]) && SideFunctions::isNumInstructionValid(_instruction[FORTH])) { // checks if instuction is in a valid format
		return true;
	}
	return false;
}

/*
function will check if the Instuction's parameters are not the same in each of it's parts
Input:
	[Void]
Output:
	if the Instuction's parameters are not the same in each of it's parts then return true, else false
*/
bool Board::isSame() const {
	if (_instruction[FIRST] == _instruction[THIRD] && _instruction[SECOND] == _instruction[FORTH]) { return true; }
	return false;
}

bool Board::pieceExists() const {
	if (_currPlayer == WHITE_PLAYER) {
		if (SideFunctions::whichPlayer((*_pieces[_instruction[FIRST] - 'a'][_instruction[SECOND]]).getType()) == WHITE_PLAYER) {
			return true;
		}
	}
	else {
		if (SideFunctions::whichPlayer((*_pieces[_instruction[FIRST] - 'a'][_instruction[SECOND]]).getType()) == BLACK_PLAYER) {
			return true;
		}
	}
	return false;
}

bool Board::noPiece() const {
	if (_currPlayer == WHITE_PLAYER) {
		if (SideFunctions::whichPlayer((*_pieces[_instruction[THIRD] - 'a'][_instruction[FORTH]]).getType()) == WHITE_PLAYER) {
			return false;
		}
	}
	else {
		if (SideFunctions::whichPlayer((*_pieces[_instruction[THIRD] - 'a'][_instruction[FORTH]]).getType()) == BLACK_PLAYER) {
			return false;
		}
	}
	return true;
}