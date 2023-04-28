#include "jugabilidad.h"

bool no_tiene_objeto_en_mano(personaje_t personaje){
    return personaje.objeto_en_mano == SIN_OBJETO_EN_MANO;
}

bool no_puede_cortar(){

    

}

void agarrar_soltar_alimentos(personaje_t* personaje, juego_t* juego){

    for(int i = 0; i < juego->tope_comida; i++){

        if(juego->comida_actual == juego->comida[i].tipo){ 
            
            for(int j = 0; j < juego->comida[i].tope_ingredientes; j++){
 
                if(juego->comida[i].ingrediente[j].posicion.col == personaje->posicion.col && juego->comida[i].ingrediente[j].posicion.fil == personaje->posicion.fil && no_tiene_objeto_en_mano(*personaje)){
                    personaje->objeto_en_mano = juego->comida[i].ingrediente[j].tipo;
                }else if(personaje->objeto_en_mano == juego->comida[i].ingrediente[j].tipo){
                    personaje->objeto_en_mano = ' ';
                    juego->comida[i].ingrediente[j].posicion.col = personaje->posicion.col;
                    juego->comida[i].ingrediente[j].posicion.fil = personaje->posicion.fil;
                }
            }
           
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
 
                if(personaje.objeto_en_mano == juego->comida[i].ingrediente[j].tipo && no_puede_cortar()){
                  
                    
                    }


        }
    }

}


// terminar funcion cortar ingredientes
