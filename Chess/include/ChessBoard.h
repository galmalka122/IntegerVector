#pragma once
#include "ChessSquare.h"
#include "ChessPiece.h"
#include "Pawn.h"
#include "Knight.h"
#include "King.h"
#include "Queen.h"
#include "Rook.h"
#include "Bishop.h"

using Board = vector<vector<ChessSquare*>>;

enum GameCode {
	EmptyPieceInSource = 11,
	SourcePieceWrongColor,
	DestinationPieceWrongColor,
	IllegalMovement = 21,
	CauseCheckmate = 31,
	LegalAndCheck = 41,
	Legal
};

class ChessBoard {

private:

	inline static Color m_turn = White;
	Board m_board;
	const Direction getDirection(const Steps& s) const;
	const Steps getSteps(const ChessSquare&, const ChessSquare&) const;
	ChessSquare& operator+(const Direction&) const;
	

public:

	ChessBoard(string boardString);
	const int isValid(const string& move);
	const bool iscauseCheck(const ChessSquare&, const ChessSquare&, const Color&);
	const string toString() const;
	~ChessBoard() {
		for (auto line : m_board) {
			for (auto square : line) {
				delete square;
			}
		};
	};
};