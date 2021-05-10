
# Fog of War Research

Hello! This is Ignasi Pardo, a student of the Degree in Videogame Design and Development at CITM, who has been commissioned to carry out this small personal project in search of the creation of a functional Fog of War system.  

The main goal is to provide a reliable, easy-to-use and easy-to-understand solution in C ++.

Click [here]() to download the latest release, which provides an executable with the final result and two projects, the one containing the exercises and the one containing the solutions.

---

## Index
1. Fog of War Game Concept
	- What is the Fog of War in video games?
	- Parts of the Fog of War
	- How it affects the Main Gameplay
	- Are there different types of Fog?
2. History: The Fog of War through time
	- Origins
	- First Games
	- Evolution
	- Present
3. My Personal Approach
4. Other Approaches
5. Implementation
	- Pillars of the Implementation
6. Code Implementation Exercises
7. Social Media
8. License

---

## Fog of War Game Concept

### What is the Fog of War in video games?
The concept of Fog of War is, in essence, a layer that hides the areas of a map or scenario that the players have not yet visited and that are therefore unknown to them. It is generally used in strategy or role-playing games, where they can move around the map in screen, in order to hide the enemy's position, treasures, hidden areas or simply, terrain. Even so, these elements are usually hidden again once they have left the player's field of vision. Therefore, we can differentiate 3 states of the Fog of War.

#### Parts of the Fog of War: 
- **The Revealed Area**: Field of view according to the player's position.
- **The Fog of War**: Translucent area that usually shows players the terrain, but where the items mentioned above are hidden underneath.
- **The Black Mask**: The completely dark area that has yet to be discovered by players.
![Fog of War parts](https://raw.githubusercontent.com/KuronoaScarlet/ResearchFogOfWar/master/docs/images/Fogofwar_parts.jpg)

### How it affects the Main Gameplay?
In RPG or Strategy games, the Fog of War plays a really important role in terms of gameplay, but it also offers players a greater experience and immersion when it comes to exploring the map, since it would not be the same to play Age of Empires knowing absolutely all the movements of your rivals, or it would not be the same to explore a dungeon of any game knowing the position of all the treasures.  This is how the exploration takes on a real meaning behind the screen, offering a surprise factor and the tension of not knowing what you will find when you take the next step, as a player.
### Are there different types of Fog?
Since the objective of the Fog of War is to limit the player's field of vision, it is obvious that the variety of different types and ways of applying this system is enormous. In many cases they tend to be very similar, but in others a single change makes the difference with respect to the other games, opening an even greater spectrum of possibilities. That is why the objective of this Research is to provide you with an easy to use and modify system, so that through your ideas and creativity you can adapt the code and develop a fog according to your game standards.


## History: The Fog of War through time

### Origins
The word expression Fog of War comes from the limitation of the Field of View in the military conflict, the word "fog" expresses uncertainty in war and was introduced first by the Prussian military analyst Carl von Clausewitz in his posthumously published book, Vom Kriege (1832).

At the beginning of the video game industry, developers thought about capabilities that they could not afford before, hiding information from the player is one of them.

### First Games
The first registered game that actually used the Fog Of War was [**_Empire_**](https://www.youtube.com/watch?v=sH8eqPnSSEo) by _Walter Bright_. Another example is **_Tanktics_** by _Chris Crawford_. But this last one was criticized for its unreliable and "confusing" Fog of War system.
![Empire by Walter Bright](https://raw.githubusercontent.com/KuronoaScarlet/ResearchFogOfWar/master/docs/images/maxresdefault.jpg)

### Evolution
Two large _[**Blizzard**](https://en.wikipedia.org/wiki/Blizzard_Entertainment)_ franchises, _[**Warcraft**](https://en.wikipedia.org/wiki/Warcraft)_ and _[**StarCraft**](https://en.wikipedia.org/wiki/StarCraft)_, started to use a fog of war which only reveals terrain features and enemy units through a player's reconnaissance. Without a unit actively observing, previously revealed areas of the map are subject to a shroud through which only terrain is visible, but changes in enemy units or bases are not. This is also common in both turn-based and real-time strategy games, such as the , [**_Age of Empires_ series**](https://en.wikipedia.org/wiki/Age_of_Empires_(series)),  [**_Advance Wars_ series**](https://en.wikipedia.org/wiki/Wars_(series)), [**_Fire Emblem_ series** ](https://en.wikipedia.org/wiki/Fire_Emblem_(series)) and [**_Civilization_ series**](https://en.wikipedia.org/wiki/Civilization_(series)).

![Starcraft Fog example](https://raw.githubusercontent.com/KuronoaScarlet/FoW-Research/master/docs/images/starcraft-fog-of-war-1024x574.png)

![Fire Emblem Fog example](https://raw.githubusercontent.com/KuronoaScarlet/FoW-Research/master/docs/images/16-FE5_%282%29016.png)

![Age of Empires Fog example](https://raw.githubusercontent.com/KuronoaScarlet/FoW-Research/master/docs/images/Nightfall.png)

### Present
Over time, all these examples have been consolidated into much more solid proposals that present much more dynamism than their predecessors. There are many examples on the market, but [**_Forager_**](https://store.steampowered.com/app/751780/Forager/), [**_League of Legends_**](https://en.wikipedia.org/wiki/League_of_Legends),  [**_Among Us_**]() or even [**_Battlefield_ series**](https://en.wikipedia.org/wiki/Battlefield_(video_game_series)) show how the correct use of this tool can take immersion to another level.

![Forager Fog example](https://raw.githubusercontent.com/KuronoaScarlet/FoW-Research/master/docs/images/Forager-Review-Screenshot-18.jpg)

![League of Legends Fog example](https://raw.githubusercontent.com/KuronoaScarlet/FoW-Research/master/docs/images/sr_fow_2.jpg)


## My Personal Approach
To get my personal approach right, I looked closely at the fog behaviors of some of the examples shown above. Assuming that the project is carried out on a skeleton that generates the maps by Tiles, I made the following decisions: 
- The fog had to be displayed on a tile-based map. 
- As a direct example I took that of the strategy games **Fire Emblem**, **Advance Wars** or **Age of Empires**, since they are really simple examples and close to the fog of war that could be implemented in an RPG. 

In these examples, the fog of war spreads throughout the map as soon as the game begins, and it is through the units that the player controls that the part of the map that has been discovered is visible. In addition, enemies are only visible when they are located on the revealed area of the map, and they hide again when they leave the field of vision. Thus, the key points to keep in mind are the following:
- Fog is cleared based on the player's viewing area. 
- Enemies only appear or are visible when hovering over the revealed area. 
- The area reveal function must be usable by more than one entity. The reasons may be whatever, but this adds more dynamism to the clearing of the mists and can be used for the use of perks that increase the vision ranges of certain entities.

### Advantages
- Just one container for the Fog of War need to be created, regardless of what the number of players is.
-  Adjusting the radius is just changing a parameter, everything will work equally.
- The programmer knows exactly what tiles are beeing visited without any extra calculations. (good for hiding stuff).
- We just need an SDL function to draw the fog.

### Drawbacks
- The jagged edges are not solved.
- Constant iterations are performed and performance can drop in some cases.


## Other Approaches.
My research is not limited to observing games, taking notes and thinking which is the best way to perform some actions; I also looked for solutions raised by other users, and many of them allowed me to refine the main idea that I wanted to carry out. Take a look at [this implementation method](https://stackoverflow.com/questions/13654753/sdl-drawing-negative-circles-fog-of-war) in case you are not using a Tile-Based map. All credits to Emartel.

![Emartel example of FoW implementation](https://raw.githubusercontent.com/KuronoaScarlet/FoW-Research/master/docs/images/jkxS5.png)


## Implementation
My personal implementation of the Fog of War System consists of only 4 processes, capable of generating and working all the logic behind each Tile hidden under the fog.

### Pillars of the Implementation
- **Save the necessary information**: Before we start loading the mist, we must know where to create it. When we use a tile-based map as a base, we must know the size of the map and the tiles, and in the case of tiles, we must also save the position of each of them to be able to hide them properly. In addition, the correct thing to do would be to save in said system the states in which the tiles will be found, to be able to update the tiles later without much problem. Therefore, the first challenge will be to create this class and this information container.
- **Generate the Fog**: The simplest part of all, generating the fog only consists of drawing squares with the functions that SDL provides on each tile. In this way we will completely hide the map.  Be careful with the drawing order!
- **Update the Fog depending on the Unit you want**: It is in this third challenge that the real challenge of the Fog of War is found. With a function we must be able to generate an area of vision around our player (use some int variable called radius or something similar in order to always control the size of the field of vision), and as we discover the map, darken the tiles that are outside our visible field. For this it is advisable to use the player's position with respect to the vision radius and the status box loaded in the first step to designate the alpha of the tiles to be drawn.
	- **Logic behing Tiles**: 
``` Covered Tiles --> Uncovered Tiles <--> Translucent Tiles ```
- **Hide enemies behind Translucent Tiles**: The fourth and final challenge is to hide enemies based on the player's viewing distance. Using the radius of the function to update the fog should be enough to designate whether the entity is drawn or not.

## Code Implementation Exercises
When you download the release or source code of the project, you will access a handout with various TODO's so that you can create your own Fog of War on your own and with the help of the comments. As soon as you get the Visual Studio project, if you compile, this should come out:

![TODO1 Expected Result](https://raw.githubusercontent.com/KuronoaScarlet/ResearchFogOfWar/master/docs/images/TODO1expres.png)


As you can see, there is a map where you can move, the player and three goblins that will do the job of being "enemies". 

### TODO 1: Create the necessary Variables and Info Containers
#### TODO 1.0: 
Create a structure to contain vital information about tiles and other key variables. Initialize said structure as an Array.
```Example:
struct FoWTiles
{
	Position
	State
}; 
```

#### TODO 1.1: 
Create the Tiles status box. 
```Example:
enum State
{
	STATE_1,
	STATE_2,
	STATE_3,
	.
	.
	. 
	STATE_N
};
```
### TODO 2: Load the Fog of War into an array with all the info created previously 
#### TODO 2.0: 
Declare the function to Load the Fog of War. No arguments required!
#### TODO 2.1: 
Create a dynamic FoWTiles array with the size of the Tiles Map.
#### TODO 2.2: 
Make a loop that saves the position of each tile in the world, and initializes its state to "covered" by default. 

### TODO 3: Create a function that allows the fog to be drawn on the tiles 
#### TODO 3.0: 
Declare the function for drawing the Fog of War. No arguments required! 
#### TODO 3.1: 
Make a loop that goes through all the tiles. Depending on its state, a square with more or less Alpha should be drawn (Recommended: Covered -> 255, Translucent -> ~ 128/150). I also recommend the use of a Switch to permute between every State (following the logic).

### TODO 4: Add the loading and drawing functions of the fog in the scene we want to cover (Scene1.cpp) 
#### TODO 4.0: 
Call the function to Load the Fog of War (Start()). 
#### TODO 4.1: 
Call the function to draw the Fog of War (PostUpdate()). 

From here you should be able to observe the effects of drawing the tiles. When compiling, you should only see a black screen. You can change the Update function FogDraw () to draw under the entities and check that you really got it! 

![TODO4 Expected Result](https://raw.githubusercontent.com/KuronoaScarlet/ResearchFogOfWar/master/docs/images/TODO4expres.png)


### TODO 5: It's time to implement the magic! We must create the function to clear the fog around the player. Cheer up! 
#### TODO 5.0: 
Declare the function to update the Fog of War based on an entity. Arguments required (Entity position and radius)! 
#### TODO 5.1: 
Implement the magic. (Save the position of the entity for Tiles, iterate the array, and with the use of the radius discover the tiles around the entity!). Remember to save the radius in a variable accessible from FoW. It will serve us later! 
#### TODO 5.2: 
Call the update function to discover the tiles in question (PlayerEntity.cpp). 

Expected results:

![TODO5 Expected Result](https://raw.githubusercontent.com/KuronoaScarlet/ResearchFogOfWar/master/docs/images/TODO5expres.png)


### TODO 6: Hide the Enemies behind the Translucent Tiles!
#### TODO 6.0: 
Declare the function to hide enemies under the Fog of War. Arguments required (Entity position)!
#### TODO 6.1: 
Similar to the Mist update. This time, but, it returns the value of the distance between the player and the entity in question.
#### TODO 6.2: 
Call the hide enemies function (Enemy.cpp).
#### TODO 6.3: 
Logic after drawing: If it is inside the player's FoV, it is shown; otherwise it is not drawn (Enemy.cpp).

Expected Results:
[![TODO 6 Expected Results](https://youtu.be/Xxrg9xjK3aE)


## Social Media
You can follow me and ocassionally my work from:
- [Twitter](https://twitter.com/KuronoaScarlet)
- [Github](https://github.com/KuronoaScarlet)
- [Twitch](https://twitch.tv/Kuronoa_Scarlet)

## License

This project is licensed under an unmodified MIT license, which is an OSI-certified license that allows static linking with closed source software. Check [LICENSE](LICENSE) for further details.
