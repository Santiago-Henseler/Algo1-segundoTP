#ifndef __ESTABLECER_POSICIONES_H__
#define __ESTABLECER_POSICIONES_H__

#include "cocineritos.h"
#include "iniciador.h"
#include <stdlib.h>

//PRE: -
//POST: Devuelve aleatoriamente la columna 0 o la 20  
int col_salida();

//PRE: -
//POST:
void establecer_posicion_personajes(personaje_t* personaje, juego_t juego);

//PRE:
//POST:
void establecer_posicion_ingredientes(comida_t* comida, juego_t juego);

//PRE:
//POST:
void establecer_posicion_objetos(objeto_t* objeto, juego_t juego);

//PRE:
//POST:
void establecer_posicion_agujeros(objeto_t* agujero, juego_t juego, int i);

#endif /*__ESTABLECER_POSICIONES_H__ */