#include "Torch.h"
#include "App.h"
#include "Render.h"
#include "Collisions.h"
#include "Collider.h"
#include "FadeToBlack.h"
#include "Scene1.h"
#include "Map.h"
#include "Audio.h"
#include "EntityManager.h"
#include "Fonts.h"
#include "Defs.h"
#include "Input.h"

Torch::Torch(Module* listener, fPoint position, SDL_Texture* texture, Type type) : Entity(listener, position, texture, type)
{

}

bool Torch::Start()
{
	return false;
}

bool Torch::Update(float dt)
{
	app->fog->FogUpdate(position.x, position.y, 3);
	return false;
}

bool Torch::Draw()
{
	app->render->DrawTexture(texture, position.x, position.y, NULL);

	return false;
}

void Torch::Collision(Collider* coll)
{

}

void Torch::CleanUp()
{

}
