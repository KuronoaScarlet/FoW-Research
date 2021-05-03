#include "App.h"
#include "Input.h"
#include "Textures.h"
#include "Audio.h"
#include "Render.h"
#include "Window.h"
#include "Collisions.h"
#include "Map.h"
#include "Animation.h"
#include "Title.h"
#include "FadeToBlack.h"
#include "Scene1.h"
#include "EntityManager.h"
#include "Fonts.h"

#include "Defs.h"
#include "Log.h"

Title::Title() : Module()
{
    name.Create("Logo");
}

Title::~Title()
{

}

bool Title::Awake()
{
    LOG("Loading Logo");
    bool ret = true;

    return ret;
}

// Load assets
bool Title::Start()
{
    LOG("Loading Logo assets");

    bool ret = true;

    pugi::xml_parse_result result = app->saveLoadFile.load_file("save_game.xml");
    if (result != NULL)
    {
        app->saveLoadNode = app->saveLoadFile.child("save");
        app->fileSaved = true;
    }
    if (result == NULL)
    {
        app->fileSaved = false;
    }

    screen = app->tex->Load("Assets/Textures/Screens/title_screen.png");
    app->audio->PlayMusic("Assets/Audio/Music/menu_music.ogg");

    play = new GuiButton(1, { 517, 304, 240, 60 }, "PLAY");
    play->SetObserver(this);
    play->SetTexture(app->tex->Load("Assets/Textures/newgame.png"), app->tex->Load("Assets/Textures/newgame_selected.png"), app->tex->Load("Assets/Textures/newgame_pressed.png"));
    
    load = new GuiButton(2, { 517, 370, 234, 55 }, "LOAD");
    load->SetObserver(this);
    load->SetTexture(app->tex->Load("Assets/Textures/continue.png"), app->tex->Load("Assets/Textures/continue_selected.png"), app->tex->Load("Assets/Textures/continue_pressed.png"));
    
    exit = new GuiButton(3, { 580, 569, 117, 55 }, "EXIT");
    exit->SetObserver(this);
    exit->SetTexture(app->tex->Load("Assets/Textures/exit.png"), app->tex->Load("Assets/Textures/exit_selected.png"), app->tex->Load("Assets/Textures/exit_pressed.png"));

    credits = new GuiButton(4, { 551, 514, 172, 55 }, "CREDITS");
    credits->SetObserver(this);
    credits->SetTexture(app->tex->Load("Assets/Textures/credits.png"), app->tex->Load("Assets/Textures/credits_selected.png"), app->tex->Load("Assets/Textures/credits_pressed.png"));

    back = new GuiButton(5, { 40, 20, 200, 100 }, "ESC");
    back->SetObserver(this);
    back->SetTexture(app->tex->Load("Assets/Textures/esc.png"), app->tex->Load("Assets/Textures/esc2.png"), app->tex->Load("Assets/Textures/esc3.png"));


    creditSceneFlag = false;
    fullSc = false;
    vsync = true;
    exitGame = false;

    app->render->camera.x = 0;

    return ret;
}

bool Title::PreUpdate()
{
    return true;
}

bool Title::Update(float dt)
{
    if (creditSceneFlag == false)
    {
        play->Update(app->input, dt);
        load->Update(app->input, dt);
        credits->Update(app->input, dt);
        exit->Update(app->input, dt);
    }
    if (creditsOnScreen)
    {
        back->Update(app->input, dt);
    }
    if (app->input->GetKey(SDL_SCANCODE_ESCAPE) == KEY_DOWN)
    {
        creditSceneFlag = false;
        creditsOnScreen = false;
    }

    return true;
}

// Update: draw background
bool Title::PostUpdate()
{
    bool ret = true;

   // Draw everything --------------------------------------
    if (app->input->GetKey(SDL_SCANCODE_SPACE) == KEY_DOWN)
    {
        app->fade->Fade(this, (Module*)app->scene1, 10);

    }
    if (!creditSceneFlag)
    {
        
        app->render->camera.y = 0;
        app->render->DrawTexture(screen, 0, 0, NULL);

        play->Draw(app->render);
        load->Draw(app->render);
        credits->Draw(app->render);
        exit->Draw(app->render);
    }

    if (exitGame == true)
    {
        return false;
    }
    
    return ret;
}

bool Title::CleanUp()
{
    if (!active)return true;
    LOG("Freeing Logo");
    app->title->active = false;
    app->tex->UnLoad(screen);
    return true;
}

bool Title::OnGuiMouseClickEvent(GuiControl* control)
{
    switch (control->type)
    {
    case GuiControlType::BUTTON:
    {
        if (control->id == 2)
        {
            //LoadGame
            app->loadingGame = true;
            pugi::xml_document savedGame;
            savedGame.load_file("save_game.xml");

            pugi::xml_node generalNode = savedGame.child("save");
            pugi::xml_node map = generalNode.child("map");
            app->map->LoadState(map);

            if (app->currentLevel == 1) app->fade->Fade((Module*)app->title, (Module*)app->scene1, 10);
        }
        else if (control->id == 2)
        {
            //Exit
            app->title->exitGame = true;
        }
    }
    case GuiControlType::SLIDER:
    {

    }
    case GuiControlType::CHECKBOX:
    {
 
    }
    default: break;
    }

    return true;
}