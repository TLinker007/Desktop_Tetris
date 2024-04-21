#ifndef _GAME_
#define _GAME_

#include "Board.h"
#include "Pieces.h"
#include "IO.h"
#include <time.h>

// Number of milliseconds that the piece remains before going 1 block down.
#define WAIT_TIME 700

class Game
{
public:
	Game(Board *pBoard, Pieces *pPieces, IO *pIO, int pScreenHeight);

	void DrawScene();
	void CreateNewPiece();

	// Position of the piece that is falling down.
	int mPosX, mPosY;
	// Kind and rotation of the piece that is falling down.
	int mPiece, mRotation;
	
private:
	// Screen height in pixels.
	int mScreenHeight;
	// Position of the next piece.
	int mNextPosX, mNextPosY;
	// Kind and rotation of the next piece.
	int mNextPiece, mNextRotation;

	Board *mBoard;
	Pieces *mPieces;
	IO *mIO;

	int GetRand(int pA, int pB);
	void InitGame();
	void DrawPiece(int pX, int pY, int pPiece, int pRotation);
	void DrawBoard();
};
#endif // !_GAME_

