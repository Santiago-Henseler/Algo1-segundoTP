#ifndef __JUGABILIDAD_H__
#define __JUGABILIDAD_H__

#include "cocineritos.h"
#include "iniciador.h"

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

//PRE:
//POST:
bool no_tiene_objeto_en_mano(personaje_t personaje);

//PRE:
//POST:
void movimiento_personaje(personaje_t* personaje, char movimiento, juego_t* juego);

//PRE:
//POST:
void cortar_ingrediente(personaje_t personaje, juego_t* juego);

#endif /*__JUGABILIDAD_H__*/