#pragma once
#define STARTOF_WIDTH 'a'
#define ENDOF_WIDTH 'h'
#define FIRST_PLAYER 1
#define SECOND_PLAYER 2
#define STARTOF_LENGTH 1
#define ENDOF_LENGTH 8

class SideFunctions
{
public:
	static bool isCharInstructionValid(const char ch);
	static bool isNumInstructionValid(const int num);
	static void changePlayer(int* num);
};

