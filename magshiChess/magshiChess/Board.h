#pragma once
#include "Piece.h"
#include "SideFunctions.h"
#include <string>

#define WHITE_PLAYER 1
#define BLACK_PLAYER 2
#define INSTRUCTION_LEN 4
#define ENDOF_LENGTH 8
#define PIECES_PER_PLAYER 16
enum INSTRUCTION {FIRST, SECOND, THIRD, FORTH};

class Board
{
private:
	Piece* _pieces[ENDOF_LENGTH][ENDOF_LENGTH];
	std::string _instruction;
	int _currPlayer;
public:
	Board();
	bool isValidRange() const;
	bool pieceExists() const;
	bool noPiece() const;
	void isReachable();
	void isSelfChess();
	void isChess();
	void eat();
	bool isSame() const;
	void makeMove();
	~Board();
};

