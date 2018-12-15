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

void SideFunctions::changePlayer(int* num) {
	if (*num == FIRST_PLAYER) {
		*num = SECOND_PLAYER;
	}
	else {
		*num = FIRST_PLAYER;
	}
}