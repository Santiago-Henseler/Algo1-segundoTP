#include "cocineritos.h"
#include "jugabilidad.h"
#include "jugabilidad_auxiliar.h"
#include "iniciador.h"
#include "establecer_posiciones.h"
#include "funciones_auxiliares.h"

void inicializar_juego(juego_t* juego, int precio){

    juego->personaje_activo = STICH;
    juego->movimientos = 0;

    juego->precio_total = precio;

    juego->mesa.col = POSICION_MESA;
    juego->mesa.fil = POSICION_MESA;

    juego->comida_actual = ENSALADA;
    juego->tope_comida = 0;
    juego->tope_comida_lista = 0;

    crear_mapa(juego->paredes, &juego->tope_paredes);
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

    cargar_terreno(juego, terreno);

    // visualizamos por pantalla la matriz terreno
    for(int i = 0; i < LARGO_TABLERO; i++){
        for(int j = 0; j< LARGO_TABLERO; j++){
            printf(" %c", terreno[i][j]);
        }printf("\n");
    }
}

void realizar_jugada(juego_t* juego, char movimiento){
   
    if(juego->movimientos == MOVIMIENTOS_FUEGO && !fuego_activo(*juego)){
        iniciar_fuego_matafuego(juego);
    }
   
    if(juego->personaje_activo == STICH){
        if(movimiento == CAMBIO_PERSONAJE){
            juego->personaje_activo = RUBEN;
        }else if(movimiento == CORTAR && !fuego_activo(*juego)){
            usar_herramienta(juego->stitch, juego);
        }else if(movimiento == INTERACTUAR_MESA && !fuego_activo(*juego)){
            pasar_por_la_mesa(&juego->stitch, juego);
        }else if(movimiento == USAR_MATAFUEGO && fuego_activo(*juego)){
            apagar_fuego(&juego->stitch, juego);
        }else{
            movimiento_personaje(&juego->stitch, movimiento, juego);
        }
    }
    else if(juego->personaje_activo == RUBEN){
        if(movimiento == CAMBIO_PERSONAJE){
            juego->personaje_activo = STICH;
        }else if(movimiento == COCINAR && !fuego_activo(*juego)){
            usar_herramienta(juego->reuben, juego);
        }else if(movimiento == INTERACTUAR_MESA && !fuego_activo(*juego)){
            pasar_por_la_mesa(&juego->reuben, juego);
        }else if(movimiento == USAR_MATAFUEGO && fuego_activo(*juego)){
            apagar_fuego(&juego->reuben, juego);
        }else{
            movimiento_personaje(&juego->reuben, movimiento, juego);
        }
    }
    
    if(termino_comida(*juego)){
        nueva_comida(juego);
        iniciar_comidas(juego, juego->precio_total);
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

        if(juego.precio_total > SEGUNDO_MENU && juego.precio_total <= TERCER_MENU && juego.comida_actual == SANGUCHE){ 
           estado = 1;
        }else if(juego.precio_total <= SEGUNDO_MENU && juego.comida_actual == HAMBURGESA){ 
           estado = 1;
        }else if(juego.precio_total > TERCER_MENU && juego.comida_actual == SANGUCHE && termino_comida(juego)){ 
           estado = 1;
        }
    }

    return estado;
}