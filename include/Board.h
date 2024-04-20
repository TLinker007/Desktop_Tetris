#ifndef _BOARD_
#define _BOARD_

#include "Pieces.h"

// Width of each of the two lines that delimit the board.
#define BOARD_LINE_WIDTH 6
// Width and height of each block of a piece.
#define BLOCK_SIZE 16
// Center position of the board from the left of the screen.
#define BOARD_POSITION 320
// Board width in blocks.
#define BOARD_WIDTH 10
// Board height in blocks.
#define BOARD_HEIGHT 20
// Minimum vertical margin for the board limit.
#define MIN_VERTICAL_MARGIN 20
// Minimum horizontal margin for the board limit.
#define MIN_HORIZONTAL_MARGIN 20
// Number of horizontal and vertical blocks of a matrix piece
#define PIECE_BLOCKS 5

// Board Class
class Board
{
	public:

		Board(Pieces *ptrPieces, int pScreenHeight);

		int GetXPosInPixels(int pPos);
		int GetYPosInPixels(int pPos);
		bool IsFreeBlock(int pX, int pY);
		bool IsPossibleMovement(int pX, int pY, int pPiece, int pRotation);
		void StorePiece(int pX, int pY, int pPiece, int pRotation);
		void DeletePossibleLines();
		bool IsGameOver();

	private:

		// POS_FREE = free position of the board and POS_FILLED = filled position of the board
		enum {POS_FREE, POS_FILLED};
		// Board that contains the pieces
		int mBoard[BOARD_WIDTH][BOARD_HEIGHT];
		Pieces *mPieces;
		int mScreenHeight;

		void InitBoard();
		void DeleteLine(int pY);
};

#endif

