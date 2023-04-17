#include "Rook.h"

Rook::Rook(const Color& color, const char rep) : 
	ChessPiece(color, rep, {direction_horizontal, direction_vertical}) {
	
}

bool Rook::isValidMove(const Direction& d, const Steps& s)
{
	//one direction should be greater than 1 while the second must be 0. can move multiple squares
	return std::find(getValidDirections().begin(), getValidDirections().end(), d) != getValidDirections().end();
}
