#include "establecer_posiciones.h"

bool no_esta_ocupado(juego_t juego, int fil, int col){
    bool rta = false;

    for(int i = 0; i < juego.tope_obstaculos; i++){
        if(distancia_manhattan(juego.obstaculos[i].posicion.fil, juego.obstaculos[i].posicion.col, fil, col) != 0){
            rta = true;
            i = juego.tope_obstaculos;
        }else{
            rta =  false;
        }
    }

    for(int i = 0; i < juego.tope_herramientas; i++){
        if(distancia_manhattan(juego.herramientas[i].posicion.fil, juego.herramientas[i].posicion.col, fil, col) != 0){
            rta = true;
            i = juego.tope_herramientas;
        }
        else{
            rta =  false;
        }
    }
  
    if((distancia_manhattan(juego.stitch.posicion.fil, juego.stitch.posicion.col, fil, col) != 0 || distancia_manhattan(juego.reuben.posicion.fil, juego.reuben.posicion.col, fil, col) != 0)){
        rta = true;
    }
    else{
        rta =  false;
    }

    return rta;
}

bool ingrediente_de_ruben(int i, comida_t comida){
    char ingrediente = comida.ingrediente[i].tipo;

    return (ingrediente == CARNE || ingrediente == MASA || ingrediente == MILANESA);
}

void establecer_posicion_ingredientes(comida_t* comida, juego_t juego){

    for(int i = 0; i < comida->tope_ingredientes; i++){
        bool c = true;

        while (c){
            int col = 0;
            int fil = 0;
                
            if(ingrediente_de_ruben(i, *comida)){
                fil = rand() % 9 + 11;
                col = rand() % 19 + 1;
            }else{
                col = rand() % 19 + 1;
                fil = rand() % 9 + 1;
            }

            if(no_esta_ocupado(juego, fil, col)){
                comida->ingrediente[i].posicion.col = col;
                comida->ingrediente[i].posicion.fil = fil;
                c = false;
            }
        }  
    }  
}

void establecer_posicion_objetos(objeto_t* objeto, juego_t juego){
    bool c = true;

    while (c){
        int col = 0;
        int fil = 0;
        
        if(objeto->tipo == HORNO){
            fil = rand() % 9 + 11;
            col = rand() % 19 + 1;
        }
        if(objeto->tipo == CUCHILLO){
            col = rand() % 19 + 1;
            fil = rand() % 9 + 1;
        }
        if(no_esta_ocupado(juego, fil, col)){
            objeto->posicion.col = col;
            objeto->posicion.fil = fil;
            c = false;
        }
    }
}

void establecer_posicion_agujeros(objeto_t* agujero, juego_t juego, int i){
    bool c = true;

    while (c){
        int col = 0;
        int fil = 0;
        
        if(i < 10){
            fil = rand() % 9 + 1;
            col = rand() % 19 + 1;
        }else if(i >= 10){
            fil = rand() % 9 + 11;
            col = rand() % 19 + 1;
        }
        if(no_esta_ocupado(juego,  fil,  col) && fil != 9){
            agujero->posicion.col = col;
            agujero->posicion.fil = fil;
            c = false;
        }
    }
}

void establecer_posicion_personajes(personaje_t* personaje, juego_t juego){
    bool c = true;

    while (c){
        int col = 0;
        int fil = 0;
        
        if(personaje->tipo == RUBEN){
            fil = rand() % 9 + 11;
            col = rand() % 19 + 1;
        }

        if(personaje->tipo == STICH){
            col = rand() % 19 + 1;
            fil = rand() % 9 + 1;
        }

        if(no_esta_ocupado(juego, fil, col)){
            personaje->posicion.col = col;
            personaje->posicion.fil = fil;
            c = false;
        }
    }
}

void establecer_posicion_salida(juego_t* juego){
    bool c = true;

    int fil = 0;
    int col = 0;

    while (c){
        fil = rand() % 9 + 11;
        col = rand() % 19 + 1;
        
        if(no_esta_ocupado(*juego, fil, col)){
            juego->salida.col = col;
            juego->salida.fil = fil;
            c = false;
        }
    }
}

void establecer_posicion_fuego_matafuego(juego_t* juego, int posicion, objeto_t* tipo){

    bool c = true;

    int col = 0;
    int fil = 0;

    while (c){
        
        if(posicion == 0){
            fil = rand() % 9 + 11;
            col = rand() % 19 + 1;
        }

        if(posicion == 1){
            col = rand() % 19 + 1;
            fil = rand() % 9 + 1;
        }

        if(no_esta_ocupado(*juego, fil, col)){
            tipo->posicion.col = col;
            tipo->posicion.fil  = fil;
            c = false;
        }

    }
}

// INTENTAAR MODULARIZAR
