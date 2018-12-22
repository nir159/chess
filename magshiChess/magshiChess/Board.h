#pragma once
#include "Piece.h"
#include "SideFunctions.h"
#include <string>
#include "SideFunctions.h"
#include "Rook.h"
#include "King.h"
#include "Blank.h"
#include "Pawn.h"
#include "Knight.h"
#include "Bishop.h"
#include "Queen.h"

class Board
{
private:
	Piece* _pieces[ENDOF_LENGTH][ENDOF_LENGTH];
	std::string _instruction;
	int _currPlayer;
	bool _isPlayerDst;
public:
	Board(std::string gameBoard);
	bool isValidRange() const;
	bool pieceExists() const;
	bool isPiece() const;
	bool isChess();
	bool isReachable();
	bool isSelfChess();
	bool isSame() const;
	void setInstruction(std::string instruction);
	void setPlayer(int player);
	int getPlayer();
	void switchPieces(Piece* src, Piece* dst);
	void setIsPlayerDst();
	~Board();
};

