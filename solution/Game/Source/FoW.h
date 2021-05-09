#ifndef _FOW_H_
#define _FOW_H_

#include "Point.h"
#include "List.h"

class FoW
{
public:
	//Constructor
	FoW() { }

	//Destructor
	~FoW() {}

	void FogLoad();
	void FogDraw();
	void FogUpdate(int x, int y, int radius);
	int EntityHidden(float x, float y);


public:
	enum State
	{
		COVERED,
		TRANSLUCENT,
		UNCOVERED
	};

	struct FoWTiles
	{
		iPoint position;

		int state = 0;
	};

	uint w, h;
	uint size;
	int fieldOfView;
	bool hide;

	FoWTiles* fogTiles;
};

#endif //_FOW_H_