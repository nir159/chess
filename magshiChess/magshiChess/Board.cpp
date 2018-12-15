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
	if (SideFunctions::isCharInstructionValid(instruction[FIRST]) && SideFunctions::isNumInstructionValid(instruction[SECOND]) && SideFunctions::isCharInstructionValid(instruction[THIRD]) && SideFunctions::isNumInstructionValid(instruction[FORTH])) { // checks if instuction is in a valid format
		return true;
	}
	return false;
}