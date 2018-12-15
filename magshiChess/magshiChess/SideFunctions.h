#pragma once
#define STARTOF_WIDTH 'a'
#define ENDOF_WIDTH 'h'
#define STARTOF_LENGTH 1
#define ENDOF_LENGTH 8

class SideFunctions
{
public:
	static bool isCharInstructionValid(const char ch);
	static bool isNumInstructionValid(const int num);
};

