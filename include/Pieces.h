#ifndef _PIECES_
#define _PIECES_

class Pieces
{
public:

	int GetBlockType(int pPieces, int pRotation, int pX, int pY);
	int GetXInitialPosition(int pPiece, int pRotation);
	int GetYInitialPosition(int pPiece, int pRotation);
};
#endif // !_PIECES_

