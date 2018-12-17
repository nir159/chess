#pragma once
#include <string>
#define STARTOF_WIDTH 'a'
#define ENDOF_WIDTH 'h'

#define BLANK_PLAYER 0
#define WHITE_PLAYER 1
#define BLACK_PLAYER 2

#define STARTOF_LENGTH 1
#define ENDOF_LENGTH 8

#define STARTOF_TYPE_P1 'a'
#define ENDOF_TYPE_P1 'z'

#define STARTOF_TYPE_P2 'A'
#define ENDOF_TYPE_P2 'Z'
#define BLANK '#'
#define BLACK_KING 'K'
#define WHITE_KING 'k'

#define INSTRUCTION_LEN 4
#define PIECES_PER_PLAYER 16
enum INSTRUCTION { FIRST, SECOND, THIRD, FORTH };

class SideFunctions
{
public:
	static bool isInstructionValid(const char size);
	static void changePlayer(int* length);
	static int whichPlayer(const char width);
};

