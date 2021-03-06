#include "SideFunctions.h"

/*
function will check if the number in Instuction is valid if it is return true, else return false
Input:
	size - the size of the char
Output:
	if Instuction is valid return true, else return false
*/
bool SideFunctions::isInstructionValid(const char size) {
	if (size >= ZERO && size <= ENDOF_LENGTH) { return true; }
	return false;
}


/*
function will switch current player playing
Input:
	player - number that represents current player playing
Output:
	the opposite player
*/
int SideFunctions::changePlayer(int player) {
	if (player == WHITE_PLAYER) { return BLACK_PLAYER; }
	else { return WHITE_PLAYER; }
}

/*
function will check which player is controling the recieved piece
Input:
	width - piece type to check
Output:
	if player 1 is controling the recieved piece, return 1,
	if player 2 is controling the recieved piece, return 2
	if none of the players are controling the recieved piece, return 0
*/
int SideFunctions::whichPlayer(const char width) {
	if (STARTOF_TYPE_P1 < width && width < ENDOF_TYPE_P1) { return WHITE_PLAYER; }
	else if (STARTOF_TYPE_P2 < width && width < ENDOF_TYPE_P2) { return BLACK_PLAYER; }
	else { return BLANK_PLAYER; }
}
