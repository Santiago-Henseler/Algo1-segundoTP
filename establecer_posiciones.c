#include "establecer_posiciones.h"

bool esta_libre(juego_t juego, int fil, int col, bool inicio){
    bool rta = true;

    if((distancia_manhattan(juego.stitch.posicion.fil, juego.stitch.posicion.col, fil, col) == 0 || distancia_manhattan(juego.reuben.posicion.fil, juego.reuben.posicion.col, fil, col) == 0) && inicio){
        rta = false;
    }

    for(int i = 0; i < juego.tope_obstaculos; i++){
        if(distancia_manhattan(juego.obstaculos[i].posicion.fil, juego.obstaculos[i].posicion.col, fil, col) == 0){
            rta = false;
            i = juego.tope_obstaculos;
        }
    }

    for(int i = 0; i < juego.tope_herramientas; i++){
        if(distancia_manhattan(juego.herramientas[i].posicion.fil, juego.herramientas[i].posicion.col, fil, col) == 0){
            rta = false;
            i = juego.tope_herramientas;
        }
    }

     for(int i = 0; i < juego.tope_comida; i++){

        if(juego.comida_actual == juego.comida[i].tipo){ 
            
            for(int j = 0; j < juego.comida[i].tope_ingredientes; j++){
                if(distancia_manhattan(juego.comida[i].ingrediente[j].posicion.fil, juego.comida[i].ingrediente[j].posicion.col, fil, col) == 0){
                    rta = false;
                    j = juego.comida[i].tope_ingredientes;
                }
  
            }
        i = juego.tope_comida;
        }
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

            if(esta_libre(juego, fil, col, true)){
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
        if(esta_libre(juego, fil, col, true)){
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
        if(esta_libre(juego,  fil,  col, true)){
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

        if(esta_libre(juego, fil, col, true)){
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
        
        if(esta_libre(*juego, fil, col, true)){
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

        if(esta_libre(*juego, fil, col, true)){
            tipo->posicion.col = col;
            tipo->posicion.fil  = fil;
            c = false;
        }

    }
}
