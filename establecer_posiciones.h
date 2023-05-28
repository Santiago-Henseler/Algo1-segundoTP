#ifndef __ESTABLECER_POSICIONES_H__
#define __ESTABLECER_POSICIONES_H__

#include "cocineritos.h"
#include "iniciador.h"
#include "jugabilidad.h"
#include "jugabilidad_auxiliar.h"
#include "funciones_auxiliares.h"
#include <stdlib.h>

//PRE: -
//POST: Revisa si se pueden ubicar los personajes y los posiciona
void establecer_posicion_personajes(personaje_t* personaje, juego_t juego);

//PRE:-
//POST: Revisa si se pueden ubicar los ingredientes y los posiciona
void establecer_posicion_ingredientes(comida_t* comida, juego_t juego);

//PRE:-
//POST: Revisa si se pueden ubicar los objetos y los posiciona
void establecer_posicion_objetos(objeto_t* objeto, juego_t juego);

//PRE:-
//POST: Revisa si se pueden ubicar los agujeros y los posiciona
void establecer_posicion_agujeros(objeto_t* agujero, juego_t juego, int i);

//PRE:-
//POST: Devuelve true si el ingrediente pertenece a ruben
bool ingrediente_de_ruben(int i, comida_t comida);

//PRE:-
//POST: Revisa si se puede ubicar la salida y la posiciona
void establecer_posicion_salida(juego_t* juego);

//PRE:-
//POST: Revisa si se puede ubicar el fuego y el matafuegos y los posiciona
void establecer_posicion_fuego_matafuego(juego_t* juego, int posicion, objeto_t* tipo);

//PRE:-
//POST: Devuelve true si no hay otro objeto en esa posicion
bool esta_libre(juego_t juego, int fil, int col, bool inicio);

#endif /*__ESTABLECER_POSICIONES_H__ */