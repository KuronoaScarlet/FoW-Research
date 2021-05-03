#ifndef __TITLE_H__
#define __TITLE_H__

#include "Module.h"
#include "Animation.h"

#include "GuiButton.h"
#include "GuiSlider.h"
#include "GuiCheckBox.h"

class GuiControl;
class GuiSlider;

struct SDL_Texture;

class Title : public Module
{
public:
    //Constructor
    Title();

    //Destructor
    ~Title();

    bool Awake();

    // Called when the module is activated
    // Loads the necessary textures for the map background
    bool Start();

    bool PreUpdate();

    // Called at the middle of the application loop
    // Updates the scene's background animations
    bool Update(float dt);

    // Called at the end of the application loop.
    // Performs the render call of all the parts of the scene's background
    bool PostUpdate();

    bool CleanUp();

    bool OnGuiMouseClickEvent(GuiControl* control);

public:
    SDL_Texture* screen = nullptr;

    GuiButton* play;
    GuiButton* load;
    GuiButton* exit;
    GuiButton* credits;
    GuiButton* back;

    bool creditSceneFlag;
    
    bool creditsOnScreen = false;
    bool fullSc;
    bool vsync;
    bool exitGame;

};

#endif