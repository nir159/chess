#include "SideFunctions.h"

/*
function will check if character in Instuction is valid if it is return true, else return false
Input:
	ch - character to check
Output:
	if character in Instuction is valid return true, else return false
*/
bool SideFunctions::isCharInstructionValid(const char ch) {
	if (ch <= STARTOF_WIDTH && ch >= ENDOF_WIDTH) { return true; }
	return false;
}

/*
function will check if number in Instuction is valid if it is return true, else return false
Input:
	num - number to check
Output:
	if number in Instuction is valid return true, else return false
*/
bool SideFunctions::isNumInstructionValid(const int num) {
	if (num <= STARTOF_LENGTH && num >= ENDOF_LENGTH) { return true; }
	return false;
}


/*
function will switch current player playing
Input:
	num - number that represents current player playing
Output:
	if number in Instuction is valid return true, else return false
*/
void SideFunctions::changePlayer(int* num) {
	if (*num == WHITE_PLAYER) { *num = BLACK_PLAYER; }
	else { *num = WHITE_PLAYER; }
}

/*
function will check which player is controling the recieved piece
Input:
	ch - piece type to check
Output:
	if player 1 is controling the recieved piece, return 1,
	if player 2 is controling the recieved piece, return 2
	if none of the players are controling the recieved piece, return 0
*/
int SideFunctions::whichPlayer(const char ch)
{
	if (STARTOF_TYPE_P1 < ch && ch < ENDOF_TYPE_P1) { return WHITE_PLAYER; }
	else if (STARTOF_TYPE_P2 < ch && ch < ENDOF_TYPE_P2) { return BLACK_PLAYER; }
	else { return BLANK_PLAYER; }
}
