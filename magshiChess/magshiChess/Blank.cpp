#include "Blank.h"

/*
function will construct an Blank object
input:
	[Void]
*/
Blank::Blank() : Piece::Piece('#') {
}


Blank::~Blank()
{
}

bool Blank::moveFormat(std::string str) {
	// can't move
	return false;
}
