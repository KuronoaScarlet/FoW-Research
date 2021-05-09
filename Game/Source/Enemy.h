#ifndef _ENEMY_H_
#define _ENEMY_H_

#include "Point.h"
#include "Entity.h"
#include "Animation.h"
#include "DynArray.h"

#include "GuiButton.h"

struct SDL_Texture;
struct Collider;

class Enemy : Entity
{
public:
	Enemy(Module* listener, fPoint position, SDL_Texture* texture, Type type);

	bool Start();

	bool Update(float dt);

	bool Draw();

	void Collision(Collider* coll);

	void CleanUp();

private:

	Animation idleAnimation;

	Animation* currentAnimation;
};

#endif
