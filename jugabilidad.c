#include "jugabilidad.h"
#include "jugabilidad_auxiliar.h"

void agarrar_soltar_alimentos(personaje_t* personaje, juego_t* juego){

    for(int i = 0; i < juego->tope_comida; i++){

        if(juego->comida_actual == juego->comida[i].tipo){ 
            
            for(int j = 0; j < juego->comida[i].tope_ingredientes; j++){

                if(distancia_manhattan(juego->comida[i].ingrediente[j].posicion.fil, juego->comida[i].ingrediente[j].posicion.col, personaje->posicion.fil, personaje->posicion.col) == 0 && no_tiene_objeto_en_mano(*personaje)){
                    personaje->objeto_en_mano = juego->comida[i].ingrediente[j].tipo;
                    j = juego->comida[i].tope_ingredientes;
                }else if(personaje->objeto_en_mano == juego->comida[i].ingrediente[j].tipo){
                    personaje->objeto_en_mano = ' ';
                    juego->comida[i].ingrediente[j].posicion.col = personaje->posicion.col;
                    juego->comida[i].ingrediente[j].posicion.fil = personaje->posicion.fil;
                    j = juego->comida[i].tope_ingredientes;
                }
            }
        i = juego->tope_comida;
        }
    }
}

void agarrar_soltar_matafuego(personaje_t* personaje, juego_t* juego){

    for(int i = 0; i < juego->tope_herramientas; i++){

        if(juego->herramientas[i].tipo == MATAFUEGO){ 
            if(distancia_manhattan(juego->herramientas[i].posicion.fil, juego->herramientas[i].posicion.col, personaje->posicion.fil, personaje->posicion.col) == 0 && no_tiene_objeto_en_mano(*personaje)){
                personaje->objeto_en_mano = juego->herramientas[i].tipo;
            }else if(personaje->objeto_en_mano == juego->herramientas[i].tipo){
                personaje->objeto_en_mano = ' ';
                juego->herramientas[i].posicion.col = personaje->posicion.col;
                juego->herramientas[i].posicion.fil = personaje->posicion.fil;
            }
            i = juego->tope_herramientas;
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

    
    if(movimiento == ACCION_AGARRAR && juego->movimientos > 15){
        agarrar_soltar_matafuego(personaje,  juego);
    }
    if(movimiento == ACCION_AGARRAR){
        agarrar_soltar_alimentos(personaje, juego);
    }
}

void usar_herramienta(personaje_t personaje, juego_t* juego){

    for(int i = 0; i < juego->tope_comida; i++){

        if(juego->comida_actual == juego->comida[i].tipo){ 
            
            for(int j = 0; j < juego->comida[i].tope_ingredientes; j++){
                
                if(personaje.tipo == STICH){
                    if(personaje.objeto_en_mano == juego->comida[i].ingrediente[j].tipo && puede_usar_herramienta(personaje, *juego, CUCHILLO) && !juego->comida[i].ingrediente[j].esta_cortado){
                        juego->comida[i].ingrediente[j].esta_cortado = true;
                        j = juego->comida[i].tope_ingredientes;
                    }
                }else{ 
                    if(personaje.objeto_en_mano == juego->comida[i].ingrediente[j].tipo && puede_usar_herramienta(personaje, *juego, HORNO) && !juego->comida[i].ingrediente[j].esta_cocinado){
                        juego->comida[i].ingrediente[j].esta_cocinado = true;
                        j = juego->comida[i].tope_ingredientes;
                    }
                }
            }
        i = juego->tope_comida;
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

void dejar_en_la_salida(personaje_t* personaje, juego_t* juego){

    if(distancia_manhattan(juego->salida.fil, juego->salida.col, personaje->posicion.fil, personaje->posicion.col) == 0){
        
        for(int i = 0; i < juego->tope_comida; i++){

            if(juego->comida_actual == juego->comida[i].tipo){ 

                for(int j = 0; j < juego->comida[i].tope_ingredientes; j++){

                    if (personaje->objeto_en_mano == juego->comida[i].ingrediente[j].tipo && esta_listo(j, juego->comida[i])){
                        juego->comida_lista[juego->tope_comida_lista].tipo = juego->comida[i].ingrediente[j].tipo;
                        juego->tope_comida_lista += 1;
                        personaje->objeto_en_mano = SIN_OBJETO_EN_MANO;

                    }
                }
            i = juego->tope_comida;
            }
        }
    }
}

void nueva_comida(juego_t* juego){

    for(int i = 0; i < juego->tope_comida; i++){

        if(juego->comida_actual == juego->comida[i].tipo){ 
                
            juego->comida_actual = juego->comida[i+1].tipo;
            juego->tope_comida_lista = 0;
            i = juego->tope_comida;
        }
    }
}

void apagar_fuego(personaje_t* personaje, juego_t* juego){
    
    for(int i = 0; i < juego->tope_obstaculos; i++){
        if(juego->obstaculos[i].tipo == FUEGO){
            if(personaje->objeto_en_mano == MATAFUEGO && distancia_manhattan(personaje->posicion.fil, personaje->posicion.col, juego->obstaculos[i].posicion.fil, juego->obstaculos[i].posicion.col) <= 2){
                juego->movimientos = 0;
                personaje->objeto_en_mano = SIN_OBJETO_EN_MANO;
                juego->tope_obstaculos -=1;
                juego->tope_herramientas -= 1;
            }
        }
    }
}