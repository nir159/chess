#pragma once
#define STARTOF_WIDTH 'a'
#define ENDOF_WIDTH 'h'

#define BLANK_PLAYER 0
#define FIRST_PLAYER 1
#define SECOND_PLAYER 2

#define STARTOF_LENGTH 1
#define ENDOF_LENGTH 8

#define STARTOF_TYPE_P1 'a'
#define ENDOF_TYPE_P1 'z'

#define STARTOF_TYPE_P2 'A'
#define ENDOF_TYPE_P2 'Z'

class SideFunctions
{
public:
	static bool isCharInstructionValid(const char ch);
	static bool isNumInstructionValid(const int num);
	static void changePlayer(int* num);
	static int whichPlayer(const char ch);
};

