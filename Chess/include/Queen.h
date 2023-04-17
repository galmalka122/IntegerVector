#pragma once
#include "ChessPiece.h"


class Queen : public ChessPiece {
public:

	Queen(const Color& color, const char rep) : ChessPiece(color, rep) {};
	bool isValidMove(const Direction& d, const Steps& s) override { return true; };

};