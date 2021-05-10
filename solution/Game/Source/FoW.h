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
	////TODO 2
	// TODO 2.0: Declare the function to charge the Fog of War. No arguments required!  
	void FogLoad();
	////

	////TODO 3
	// TODO 3.0: Declare the function for drawing the Fog of War. No arguments required! 
	void FogDraw();
	////

	////TODO 5
	// TODO 5.0: Declare the function to update the Fog of War based on an entity. Arguments required (Entity position and radius)! 
	void FogUpdate(int x, int y, int radius);
	////

	////TODO 6
	// TODO 6.0: Declare the function to hide enemies under the Fog of War. Arguments required (Entity position)! 
	int EntityHidden(float x, float y);


public:
	////TODO 1
	// TODO 1.0: Create a structure to contain vital information about tiles and other key variables. Initialize said structure as an Array 
	struct FoWTiles
	{
		iPoint position;

		int state = 0;
	};

	uint w, h;
	uint size;
	int fieldOfView;
	FoWTiles* fogTiles;

	// TODO 1.1: Create the Tiles status box  
	enum State
	{
		COVERED,
		TRANSLUCENT,
		UNCOVERED
	};
	////


};

#endif //_FOW_H_