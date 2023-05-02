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
#define DEJAR_EN_SALIDA 'P'
#define USAR_MATAFUEGO 'M'

//PRE:-
//POST: Mueve el personaje en la direccion recibida
void movimiento_personaje(personaje_t* personaje, char movimiento, juego_t* juego);

//PRE:-
//POST: Si el personaje es stich esta funcion sirve para el uso del cuchillo. Si el personaje es ruben esta funcion sirve para el uso del horno
void usar_herramienta(personaje_t personaje, juego_t* juego);

//PRE:-
//POST: Si el personaje es stich deja la comida lista en la mesa. Si el personaje es ruben agarra la comida lista de la mesa
void pasar_por_la_mesa(personaje_t* personaje, juego_t* juego);

//PRE:-
//POST: Revisa si el ingrediente esta listo y lo deja en el vector comida_lista
void dejar_en_la_salida(personaje_t* personaje, juego_t* juego);

//PRE:-
//POST: Inicia los ingredientes de la siguiente comida
void nueva_comida(juego_t* juego);

//PRE:-
//POST: Si tenes el matafuego y estas a una distancia menor a 2, desactiva el fuego y permite seguir jugando
void apagar_fuego(personaje_t* personaje, juego_t* juego);

#endif /*__JUGABILIDAD_H__*/