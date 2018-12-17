#include "Board.h"


Board::Board(std::string gameBoard) : _currPlayer(WHITE_PLAYER), _instruction("")
{
	int i = 0, j = 0;
	for (i = ENDOF_LENGTH - ONE; i >= 0; i--) {
		for (j = 0; j < ENDOF_LENGTH; j++) {
			switch (gameBoard[i*j]) {
				case 'R':
				case 'r':
					_pieces[i][j] = new Rook(gameBoard[i*j]);
					break;
				case 'K':
				case 'k':
					_pieces[i][j] = new King(gameBoard[i*j]);
					break;
				}
			//_pieces[i][j] = new ;
		}
	}
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
	if (SideFunctions::isInstructionValid(_instruction[FIRST] - STARTOF_WIDTH + ONE) && SideFunctions::isInstructionValid(_instruction[SECOND] - STARTOF_LENGTH_CHAR + ONE) && SideFunctions::isInstructionValid(_instruction[THIRD] - STARTOF_WIDTH + ONE) && SideFunctions::isInstructionValid(_instruction[FORTH] - STARTOF_LENGTH_CHAR + ONE)) { // checks if instuction is in a valid format
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
	if (_pieces[_instruction[FIRST] - STARTOF_TYPE_P1][_instruction[SECOND]]->moveFormat(distance) && !(_pieces[_instruction[FIRST] - STARTOF_TYPE_P1][_instruction[SECOND]]->hasSkippedPlayers(distance, _pieces))) { /* checks if the piece threatens the king */ return true; }
	return false;
}

/*
function will check if the Instruction can be committed
Input:
	[Void]
Output:
	if the Instruction can be committed then return true, else false
*/
bool Board::isReachable() const {
	if (_pieces[_instruction[FIRST] - STARTOF_TYPE_P1][_instruction[SECOND] - ONE]->moveFormat(_instruction) && !(_pieces[_instruction[FIRST] - STARTOF_TYPE_P1][_instruction[SECOND] - ONE]->hasSkippedPlayers(_instruction, _pieces))) { return true; }
	return false;
}

/*
Function will set an Shape class' _instruction field
Input:
	instruction - field value to set
Output:
	[Void]
*/
void Board::setInstruction(std::string instruction)
{
	this->_instruction = instruction;
}