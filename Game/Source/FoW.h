#ifndef _FOW_H_
#define _FOW_H_

#include "Point.h"
#include "List.h"

class FoW
{
public:
	//Constructor
	FoW() { }

	//Destructor
	~FoW() {}

	/*
	Función de carga de la niebla.
		Para cargar la niebla hay que seguir ciertos pasos:
			1. Guardar todas las tiles en una lista aparte. esta lista debe contener lo siguiente:
				- Posición de cada tile en el mapa (x, y).
				- El tamaño de los Tiles.
				- Tres estados: Cubiertas, translúcidas, descubiertas

			2. Cubrir con Cuadrados o textura (por decidir) todos los tiles del mapa. 
				- Approaches:
					· Modificar la función Draw de Map.cpp.
					· Updatear directamente desde el Update del FoW cada uno de los tiles con un bucle.
	*/

	/*
	Función para conseguir descubrir los tiles.
		Buscar el tile del jugador, aplicar un FoV y cambiar los estados de los tiles alrededor del player.
			1. Función de búsqueda del player en el mapa.
				- Hacer retrieve del tile en el que se encuentra el Player en todo momento.
			2. Crear un algoritmo para conocer cuantos tiles hay que mantener decubiertos en función del FoV.
			3. Conseguir este comportamiento:
				- COVERED --> UNCOVERED <--> TRANSLUCID.
	*/

	void LoadFog();
	void FogDraw();
	void FogUpdate(int x, int y, int radius);


public:
	enum State
	{
		COVERED,
		TRANSLUCID,
		UNCOVERED
	};

	struct FoWTiles
	{
		iPoint position;

		int state = 0;
	};

	uint w, h;
	uint size;

	FoWTiles* fogTiles;
};

#endif //_FOW_H_