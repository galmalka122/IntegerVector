#pragma once
#include "ChessPiece.h"

class Pawn: public ChessPiece {

private:

public:

	Pawn(const Color& color, const char rep) : ChessPiece(color, rep) {};
	bool isValidMove(const Direction& d, const Steps& s) override { return true; };
};