#include "establecer_posiciones.h"

bool no_esta_ocupado(juego_t juego, int fil, int col){
    
    for(int i = 0; i < juego.tope_obstaculos; i++){
        if (juego.obstaculos[i].posicion.fil != fil && juego.obstaculos[i].posicion.col != col){
            i = juego.tope_obstaculos;
            return true;
        }
    }

    for(int i = 0; i < juego.tope_herramientas; i++){
        if (juego.herramientas[i].posicion.fil != fil && juego.herramientas[i].posicion.col != col){
            i = juego.tope_herramientas;
            return true;
        }
    }

    for(int i = 0; i < juego.tope_obstaculos; i++){
       if (juego.obstaculos[i].posicion.fil != fil && juego.obstaculos[i].posicion.col != col){
            i = juego.tope_obstaculos;
            return true;
        } 
    }

    return false;
}
 
bool cuadrante_ruben(int i, comida_t comida){
    char ingrediente = comida.ingrediente[i].tipo;

    return (ingrediente == CARNE || ingrediente == MASA || ingrediente == MILANESA);
}

int col_salida(){
    
    int rta = 0;

    if(rand() % 20 > 10){
        rta = 20;
    }

    return rta;
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

void establecer_posicion_ingredientes(comida_t* comida, juego_t juego){

    for(int i = 0; i < comida->tope_ingredientes; i++){
        bool c = true;

        while (c){
            int col = 0;
            int fil = 0;
                
            if(cuadrante_ruben(i, *comida)){
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
        if(no_esta_ocupado(juego,  fil,  col)){
            agujero->posicion.col = col;
            agujero->posicion.fil = fil;
            c = false;
        }
    }
}

