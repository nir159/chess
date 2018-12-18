#pragma once
#include "Piece.h"
#include "SideFunctions.h"
#include <string>
#include "SideFunctions.h"
#include "Rook.h"
#include "King.h"
#include "Blank.h"

class Board
{
private:
	Piece* _pieces[ENDOF_LENGTH][ENDOF_LENGTH];
	std::string _instruction;
	int _currPlayer;
public:
	Board(std::string gameBoard);
	bool isValidRange() const;
	bool pieceExists() const;
	bool noPiece() const;
	bool isChess() const;
	bool isReachable() const;
	void isSelfChess();
	bool isSame() const;
	void makeMove() const;
	void setInstruction(std::string instruction);
	void setPlayer(int player);
	int getPlayer();
	void switchPieces(Piece** src, Piece** dst);
	~Board();
};

