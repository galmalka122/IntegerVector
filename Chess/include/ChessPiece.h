#pragma once
#include  <utility>
#include <vector>
using std::vector;
using Direction = std::pair<int, int>;
using ValidDirections = std::vector<Direction>;
using Steps = std::pair<int, int>;

constexpr Direction direction_horizontal(0, 1);
constexpr Direction direction_vertical(1, 0);
constexpr Direction direction_cross(1, 1);


enum Color : bool
{
	White = true,
	Black = false
};



class ChessPiece {

private:

	int m_validSteps;
	ValidDirections m_validDirections;
	Color m_color;
	char m_rep;

public:

	ChessPiece(const Color& color, const char rep, const ValidDirections validDirections) :
		m_color(color), m_rep(rep), m_validDirections(validDirections) {};
	const ValidDirections& getValidDirections() { return m_validDirections; };
	virtual bool canColide(ChessPiece&) {};
	virtual bool isValidMove(const Direction& d, const Steps& s) = 0;
	const Color getColor() const { return m_color; };
	const char getRep() const { return m_rep; };
	virtual ~ChessPiece() = default;
};