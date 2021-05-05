#include "FoW.h"

#include "App.h"
#include "Log.h"
#include "Textures.h"
#include "Render.h"
#include "Fonts.h"
#include "Map.h"

FoW::FoW()
{
	name.Create("FogOfWar");
}

bool FoW::Awake()
{
	return true;
}

bool FoW::Start()
{
	return true;
}

bool FoW::Update()
{
	return true;
}

bool FoW::PostUpdate()
{
	return true;
}

bool FoW::CleanUp()
{
	return true;
}

void FoW::LoadFog()
{
	uint w, h;
	app->map->GetSize(w, h);

	for (int y = 0; y < h; ++y)
	{
		for (int x = 0; x < w; ++x)
		{
			FoWTiles* tile = new FoWTiles;
			tile->position = app->map->MapToWorld(x, y);
			fogTiles.Add(tile);
		}
	}
}