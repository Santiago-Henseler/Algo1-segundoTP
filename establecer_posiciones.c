#include "establecer_posiciones.h"
#include "funciones_auxiliares.h"

bool esta_libre(juego_t juego, int fil, int col, bool inicio){
    bool rta = true;

    bool encontrado = false;

    int i = 0;
    int j = 0;

    if((distancia_manhattan(juego.stitch.posicion.fil, juego.stitch.posicion.col, fil, col) == 0 || distancia_manhattan(juego.reuben.posicion.fil, juego.reuben.posicion.col, fil, col) == 0) && inicio){
        rta = false;
    }

    while (i < juego.tope_obstaculos && !encontrado){
        if(distancia_manhattan(juego.obstaculos[i].posicion.fil, juego.obstaculos[i].posicion.col, fil, col) == 0){
            encontrado = true;
            rta = false;
        }
        i++;
    }

    i = 0;
    encontrado = false;

    while (i < juego.tope_herramientas && !encontrado){
        if(distancia_manhattan(juego.herramientas[i].posicion.fil, juego.herramientas[i].posicion.col, fil, col) == 0){
            encontrado = true;
            rta = false;
        }
        i++;
    }

    i = 0;
    encontrado = false;

    while (i < juego.tope_comida && !encontrado){

        if(juego.comida_actual == juego.comida[i].tipo){ 
            
            while (j < juego.comida[i].tope_ingredientes && !encontrado){
                if(distancia_manhattan(juego.comida[i].ingrediente[j].posicion.fil, juego.comida[i].ingrediente[j].posicion.col, fil, col) == 0){
                    encontrado = true;
                    rta = false;
                }
                j++;
            }
        }
        i++;
    }
    return rta;
}

bool ingrediente_de_ruben(int i, comida_t comida){
    char ingrediente = comida.ingrediente[i].tipo;

    return (ingrediente == CARNE || ingrediente == MASA || ingrediente == MILANESA);
}

void establecer_posicion_ingredientes(comida_t* comida, juego_t juego){

    for(int i = 0; i < comida->tope_ingredientes; i++){
        bool posicionado = false;

        while (!posicionado){
            int col = 0;
            int fil = 0;
                
            if(ingrediente_de_ruben(i, *comida)){
                posicion_random( &col, &fil, 2);
            }else{
                posicion_random( &col, &fil, 1);
            }

            if(esta_libre(juego, fil, col, true)){
                comida->ingrediente[i].posicion.col = col;
                comida->ingrediente[i].posicion.fil = fil;
                posicionado = true;
            }
        }  
    }  
}

void establecer_posicion_objetos(objeto_t* objeto, juego_t juego){
    bool posicionado = false;

    while (!posicionado){
        int col = 0;
        int fil = 0;
        
        if(objeto->tipo == HORNO){
            posicion_random( &col, &fil, 2);
        }
        if(objeto->tipo == CUCHILLO){
            posicion_random( &col, &fil, 1);
        }
 
        if(esta_libre(juego, fil, col, true)){
            objeto->posicion.col = col;
            objeto->posicion.fil = fil;
            posicionado = true;
        }
    }
}

void establecer_posicion_agujeros(objeto_t* agujero, juego_t juego, int i){
    bool posicionado = false;

    while(!posicionado){
        int col = 0;
        int fil = 0;
        
        if(i < 10){
            posicion_random( &col, &fil, 1);
        }else if(i >= 10){
            posicion_random( &col, &fil, 2);
        }
        if(esta_libre(juego,  fil,  col, true)){
            agujero->posicion.col = col;
            agujero->posicion.fil = fil;
            posicionado = true;
        }
    }
}

void establecer_posicion_personajes(personaje_t* personaje, juego_t juego){
    bool posicionado = false;

    while (!posicionado){
        int col = 0;
        int fil = 0;
        
        if(personaje->tipo == RUBEN){
           posicion_random( &col, &fil, 2);
        }

        if(personaje->tipo == STICH){
            posicion_random( &col, &fil, 1);
        }

        if(esta_libre(juego, fil, col, true)){
            personaje->posicion.col = col;
            personaje->posicion.fil = fil;
            posicionado = true;
        }
    }
}

void establecer_posicion_salida(juego_t* juego){
    bool posicionado = false;

    int fil = 0;
    int col = 0;

    while (!posicionado){
      posicion_random( &col, &fil, 2);
        
        if(esta_libre(*juego, fil, col, true)){
            juego->salida.col = col;
            juego->salida.fil = fil;
            posicionado = true;
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
