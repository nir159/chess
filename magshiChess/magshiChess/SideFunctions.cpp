#include "SideFunctions.h"

bool SideFunctions::isCharInstructionValid(const char ch) {
	if (ch <= STARTOF_WIDTH && ch >= ENDOF_WIDTH) { return true; }
	return false;
}

bool SideFunctions::isNumInstructionValid(const int num) {
	if (num <= STARTOF_LENGTH && num >= ENDOF_LENGTH) { return true; }
	return false;
}