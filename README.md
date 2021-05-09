# Fog of War Research

Hello! This is Ignasi Pardo, a student of the Degree in Videogame Design and Development at CITM, who has been commissioned to carry out this small personal project in search of the creation of a functional Fog of War system.  

The main goal is to provide a reliable, easy-to-use and easy-to-understand solution in C ++.

Click [here]() to download the latest release, which provides an executable with the final result and two projects, the one containing the exercises and the one containing the solutions.

## Fog of War Game Concept
### What is the Fog of War in video games?
The concept of Fog of War is, in essence, a layer that hides the areas of a map or scenario that the players have not yet visited and that are therefore unknown to them. It is generally used in strategy or role-playing games, where they can move around the map in screen, in order to hide the enemy's position, treasures, hidden areas or simply, terrain. Even so, these elements are usually hidden again once they have left the player's field of vision. Therefore, we can differentiate 3 states of the Fog of War.
#### Parts of the Fog of War: 
- **The Revealed Area**: Field of view according to the player's position.
- **The Fog of War**: Translucent area that usually shows players the terrain, but where the items mentioned above are hidden underneath.
- **The Black Mask**: The completely dark area that has yet to be discovered by players.
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
### Evolution
Two large [**_Blizzard_**](https://en.wikipedia.org/wiki/Blizzard_Entertainment) franchises, _[**_Warcraft_**](https://en.wikipedia.org/wiki/Warcraft)_ and _[**_StarCraft_**](https://en.wikipedia.org/wiki/StarCraft)_, started to use a fog of war which only reveals terrain features and enemy units through a player's reconnaissance. Without a unit actively observing, previously revealed areas of the map are subject to a shroud through which only terrain is visible, but changes in enemy units or bases are not. This is also common in both turn-based and real-time strategy games, such as the , [**_Age of Empires_ series**](https://en.wikipedia.org/wiki/Age_of_Empires_(series)),  [**_Advance Wars_ series**](https://en.wikipedia.org/wiki/Wars_(series)), [**_Fire Emblem_ series** ](https://en.wikipedia.org/wiki/Fire_Emblem_(series)) and [**_Civilization_ series**](https://en.wikipedia.org/wiki/Civilization_(series)).
### Present
Over time, all these examples have been consolidated into much more solid proposals that present much more dynamism than their predecessors. There are many examples on the market, but [**_Forager_**](https://store.steampowered.com/app/751780/Forager/), [**_League of Legends_**](https://en.wikipedia.org/wiki/League_of_Legends),  [**_Among Us_**]() or even [**_Battlefield_ series**](https://en.wikipedia.org/wiki/Battlefield_(video_game_series)) show how the correct use of this tool can take immersion to another level.

## My Personal Approach
To get my personal approach right, I looked closely at the fog behaviors of some of the examples shown above. Assuming that the project is carried out on a skeleton that generates the maps by Tiles, I made the following decisions: 
- The fog had to be displayed on a tile-based map. 
- As a direct example I took that of the strategy games **Fire Emblem**, **Advance Wars** or **Age of Empires**, since they are really simple examples and close to the fog of war that could be implemented in an RPG. 

In these examples, the fog of war spreads throughout the map as soon as the game begins, and it is through the units that the player controls that the part of the map that has been discovered is visible. In addition, enemies are only visible when they are located on the revealed area of ​​the map, and they hide again when they leave the field of vision. Thus, the key points to keep in mind are the following:
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

## Implementation
My personal implementation of the Fog of War System consists of only 3 processes, capable of generating and working all the logic behind each Tile hidden under the fog.
### Pilars of the Implementation
- **Save the necessary information**: Before we start loading the mist, we must know where to create it. When we use a tile-based map as a base, we must know the size of the map and the tiles, and in the case of tiles, we must also save the position of each of them to be able to hide them properly. In addition, the correct thing to do would be to save in said system the states in which the tiles will be found, to be able to update the tiles later without much problem. Therefore, the first challenge will be to create this class and this information container.
- **Generate the Fog**: The simplest part of all, generating the fog only consists of drawing squares with the functions that SDL provides on each tile. In this way we will completely hide the map.  Be careful with the drawing order!
- **Update the Fog depending on the Unit you want**: It is in this third challenge that the real challenge of the Fog of War is found. With a function we must be able to generate an area of vision around our player (use some int variable called radius or something similar in order to always control the size of the field of vision), and as we discover the map, darken the tiles that are outside our visible field. For this it is advisable to use the player's position with respect to the vision radius and the status box loaded in the first step to designate the alpha of the tiles to be drawn.
- **Logic behing Tiles**: 
 ```mermaid
graph LR
A[Covered Tiles]--> 
B[Uncovered Tiles]-->
C[Translucent Tiles]
C-->B
```
- **Hide enemies behind Translucent Tiles**: The fourth and final challenge is to hide enemies based on the player's viewing distance. Using the radius of the function to update the fog should be enough to designate whether the entity is drawn or not.
## Code Implementation Excercises

## Social Media
You can follow me and ocassionally my work from:
- [Twitter](https://twitter.com/KuronoaScarlet)
- [Github](https://github.com/KuronoaScarlet)
- [Twitch](https://twitch.tv/Kuronoa_Scarlet)

## License

This project is licensed under an unmodified MIT license, which is an OSI-certified license that allows static linking with closed source software. Check [LICENSE](LICENSE) for further details.
