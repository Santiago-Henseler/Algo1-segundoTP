#ifndef __FUNCIONES_AUXILIARES_H__
#define __FUNCIONES_AUXILIARES_H__

#include "cocineritos.h"
#include "jugabilidad.h"
#include <stdio.h>
#include <stdlib.h>

//PRE:-
//POST: Agrega a la matriz terreno todos los objetos del juego 
void cargar_terreno(juego_t juego, char terreno[LARGO_TABLERO][LARGO_TABLERO]);

//PRE:-
//POST: Devuelve true en caso de que el movimiento enviado sea valido
bool movimiento_valido(char movimento);

//PRE:-
//POST: Devuelve true en caso de que el movimiento enviado sea valido
void posicion_random(int* col, int* fil, int lado);

#endif /* __FUNCIONES_AUXILIARES_H__*/