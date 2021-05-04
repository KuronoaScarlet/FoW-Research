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
	idleAnimation.PushBack({ 44, 0, 13, 19 });
	idleAnimation.speed = 0.01f;

	walkAnimationRight.loop = true;
	walkAnimationRight.speed = 0.15f;
	walkAnimationRight.PushBack({ 0, 0, 14, 19 });
	walkAnimationRight.PushBack({ 15, 0, 14, 19 });
	walkAnimationRight.PushBack({ 30, 0, 13, 19 });
	walkAnimationRight.PushBack({ 44, 0, 13, 19 });
	walkAnimationRight.PushBack({ 58, 0, 13, 19 });
	walkAnimationRight.PushBack({ 72, 0, 13, 19 });
	walkAnimationRight.PushBack({ 86, 0, 14, 19 });
	walkAnimationRight.PushBack({ 100, 0, 14, 19 });

	walkAnimationLeft.loop = true;
	walkAnimationLeft.speed = 0.15f;
	walkAnimationLeft.PushBack({ 0, 20, 14, 19 });
	walkAnimationLeft.PushBack({ 15, 20, 14, 19 });
	walkAnimationLeft.PushBack({ 30, 20, 13, 19 });
	walkAnimationLeft.PushBack({ 44, 20, 13, 19 });
	walkAnimationLeft.PushBack({ 58, 20, 13, 19 });
	walkAnimationLeft.PushBack({ 72, 20, 13, 19 });
	walkAnimationLeft.PushBack({ 86, 20, 14, 19 });
	walkAnimationLeft.PushBack({ 100, 20, 14, 19 });

	currentAnimation = &idleAnimation;

	collider = app->collisions->AddCollider(SDL_Rect({ (int)position.x, (int)position.y, 10, 15 }), Collider::Type::PLAYER, listener);
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

	//app->render->camera.x = -position.x + (640/2);
	//app->render->camera.y = -position.y + 60;

	//printf_s("%.0f, %.0f   -   %d, %d\n", position.x, position.y, app->render->camera.x, app->render->camera.y);

	//Player Movement
	float speed = (godMode) ? 100 : 50;

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

	if (app->input->GetKey(SDL_SCANCODE_F5) == KEY_DOWN) app->SaveGameRequest();
	if (app->input->GetKey(SDL_SCANCODE_F6) == KEY_DOWN) app->LoadGameRequest();

	currentAnimation->Update();
	collider->SetPos(position.x+2,position.y+3);
	
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
	if (coll->type == Collider::Type::WALL)
	{
		position = tempPlayerPosition;
	}
}

void PlayerEntity::CleanUp()
{

}