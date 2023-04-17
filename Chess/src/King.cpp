#include "King.h"

bool King::isValidMove(const Direction& d, const Steps& s)
{
	return abs(s.first) == 1 || abs(s.second == 1);
}
