#pragma once
#include "ChessPiece.h"

class King : public ChessPiece {
public:

	King(const Color& color, const char rep) : ChessPiece(color, rep, {direction_cross, direction_horizontal, direction_vertical}) {};
	bool isValidMove(const Direction& d, const Steps& s);

};