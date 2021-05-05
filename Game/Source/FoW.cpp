#include "FoW.h"

#include "App.h"
#include "Log.h"
#include "Textures.h"
#include "Render.h"
#include "Fonts.h"
#include "Map.h"

void FoW::LoadFog()
{
	app->map->GetSize(w, h);

	for (int y = 0; y < h; ++y)
	{
		for (int x = 0; x < w; ++x)
		{
			FoWTiles* tile = new FoWTiles;
			tile->position = app->map->MapToWorld(x, y);
			tile->state = State::COVERED;
			fogTiles.Add(tile);
		}
	}
}

void FoW::FogDraw()
{
	for (int i = 0; i < fogTiles.Count(); ++i)
	{
		switch (fogTiles.At(i)->data->state)
		{
		case COVERED:
			app->render->DrawRectangle({ fogTiles.At(i)->data->position.x, fogTiles.At(i)->data->position.y, 32, 32 }, 0, 0, 0, 255);
			break;
		case TRANSLUCID:
			app->render->DrawRectangle({ fogTiles.At(i)->data->position.x, fogTiles.At(i)->data->position.y, 32, 32 }, 0, 0, 0, 150);
			break;
		case UNCOVERED:
			break;
		}
	}
}

void FoW::FogUpdate(int x, int y, int radius)
{
	iPoint pos = { x / 32, y / 32};

	for (int i = 0; i < fogTiles.Count(); ++i)
	{
		if (pos.x == (fogTiles.At(i)->data->position.x / 32) && 
			pos.y == (fogTiles.At(i)->data->position.y / 32))
		{
			fogTiles.At(i - 80)->data->state = UNCOVERED;
			fogTiles.At(i - 39)->data->state = UNCOVERED;
			fogTiles.At(i - 40)->data->state = UNCOVERED;
			fogTiles.At(i - 41)->data->state = UNCOVERED;
			fogTiles.At(i - 2)->data->state = UNCOVERED;
			fogTiles.At(i - 1)->data->state = UNCOVERED;
			fogTiles.At(i)->data->state = UNCOVERED;
			fogTiles.At(i + 1)->data->state = UNCOVERED;
			fogTiles.At(i + 2)->data->state = UNCOVERED;
			fogTiles.At(i + 39)->data->state = UNCOVERED;
			fogTiles.At(i + 40)->data->state = UNCOVERED;
			fogTiles.At(i + 41)->data->state = UNCOVERED;
			fogTiles.At(i + 80)->data->state = UNCOVERED;
		}

		else if ((pos.x != (fogTiles.At(i)->data->position.x / 32) ||
				pos.y != (fogTiles.At(i)->data->position.y / 32)) &&
				fogTiles.At(i)->data->state == UNCOVERED)
		{
			fogTiles.At(i)->data->state = TRANSLUCID;
		}
	}
}
