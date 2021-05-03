#ifndef __SCENE1_H__
#define __SCENE1_H__

#include "Module.h"
#include "Animation.h"
#include "Timer.h"
#include "Title.h"
#include "GuiButton.h"
#include "GuiCheckBox.h"

class GuiCheckBox;
class GuiButton;
class GuiControl;

class Scene1 : public Module
{
public:

	Scene1();

	// Destructor
	virtual ~Scene1();

	// Called before render is available
	bool Awake();

	// Called before the first frame
	bool Start();

	// Called before all Updates
	bool PreUpdate();

	// Called each loop iteration
	bool Update(float dt);

	// Called before all Updates
	bool PostUpdate();

	// Called before quitting
	bool CleanUp();

	bool OnGuiMouseClickEvent(GuiControl* control)
	{
		app->title->OnGuiMouseClickEvent(control);
		return true;
	}

	bool firstEntry = true;
};


#endif // __SCENE1_H__