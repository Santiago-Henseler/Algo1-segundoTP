#include "cocineritos.h"
#include "jugabilidad.h"
#include "iniciador.h"
#include "establecer_posiciones.h"

// METER EN OTRO ARCHIVO
bool ya_entregado(juego_t juego, char comida){
    bool rta = false;

    for(int i = 0; i < juego.tope_comida; i++){
        if(comida == juego.comida_lista[i].tipo){
            rta = true;
        }
    }
    return rta;
}

bool termino_comida(juego_t juego){
    bool rta = false;

    for(int i = 0; i< juego.tope_comida; i++){
        
        if(juego.comida_actual == juego.comida[i].tipo){
            if(juego.comida[i].ingrediente->tipo == juego.comida_lista->tipo){
                printf("SE");
            }
        }
    }
    return rta; 
}




void inicializar_juego(juego_t* juego, int precio){

    juego->personaje_activo = STICH;
    juego->precio_total = precio;

    juego->mesa.col = POSICION_MESA;
    juego->mesa.fil = POSICION_MESA;

    crear_mapa(juego);
    iniciar_obstaculos(juego);
    iniciar_comidas(juego, precio);
    iniciar_objetos(juego);
    iniciar_personaje(juego);
    iniciar_salida(juego);
  
    juego->comida_actual = juego->comida[0].tipo;
    juego->tope_comida_lista = 0;
}

void imprimir_terreno(juego_t juego){
  
    // limpiamos la pantalla
    //system("clear");

    char terreno[LARGO_TABLERO][LARGO_TABLERO];

    // posiciones de las paredes
    for(int i = 0; i < juego.tope_paredes; i++){

        for(int j = 0; j< juego.tope_paredes; j++){

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
        terreno[juego.herramientas[i].posicion.fil][juego.herramientas[i].posicion.col] = juego.herramientas[i].tipo; 
    }

    // posiciones de los personajes
    terreno[juego.stitch.posicion.fil][juego.stitch.posicion.col] = STICH; 
    terreno[juego.reuben.posicion.fil][juego.reuben.posicion.col] = RUBEN; 
 
    // visualizamos por pantalla la matriz terreno
    for(int i = 0; i < juego.tope_paredes; i++){
        for(int j = 0; j< juego.tope_paredes; j++){
            printf(" %c", terreno[i][j]);
        }printf("\n");
    }
}

void realizar_jugada(juego_t* juego, char movimiento){
    /*
    if(juego->movimientos == MOVIMIENTOS_FUEGO){
        iniciar_fuego_matafuego(juego);
        juego->movimientos += 1;
    }else if(juego->movimientos == 16){


    }else{
        */
        juego->movimientos += 1;

        if(juego->personaje_activo == STICH){
            if(movimiento == CAMBIO_PERSONAJE){
                juego->personaje_activo = RUBEN;
            }else if(movimiento == CORTAR){
                usar_herramienta(juego->stitch, juego);
            }else if(movimiento == INTERACTUAR_MESA){
                pasar_por_la_mesa(&juego->stitch, juego);
            }else{
                movimiento_personaje(&juego->stitch, movimiento, juego);
            }
        }
        else if(juego->personaje_activo == RUBEN){
            if(movimiento == CAMBIO_PERSONAJE){
                juego->personaje_activo = STICH;
            }else if(movimiento == COCINAR){
                usar_herramienta(juego->reuben, juego);
            }else if(movimiento == INTERACTUAR_MESA){
                pasar_por_la_mesa(&juego->reuben, juego);
            }else if(movimiento == 'P'){
                dejar_en_la_salida(&juego->reuben, juego);
            }else{
                movimiento_personaje(&juego->reuben, movimiento, juego);
            }
        }
    imprimir_terreno(*juego);
}

int estado_juego(juego_t juego){
    int estado = 0;

    return estado;
}


  // 
  // CREAR FUEGO Y APAGARLO
  // 
  // FUNCION ESTADO JUEGO 
  //
  // FUNCION TERMINO COMIDA HACERLA FUNCIONAR :c
