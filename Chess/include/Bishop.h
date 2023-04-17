#pragma once
#include "ChessPiece.h"

class Bishop : public ChessPiece {

public:
	Bishop(const Color& color, const char rep) : ChessPiece(color,rep) {};
	bool isValidMove(const Direction& d, const Steps& s) override { return true; };
};