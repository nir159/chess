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

/*
function will check if the current player have a piece in the source tile
Input:
	[Void]
Output:
	if the current player have a piece in the source tile then return true, else false
*/
bool Board::pieceExists() const {
	if (_currPlayer == WHITE_PLAYER && SideFunctions::whichPlayer((*_pieces[_instruction[FIRST] - 'a'][_instruction[SECOND]]).getType()) == WHITE_PLAYER) { return true; }
	else if (SideFunctions::whichPlayer((*_pieces[_instruction[FIRST] - 'a'][_instruction[SECOND]]).getType()) == BLACK_PLAYER) { return true; }
	return false;
}

/*
function will check if the current player have a piece in the destination tile
Input:
	[Void]
Output:
	if the current player have a piece in the destination tile then return true, else false
*/
bool Board::noPiece() const {
	if (_currPlayer == WHITE_PLAYER && (SideFunctions::whichPlayer((*_pieces[_instruction[THIRD] - 'a'][_instruction[FORTH]]).getType()) == WHITE_PLAYER)) { return false; }
	else if (SideFunctions::whichPlayer((*_pieces[_instruction[THIRD] - 'a'][_instruction[FORTH]]).getType()) == BLACK_PLAYER) { return false; }
	return true;
}

/*
function will check if the current player have a done a move that will create a chess situation for opponent
Input:
	[Void]
Output:
	if the current player have a done a move that will create a chess situation for opponent then return true, else false
*/
bool Board::isChess() const {
	int i = 0, j = 0;
	std::string distance = ""; // distance from new position to king

	if (_currPlayer == WHITE_PLAYER) { // checks if current player is White
		/* runs on game board */
		for (i = 0; i < ENDOF_LENGTH; i++) {
			for (j = 0; j < ENDOF_LENGTH; j++) {
				if (_pieces[i][j]->getType() == BLACK_KING) { /* checks if current piece on board is opponent King piece */ distance += _instruction[THIRD] + _instruction[FORTH] + (char)i + STARTOF_TYPE_P1 + j; /* if it is save last dest + King loc in a new instruction */ }
			}
		}
	}
	else {
		/* runs on game board */
		for (i = 0; i < ENDOF_LENGTH; i++) {
			for (j = 0; j < ENDOF_LENGTH; j++) {
				if (_pieces[i][j]->getType() == WHITE_KING) { /* checks if current piece on board is opponent King piece */ distance += _instruction[THIRD] + _instruction[FORTH] + (char)i + STARTOF_TYPE_P1 + j; /* if it is save last dest + King loc in a new instruction */ }
			}
		}
	}
	if (_pieces[_instruction[FIRST] - STARTOF_TYPE_P1][_instruction[SECOND]]->moveFormat(distance) && !(_pieces[_instruction[FIRST] - STARTOF_TYPE_P1][_instruction[SECOND]]->skippedPlayers(distance, _pieces))) { /* checks if the piece threatens the king */ return true; }
	return false;
}