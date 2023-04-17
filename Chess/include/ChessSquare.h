#pragma once
#include <string>
#include "ChessPiece.h"
using std::string;

class ChessSquare {
private:

	char m_letter;
	char m_number;
	ChessPiece* m_piece;
public:

	ChessSquare(const string& position, ChessPiece* piece = nullptr) : m_letter(position[0]), m_number(position[1]), m_piece(piece){};
	ChessSquare(const ChessSquare& other){ m_letter = other.m_letter; m_number = other.m_number; m_piece = other.m_piece;};
	const int getCol() const { return int(m_number - '1'); };
	const int getRow() const { return int(m_letter - 'a'); };
	const char getNumber() const { return m_number; };
	const char getLetter() const { return m_letter; };
	const bool operator==(ChessSquare& other)const { 
		return m_letter == other.m_letter && m_number == other.m_number && m_piece == other.m_piece;
	};
	const bool operator!=(ChessSquare& other)const { return !(this == &other); };
	ChessPiece& getPiece() { return *m_piece; };
	void setPiece(ChessPiece* p) { m_piece = p; };
	~ChessSquare() {
		{
			if (m_piece) {
				delete m_piece;
				m_piece = nullptr;
			}
		};
	}
};