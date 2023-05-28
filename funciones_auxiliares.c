#include "funciones_auxiliares.h"

void cargar_terreno(juego_t juego, char terreno[LARGO_TABLERO][LARGO_TABLERO]){
    
    // posiciones de las paredes
    for(int i = 0; i < LARGO_TABLERO; i++){

        for(int j = 0; j< LARGO_TABLERO; j++){

            if(i == 0 || i == 20 || i == 10){       
                terreno[i][j] = PARED;
            }else if(j == 0 || j == 20){
                terreno[i][j] = PARED;
            }else{
                terreno[i][j] = ' ';
            }
        }
    }
    
    // posiciones de la mesa y de la salida
    terreno[juego.salida.fil][juego.salida.col] = SALIDAD;
    terreno[juego.mesa.fil][juego.mesa.col] = MESA;

    // posiciones de los obstaculos
    for(int i = 0; i < juego.tope_obstaculos; i++){
        terreno[juego.obstaculos[i].posicion.fil][juego.obstaculos[i].posicion.col] = juego.obstaculos[i].tipo;
    }    

    // posiciones de los ingredientes
    for(int i = 0; i < juego.tope_comida; i++){
        
         if(juego.comida_actual == juego.comida[i].tipo){ 
            
            for(int j = 0; j < juego.comida[i].tope_ingredientes; j++){
                
                if(!ya_entregado(juego, juego.comida[i].ingrediente[j].tipo) && juego.reuben.objeto_en_mano != juego.comida[i].ingrediente[j].tipo && juego.stitch.objeto_en_mano != juego.comida[i].ingrediente[j].tipo){
                    terreno[juego.comida[i].ingrediente[j].posicion.fil][juego.comida[i].ingrediente[j].posicion.col] = juego.comida[i].ingrediente[j].tipo;
                }
            }
           
        }
 
    }
   
   // posiciones de las herramientas
    for(int i = 0; i < juego.tope_herramientas; i++){
        if(juego.reuben.objeto_en_mano != juego.herramientas[i].tipo && juego.stitch.objeto_en_mano != juego.herramientas[i].tipo){
            terreno[juego.herramientas[i].posicion.fil][juego.herramientas[i].posicion.col] = juego.herramientas[i].tipo; 
        }
    }

    // posiciones de los personajes
    terreno[juego.stitch.posicion.fil][juego.stitch.posicion.col] = STICH; 
    terreno[juego.reuben.posicion.fil][juego.reuben.posicion.col] = RUBEN; 
 
}

bool movimiento_valido(char movimento){
    bool rta = false;

    if(movimento == DERECHA || movimento == IZQUIERDA || movimento == ABAJO || movimento == ARRIBA || movimento == CAMBIO_PERSONAJE || movimento == ACCION_AGARRAR || movimento == USAR_MATAFUEGO || movimento == INTERACTUAR_MESA || movimento == COCINAR || movimento == CORTAR || movimento == ACCION_AGARRAR){
        rta = true;
    }

    return rta;
}

void posicion_random(int* col, int* fil, int lado){

    if(lado == 1){
        *col = rand() % 19 + 1;
        *fil = rand() % 9 + 1;
    }else if(lado == 2){
        *fil = rand() % 9 + 11;
        *col = rand() % 19 + 1;
    }

}