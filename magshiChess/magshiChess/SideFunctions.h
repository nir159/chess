#pragma once
#include <string>
#include <iostream>
#define STARTOF_WIDTH 'a'
#define ENDOF_WIDTH 'h'
#define ZERO 0
#define ONE 1
#define TWO 2

#define BLANK_PLAYER 0
#define BLACK_PLAYER 1
#define WHITE_PLAYER 2


#define STARTOF_LENGTH 1
#define STARTOF_LENGTH_CHAR '1'
#define ENDOF_LENGTH 8
#define ENDOF_LINE 7

#define STARTOF_TYPE_P1 'A'
#define ENDOF_TYPE_P1 'Z'

#define STARTOF_TYPE_P2 'a'
#define ENDOF_TYPE_P2 'z'
#define BLANK '#'
#define BLACK_KING 'k'
#define WHITE_KING 'K'
#define BLACK_PAWN 'p'
#define WHITE_PAWN 'P'

#define INSTRUCTION_LEN 4
#define PIECES_PER_PLAYER 16
#define ENDOF_BOARD 63
enum INSTRUCTION { FIRST, SECOND, THIRD, FORTH };

class SideFunctions
{
public:
	static bool isInstructionValid(const char size);
	static int changePlayer(int player);
	static int whichPlayer(const char width);
};

