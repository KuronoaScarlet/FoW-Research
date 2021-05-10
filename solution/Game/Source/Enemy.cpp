#include "Enemy.h"
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
#include "FoW.h"

Enemy::Enemy(Module* listener, fPoint position, SDL_Texture* texture, Type type) : Entity(listener, position, texture, type)
{
	idleAnimation.loop = true;
	idleAnimation.PushBack({ 0, 0, 35, 31 });
	idleAnimation.PushBack({ 38, 0, 35, 31 });
	idleAnimation.PushBack({ 76, 0, 35, 31 });
	idleAnimation.PushBack({ 114, 0, 35, 31 });
	idleAnimation.PushBack({ 152, 0, 35, 31 });
	idleAnimation.PushBack({ 190, 0, 35, 31 });
	idleAnimation.PushBack({ 228, 0, 35, 31 });
	idleAnimation.PushBack({ 266, 0, 35, 31 });
	idleAnimation.speed = 0.2f;
	currentAnimation = &idleAnimation;
}

bool Enemy::Start()
{
	return false;
}

bool Enemy::Update(float dt)
{
	currentAnimation->Update();

	return false;
}

bool Enemy::Draw()
{
	SDL_Rect enemyRect = currentAnimation->GetCurrentFrame();
	//TODO 6.2: Call the hide enemies function.
	float d = app->fog->EntityHidden(position.x, position.y);
	//TODO 6.3: Logic after drawing: If it is inside the player's FoV, it is shown; otherwise it is not drawn. 
	if ( d < app->fog->fieldOfView)
	{
		app->render->DrawTexture(texture, position.x, position.y, &enemyRect);
	}

	return false;
}

void Enemy::Collision(Collider* coll)
{

}

void Enemy::CleanUp()
{

}
