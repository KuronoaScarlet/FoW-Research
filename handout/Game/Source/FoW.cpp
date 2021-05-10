#include "FoW.h"

#include "App.h"
#include "Log.h"
#include "Textures.h"
#include "Render.h"
#include "Fonts.h"
#include "Map.h"
#include "EntityManager.h"

//void FoW::FogLoad()
//{
//	//TODO 2.1: Create a dynamic FoWTiles array with the size of the Tiles Map.
//
//
//	//TODO 2.2:Make a loop that saves the position of each tile in the world, and initializes its state to "covered" by default. 
//	
//}
//
//void FoW::FogDraw()
//{
//	//TODO 3.1: Make a loop that goes through all the tiles. Depending on its state, a square with more or less Alpha should be drawn (Recommended: Covered -> 255, Translucent -> ~ 128/150) 
//	
//}
//
//void FoW::FogUpdate(int x, int y, int radius)
//{
//	//TODO 5.1: Implement the magic. (Save the position of the entity for Tiles, iterate the array, and with the use of the radius discover the tiles around the entity!) 
//	//Remember to save the radius in a variable accessible from FoW. It will serve us later! 
//}
//
//int FoW::EntityHidden(float x, float y)
//{
//	//TODO 6.1: Similar to the Mist update. This time, but, it returns the value of the distance between the player and the entity in question. 
//	
//}
