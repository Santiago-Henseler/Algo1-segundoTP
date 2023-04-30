#ifndef __ESTABLECER_POSICIONES_H__
#define __ESTABLECER_POSICIONES_H__

#include "cocineritos.h"
#include "iniciador.h"
#include "jugabilidad.h"
#include <stdlib.h>

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

//PRE:
//POST:
bool ingrediente_de_ruben(int i, comida_t comida);

//PRE:
//POST:
void establecer_posicion_salida(juego_t* juego);

#endif /*__ESTABLECER_POSICIONES_H__ */