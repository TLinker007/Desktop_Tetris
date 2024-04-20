#include "..\include\Board.h"

// Initlizer
Board::Board(Pieces *ptrPieces, int pScreenHeight)
{
	// Retrieve the screen height.
	mScreenHeight = pScreenHeight;
	// Get the pointer to the pieces class.
	mPieces = ptrPieces;
	// Initialize the board blocks with free pieces.
	InitBoard();
}

// Initializes the board with free positions.
void Board::InitBoard()
{
	for (int w = 0; w < BOARD_WIDTH; w++)
	{
		for (int h = 0; h < BOARD_HEIGHT; h++)
		{
			mBoard[w][h] = POS_FREE;
		}
	}
}

/*
----------------------------------------------------
Store a piece in the board by filling the blocks.

Parameters:
pX -> Horizontal position in blocks
pY -> Vertical position in blocks
pPiece -> Piece to draw
pRotation -> 1 of the 4 possible rotations

----------------------------------------------------
*/
void Board::StorePiece(int pX, int pY, int pPiece, int pRotation)
{
	for(int i1 = pX, i2 = 0; i1 < pX + PIECE_BLOCKS; i1++, i2++)
	{
		for (int j1 = pY, j2 = 0; j1 < pY + PIECE_BLOCKS; j1++, j2++) 
		{
			// Store only the blocks of the piece that are not holes.
			if (mPieces->GetBlockType(pPiece, pRotation, j2, i2) != 0)
			{
				mBoard[i1][j1] = POS_FILLED;
			}
		}
	}
}

/*
--------------------------------------------------------
Checks if the game is over because a piece has received
the upper position or top of the game screen.

Returns true or false
--------------------------------------------------------
*/
bool Board::IsGameOver() 
{
	// If the first line has blocks then, game over.
	for (int i = 0; i < BOARD_WIDTH; i++) 
	{
		if(mBoard[i][0] == POS_FILLED)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

/*
--------------------------------------------------------
Delete a line of the board by moving all above lines
down.

Parameters:
pY -> Vertical positions in blocks of the line to delete.
--------------------------------------------------------
*/
void Board::DeleteLine(int pY)
{
	// Moves all the upper lines one row down.
	for (int col = pY; col > 0; col--)
	{
		for (int row = 0; row < BOARD_WIDTH; row++)
		{
			mBoard[row][col] = mBoard[row][col - 1];
		}
	}
}

/*
--------------------------------------------------------
Deletes all the linse that should be removed where the 
condition is that all the blocks fill the width of the
game screen for that particular row.
--------------------------------------------------------
*/
void Board::DeletePossibleLines()
{
	for (int row = 0; row < BOARD_HEIGHT; row++)
	{
		int col = 0;
		while (col < BOARD_WIDTH)
		{
			if (mBoard[col][row] != POS_FILLED) break;
			col++;
		}

		if (col == BOARD_WIDTH) 
		{
			DeleteLine(row);
		}
	}
}

/*
-----------------------------------------------------------------------
Returns 1 (true) if this block of the board is empty, 0 if it is filled

Parameters:
pX -> Horizontal position in blocks
pY -> Vertical position in blocks
-----------------------------------------------------------------------
*/
bool Board::IsFreeBlock(int pX, int pY)
{
	mBoard[pX][pY] == POS_FREE ? true : false;
}

// Find the pixels to print to on screen.

/*
-----------------------------------------------------------------------
Returns the horizontal position (in pixels) of the block given
the horizontal position.

Parameters:
pPos -> Horizontal position of the block in the board.
-----------------------------------------------------------------------
*/
int Board::GetXPosInPixels(int pPos) 
{
	return ((BOARD_POSITION - (BLOCK_SIZE * (BOARD_WIDTH / 2))) + (pPos * BLOCK_SIZE));
}

/*
-----------------------------------------------------------------------
Returns the vertical position (in pixels) of the block given
the vertical position.

Parameters:
pPos -> Vertical position of the block in the board.
-----------------------------------------------------------------------
*/
int Board::GetYPosInPixels(int pPos)
{
	return ((mScreenHeight - (BLOCK_SIZE * BOARD_HEIGHT)) + (pPos * BLOCK_SIZE));
}

/*
Will be implemented later in the main loop to check if the movement of a piece is possible or not.
The method compares all the blocks of a piece with the blocks already stored in the board and with
the board limits. That comparison is made by iterating through the piece matrix and comparing with
the appropriate 5x5 area in the board. If there is a collision, that means the movement is not
possible, so it returns false. If there is no collision, the movement is possible and it returns
true.
*/

/*
-----------------------------------------------------------------------
Checks if the piece can be stored at this position without any collision.
Returns true if the movement is possible, otherwise false.

Parameters:
pX -> Horizonal position in blocks.
pY -> Vertical position in blocks.
pPiece -> Piece to draw.
pRotation -> 1 of 4 possible rotations
-----------------------------------------------------------------------
*/
bool Board::IsPossibleMovement(int pX, int pY, int pPiece, int pRotation)
{
	for (int i1 = pX, i2 = 0; i1 < pX + PIECE_BLOCKS; i1++, i2++)
	{
		for (int j1 = pY, j2 = 0; j1 < pY + PIECE_BLOCKS; j1++, j2++)
		{
			// Check if the piece is outside the limits of the board.
			if (i1 < 0 || i1 > BOARD_WIDTH - 1 || j1 > BOARD_HEIGHT - 1)
			{
				if (mPieces->GetBlockType(pPiece, pRotation, j2, i2) != 0)
				{
					return 0;
				}
			}

			if (j1 >= 0)
			{
				if ((mPieces->GetBlockType(pPiece, pRotation, j2, i2) != 0) && (!IsFreeBlock(i1, j1)))
				{
					return false;
				}
			}
		}
	}

	// No collison occurred.
	return true;
}