#pragma once
#include "ChessPiece.h"

class Knight : public ChessPiece {
public:

	Knight(const Color& color, const char rep) : ChessPiece(color, rep) {};
	bool isValidMove(const Direction& d, const Steps& s) override { return true; };

};