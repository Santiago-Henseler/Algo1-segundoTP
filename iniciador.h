#ifndef __INICIADOR_H__
#define __INICIADOR_H__

#include "cocineritos.h"
#include <stdio.h>
#include <stdlib.h>

// INGREDIENTES
#define TOMATE  'T'
#define LECHUGA  'L'
#define MASA  'O'
#define QUESO  'Q'
#define PAN  'N'
#define CARNE  'B'
#define MILANESA  'I'
#define JAMON  'J'

// COMIDAS
#define ENSALADA  'E'
#define PIZZA  'P'
#define HAMBURGESA  'H'
#define SANGUCHE  'S'

// PERSONAJES
#define STICH  'S'
#define RUBEN  'R'

// OBJETOS
#define CUCHILLO  'C'
#define HORNO  'H'
#define MATAFUEGO  'M'
#define AGUJERO  'A'   
#define PARED  '#'
#define MESA  '-'
#define SALIDAD  'P'

// terreno
#define LARGO_TABLERO 21
#define MAX_AGUJEROS 20


//PRE: -
//POST: Carga todos los atributos de los 2 personajes
void iniciar_personaje(juego_t* juego);

//PRE: Recibe un precio para cargar solo las comidas necesarias
//POST: Carga todos los atributos de las comidas  
void iniciar_comidas(juego_t* juego, int precio);

//PRE: -
//POST: Carga las paredes del mapa
void crear_mapa(juego_t* juego);

//PRE: -
//POST: Carga todos los atributos de los objetos
void iniciar_objetos(juego_t* juego);

//PRE: -
//POST: Carga los 20 agujeros del juego
void iniciar_obstaculos(juego_t* juego);

#endif /* __INICIADOR_H__*/