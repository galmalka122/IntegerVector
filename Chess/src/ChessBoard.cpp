#include "ChessBoard.h"

const Steps ChessBoard::getSteps(const ChessSquare& src, const ChessSquare& dst) const
{
	return Steps(dst.getRow() - src.getRow(), dst.getCol() - src.getCol());
}

const Direction ChessBoard::getDirection(const Steps& s) const
{
	return Direction(s.first == 0 ? 0 : s.first / abs(s.first), s.second == 0 ? 0 : s.second / abs(s.second));
}

ChessBoard::ChessBoard(string boardString)
{
	// Initialize the board vector
	vector<ChessSquare*> curLine;

	for (auto character : boardString)
	{
		// Determine the position by the vector size
		string position = string() + char('a' + m_board.size()) + char('1' + curLine.size());

		// Determine the color of the piece by the representing charecter
		if (character == '#')
		{
			curLine.push_back(new ChessSquare(position));
		}
		else {
			Color color = character > 96 && character < 123 ? Color::Black : Color::White;

			// Initialize the piece
			switch (character)
			{
			case 'p': case 'P':
			{
				curLine.push_back(new ChessSquare(position, new Pawn(color, character)));
				break;
			}
			case 'k': case 'K':
			{
				curLine.push_back(new ChessSquare(position, new King(color, character)));
				break;
			}
			case 'r': case 'R':
			{
				curLine.push_back(new ChessSquare(position, new Rook(color, character)));
				break;
			}
			case 'q': case 'Q':
			{
				curLine.push_back(new ChessSquare(position, new Queen(color, character)));
				break;
			}
			case 'n': case 'N':
			{
				curLine.push_back(new ChessSquare(position, new Knight(color, character)));
				break;
			}
			case 'b': case 'B':
			{
				curLine.push_back(new ChessSquare(position, new Bishop(color, character)));
				break;
			}
			}
		}
		if (curLine.size() == 8) {
			m_board.push_back(curLine);
			curLine.clear();
		}
	}

}

const int ChessBoard::isValid(const string& move)
{
	string position = move.substr(0, 2);
	ChessSquare* source = m_board[position[0] - 'a'][position[1] - '1'];
	ChessPiece& sourcePiece = source->getPiece();

	// no piece in source
	if (!&sourcePiece) {
		return EmptyPieceInSource;
	}

	if (sourcePiece.getColor() != m_turn) {
		return SourcePieceWrongColor;
	}

	// check if the destination has a same color piece
	position = move.substr(2, 2);
	ChessSquare* destination = m_board[position[0] - 'a'][position[1] - '1'];
	ChessPiece& destinationPiece = destination->getPiece();
	if (&destinationPiece &&
		sourcePiece.getColor() == destinationPiece.getColor()) {
		return DestinationPieceWrongColor;
	}

	
	Steps s = getSteps(*source, *destination);
	Direction d = getDirection(s);

	// check if the destination is a valid move
	if (!sourcePiece.isValidMove(d,s)) {
		return IllegalMovement;
	}
	
	// TODO: check if the game piece is not a knight and there is no other pieces in the route
	ChessSquare* currentPosition = m_board[source->getRow() + d.first][source->getCol() + d.second];

	while(currentPosition != destination) {
		if (&(currentPosition->getPiece())) {
			return IllegalMovement;
		}
		currentPosition = m_board[currentPosition->getRow() + d.first][currentPosition->getCol() + d.second];
	}

	destination->setPiece(&sourcePiece);
	source->setPiece(nullptr);
	if (m_turn == White) {
		m_turn = Black;
	}
	else m_turn = White;
	return Legal;
}



const string ChessBoard::toString() const
{
	string board = "";
	for (auto line : m_board) {
		for (auto square : line) {
			if(&square->getPiece())
				board.push_back(square->getPiece().getRep());
			else board.push_back('#');
		}
	}
	return board;
}


