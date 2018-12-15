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