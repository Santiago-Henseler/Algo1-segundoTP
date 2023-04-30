#ifndef __JUGABILIDAD_H__
#define __JUGABILIDAD_H__

#include "cocineritos.h"
#include "iniciador.h"
#include "establecer_posiciones.h"

// Movilidad
#define DERECHA 'D'
#define ARRIBA 'W'
#define IZQUIERDA 'A'
#define ABAJO 'S'

// Acciones
#define CAMBIO_PERSONAJE 'X'
#define SIN_OBJETO_EN_MANO ' '
#define ACCION_AGARRAR 'R'
#define CORTAR 'C'
#define COCINAR 'H'
#define INTERACTUAR_MESA 'T'

//PRE:
//POST:
bool no_tiene_objeto_en_mano(personaje_t personaje);

//PRE:
//POST:
void movimiento_personaje(personaje_t* personaje, char movimiento, juego_t* juego);

//PRE:
//POST:
void usar_herramienta(personaje_t personaje, juego_t* juego);

//PRE:
//POST:
int distancia_manhattan(int fil1, int col1, int fil2, int col2);

//PRE:
//POST:
void pasar_por_la_mesa(personaje_t* personaje, juego_t* juego);

//PRE:
//POST:
void dejar_en_la_salida(personaje_t* personaje, juego_t* juego);

#endif /*__JUGABILIDAD_H__*/