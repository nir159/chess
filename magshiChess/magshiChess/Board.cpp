#include "Board.h"


Board::Board()
{
}


Board::~Board()
{
}

bool Board::isValidRange(std::string str) const {
	if (str.length() == INSTRUCTION_LEN && SideFunctions::isCharInstructionValid(str[FIRST]) && SideFunctions::isNumInstructionValid(str[SECOND]) && SideFunctions::isCharInstructionValid(str[THIRD]) && SideFunctions::isNumInstructionValid(str[FORTH])) {
		return true;
	}
	return false;
}