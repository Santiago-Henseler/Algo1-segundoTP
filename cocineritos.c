#include "cocineritos.h"
#include "jugabilidad.h"
#include "jugabilidad_auxiliar.h"
#include "iniciador.h"
#include "establecer_posiciones.h"

void inicializar_juego(juego_t* juego, int precio){

    juego->personaje_activo = STICH;

    juego->precio_total = precio;

    juego->mesa.col = POSICION_MESA;
    juego->mesa.fil = POSICION_MESA;

    juego->comida_actual = ENSALADA;
    juego->tope_comida_lista = 0;

    crear_mapa(juego);
    iniciar_obstaculos(juego);
    iniciar_objetos(juego);
    iniciar_comidas(juego, precio);
    iniciar_personaje(juego);
    iniciar_salida(juego);

}

void imprimir_terreno(juego_t juego){
    
    // limpiamos la pantalla
    system("clear");

    hud(juego);

    char terreno[LARGO_TABLERO][LARGO_TABLERO];

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
 
    // visualizamos por pantalla la matriz terreno
    for(int i = 0; i < LARGO_TABLERO; i++){
        for(int j = 0; j< LARGO_TABLERO; j++){
            printf(" %c", terreno[i][j]);
        }printf("\n");
    }
}

void realizar_jugada(juego_t* juego, char movimiento){
   
    if(juego->movimientos == MOVIMIENTOS_FUEGO){
        iniciar_fuego_matafuego(juego);
    }
   
    if(juego->personaje_activo == STICH){
        if(movimiento == CAMBIO_PERSONAJE){
            juego->personaje_activo = RUBEN;
        }else if(movimiento == CORTAR && juego->movimientos < MOVIMIENTOS_FUEGO){
            usar_herramienta(juego->stitch, juego);
        }else if(movimiento == INTERACTUAR_MESA && juego->movimientos < MOVIMIENTOS_FUEGO){
            pasar_por_la_mesa(&juego->stitch, juego);
        }else if(movimiento == USAR_MATAFUEGO && juego->movimientos >= MOVIMIENTOS_FUEGO){
            apagar_fuego(&juego->stitch, juego);
        }else{
            movimiento_personaje(&juego->stitch, movimiento, juego);
        }
    }
    else if(juego->personaje_activo == RUBEN){
        if(movimiento == CAMBIO_PERSONAJE){
            juego->personaje_activo = STICH;
        }else if(movimiento == COCINAR && juego->movimientos < MOVIMIENTOS_FUEGO){
            usar_herramienta(juego->reuben, juego);
        }else if(movimiento == INTERACTUAR_MESA && juego->movimientos < MOVIMIENTOS_FUEGO){
            pasar_por_la_mesa(&juego->reuben, juego);
        }else if(movimiento == DEJAR_EN_SALIDA && juego->movimientos < MOVIMIENTOS_FUEGO){
            dejar_en_la_salida(&juego->reuben, juego);
        }else if(movimiento == USAR_MATAFUEGO && juego->movimientos >= MOVIMIENTOS_FUEGO){
            apagar_fuego(&juego->reuben, juego);
        }else{
            movimiento_personaje(&juego->reuben, movimiento, juego);
        }
    }
    
    if(termino_comida(*juego)){
        nueva_comida(juego);
    }

}

int estado_juego(juego_t juego){
    int estado = 0;

    // revisa si se cayo el personaje
    for(int i = 0; i < juego.tope_obstaculos; i++){
        if(distancia_manhattan(juego.stitch.posicion.fil, juego.stitch.posicion.col, juego.obstaculos[i].posicion.fil, juego.obstaculos[i].posicion.col) == 0){
            estado = -1;
        }else if(distancia_manhattan(juego.reuben.posicion.fil, juego.reuben.posicion.col, juego.obstaculos[i].posicion.fil, juego.obstaculos[i].posicion.col) == 0){
            estado = -1;
        }
    }

    // revisa si ganaste el juego
    for(int i = 0; i < juego.tope_comida; i++){

        if(juego.comida_actual == juego.comida[i].tipo && i == juego.tope_comida-1 && termino_comida(juego)){ 
           estado = 1;
        }
    }

    return estado;
}
