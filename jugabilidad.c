#include "jugabilidad.h"

bool no_tiene_objeto_en_mano(personaje_t personaje){
    return personaje.objeto_en_mano == SIN_OBJETO_EN_MANO;
}

bool mesa_vacia(int fil, int col){

    return distancia_manhattan(POSICION_MESA, POSICION_MESA, fil,col) != 0;
}

int distancia_manhattan(int fil1, int col1, int fil2, int col2){
    int distancia = 0;
    int fila = 0;
    int columna = 0;

    fila = fil1 - fil2;
    
    if(fila < 0){
        fila *= -1;
    }

    columna = col1 - col2;

    if(columna < 0){
        columna *= -1;
    }

    distancia = fila + columna;

    return distancia;
}

bool puede_cortar(personaje_t personaje, juego_t juego){
    bool rta = false;

    for(int i = 0; i < juego.tope_herramientas; i++){
    
        if(juego.herramientas[i].tipo == CUCHILLO && distancia_manhattan(juego.herramientas[i].posicion.fil, juego.herramientas[i].posicion.col, personaje.posicion.fil, personaje.posicion.col) == 0){
            
            rta = true;
        }
    }
    return rta;
}

bool puede_cocinar(personaje_t personaje, juego_t juego){
    bool rta = false;    

    for(int i = 0; i < juego.tope_herramientas; i++){
    
        if(juego.herramientas[i].tipo == HORNO &&  distancia_manhattan(juego.herramientas[i].posicion.fil, juego.herramientas[i].posicion.col, personaje.posicion.fil, personaje.posicion.col) == 1){
            
            rta = true;
        }
    }
    return rta;
}

void agarrar_soltar_alimentos(personaje_t* personaje, juego_t* juego){

    for(int i = 0; i < juego->tope_comida; i++){

        if(juego->comida_actual == juego->comida[i].tipo){ 
            
            for(int j = 0; j < juego->comida[i].tope_ingredientes; j++){

                if(distancia_manhattan(juego->comida[i].ingrediente[j].posicion.fil, juego->comida[i].ingrediente[j].posicion.col, personaje->posicion.fil, personaje->posicion.col) == 0 && no_tiene_objeto_en_mano(*personaje)){
                    personaje->objeto_en_mano = juego->comida[i].ingrediente[j].tipo;
                }else if(personaje->objeto_en_mano == juego->comida[i].ingrediente[j].tipo){
                    personaje->objeto_en_mano = ' ';
                    juego->comida[i].ingrediente[j].posicion.col = personaje->posicion.col;
                    juego->comida[i].ingrediente[j].posicion.fil = personaje->posicion.fil;
                }
            }
        i = juego->tope_comida;
        }
    }
}

void movimiento_personaje(personaje_t* personaje, char movimiento, juego_t* juego){

    if(movimiento == DERECHA && personaje->posicion.col + 1 != juego->paredes->col){
        personaje->posicion.col += 1;
    }else if(movimiento == IZQUIERDA && personaje->posicion.col - 1 != juego->paredes->col){
        personaje->posicion.col -= 1;
    }else if(movimiento == ARRIBA && personaje->posicion.fil - 1 != juego->paredes->fil){
        personaje->posicion.fil -= 1;
    }else if(movimiento == ABAJO && personaje->posicion.fil + 1 != juego->paredes->fil){
        personaje->posicion.fil += 1;
    }

    if(movimiento == ACCION_AGARRAR){
        agarrar_soltar_alimentos(personaje, juego);
    }

}

void cortar_ingrediente(personaje_t personaje, juego_t* juego){

    for(int i = 0; i < juego->tope_comida; i++){

        if(juego->comida_actual == juego->comida[i].tipo){ 
            
            for(int j = 0; j < juego->comida[i].tope_ingredientes; j++){
                
                if(personaje.objeto_en_mano == juego->comida[i].ingrediente[j].tipo && puede_cortar(personaje, *juego) && !juego->comida[i].ingrediente[j].esta_cortado){
                    juego->comida[i].ingrediente[j].esta_cortado = true;
                }
            }
        }
    }
}

void usar_horno(personaje_t personaje, juego_t* juego){

   for(int i = 0; i < juego->tope_comida; i++){

        if(juego->comida_actual == juego->comida[i].tipo){ 
            
            for(int j = 0; j < juego->comida[i].tope_ingredientes; j++){
                
                if(personaje.objeto_en_mano == juego->comida[i].ingrediente[j].tipo && puede_cocinar(personaje, *juego) && !juego->comida[i].ingrediente[j].esta_cocinado){
                    
                    juego->comida[i].ingrediente[j].esta_cocinado = true;
                }
            }
        }
    }
}

void pasar_por_la_mesa(personaje_t* personaje, juego_t* juego){

    if(distancia_manhattan(POSICION_MESA, POSICION_MESA, personaje->posicion.fil, personaje->posicion.col) == 1){
        
        for(int i = 0; i < juego->tope_comida; i++){

            if(juego->comida_actual == juego->comida[i].tipo){ 
                
                for(int j = 0; j < juego->comida[i].tope_ingredientes; j++){
                    int fil = juego->comida[i].ingrediente[j].posicion.fil;
                    int col = juego->comida[i].ingrediente[j].posicion.col;

                    if(personaje->tipo == STICH){
                        if (personaje->objeto_en_mano == juego->comida[i].ingrediente[j].tipo && mesa_vacia(fil, col) && juego->comida[i].ingrediente[j].esta_cortado){
                            juego->comida[i].ingrediente[j].posicion.col = POSICION_MESA;
                            juego->comida[i].ingrediente[j].posicion.fil = POSICION_MESA;
                            personaje->objeto_en_mano = SIN_OBJETO_EN_MANO;
                            j = juego->comida[i].tope_ingredientes;
                        }
                    }else{
                        if(personaje->objeto_en_mano == SIN_OBJETO_EN_MANO  && !mesa_vacia(fil, col)){
                            printf("d");
                            personaje->objeto_en_mano = juego->comida[i].ingrediente[j].tipo;
                            j = juego->comida[i].tope_ingredientes;
                        }
                    }
                }
            i = juego->tope_comida;
            }
        }
    }
}



// MODULARIZAR MAS LOCO
// NO AGARRA DE LA MESA