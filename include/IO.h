#ifndef _IO_
#define _IO_

#ifndef LINUX
#include "../../SDL/include/SDL.h"
#include "../../SDL/SDL_GfxPrimitives/SDL_gfxPrimitives.h"
#else
#include "../../SDL/include/SDL.h"
#include "../../SDL/SDL_GfxPrimitives/SDL_gfxPrimitives.h"
#endif // !LINUX

#pragma comment (lib, "../../../SDL/lib/SDL.lib")
#pragma comment (lib, "../../../SDL/SDL_GfxPrimitives/SDL_GfxPrimitives_Static.lib")

// Colors.
enum color {BLACK, RED, GREEN, BLUE, CYAN, MAGENTA, YELLOW, WHITE, COLOR_MAX};

// Class.
class IO
{
public:
	IO();

	void DrawRectangle(int pX1, int pY1, int pX2, int pY2, enum color pC);
	void boxColor(SDL_Surface* screen, int pX1, int pY1, int pX2, int pY2, Uint32 color);
	void ClearScreen();
	int GetScreenHeight();
	int InitGraph();
	int Pollkey();
	int Getkey();
	int IsKeyDown(int pKey);
	void UpdateScreen();
};


#endif // !_IO_

