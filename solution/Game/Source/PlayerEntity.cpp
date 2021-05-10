#include "PlayerEntity.h"
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

PlayerEntity::PlayerEntity(Module* listener, fPoint position, SDL_Texture* texture, Type type) : Entity(listener, position, texture, type)
{
	idleAnimation.loop = true;
	idleAnimation.PushBack({ 88, 0, 26, 38 });
	idleAnimation.speed = 0.01f;

	walkAnimationRight.loop = true;
	walkAnimationRight.speed = 0.15f;
	walkAnimationRight.PushBack({ 0, 0, 28, 38 });
	walkAnimationRight.PushBack({ 30, 0, 28, 38 });
	walkAnimationRight.PushBack({ 60, 0, 26, 38 });
	walkAnimationRight.PushBack({ 88, 0, 26, 38 });
	walkAnimationRight.PushBack({ 116, 0, 26, 38 });
	walkAnimationRight.PushBack({ 144, 0, 26, 38 });
	walkAnimationRight.PushBack({ 172, 0, 28, 38 });
	walkAnimationRight.PushBack({ 200, 0, 28, 38 });

	walkAnimationLeft.loop = true;
	walkAnimationLeft.speed = 0.15f;
	walkAnimationLeft.PushBack({ 0, 40, 28, 38 });
	walkAnimationLeft.PushBack({ 30, 40, 28, 38 });
	walkAnimationLeft.PushBack({ 60, 40, 26, 38 });
	walkAnimationLeft.PushBack({ 88, 40, 26, 38 });
	walkAnimationLeft.PushBack({ 116, 40, 26, 38 });
	walkAnimationLeft.PushBack({ 144, 40, 26, 38 });
	walkAnimationLeft.PushBack({ 172, 40, 28, 38 });
	walkAnimationLeft.PushBack({ 200, 40, 28, 38 });

	currentAnimation = &idleAnimation;

	collider = app->collisions->AddCollider(SDL_Rect({ (int)position.x, (int)position.y, 20, 30 }), Collider::Type::PLAYER, listener);
}

bool PlayerEntity::Start()
{
	return true;
}

bool PlayerEntity::Update(float dt)
{
	tempPlayerPosition = position;

	//PlayerData Info Containers
	app->entityManager->playerData.position.x = position.x;
	app->entityManager->playerData.position.y = position.y;

	app->render->camera.x = -position.x + (SCREEN_WIDTH/2);
	app->render->camera.y = -position.y + (SCREEN_HEIGHT/2);

	//printf_s("%.0f, %.0f   -   %d, %d\n", position.x, position.y, app->render->camera.x, app->render->camera.y);

	//Player Movement
	float speed = (godMode) ? 200 : 70;

	if (app->input->GetKey(SDL_SCANCODE_A) == KEY_IDLE
		&& app->input->GetKey(SDL_SCANCODE_D) == KEY_IDLE
		&& app->input->GetKey(SDL_SCANCODE_W) == KEY_IDLE
		&& app->input->GetKey(SDL_SCANCODE_S) == KEY_IDLE)
	{
		if (currentAnimation != &idleAnimation)
		{
			idleAnimation.Reset();
			currentAnimation = &idleAnimation;
		}
	}

	if (app->input->GetKey(SDL_SCANCODE_A) == KEY_REPEAT)
	{
		position.x -= speed * dt;
		if (currentAnimation != &walkAnimationLeft && app->input->GetKey(SDL_SCANCODE_W) != KEY_REPEAT && app->input->GetKey(SDL_SCANCODE_S) != KEY_REPEAT)
		{
			walkAnimationLeft.Reset();
			currentAnimation = &walkAnimationLeft;
		}
	}
	if (app->input->GetKey(SDL_SCANCODE_D) == KEY_REPEAT)
	{
		position.x += speed * dt;
		if (currentAnimation != &walkAnimationRight && app->input->GetKey(SDL_SCANCODE_W) != KEY_REPEAT && app->input->GetKey(SDL_SCANCODE_S) != KEY_REPEAT)
		{
			walkAnimationRight.Reset();
			currentAnimation = &walkAnimationRight;
		}
	}
	if (app->input->GetKey(SDL_SCANCODE_W) == KEY_REPEAT)
	{
		position.y -= speed * dt;
		if (currentAnimation != &walkAnimationRight)
		{
			walkAnimationRight.Reset();
			currentAnimation = &walkAnimationRight;
		}
	}
	if (app->input->GetKey(SDL_SCANCODE_S) == KEY_REPEAT)
	{
		position.y += speed * dt;
		if (currentAnimation != &walkAnimationLeft)
		{
			walkAnimationRight.Reset();
			currentAnimation = &walkAnimationLeft;
		}
	}
	if (app->input->GetKey(SDL_SCANCODE_F10) == KEY_DOWN)
	{
		godMode = !godMode;
	}
	if (app->input->GetKey(SDL_SCANCODE_R) == KEY_DOWN)
	{
		app->fog->FogLoad();
	}

	if (app->input->GetKey(SDL_SCANCODE_F5) == KEY_DOWN) app->SaveGameRequest();
	if (app->input->GetKey(SDL_SCANCODE_F6) == KEY_DOWN) app->LoadGameRequest();

	currentAnimation->Update();
	collider->SetPos(position.x+4,position.y+6);

	//TODO 5.2: Call the update function to discover the tiles in question. 
	app->fog->FogUpdate((int)position.x + 16, (int)position.y + 16, radius);
	
	return true;
}

bool PlayerEntity::Draw()
{
	SDL_Rect playerRect = currentAnimation->GetCurrentFrame();
	app->render->DrawTexture(texture, position.x, position.y, &playerRect);


	return true;
}

void PlayerEntity::Collision(Collider* coll)
{
	if (coll->type == Collider::Type::WALL && godMode == false)
	{
		position = tempPlayerPosition;
	}
}

void PlayerEntity::CleanUp()
{

}