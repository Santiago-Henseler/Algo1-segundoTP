#include "jugabilidad.h"
#include "jugabilidad_auxiliar.h"

void agarrar_soltar_alimentos(personaje_t* personaje, juego_t* juego){

    int i = 0;
    int j = 0;

    bool encotrado = false;
    bool accion = false;

    while ( i < juego->tope_comida && !encotrado){
        if(juego->comida_actual == juego->comida[i].tipo){ 
            while (j < juego->comida[i].tope_ingredientes && !accion){
                if(distancia_manhattan(juego->comida[i].ingrediente[j].posicion.fil, juego->comida[i].ingrediente[j].posicion.col, personaje->posicion.fil, personaje->posicion.col) == 0 && no_tiene_objeto_en_mano(*personaje)){
                    personaje->objeto_en_mano = juego->comida[i].ingrediente[j].tipo;
                    accion = true;
                }else if(personaje->objeto_en_mano == juego->comida[i].ingrediente[j].tipo && esta_libre(*juego, personaje->posicion.fil, personaje->posicion.col, false)){
                    personaje->objeto_en_mano = SIN_OBJETO_EN_MANO;
                    juego->comida[i].ingrediente[j].posicion.col = personaje->posicion.col;
                    juego->comida[i].ingrediente[j].posicion.fil = personaje->posicion.fil;
                    accion = true;
                }
                j++;
            }
            encotrado = true;
        }
        i++;
    }
}

void agarrar_matafuego(personaje_t* personaje, juego_t* juego){

    for(int i = 0; i < juego->tope_herramientas; i++){

        if(juego->herramientas[i].tipo == MATAFUEGO){ 
            if(distancia_manhattan(juego->herramientas[i].posicion.fil, juego->herramientas[i].posicion.col, personaje->posicion.fil, personaje->posicion.col) == 0 && no_tiene_objeto_en_mano(*personaje)){
                personaje->objeto_en_mano = juego->herramientas[i].tipo;
            }
            i = juego->tope_herramientas;
        }
        
    }
}

void movimiento_personaje(personaje_t* personaje, char movimiento, juego_t* juego){

    if(movimiento == DERECHA && puede_avanzar(personaje->posicion.fil, personaje->posicion.col + 1, *juego)){
        personaje->posicion.col += 1;
        juego->movimientos += 1;
    }else if(movimiento == IZQUIERDA && puede_avanzar(personaje->posicion.fil, personaje->posicion.col - 1, *juego)){
        personaje->posicion.col -= 1;
        juego->movimientos += 1;
    }else if(movimiento == ARRIBA && puede_avanzar(personaje->posicion.fil -1, personaje->posicion.col, *juego)){
        personaje->posicion.fil -= 1;
        juego->movimientos += 1;
    }else if(movimiento == ABAJO && puede_avanzar(personaje->posicion.fil +1, personaje->posicion.col, *juego)){
        personaje->posicion.fil += 1;
        juego->movimientos += 1;
    }

    dejar_en_la_salida(&juego->reuben, juego);
    
    agarrar_matafuego(personaje,  juego);

    if(movimiento == ACCION_AGARRAR){
        agarrar_soltar_alimentos(personaje, juego);
    }
}

void usar_herramienta(personaje_t personaje, juego_t* juego){

    int i = 0;
    int j = 0;

    bool encotrado = false;
    bool accion = false;

    while ( i < juego->tope_comida && !encotrado){

        if(juego->comida_actual == juego->comida[i].tipo){ 
            
            while (j < juego->comida[i].tope_ingredientes && !accion){
                
                if(personaje.tipo == STICH){
                    if(personaje.objeto_en_mano == juego->comida[i].ingrediente[j].tipo && puede_usar_herramienta(personaje, *juego, CUCHILLO) && !juego->comida[i].ingrediente[j].esta_cortado){
                        juego->comida[i].ingrediente[j].esta_cortado = true;
                        accion = true;
                    }
                }else{ 
                    if(personaje.objeto_en_mano == juego->comida[i].ingrediente[j].tipo && puede_usar_herramienta(personaje, *juego, HORNO) && !juego->comida[i].ingrediente[j].esta_cocinado){
                        juego->comida[i].ingrediente[j].esta_cocinado = true;
                        accion = true;
                    }
                }
                j++;
            }
            encotrado = true;
        }
        i++;
    }
}

void pasar_por_la_mesa(personaje_t* personaje, juego_t* juego){

    if(distancia_manhattan(POSICION_MESA, POSICION_MESA, personaje->posicion.fil, personaje->posicion.col) == 1){
        
        int i = 0;
        int j = 0;

        bool encotrado = false;
        bool accion = false;

        while ( i < juego->tope_comida && !encotrado){

            if(juego->comida_actual == juego->comida[i].tipo){ 
                
                while (j < juego->comida[i].tope_ingredientes && !accion){
                    
                    if (personaje->objeto_en_mano == juego->comida[i].ingrediente[j].tipo && mesa_vacia(*juego)){
                        juego->comida[i].ingrediente[j].posicion.col = POSICION_MESA;
                        juego->comida[i].ingrediente[j].posicion.fil = POSICION_MESA;
                        personaje->objeto_en_mano = SIN_OBJETO_EN_MANO;
                        accion = true;
                    } else if(personaje->objeto_en_mano == SIN_OBJETO_EN_MANO  && !mesa_vacia(*juego)){
                        personaje->objeto_en_mano = juego->comida[i].ingrediente[j].tipo;
                        accion = true;
                    }
                    j++;
                }
                encotrado = true;
            }
            i++;
        }
    }
}

void dejar_en_la_salida(personaje_t* personaje, juego_t* juego){

    if(distancia_manhattan(juego->salida.fil, juego->salida.col, personaje->posicion.fil, personaje->posicion.col) == 0){

        int i = 0;
        int j = 0;

        bool encotrado = false;
        bool accion = false;
        
        while ( i < juego->tope_comida && !encotrado){

            if(juego->comida_actual == juego->comida[i].tipo){ 

                while (j < juego->comida[i].tope_ingredientes && !accion){

                    if (personaje->objeto_en_mano == juego->comida[i].ingrediente[j].tipo && esta_listo(j, juego->comida[i])){
                        juego->comida_lista[juego->tope_comida_lista].tipo = juego->comida[i].ingrediente[j].tipo;
                        juego->tope_comida_lista += 1;
                        personaje->objeto_en_mano = SIN_OBJETO_EN_MANO;
                        accion = true;
                    }
                    j++;
                }
                encotrado = true;
            }
            i++;
        }
    }
}

void nueva_comida(juego_t* juego){

    char comidas[MAX_COMIDA] = {ENSALADA, PIZZA, HAMBURGESA, SANGUCHE,' '};

    int i = 0;
    
    bool encotrado = false;
    
    while ( i < juego->tope_comida && !encotrado){

        if(juego->comida_actual == juego->comida[i].tipo){ 

            juego->comida_actual = comidas[i+1];
            juego->tope_comida_lista = 0;
            encotrado = true;
        }
        i++;
    }
    if(!encotrado){
        juego->comida_actual = comidas[MAX_COMIDA];
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