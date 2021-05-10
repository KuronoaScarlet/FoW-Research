#include "FoW.h"

#include "App.h"
#include "Log.h"
#include "Textures.h"
#include "Render.h"
#include "Fonts.h"
#include "Map.h"
#include "EntityManager.h"

void FoW::FogLoad()
{
	//TODO 2.1: Create a dynamic FoWTiles array with the size of the Tiles Map.
	app->map->GetSize(w, h);
	size = w * h;
	fogTiles = new FoWTiles[size];

	//TODO 2.2: Make a loop that saves the position of each tile in the world, and initializes its state to "covered" by default. 
	for (int y = 0; y < h; ++y)
	{
		for (int x = 0; x < w; ++x)
		{
			FoWTiles tile;
			tile.position = app->map->MapToWorld(x, y);
			tile.state = State::COVERED;
			fogTiles[x + y * w] = tile;
		}
	}
}

void FoW::FogDraw()
{
	//TODO 3.1: Make a loop that goes through all the tiles. Depending on its state, a square with more or less Alpha should be drawn (Recommended: Covered -> 255, Translucent -> ~ 128/150) 
	for (int i = 0; i < size; ++i)
	{
		switch (fogTiles[i].state)
		{
		case COVERED:
			app->render->DrawRectangle({ fogTiles[i].position.x, fogTiles[i].position.y, 32, 32 }, 0, 0, 0, 255);
			break;
		case TRANSLUCENT:
			app->render->DrawRectangle({ fogTiles[i].position.x, fogTiles[i].position.y, 32, 32 }, 0, 0, 0, 150);
			break;
		case UNCOVERED:
			fogTiles[i].state = TRANSLUCENT;
			break;
		}
	}
}

void FoW::FogUpdate(int x, int y, int radius)
{
	//TODO 5.1: Implement the magic. (Save the position of the entity for Tiles, iterate the array, and with the use of the radius discover the tiles around the entity!) 
	//Remember to save the radius in a variable accessible from FoW. It will serve us later! 
	iPoint pos = { x / 32, y / 32};
	fieldOfView = radius; 

	for (int i = 0; i < size; ++i)
	{
		iPoint pt = { fogTiles[i].position.x / 32, fogTiles[i].position.y / 32 };
		float d = pt.DistanceTo(pos);

		if (d < radius)
		{
			fogTiles[i].state = UNCOVERED;
		}
	}
}

int FoW::EntityHidden(float x, float y)
{
	//TODO 6.1: Similar to the Mist update. This time, but, it returns the value of the distance between the player and the entity in question. 
	fPoint pos = { (x + 16 / 2) / 32, (y + 16 / 2) / 32 };
	fPoint dt = { (app->entityManager->playerData.position.x + 16 / 2) / 32, (app->entityManager->playerData.position.y + 16 / 2) / 32 };

	float d = pos.DistanceTo(dt);
	return d;
}
