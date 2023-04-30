#ifndef __JUGABILIDAD_AUXILIAR_H__
#define __JUGABILIDAD_AUXILIAR_H__

#include "cocineritos.h"
#include "iniciador.h"
#include "establecer_posiciones.h"

//PRE:
//POST:
int distancia_manhattan(int fil1, int col1, int fil2, int col2);

//PRE:
//POST:
bool no_tiene_objeto_en_mano(personaje_t personaje);

//PRE:
//POST:
bool mesa_vacia(int fil, int col);

//PRE:
//POST:
bool esta_listo(int i, comida_t comida);

//PRE:
//POST:
bool puede_usar_herramienta(personaje_t personaje, juego_t juego, char herramienta);

#endif /*__JUGABILIDAD_AUXILIAR_H__*/