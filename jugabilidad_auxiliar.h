#ifndef __JUGABILIDAD_AUXILIAR_H__
#define __JUGABILIDAD_AUXILIAR_H__

#include "cocineritos.h"
#include "iniciador.h"
#include "establecer_posiciones.h"

//PRE:-
//POST: Devuelve un entero que es la distancia a un punto
int distancia_manhattan(int fil1, int col1, int fil2, int col2);

//PRE:-
//POST: Revisa si tiene un objeto y devuelve true si no tiene
bool no_tiene_objeto_en_mano(personaje_t personaje);

//PRE:-
//POST: Revisa si la mesa esta ocupada y devuelve false si lo esta
bool mesa_vacia(juego_t);

//PRE:-
//POST: Revisa si el ingrediente esta preparado y devuelve true si lo esta
bool esta_listo(int i, comida_t comida);

//PRE:-
//POST: Revisa si esta a la distancia necesaria para usar una herramienta y devuelve true si puede usarla
bool puede_usar_herramienta(personaje_t personaje, juego_t juego, char herramienta);

//PRE:-
//POST: Devuelve true si la comida actual ya esta terminada y entregada
bool ya_entregado(juego_t juego, char comida);

//PRE:-
//POST: Revisa si la comida actual esta preparada
bool termino_comida(juego_t juego);

//PRE:-
//POST: Muestra por pantalla el personaje activo y lo que lleva en la mano
void hud(juego_t juego);

//PRE:-
//POST:Devuelve true si la posicion dada es valida para avanzar
bool puede_avanzar(int fil, int col, juego_t juego);

//PRE:-
//POST:Devuelve true si hay un fuego activo
bool fuego_activo(juego_t juego);

#endif /*__JUGABILIDAD_AUXILIAR_H__*/