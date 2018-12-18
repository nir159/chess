#include "Board.h"

/*
function will construct an Board object
input:
	gameBoard - field value to set
*/
Board::Board(std::string gameBoard) : _currPlayer(BLACK_PLAYER), _instruction("")
{
	int i = 0, j = 0, last = 0;
	for (i = 0; i < 8; i++) {
		for (j = 0; j < 8; j++) {
			switch (gameBoard[last]) {
				case 'R':
				case 'r':
					_pieces[i][j] = new Rook(gameBoard[last]);
					break;
				case 'K':
				case 'k':
					_pieces[i][j] = new King(gameBoard[last]);
					break;
				default:
					_pieces[i][j] = new Blank();
			}
			last++;
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
	if (SideFunctions::isInstructionValid(_instruction[FIRST] - STARTOF_WIDTH) && SideFunctions::isInstructionValid(_instruction[SECOND] - STARTOF_LENGTH_CHAR) && SideFunctions::isInstructionValid(_instruction[THIRD] - STARTOF_WIDTH) && SideFunctions::isInstructionValid(_instruction[FORTH] - STARTOF_LENGTH_CHAR)) { // checks if instuction is in a valid format
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
	std::cout << _pieces[ENDOF_LINE - _instruction[SECOND] + STARTOF_LENGTH_CHAR][_instruction[FIRST] - STARTOF_TYPE_P2]->getType() << std::endl << _pieces[1][2]->getType();
	if (_currPlayer == WHITE_PLAYER && SideFunctions::whichPlayer((_pieces[ENDOF_LINE - _instruction[SECOND] + STARTOF_LENGTH_CHAR][_instruction[FIRST] - STARTOF_TYPE_P2])->getType()) == WHITE_PLAYER) { return true; }
	else if (_currPlayer == BLACK_PLAYER && SideFunctions::whichPlayer((_pieces[ENDOF_LINE - _instruction[SECOND] + STARTOF_LENGTH_CHAR][_instruction[FIRST] - STARTOF_TYPE_P2])->getType()) == BLACK_PLAYER) { return true; }
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
	if (_currPlayer == WHITE_PLAYER && (SideFunctions::whichPlayer((_pieces[_instruction[THIRD] - 'a'][_instruction[FORTH]])->getType()) == WHITE_PLAYER)) { return false; }
	else if (SideFunctions::whichPlayer((_pieces[_instruction[THIRD] - 'a'][_instruction[FORTH]])->getType()) == BLACK_PLAYER) { return false; }
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
	if (_pieces[ENDOF_LINE - _instruction[SECOND] + STARTOF_LENGTH_CHAR][_instruction[FIRST] - STARTOF_TYPE_P2]->moveFormat(_instruction) && !(_pieces[ENDOF_LINE - _instruction[SECOND] + STARTOF_LENGTH_CHAR][_instruction[FIRST] - STARTOF_TYPE_P2]->hasSkippedPlayers(_instruction, _pieces))) { return true; }
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

/*
Function will set the _currPlayer field
Input:
player - player to set
Output:
[Void]
*/
void Board::setPlayer(int player)
{
	if (player == ONE || player == TWO) {
		this->_currPlayer = player;
	}
}

/*
Function will return the _currPlayer field
Input:
[Void]
Output:
_currPlayer - the current player
*/
int Board::getPlayer() {
	return _currPlayer;
}