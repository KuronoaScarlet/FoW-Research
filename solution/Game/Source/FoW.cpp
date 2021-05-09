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
	app->map->GetSize(w, h);
	size = w * h;
	fogTiles = new FoWTiles[size];

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
	fPoint pos = { (x + 16) / 32, (y + 16) / 32 };
	fPoint dt = { (app->entityManager->playerData.position.x + 16) / 32, (app->entityManager->playerData.position.y + 16) / 32 };

	float d = pos.DistanceTo(dt);
	return d;
}
