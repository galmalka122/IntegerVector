#pragma once
#include "ChessPiece.h"

class Rook : public ChessPiece {

public:

	Rook(const Color& color, const char rep);
	bool isValidMove(const Direction& d, const Steps& s) override;
};